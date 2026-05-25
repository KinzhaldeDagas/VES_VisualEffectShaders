sampler2D SceneSampler : register(s0);
sampler2D DepthSampler : register(s1);
float4 MoonSugarParams : register(c0);
float4 MoonSugarScreen : register(c1);
float4 MoonSugarTuning : register(c2);
float4 MoonSugarProfile : register(c3);
float4 MoonSugarViewport : register(c4);
float4 MoonSugarDepthState : register(c5);

float MoonSugarLuma(float3 c)
{
    return dot(c, float3(0.299, 0.587, 0.114));
}

float2 MoonSugarLocalUV(float2 uv)
{
    float2 extent = max(MoonSugarViewport.zw, float2(0.0005, 0.0005));
    return saturate((uv - MoonSugarViewport.xy) / extent);
}

float2 MoonSugarViewportClamp(float2 uv)
{
    float2 px = max(MoonSugarScreen.xy, float2(0.0005, 0.0005));
    float2 minUv = MoonSugarViewport.xy + px * 0.5;
    float2 maxUv = MoonSugarViewport.xy + max(MoonSugarViewport.zw - px * 0.5, px);
    return clamp(uv, minUv, maxUv);
}

float3 MoonSugarSceneSample(float2 uv)
{
    return tex2D(SceneSampler, MoonSugarViewportClamp(uv)).rgb;
}

float3 MoonSugarStableSceneSample(float2 uv, float3 fallback)
{
    float3 sampleColor = MoonSugarSceneSample(uv);
    float sampleLuma = MoonSugarLuma(sampleColor);
    float fallbackLuma = MoonSugarLuma(fallback);
    float lowChannel = min(sampleColor.r, min(sampleColor.g, sampleColor.b));
    float nearWhite = smoothstep(0.90, 0.985, sampleLuma) * smoothstep(0.68, 0.95, lowChannel);
    float mismatch = smoothstep(0.20, 0.52, abs(sampleLuma - fallbackLuma));
    float fallbackNotWhite = 1.0 - smoothstep(0.78, 0.94, fallbackLuma);
    return lerp(sampleColor, fallback, nearWhite * mismatch * fallbackNotWhite);
}

float3 MoonSugarSceneEdge(float2 uv)
{
    float2 px = max(MoonSugarScreen.xy, float2(0.0005, 0.0005));
    float l = MoonSugarLuma(MoonSugarSceneSample(uv - float2(px.x, 0.0)));
    float r = MoonSugarLuma(MoonSugarSceneSample(uv + float2(px.x, 0.0)));
    float u = MoonSugarLuma(MoonSugarSceneSample(uv - float2(0.0, px.y)));
    float d = MoonSugarLuma(MoonSugarSceneSample(uv + float2(0.0, px.y)));
    float dl = MoonSugarLuma(MoonSugarSceneSample(uv - px));
    float dr = MoonSugarLuma(MoonSugarSceneSample(uv + px));
    float ul = MoonSugarLuma(MoonSugarSceneSample(uv + float2(-px.x, px.y)));
    float ur = MoonSugarLuma(MoonSugarSceneSample(uv + float2(px.x, -px.y)));
    float2 g = float2(r - l, d - u);
    float diagonal = abs(dr - dl) + abs(ur - ul);
    return float3(g, saturate(length(g) * 4.4 + diagonal * 2.2));
}

float MoonSugarDepthValid(float d)
{
    return smoothstep(0.00005, 0.0020, d) * (1.0 - smoothstep(0.99920, 0.99998, d));
}

float MoonSugarDepthAvailable()
{
    return saturate(max(MoonSugarProfile.z, MoonSugarDepthState.x));
}

float MoonSugarCapturedDepthTrust()
{
    return saturate(MoonSugarDepthState.y);
}

float4 MoonSugarDepthSurfaceMask(float2 uv, float edgePresence)
{
    float2 px = max(MoonSugarScreen.xy, float2(0.0005, 0.0005));
    float c = tex2D(DepthSampler, uv).r;
    float l = tex2D(DepthSampler, uv - float2(px.x, 0.0)).r;
    float r = tex2D(DepthSampler, uv + float2(px.x, 0.0)).r;
    float u = tex2D(DepthSampler, uv - float2(0.0, px.y)).r;
    float d = tex2D(DepthSampler, uv + float2(0.0, px.y)).r;
    float centerValid = MoonSugarDepthValid(c);
    float crossValid = min(min(MoonSugarDepthValid(l), MoonSugarDepthValid(r)), min(MoonSugarDepthValid(u), MoonSugarDepthValid(d)));
    float span = max(max(abs(c - l), abs(c - r)), max(abs(c - u), abs(c - d)));
    float depthEdge = saturate((abs(r - l) + abs(d - u)) * 72.0);
    float coherence = 1.0 - smoothstep(0.010, 0.080, span);
    float interior = centerValid * crossValid * coherence;
    float boundary = centerValid * depthEdge * smoothstep(0.65, 1.0, edgePresence);
    float surface = saturate(interior * 0.94 + boundary * 0.16);
    return float4(c, centerValid, depthEdge, surface);
}

