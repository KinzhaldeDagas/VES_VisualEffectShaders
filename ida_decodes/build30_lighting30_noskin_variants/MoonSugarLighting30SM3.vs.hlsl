float4 MVP0 : register(c0);
float4 MVP1 : register(c1);
float4 MVP2 : register(c2);
float4 MVP3 : register(c3);
float4 FogParam : register(c15);
float4 FogColor : register(c16);
#ifdef USE_PROJ_SHADOW
float4 ShadowProj0 : register(c21);
float4 ShadowProj1 : register(c22);
float4 ShadowProj3 : register(c24);
float4 ShadowProjData : register(c25);
float4 ShadowProjTransform : register(c26);
float4 MoonSugar0 : register(c27);
float4 MoonSugar1 : register(c28);
#else
float4 MoonSugar0 : register(c26);
float4 MoonSugar1 : register(c27);
#endif
struct VSIn
{
    float4 position : POSITION0;
    float3 tangent : TANGENT0;
    float3 binormal : BINORMAL0;
    float3 normal : NORMAL0;
    float2 texcoord : TEXCOORD0;
#ifdef USE_VERTEX_COLOR
    float4 color : COLOR0;
#endif
};
struct VSOut
{
    float4 position : POSITION0;
    float2 texcoord : TEXCOORD0;
    float4 color : COLOR0;
    float3 tangent : TEXCOORD3;
    float3 binormal : TEXCOORD4;
    float3 normal : TEXCOORD5;
    float3 sourcePosition : TEXCOORD6;
#ifdef USE_PROJ_SHADOW
    float4 shadow : TEXCOORD1;
#endif
    float4 fog : TEXCOORD7;
};
float SmoothTri(float x)
{
    float y = abs(frac(x) * 2.0 - 1.0);
    y = y * y * (3.0 - 2.0 * y);
    return y * 2.0 - 1.0;
}
float3 SafeNormalize(float3 v)
{
    return v * rsqrt(max(dot(v, v), 0.000001));
}
VSOut MoonSugarVS(VSIn input)
{
    VSOut output;
    float3 basePos = input.position.xyz;
    float3 axisTangent = SafeNormalize(input.tangent);
    float3 axisBinormal = SafeNormalize(input.binormal);
    float3 axisNormal = SafeNormalize(input.normal);
    float time = MoonSugar0.x;
    float intensity = saturate(MoonSugar0.y);
    float amplitude = MoonSugar0.z * intensity;
    float speed = MoonSugar0.w;
    float normalAmp = MoonSugar1.x;
    float tangentAmp = MoonSugar1.y;
    float frequency = MoonSugar1.z;
    float phase = MoonSugar1.w;
    float waveA = SmoothTri(dot(basePos, float3(0.017, 0.011, 0.007)) * frequency + time * speed + phase);
    float waveB = SmoothTri(dot(basePos, float3(-0.009, 0.015, 0.013)) * frequency - time * speed * 0.63 + phase * 1.71);
    float3 displaced = basePos + axisNormal * (waveA * normalAmp * amplitude);
    displaced += axisTangent * (waveB * tangentAmp * amplitude);
    displaced += axisBinormal * (waveA * waveB * tangentAmp * amplitude * 0.35);
    float4 pos = float4(displaced, input.position.w);
    float4 clip = float4(dot(MVP0, pos), dot(MVP1, pos), dot(MVP2, pos), dot(MVP3, pos));
    float fogDistance = length(clip.xyz);
    float fogAmount = saturate((FogParam.x - fogDistance) / max(FogParam.y, 0.000001));
    float fogKeep = 1.0 - fogAmount;
    output.position = clip;
    output.texcoord = input.texcoord;
#ifdef USE_VERTEX_COLOR
    output.color = input.color;
#else
    output.color = 1.0;
#endif
    output.tangent = input.tangent;
    output.binormal = input.binormal;
    output.normal = input.normal;
    output.sourcePosition = displaced;
#ifdef USE_PROJ_SHADOW
    float shadowW = dot(ShadowProj3, pos);
    float3 shadowTransform = shadowW * ShadowProjTransform.xyw;
    float2 shadowClip = float2(dot(ShadowProj0, pos), dot(ShadowProj1, pos));
    float2 shadowProjected = shadowClip - ShadowProjData.xy;
    float invShadowW = rcp(max(abs(shadowTransform.z), 0.000001)) * (shadowTransform.z < 0.0 ? -1.0 : 1.0);
    float invShadowDataW = rcp(max(abs(ShadowProjData.w), 0.000001)) * (ShadowProjData.w < 0.0 ? -1.0 : 1.0);
    output.shadow.xy = (shadowTransform.xy + shadowClip) * invShadowW;
    output.shadow.z = shadowProjected.x * invShadowDataW;
    output.shadow.w = 1.0 - shadowProjected.y * invShadowDataW;
#endif
    output.fog.xyz = FogColor.xyz;
    output.fog.w = fogKeep * FogParam.z;
    return output;
}
