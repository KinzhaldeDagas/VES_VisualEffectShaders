float4 SkinMVP0 : register(c1);
float4 SkinMVP1 : register(c2);
float4 SkinMVP2 : register(c3);
float4 SkinMVP3 : register(c4);
float4 FogParam : register(c15);
float4 FogColor : register(c16);
#ifdef USE_PROJ_SHADOW
float4 ShadowProj0 : register(c21);
float4 ShadowProj1 : register(c22);
float4 ShadowProj3 : register(c24);
float4 ShadowProjData : register(c25);
float4 ShadowProjTransform : register(c26);
#endif
float4 MoonSugar0 : register(c27);
float4 MoonSugar1 : register(c28);
float4 Bones[54] : register(c31);
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
    float4 blendWeights : BLENDWEIGHT0;
    float4 blendIndices : BLENDINDICES0;
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
float3 SkinVector(float3 value, float index)
{
    int row = (int)index;
    return float3(dot(Bones[row].xyz, value), dot(Bones[row + 1].xyz, value), dot(Bones[row + 2].xyz, value));
}
float3 SkinPosition(float3 value, float index)
{
    int row = (int)index;
    float4 pos = float4(value, 1.0);
    return float3(dot(Bones[row], pos), dot(Bones[row + 1], pos), dot(Bones[row + 2], pos));
}
float3 BlendVector(float3 value, float4 indices, float4 weights)
{
    float3 blended = SkinVector(value, indices.y) * weights.y;
    blended += SkinVector(value, indices.x) * weights.x;
    blended += SkinVector(value, indices.z) * weights.z;
    blended += SkinVector(value, indices.w) * weights.w;
    return blended;
}
float3 BlendPosition(float3 value, float4 indices, float4 weights)
{
    float3 blended = SkinPosition(value, indices.y) * weights.y;
    blended += SkinPosition(value, indices.x) * weights.x;
    blended += SkinPosition(value, indices.z) * weights.z;
    blended += SkinPosition(value, indices.w) * weights.w;
    return blended;
}
VSOut MoonSugarVS(VSIn input)
{
    VSOut output;
    float4 indices = floor(input.blendIndices.zyxw * 765.01001);
    float4 weights = float4(input.blendWeights.xyz, 1.0 - dot(input.blendWeights.xyz, 1.0));
    float3 skinnedNormal = SafeNormalize(BlendVector(input.normal, indices, weights));
    float3 skinnedTangent = SafeNormalize(BlendVector(input.tangent, indices, weights));
    float3 skinnedBinormal = SafeNormalize(BlendVector(input.binormal, indices, weights));
    float3 basePos = BlendPosition(input.position.xyz, indices, weights);
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
    float3 displaced = basePos + skinnedNormal * (waveA * normalAmp * amplitude);
    displaced += skinnedTangent * (waveB * tangentAmp * amplitude);
    displaced += skinnedBinormal * (waveA * waveB * tangentAmp * amplitude * 0.35);
    float4 pos = float4(displaced, 1.0);
    float4 clip = float4(dot(SkinMVP0, pos), dot(SkinMVP1, pos), dot(SkinMVP2, pos), dot(SkinMVP3, pos));
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
    output.tangent = skinnedTangent;
    output.binormal = skinnedBinormal;
    output.normal = skinnedNormal;
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