float4 HeadWoundPS(float2 uv)
{
    float t = MoonSugarParams.x;
    float i = saturate(MoonSugarParams.y);
    float severity = saturate(MoonSugarProfile.y);
    float2 localUv = MoonSugarLocalUV(uv);
    float2 p = localUv - 0.5;
    float r2 = dot(p, p);
    float radius = sqrt(r2 + 0.00001);
    float edge = saturate((r2 - 0.035) * 2.40);
    float heartbeat = pow(sin(t * 3.45) * 0.5 + 0.5, 2.7);
    float pulse = pow(sin(t * 4.15 + radius * 2.0) * 0.5 + 0.5, 2.0);
    float ring = sin(t * 8.0 - radius * 31.0) * 0.5 + 0.5;
    float shock = saturate(1.0 - abs(frac(t * 0.37) - 0.08) * 10.5);
    float2 dir = normalize(p + float2(0.0001, -0.0001));
    float3 sceneEdge = MoonSugarSceneEdge(uv);
    float objectEdge = saturate(sceneEdge.z * (0.95 + edge * 0.45));
    float2 edgeDir = normalize(sceneEdge.xy + dir * 0.012 + float2(0.0001, -0.0001));
    float2 edgeTangent = float2(-edgeDir.y, edgeDir.x);
    float edgeCrawl = sin(t * 16.0 + localUv.x * 41.0 - localUv.y * 37.0);
    float2 drift = float2(sin(t * 2.6 + localUv.y * 3.1), cos(t * 2.1 + localUv.x * 2.4)) * (0.0018 + 0.0054 * severity) * i;
    float2 tremor = float2(sin(t * 21.0 + localUv.y * 17.0), cos(t * 19.0 - localUv.x * 13.0)) * (0.0009 + 0.0018 * severity) * i;
    float2 edgeWarp = (edgeDir * edgeCrawl + edgeTangent * cos(t * 11.5 + localUv.x * 19.0 + localUv.y * 23.0) * 0.55) * objectEdge * (0.0016 + 0.0046 * severity) * i;
    float radialBlur = (0.0014 + severity * 0.0058) * (0.30 + pulse * 0.52 + heartbeat * 0.18 + shock * 0.24) * i;
    float2 blurVec = dir * radialBlur + tremor;
    float focus = saturate(1.0 - edge * (0.45 + severity * 0.30));
    float3 center = MoonSugarSceneSample(uv + drift * 0.34 + edgeWarp * 0.45);
    float3 nearA = MoonSugarStableSceneSample(uv + blurVec + drift + edgeWarp, center);
    float3 nearB = MoonSugarStableSceneSample(uv - blurVec * 0.75 - drift * 0.35 - edgeWarp * 0.55, center);
    float3 farA = MoonSugarStableSceneSample(uv + blurVec * 2.15 + drift * 1.35 + edgeWarp * 1.40, center);
    float3 farB = MoonSugarStableSceneSample(uv - blurVec * 1.70 - drift - edgeWarp, center);
    float3 color = center * (0.44 + focus * 0.08) + (nearA + nearB) * 0.205 + (farA + farB) * (0.065 + severity * 0.015);
    float2 echoOffset = float2(sin(t * 3.35), cos(t * 2.85)) * (0.0042 + severity * 0.0100) * i * (0.55 + shock * 0.45);
    float3 echoA = MoonSugarStableSceneSample(uv + echoOffset + edgeWarp * 0.65, center);
    float3 echoB = MoonSugarStableSceneSample(uv - echoOffset * 0.85 - edgeWarp * 0.40, center);
    float3 edgeEcho = MoonSugarStableSceneSample(uv - edgeWarp * 2.15 + tremor * 0.45, center);
    color = lerp(color, (echoA + echoB) * 0.5, (0.16 + severity * 0.20) * i * (1.0 - edge * 0.18));
    color = lerp(color, edgeEcho, objectEdge * (0.16 + heartbeat * 0.08 + severity * 0.10) * i);
    float2 splitOffset = (dir * (0.0020 + severity * 0.0050) + edgeTangent * objectEdge * 0.0022) * i;
    float3 redSplit = MoonSugarStableSceneSample(uv + splitOffset + drift * 0.45, center);
    float3 blueSplit = MoonSugarStableSceneSample(uv - splitOffset * 0.85 - drift * 0.25, center);
    float luma = MoonSugarLuma(color);
    color.r = lerp(color.r, redSplit.r, (0.16 + objectEdge * 0.20) * severity * i);
    color.b = lerp(color.b, blueSplit.b, (0.18 + objectEdge * 0.22) * severity * i);
    color = lerp(color, float3(luma, luma, luma), (0.28 + severity * 0.32) * i);
    color = (color - 0.5) * (1.0 - (0.10 + severity * 0.16) * i) + 0.5;
    color.r += (edge * 0.18 + pulse * 0.040 + ring * edge * 0.035 + objectEdge * 0.055) * severity * i;
    color.g -= (edge * 0.080 + pulse * 0.018 + objectEdge * 0.028) * severity * i;
    color.b -= (edge * 0.105 + pulse * 0.028 + objectEdge * 0.038) * severity * i;
    color *= 1.0 - edge * (0.38 + severity * 0.26) * i;
    color += (heartbeat * 0.020 + shock * 0.035 + pulse * 0.018) * i;
    return float4(saturate(color), 1.0);
}

