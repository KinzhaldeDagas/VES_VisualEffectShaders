float4 MVP0 : register(c0);
float4 MVP1 : register(c1);
float4 MVP2 : register(c2);
float4 MVP3 : register(c3);
float4 ObjToCube0 : register(c10);
float4 ObjToCube1 : register(c11);
float4 ObjToCube2 : register(c12);
float4 EyePosition : register(c14);
float4 MoonSugar0 : register(c26);
float4 MoonSugar1 : register(c27);
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
    float3 displaced = basePos + SafeNormalize(normal) * (waveA * normalAmp * amplitude);
    displaced += SafeNormalize(tangent) * (waveB * tangentAmp * amplitude);
    displaced += SafeNormalize(binormal) * (waveA * waveB * tangentAmp * amplitude * 0.35);
    return displaced;
}
VSOut MoonSugarVS(VSIn input)
{
    VSOut output;
    float3 displaced = ApplyMoonSugar(input.position.xyz, input.tangent, input.binormal, input.normal);
    float4 pos = float4(displaced, input.position.w);
    output.position = float4(dot(MVP0, pos), dot(MVP1, pos), dot(MVP2, pos), dot(MVP3, pos));
    float3 cubePos = float3(dot(ObjToCube0, pos), dot(ObjToCube1, pos), dot(ObjToCube2, pos));
    float3 viewCube = EyePosition.xyz - cubePos;
    output.texcoord = input.texcoord;
    output.cubeRow0 = float4(dot(input.tangent, ObjToCube0.xyz), dot(input.binormal, ObjToCube0.xyz), dot(input.normal, ObjToCube0.xyz), viewCube.x);
    output.cubeRow1 = float4(dot(input.tangent, ObjToCube1.xyz), dot(input.binormal, ObjToCube1.xyz), dot(input.normal, ObjToCube1.xyz), viewCube.y);
    output.cubeRow2 = float4(dot(input.tangent, ObjToCube2.xyz), dot(input.binormal, ObjToCube2.xyz), dot(input.normal, ObjToCube2.xyz), viewCube.z);
#ifdef USE_VERTEX_COLOR
    output.color = input.color.xyz;
#else
    output.color = 1.0;
#endif
    return output;
}
