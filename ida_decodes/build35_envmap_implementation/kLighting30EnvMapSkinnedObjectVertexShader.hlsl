float4 SkinMVP0 : register(c1);
float4 SkinMVP1 : register(c2);
float4 SkinMVP2 : register(c3);
float4 SkinMVP3 : register(c4);
float4 EyePosition : register(c14);
float4 MoonSugar0 : register(c24);
float4 MoonSugar1 : register(c25);
float4 SkinToCube0 : register(c27);
float4 SkinToCube1 : register(c28);
float4 SkinToCube2 : register(c29);
float4 Bones[54] : register(c31);
struct VSIn
{
    float4 position : POSITION0;
    float2 texcoord : TEXCOORD0;
    float3 normal : NORMAL0;
    float3 tangent : TANGENT0;
    float3 binormal : BINORMAL0;
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
    float4 cubeRow0 : TEXCOORD1;
    float4 cubeRow1 : TEXCOORD2;
    float4 cubeRow2 : TEXCOORD3;
    float3 color : COLOR0;
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
float3 ApplyMoonSugar(float3 basePos, float3 tangent, float3 binormal, float3 normal)
{
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
    float3 displaced = basePos + normal * (waveA * normalAmp * amplitude);
    displaced += tangent * (waveB * tangentAmp * amplitude);
    displaced += binormal * (waveA * waveB * tangentAmp * amplitude * 0.35);
    return displaced;
}
VSOut MoonSugarVS(VSIn input)
{
    VSOut output;
    float4 indices = floor(input.blendIndices.zyxw * 765.01001);
    float4 weights = float4(input.blendWeights.xyz, 1.0 - dot(input.blendWeights.xyz, 1.0));
    float3 skinnedPos = BlendPosition(input.position.xyz, indices, weights);
    float3 skinnedTangent = SafeNormalize(BlendVector(input.tangent, indices, weights));
    float3 skinnedBinormal = SafeNormalize(BlendVector(input.binormal, indices, weights));
    float3 skinnedNormal = SafeNormalize(BlendVector(input.normal, indices, weights));
    float3 displaced = ApplyMoonSugar(skinnedPos, skinnedTangent, skinnedBinormal, skinnedNormal);
    float4 pos = float4(displaced, 1.0);
    output.position = float4(dot(SkinMVP0, pos), dot(SkinMVP1, pos), dot(SkinMVP2, pos), dot(SkinMVP3, pos));
    float3 cubePos = float3(dot(SkinToCube0, pos), dot(SkinToCube1, pos), dot(SkinToCube2, pos));
    float3 viewCube = EyePosition.xyz - cubePos;
    output.texcoord = input.texcoord;
    output.cubeRow0 = float4(dot(skinnedTangent, SkinToCube0.xyz), dot(skinnedBinormal, SkinToCube0.xyz), dot(skinnedNormal, SkinToCube0.xyz), viewCube.x);
    output.cubeRow1 = float4(dot(skinnedTangent, SkinToCube1.xyz), dot(skinnedBinormal, SkinToCube1.xyz), dot(skinnedNormal, SkinToCube1.xyz), viewCube.y);
    output.cubeRow2 = float4(dot(skinnedTangent, SkinToCube2.xyz), dot(skinnedBinormal, SkinToCube2.xyz), dot(skinnedNormal, SkinToCube2.xyz), viewCube.z);
#ifdef USE_VERTEX_COLOR
    output.color = input.color.xyz;
#else
    output.color = 1.0;
#endif
    return output;
}