float4 BlindPS(float2 uv)
{
    float t = MoonSugarParams.x;
    float effect = saturate(MoonSugarParams.y);
    float blind = saturate(MoonSugarProfile.y) * effect;
    float2 localUv = MoonSugarLocalUV(uv);
    float2 p = localUv - 0.5;
    p.x *= MoonSugarScreen.z / max(MoonSugarScreen.w, 1.0);
    float radius = length(p);
    float peripheral = smoothstep(0.16, 0.82, radius);
    float centerBlur = blind * (0.28 + blind * 0.26);
    float edgeBlur = blind * (0.82 + peripheral * 0.98);
    float2 dir = normalize(p + float2(0.0001, -0.0001));
    float3 sceneEdge = MoonSugarSceneEdge(uv);
    float edgePresence = saturate(sceneEdge.z * (0.60 + blind * 0.85));
    float verticalFar = 1.0 - smoothstep(0.24, 0.96, localUv.y);
    float lowDetailFar = 1.0 - saturate(edgePresence * 1.75);
    float screenDistanceCue = verticalFar * 0.56 + lowDetailFar * verticalFar * 0.28 + peripheral * 0.16;
    float distanceCue = saturate(screenDistanceCue * blind);
    float2 edgeDir = normalize(sceneEdge.xy + dir * 0.010 + float2(0.0001, -0.0001));
    float2 tangent = float2(-edgeDir.y, edgeDir.x);
    float2 motionDir = normalize(float2(sin(t * 1.23) + 0.35 * cos(t * 0.61), cos(t * 0.97) - 0.25 * sin(t * 0.77)) + float2(0.0001, 0.0002));
    float shimmer = sin(t * 1.10 + radius * 6.0 + localUv.x * 2.0) * 0.5 + 0.5;
    float blur = (0.0022 + blind * 0.0145) * (0.40 + edgeBlur + edgePresence * 0.42) + distanceCue * (0.0018 + blind * 0.0050);
    float motion = (0.0016 + blind * 0.0095) * (0.48 + shimmer * 0.38 + peripheral * 0.34);
    float2 softDrift = (dir * (shimmer - 0.5) + tangent * (sin(t * 0.71 + localUv.y * 4.0) * 0.5)) * blind * peripheral * 0.0040;
    float2 blurVec = dir * blur + softDrift;
    float2 motionVec = motionDir * motion;
    float3 center = tex2D(SceneSampler, uv + softDrift * 0.25).rgb;
    float3 radialA = tex2D(SceneSampler, uv + blurVec).rgb;
    float3 radialB = tex2D(SceneSampler, uv - blurVec * 0.85).rgb;
    float3 tangentA = tex2D(SceneSampler, uv + tangent * blur * 0.90 + softDrift).rgb;
    float3 tangentB = tex2D(SceneSampler, uv - tangent * blur * 0.75 - softDrift * 0.40).rgb;
    float3 motionA = tex2D(SceneSampler, uv - motionVec).rgb;
    float3 motionB = tex2D(SceneSampler, uv - motionVec * 2.10 + softDrift * 0.50).rgb;
    float3 motionC = tex2D(SceneSampler, uv - motionVec * 3.35).rgb;
    float3 softBlur = center * 0.22 + (radialA + radialB + tangentA + tangentB) * 0.155 + motionA * 0.095 + motionB * 0.045 + motionC * 0.020;
    float blurMix = saturate(0.30 + blind * 0.68 + peripheral * blind * 0.30 + centerBlur);
    float3 color = lerp(center, softBlur, blurMix);
    float3 edgeSoft = tex2D(SceneSampler, uv + edgeDir * blur * 1.35 - motionVec * 0.85).rgb;
    color = lerp(color, edgeSoft, edgePresence * blind * 0.16);
    float ghostPulse = sin(t * 0.82 + radius * 5.5 + localUv.y * 2.0) * 0.5 + 0.5;
    float2 ghostVec = (motionVec * (3.35 + ghostPulse * 1.75) + dir * blur * (1.15 + peripheral) + tangent * blur * (0.50 - ghostPulse)) * (0.75 + peripheral * 0.55);
    float3 ghostA = tex2D(SceneSampler, uv - ghostVec).rgb;
    float3 ghostB = tex2D(SceneSampler, uv - ghostVec * 1.65 + tangent * blur * 1.25 + softDrift * 0.30).rgb;
    float3 ghostC = tex2D(SceneSampler, uv + ghostVec * 0.70 - dir * blur * 0.85).rgb;
    float3 ghost = ghostA * 0.45 + ghostB * 0.35 + ghostC * 0.20;
    float ghostLuma = MoonSugarLuma(ghost);
    ghost = lerp(float3(ghostLuma, ghostLuma, ghostLuma), float3(ghostLuma * 0.58, ghostLuma * 0.62, ghostLuma * 0.68), 0.48);
    ghost *= 0.56;
    float ghostStrength = saturate((0.16 + peripheral * 0.34 + edgePresence * 0.22) * blind + distanceCue * 0.18);
    color = lerp(color, ghost, ghostStrength);
    float luma = MoonSugarLuma(color);
    float3 gray = float3(luma, luma, luma);
    float desat = saturate(0.34 * blind + peripheral * blind * 0.24);
    color = lerp(color, gray, desat);
    float contrast = 1.0 - saturate(blind * 0.42 + peripheral * blind * 0.24);
    color = (color - 0.5) * contrast + 0.5;
    float wash = saturate(0.08 + blind * 0.14 + shimmer * blind * 0.025);
    color = lerp(color, float3(0.42, 0.44, 0.46), wash);
    float distanceDark = saturate(distanceCue * (0.36 + blind * 0.24));
    color = lerp(color, float3(0.012, 0.014, 0.018), distanceDark);
    color *= 1.0 - distanceCue * 0.25;
    color *= 1.0 - blind * (0.261 + peripheral * 0.348);
    color -= float3(0.0261, 0.0290, 0.0348) * blind * (0.45 + peripheral * 0.55);
    color *= lerp(1.0, 0.55, effect);
    return float4(saturate(color), 1.0);
}

float4 DimPS(float2 uv)
{
    float effect = saturate(MoonSugarParams.y);
    float dim = saturate(MoonSugarProfile.y) * effect;
    float variant = MoonSugarProfile.w;
    float dimBoost = (variant > 0.5) ? 1.35 : 1.0;
    float3 scene = MoonSugarSceneSample(uv);
    float luma = MoonSugarLuma(scene);
    float3 gray = float3(luma, luma, luma);
    float desat = saturate(dim * 0.10);
    float darkness = saturate(dim * 0.62 * dimBoost);
    float blackMix = saturate(dim * 0.055 * dimBoost);
    float3 color = lerp(scene, gray, desat);
    color *= 1.0 - darkness;
    color = lerp(color, float3(0.006, 0.007, 0.010), blackMix);
    if (variant > 3.5)
    {
        float3 redDim = color * float3(1.08, 0.44, 0.36) + float3(0.055, 0.006, 0.004) * dim;
        color = lerp(color, redDim, saturate(dim * 0.72));
    }
    else if (variant > 2.5)
    {
        float3 purpleDim = color * float3(0.76, 0.46, 1.12) + float3(0.028, 0.006, 0.075) * dim;
        color = lerp(color, purpleDim, saturate(dim * 0.72));
    }
    else if (variant > 1.5)
    {
        float3 inverted = 1.0 - scene;
        float invLuma = MoonSugarLuma(inverted);
        float3 whiteInverted = lerp(float3(invLuma, invLuma, invLuma), inverted, 0.24);
        whiteInverted = lerp(whiteInverted, float3(0.78, 0.82, 0.92), 0.30);
        whiteInverted *= 1.0 - saturate(dim * 0.36);
        color = lerp(color, whiteInverted, saturate(dim * 0.62));
    }
    else
    {
        color = lerp(color, color * float3(0.94, 0.96, 1.0), dim * 0.08);
    }
    return float4(saturate(color), 1.0);
}

float OnFireHash(float2 p)
{
    return frac(sin(dot(p, float2(127.1, 311.7))) * 43758.5453);
}

float OnFireNoise(float2 p)
{
    float2 ip = floor(p);
    float2 fp = frac(p);
    fp = fp * fp * (3.0 - 2.0 * fp);
    float a = OnFireHash(ip);
    float b = OnFireHash(ip + float2(1.0, 0.0));
    float c = OnFireHash(ip + float2(0.0, 1.0));
    float d = OnFireHash(ip + float2(1.0, 1.0));
    return lerp(lerp(a, b, fp.x), lerp(c, d, fp.x), fp.y);
}

float FireHashFast(float2 p)
{
    float3 p3 = frac(float3(p.x, p.y, p.x) * float3(0.1031, 0.11369, 0.13787));
    p3 += dot(p3, p3.yzx + float3(19.19, 19.19, 19.19));
    return frac((p3.x + p3.y) * p3.z);
}

float FireNoiseFast(float2 p)
{
    float2 ip = floor(p);
    float2 fp = frac(p);
    fp = fp * fp * (3.0 - 2.0 * fp);
    float a = FireHashFast(ip);
    float b = FireHashFast(ip + float2(1.0, 0.0));
    float c = FireHashFast(ip + float2(0.0, 1.0));
    float d = FireHashFast(ip + float2(1.0, 1.0));
    return lerp(lerp(a, b, fp.x), lerp(c, d, fp.x), fp.y);
}

float4 HeatShimmerPS(float2 uv)
{
    float t = MoonSugarParams.x;
    float effect = saturate(MoonSugarParams.y);
    float severity = saturate(MoonSugarProfile.y);
    float heat = severity * effect;
    float2 localUv = MoonSugarLocalUV(uv);
    float2 p = localUv - 0.5;
    p.x *= MoonSugarScreen.z / max(MoonSugarScreen.w, 1.0);
    float3 scene = MoonSugarSceneSample(uv);
    float3 sceneEdge = MoonSugarSceneEdge(uv);
    float edgePresence = saturate(sceneEdge.z * (0.85 + severity * 0.45));
    float groundBand = smoothstep(0.36, 0.94, localUv.y);
    float horizonFeather = smoothstep(0.24, 0.56, localUv.y);
    float depthBound = MoonSugarCapturedDepthTrust();
    float4 depthMask = MoonSugarDepthSurfaceMask(uv, edgePresence);
    float worldSurfaceMask = depthMask.w;
    float groundMask = saturate(groundBand * horizonFeather * worldSurfaceMask * depthBound);
    float n0 = OnFireNoise(float2(localUv.x * 6.5 + sin(t * 0.62 + localUv.y * 5.0) * 0.42, localUv.y * 11.5 - t * (1.55 + severity * 1.10)));
    float n1 = OnFireNoise(float2(localUv.x * 17.0 - t * 0.74, localUv.y * 26.0 - t * (3.80 + severity * 2.50)));
    float n2 = OnFireNoise(float2(localUv.x * 39.0 + t * 1.10, localUv.y * 52.0 - t * (8.40 + severity * 4.20)));
    float wave = sin(localUv.y * (88.0 + severity * 58.0) - t * (15.0 + severity * 15.0) + n0 * 6.0 + p.x * 3.0) * 0.5 + 0.5;
    float boil = saturate(n0 * 0.48 + n1 * 0.34 + n2 * 0.18);
    float cell = smoothstep(0.30, 0.92, boil) * (1.0 - smoothstep(0.93, 1.0, boil));
    float heatMask = saturate(groundMask * heat * (0.44 + boil * 0.52 + wave * 0.26 + cell * 0.22));
    float2 edgeDir = normalize(sceneEdge.xy + float2(0.0001, -0.0001));
    float horizontalWaver = (n0 - 0.5) * 1.60 + sin(t * 8.0 + localUv.y * 72.0 + n1 * 5.0) * 0.42;
    float upwardWaver = -abs(n1 - 0.5) * 0.78 - wave * 0.18;
    float2 shimmerOffset = float2(horizontalWaver, upwardWaver) * heatMask * (0.0026 + severity * 0.0148);
    shimmerOffset += edgeDir * (n2 - 0.5) * heatMask * (0.0016 + severity * 0.0058);
    float2 bandOffset = float2(sin(t * 11.0 + localUv.y * 118.0 + n2 * 7.0), 0.0) * heatMask * (0.0009 + severity * 0.0044);
    float3 warpA = MoonSugarStableSceneSample(uv + shimmerOffset + bandOffset, scene);
    float3 warpB = MoonSugarStableSceneSample(uv - shimmerOffset * 0.55 + bandOffset * 0.60, scene);
    float3 glint = MoonSugarStableSceneSample(uv + float2(shimmerOffset.x * 1.45, shimmerOffset.y * 0.35), scene);
    float3 refracted = warpA * 0.54 + warpB * 0.30 + glint * 0.16;
    float refractMix = saturate(heatMask * (0.46 + severity * 0.38 + wave * 0.10));
    float3 color = lerp(scene, refracted, refractMix);
    float lens = pow(saturate(boil * wave + cell * 0.22), 2.4) * heatMask;
    color = lerp(color, color * float3(1.055, 1.010, 0.940) + float3(0.022, 0.010, 0.002), heatMask * (0.18 + severity * 0.16));
    color += float3(1.0, 0.58, 0.20) * lens * (0.035 + severity * 0.055);
    color = lerp(color, scene, saturate((1.0 - groundMask) * 0.12));
    return float4(saturate(color), 1.0);
}

float4 DepthMaskDebugPS(float2 uv)
{
    float2 localUv = MoonSugarLocalUV(uv);
    float3 scene = tex2D(SceneSampler, uv).rgb;
    float3 sceneEdge = MoonSugarSceneEdge(uv);
    float4 depthMask = MoonSugarDepthSurfaceMask(uv, saturate(sceneEdge.z));
    float depthAvailable = MoonSugarDepthAvailable();
    float capturedTrust = MoonSugarCapturedDepthTrust();
    float activeFallback = saturate(MoonSugarDepthState.z);
    float depthValid = depthMask.y * depthAvailable;
    float raw = saturate(depthMask.x);
    float surface = depthMask.w * capturedTrust;
    float depthEdge = depthMask.z * depthAvailable;
    float3 rawDepth = lerp(float3(0.035, 0.035, 0.045), float3(raw, raw, raw), depthValid);
    float3 maskColor = rawDepth * 0.42 + float3(surface, depthEdge * 0.85, depthValid) * 0.95;
    float3 sourceColor = float3(0.90, 0.10, 0.08);
    sourceColor = lerp(sourceColor, float3(1.00, 0.72, 0.10), activeFallback);
    sourceColor = lerp(sourceColor, float3(0.05, 0.95, 0.42), capturedTrust);
    float band = 1.0 - smoothstep(0.035, 0.055, localUv.y);
    float3 color = lerp(scene * 0.18 + maskColor * 0.82, sourceColor, band * 0.86);
    color += depthEdge * float3(0.00, 0.12, 0.28);
    color = lerp(color, scene * 0.18 + float3(0.38, 0.03, 0.03), saturate((1.0 - depthAvailable) * 0.78));
    return float4(saturate(color), 1.0);
}

float4 OnFirePS(float2 uv)
{
    float t = MoonSugarParams.x;
    float effect = saturate(MoonSugarParams.y);
    float severity = saturate(MoonSugarProfile.y);
    float fire = severity * effect;
    float2 localUv = MoonSugarLocalUV(uv);
    float height = saturate(1.0 - localUv.y);
    float aspect = MoonSugarScreen.z / max(MoonSugarScreen.w, 1.0);
    float centerX = (localUv.x - 0.5) * aspect;
    float riseLimit = 0.48 + severity * 0.33;
    float verticalEnvelope = 1.0 - smoothstep(riseLimit, riseLimit + 0.34, height);
    float baseHeat = 1.0 - smoothstep(0.00, 0.18 + severity * 0.08, height);
    float topFeather = 1.0 - smoothstep(0.74 + severity * 0.12, 1.0, height);
    float sideFalloff = 1.0 - smoothstep(0.50 + severity * 0.18, 0.96 + severity * 0.16, abs(centerX));
    float sway = sin(t * 1.22 + height * 9.5 + localUv.x * 2.6) * (0.060 + height * 0.050);
    float x = localUv.x + sway * (0.28 + height * 0.72);
    float n0 = FireNoiseFast(float2(x * 4.2 + t * 0.18, height * 5.8 - t * (0.88 + severity * 0.28)));
    float n1 = FireNoiseFast(float2(x * 11.0 - t * 0.34 + n0 * 0.55, height * 14.0 - t * (2.10 + severity * 0.70)));
    float columns = sin((x + n0 * 0.13) * (20.0 + severity * 9.0) + height * 7.0 - t * 1.2) * 0.5 + 0.5;
    float curl = (n1 - 0.5) * 0.105 + sin(t * 2.75 + height * 16.0 + x * 6.5) * 0.040;
    float tongueNoise = saturate(n0 * 0.52 + n1 * 0.34 + columns * 0.14);
    float tongueThreshold = 0.38 + height * (0.52 + severity * 0.18) - baseHeat * 0.24;
    float softTongue = smoothstep(tongueThreshold - 0.22, tongueThreshold + 0.24, tongueNoise + curl);
    float innerTongue = smoothstep(tongueThreshold + 0.06, tongueThreshold + 0.43, tongueNoise + curl * 0.70);
    float flameMask = saturate(softTongue * verticalEnvelope * topFeather * sideFalloff);
    float lick = saturate(flameMask * (0.62 + n1 * 0.50 + baseHeat * 0.35));
    float coreBase = saturate(innerTongue * flameMask * 1.28 + baseHeat * 0.42 - height * 0.18);
    float core = coreBase * coreBase * (1.55 - coreBase * 0.55);
    float hotBase = saturate(core * 1.42 + baseHeat * 0.38 - height * 0.34);
    float hot = hotBase * hotBase;
    float redEdge = saturate(lick - core * 0.52);
    float heatMask = saturate((flameMask * 0.70 + core * 0.35 + baseHeat * 0.18) * fire);
    float2 heatOffset = float2((n1 - 0.5) * 1.25 + sin(t * 5.4 + height * 28.0) * 0.25, -abs(n0 - 0.5) * 0.55 - flameMask * 0.14);
    heatOffset *= heatMask * (0.0025 + severity * 0.0140);
    heatOffset.x += curl * heatMask * (0.010 + severity * 0.014);
    float3 scene = tex2D(SceneSampler, uv).rgb;
    float2 blurStep = float2(MoonSugarScreen.x * (2.0 + severity * 5.0), MoonSugarScreen.y * (2.0 + severity * 6.0));
    float3 blurA = tex2D(SceneSampler, uv + heatOffset).rgb;
    float3 blurB = tex2D(SceneSampler, uv - heatOffset * 0.45 + float2(blurStep.x, -blurStep.y * 0.55)).rgb;
    float3 blurred = scene * 0.46 + (blurA + blurB) * 0.27;
    float3 color = lerp(scene, blurred, saturate(heatMask * (0.32 + severity * 0.42)));
    float blueBase = baseHeat * hot * (0.20 + severity * 0.10);
    float3 flameColor = float3(0.55, 0.045, 0.010) * redEdge;
    flameColor += float3(0.96, 0.18, 0.018) * lick;
    flameColor += float3(1.00, 0.48, 0.060) * core;
    flameColor += float3(1.00, 0.84, 0.34) * hot;
    flameColor += float3(0.54, 0.72, 1.00) * blueBase;
    float glow = saturate((flameMask * 0.42 + core * 0.48 + baseHeat * 0.22) * fire);
    float3 warmBleed = scene * float3(1.08, 0.98, 0.86) + float3(0.10, 0.035, 0.006) * glow;
    color = lerp(color, warmBleed, saturate(glow * 0.16 + heatMask * 0.035));
    color += flameColor * (0.20 + severity * 0.46) * fire;
    color += float3(1.0, 0.38, 0.07) * glow * (0.10 + severity * 0.10);
    float smokeBand = smoothstep(0.30, 0.82, height) * (1.0 - smoothstep(0.90, 1.0, height));
    float smoke = saturate((n1 * 0.54 + n0 * 0.30 - 0.48) * smokeBand * (0.38 + flameMask * 0.62) * fire);
    color = lerp(color, color * float3(0.60, 0.55, 0.50), smoke * 0.20);
    color -= float3(0.026, 0.022, 0.018) * smoke;
    float2 sparkCell = float2(localUv.x * 72.0 + sway * 10.0 + t * 2.4, height * 76.0 - t * (10.0 + severity * 7.0));
    float sparkSeed = FireHashFast(floor(sparkCell));
    float2 sparkDelta = frac(sparkCell) - 0.5;
    float sparkDot = 1.0 - smoothstep(0.0, 0.0072, dot(sparkDelta, sparkDelta));
    float sparkAge = frac(t * (0.52 + sparkSeed * 1.35) + sparkSeed);
    float spark = sparkDot * step(0.984 - severity * 0.020, sparkSeed) * flameMask * fire * (1.0 - sparkAge) * (1.0 - smoothstep(0.76, 1.0, height));
    color += spark * float3(1.0, 0.70, 0.22) * (0.35 + severity * 0.65);
    float luma = MoonSugarLuma(color);
    color = lerp(color, float3(luma, luma * 0.92, luma * 0.82), smoke * 0.10);
    color = lerp(color, scene, saturate((1.0 - heatMask) * 0.06));
    color *= 1.0 + glow * 0.12;
    return float4(saturate(color), 1.0);
}

float4 RainLayer(float2 localUv, float2 scale, float speed, float t, float aspect, float seedOffset)
{
    float2 gridUv = float2(localUv.x * scale.x, localUv.y * scale.y - t * speed);
    float2 cell = floor(gridUv);
    float2 f = frac(gridUv);
    float seed = FireHashFast(cell + seedOffset);
    float active = step(0.18, seed);
    float slide = frac(t * (0.10 + seed * 0.18) + seed * 1.37);
    float centerX = 0.18 + FireHashFast(cell + seedOffset + float2(3.1, 7.7)) * 0.64;
    float centerY = frac(0.10 + slide * 0.92 + FireHashFast(cell + seedOffset + float2(11.7, 2.3)) * 0.10);
    float wobble = sin(t * (1.6 + seed * 1.2) + centerY * 8.0 + seed * 6.0) * 0.050;
    float2 delta = f - float2(centerX + wobble, centerY);
    float2 oval = float2(delta.x * (1.30 + aspect * 0.20), delta.y * 2.45);
    float d = dot(oval, oval);
    float size = 0.018 + FireHashFast(cell + seedOffset + float2(5.3, 9.1)) * 0.050;
    float drop = (1.0 - smoothstep(size, size * 2.35, d)) * active;
    float core = 1.0 - smoothstep(0.0, size * 0.52, d);
    float rim = saturate(drop - core * 0.58);
    float trailSpan = 0.30 + seed * 0.36;
    float trailGate = smoothstep(0.01, 0.06, delta.y) * (1.0 - smoothstep(trailSpan, trailSpan + 0.18, delta.y));
    float trailWobble = sin(f.y * 13.0 + t * (1.3 + seed) + seed * 5.0) * 0.020;
    float trailX = delta.x + trailWobble;
    float trailWidth = 0.014 + seed * 0.025;
    float trail = (1.0 - smoothstep(trailWidth, trailWidth * 3.1, abs(trailX))) * trailGate * active * (0.42 + seed * 0.48);
    float2 refract = float2(delta.x * (drop * 2.0 + trail * 1.3) + trailX * trail * 0.9, delta.y * drop * 0.75 - trail * 0.20);
    float mask = saturate(drop + trail);
    float glint = saturate(rim * 1.45 + trail * 0.32);
    return float4(refract, mask, glint);
}

float4 RainPS(float2 uv)
{
    float t = MoonSugarParams.x;
    float effect = saturate(MoonSugarParams.y);
    float severity = saturate(MoonSugarProfile.y);
    float rain = severity * effect;
    float2 localUv = MoonSugarLocalUV(uv);
    float aspect = MoonSugarScreen.z / max(MoonSugarScreen.w, 1.0);
    float3 scene = tex2D(SceneSampler, uv).rgb;
    float4 nearDrops = RainLayer(localUv, float2(8.0, 6.0), 0.72 + severity * 0.55, t, aspect, 13.0);
    float4 fineDrops = RainLayer(localUv + float2(0.037, 0.011), float2(17.0, 12.0), 1.18 + severity * 0.86, t, aspect, 47.0);
    float2 impactGrid = float2(localUv.x * 24.0 + t * 0.07, localUv.y * 15.0 - t * (1.65 + severity));
    float2 impactCell = floor(impactGrid);
    float2 impactF = frac(impactGrid) - 0.5;
    float impactSeed = FireHashFast(impactCell + 91.0);
    float impactPhase = frac(t * (1.6 + impactSeed * 1.8) + impactSeed);
    float impactDist = dot(impactF * float2(1.25, 1.0), impactF * float2(1.25, 1.0));
    float ringRadius = 0.018 + impactPhase * (0.072 + severity * 0.035);
    float impactRing = (1.0 - smoothstep(0.0, 0.010 + severity * 0.005, abs(impactDist - ringRadius))) * (1.0 - impactPhase);
    impactRing *= step(0.965 - severity * 0.045, impactSeed);
    float waterMask = saturate((nearDrops.z + fineDrops.z * 0.72 + impactRing * 0.55) * rain);
    float glint = saturate((nearDrops.w + fineDrops.w * 0.68 + impactRing * 0.85) * rain);
    float2 waterOffset = nearDrops.xy * 0.95 + fineDrops.xy * 0.55 + impactF * impactRing * 0.36;
    waterOffset *= rain * (0.0028 + severity * 0.0115);
    waterOffset.y += (nearDrops.z * 0.35 + fineDrops.z * 0.18) * rain * (0.0008 + severity * 0.0026);
    float2 px = max(MoonSugarScreen.xy, float2(0.0005, 0.0005));
    float3 refrA = tex2D(SceneSampler, uv + waterOffset).rgb;
    float3 refrB = tex2D(SceneSampler, uv + waterOffset * 0.45 + float2(px.x * 1.7, -px.y * 0.9)).rgb;
    float3 refracted = refrA * 0.72 + refrB * 0.20 + scene * 0.08;
    float3 color = lerp(scene, refracted, saturate(waterMask * (0.55 + severity * 0.28)));
    float3 coolScene = color * float3(0.88, 0.94, 1.04);
    color = lerp(color, coolScene, rain * 0.12);
    color += glint * float3(0.16, 0.20, 0.23) * (0.45 + severity * 0.50);
    color += impactRing * rain * float3(0.08, 0.10, 0.12);
    float sheen = saturate((nearDrops.z * 0.25 + fineDrops.z * 0.18) * rain);
    color = lerp(color, color + float3(0.030, 0.040, 0.050), sheen);
    color *= 1.0 - rain * (0.045 + waterMask * 0.070);
    return float4(saturate(color), 1.0);
}

float4 FrostPS(float2 uv)
{
    float t = MoonSugarParams.x;
    float effect = saturate(MoonSugarParams.y);
    float severity = saturate(MoonSugarProfile.y);
    float cold = severity * effect;
    float2 localUv = MoonSugarLocalUV(uv);
    float aspect = MoonSugarScreen.z / max(MoonSugarScreen.w, 1.0);
    float2 p = localUv - 0.5;
    p.x *= aspect;
    float2 edgeDist = min(localUv, 1.0 - localUv);
    float edgeNear = min(edgeDist.x, edgeDist.y);
    float edgeMask = 1.0 - smoothstep(0.035 + severity * 0.010, 0.34 + severity * 0.16, edgeNear);
    float cornerMask = 1.0 - smoothstep(0.10, 0.52 + severity * 0.08, min(length(localUv), min(length(localUv - float2(1.0, 0.0)), min(length(localUv - float2(0.0, 1.0)), length(localUv - 1.0)))));
    float pulse = sin(t * 0.62) * 0.5 + 0.5;
    float2 frostUv = localUv * float2(15.0, 10.5) + float2(t * 0.020, -t * 0.014);
    float n0 = FireNoiseFast(frostUv);
    float n1 = FireNoiseFast(frostUv * 2.15 + float2(8.7, 3.1) - t * 0.035);
    float2 veinUv = localUv + float2(n0 - 0.5, n1 - 0.5) * 0.040;
    float verticalNeedle = 1.0 - smoothstep(0.012, 0.072, abs(frac(veinUv.x * (21.0 + severity * 7.0) + n1 * 0.33) - 0.5));
    float diagonalNeedle = 1.0 - smoothstep(0.014, 0.068, abs(frac((veinUv.x * 0.82 + veinUv.y * 1.18) * (16.0 + severity * 5.0) + n0 * 0.27) - 0.5));
    float crossNeedle = 1.0 - smoothstep(0.016, 0.080, abs(frac((veinUv.x * 1.12 - veinUv.y * 0.94) * (13.0 + severity * 4.0) + n1 * 0.31) - 0.5));
    float crystal = saturate(max(verticalNeedle, max(diagonalNeedle, crossNeedle)) * (0.38 + n1 * 0.62));
    float frostCloud = saturate(edgeMask * (0.52 + n0 * 0.34 + n1 * 0.22) + cornerMask * (0.18 + severity * 0.18));
    float frostMask = saturate((frostCloud + crystal * edgeMask * (0.72 + severity * 0.35)) * cold);
    float rimPulse = edgeMask * cold * (0.20 + pulse * (0.25 + severity * 0.18));
    float2 frostNormal = float2(n0 - 0.5 + (diagonalNeedle - crossNeedle) * 0.18, n1 - 0.5 + verticalNeedle * 0.10);
    float2 frostOffset = frostNormal * frostMask * (0.0024 + severity * 0.0068);
    float2 px = max(MoonSugarScreen.xy, float2(0.0005, 0.0005));
    float3 scene = tex2D(SceneSampler, uv).rgb;
    float3 refrA = tex2D(SceneSampler, uv + frostOffset).rgb;
    float3 refrB = tex2D(SceneSampler, uv - frostOffset * 0.58 + float2(px.x * 1.4, px.y * 0.8)).rgb;
    float3 refracted = scene * 0.28 + refrA * 0.52 + refrB * 0.20;
    float luma = MoonSugarLuma(refracted);
    float3 icy = float3(luma * 0.70 + 0.045, luma * 0.86 + 0.090, luma * 1.10 + 0.185);
    float3 color = lerp(scene, refracted, saturate(frostMask * (0.32 + severity * 0.22)));
    color = lerp(color, icy, saturate(frostMask * (0.48 + severity * 0.26)));
    float crystalGlint = crystal * frostMask * (0.34 + severity * 0.34);
    color += float3(0.44, 0.72, 1.00) * rimPulse;
    color += float3(0.82, 0.94, 1.00) * crystalGlint;
    color += float3(0.16, 0.34, 0.58) * edgeMask * cold * (0.035 + pulse * 0.050);
    color *= 1.0 - edgeMask * cold * (0.06 + severity * 0.045);
    color = lerp(color, scene, saturate((1.0 - frostMask) * 0.045));
    return float4(saturate(color), 1.0);
}

float4 MoonSugarDefaultPS(float2 uv)
{
    float t = MoonSugarParams.x;
    float i = saturate(MoonSugarParams.y) * 0.55;
    float dose = saturate(MoonSugarParams.w * 0.18);
    float2 localUv = MoonSugarLocalUV(uv);
    float2 p = localUv - 0.5;
    float r2 = dot(p, p);
    float edge = saturate(r2 * 2.05);
    float pulse = sin(t * 5.8 + r2 * 12.0) * 0.5 + 0.5;
    float3 sceneEdge = MoonSugarSceneEdge(uv);
    float objectEdge = saturate(sceneEdge.z * (0.75 + edge * 0.35));
    float2 edgeDir = normalize(sceneEdge.xy + float2(0.0001, -0.0001));
    float2 edgeTangent = float2(-edgeDir.y, edgeDir.x);
    float edgePulse = sin(t * 18.0 + localUv.x * 43.0 + localUv.y * 37.0);
    float edgeCrawl = cos(t * 9.0 + localUv.x * 17.0 - localUv.y * 29.0);
    float2 objectWarp = (edgeDir * edgePulse + edgeTangent * edgeCrawl * 0.45) * objectEdge * (0.0034 + MoonSugarTuning.x * 0.12) * i;
    float2 tremor = float2(sin(t * 13.0 + localUv.y * 21.0), cos(t * 11.0 + localUv.x * 17.0)) * 0.00125 * i;
    float2 tunnel = p * edge * (0.0020 + 0.0010 * pulse) * i;
    float3 sharp = tex2D(SceneSampler, uv + objectWarp + tremor - tunnel).rgb;
    float3 soft = tex2D(SceneSampler, uv + objectWarp * 0.35 + p * 0.006 * edge * i).rgb;
    float3 split = tex2D(SceneSampler, uv - objectWarp * 1.2 - tremor * 2.0 + p * MoonSugarTuning.z * 0.18 * i).rgb;
    float3 edgeEcho = tex2D(SceneSampler, uv - objectWarp * 1.8 + tremor * 0.5).rgb;
    float luma = MoonSugarLuma(sharp);
    float3 color = lerp(sharp, soft, edge * 0.24 * i);
    color = lerp(color, edgeEcho, objectEdge * (0.22 + pulse * 0.10) * i);
    color = lerp(color, float3(luma, luma, luma), 0.12 * i);
    color = (color - 0.5) * (1.0 + (0.42 + dose * 0.20) * i) + 0.5;
    color.r = lerp(color.r, split.b, 0.06 * i);
    color.b = lerp(color.b, split.r, 0.07 * i);
    color += float3(0.08, 0.10, 0.14) * (pulse + objectEdge * 0.55) * i;
    color *= 1.0 - edge * (0.28 + pulse * 0.08) * i;
    return float4(saturate(color), 1.0);
}

float4 VESMoonSugarPS(float2 uv : TEXCOORD0) : COLOR0
{
    return MoonSugarDefaultPS(uv);
}

float4 VESHeadWoundPS(float2 uv : TEXCOORD0) : COLOR0
{
    return HeadWoundPS(uv);
}

float4 VESBlindPS(float2 uv : TEXCOORD0) : COLOR0
{
    return BlindPS(uv);
}

float4 VESDimPS(float2 uv : TEXCOORD0) : COLOR0
{
    return DimPS(uv);
}

float4 VESOnFirePS(float2 uv : TEXCOORD0) : COLOR0
{
    return OnFirePS(uv);
}

float4 VESHeatShimmerPS(float2 uv : TEXCOORD0) : COLOR0
{
    return HeatShimmerPS(uv);
}

float4 VESDepthMaskDebugPS(float2 uv : TEXCOORD0) : COLOR0
{
    return DepthMaskDebugPS(uv);
}

float4 VESRainPS(float2 uv : TEXCOORD0) : COLOR0
{
    return RainPS(uv);
}

float4 VESFrostPS(float2 uv : TEXCOORD0) : COLOR0
{
    return FrostPS(uv);
}

float4 MoonSugarPS(float2 uv : TEXCOORD0) : COLOR0
{
    if (MoonSugarProfile.x > 8.5)
        return DepthMaskDebugPS(uv);
    if (MoonSugarProfile.x > 7.5)
        return FrostPS(uv);
    if (MoonSugarProfile.x > 6.5)
        return RainPS(uv);
    if (MoonSugarProfile.x > 5.5)
        return HeatShimmerPS(uv);
    if (MoonSugarProfile.x > 4.5)
        return OnFirePS(uv);
    if (MoonSugarProfile.x > 3.5)
        return DimPS(uv);
    if (MoonSugarProfile.x > 2.5)
        return BlindPS(uv);
    if (MoonSugarProfile.x > 0.5)
        return HeadWoundPS(uv);
    return MoonSugarDefaultPS(uv);
}
