float4 MVP0 : register(c0);
float4 MVP1 : register(c1);
float4 MVP2 : register(c2);
float4 MVP3 : register(c3);
float4 ObjToCube0 : register(c10);
float4 ObjToCube1 : register(c11);
float4 ObjToCube2 : register(c12);
float4 EyePosition : register(c14);
float4 BoundWorldCenter : register(c20);
float4 MoonSugar0 : register(c26);
float4 MoonSugar1 : register(c27);
struct VSIn
{
    float4 position : POSITION0;
    float2 texcoord : TEXCOORD0;
};
struct VSOut
{
    float4 position : POSITION0;
    float2 texcoord : TEXCOORD0;
    float4 cubeLookup : TEXCOORD1;
    float3 viewVector : TEXCOORD2;
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
VSOut MoonSugarVS(VSIn input)
{
    VSOut output;
    float3 basePos = input.position.xyz;
    float time = MoonSugar0.x;
    float intensity = saturate(MoonSugar0.y);
    float amplitude = MoonSugar0.z * intensity;
    float speed = MoonSugar0.w;
    float normalAmp = MoonSugar1.x;
    float frequency = MoonSugar1.z;
    float phase = MoonSugar1.w;
    float wave = SmoothTri(dot(basePos, float3(0.017, 0.011, 0.007)) * frequency + time * speed + phase);
    float3 displaced = basePos + SafeNormalize(basePos) * (wave * normalAmp * amplitude);
    float4 pos = float4(displaced, input.position.w);
    output.position = float4(dot(MVP0, pos), dot(MVP1, pos), dot(MVP2, pos), dot(MVP3, pos));
    float3 cubePos = float3(dot(ObjToCube0, pos), dot(ObjToCube1, pos), dot(ObjToCube2, pos));
    float3 fromCenter = cubePos - BoundWorldCenter.xyz;
    float3 viewVector = EyePosition.xyz - cubePos;
    float3 centerDir = SafeNormalize(fromCenter);
    float3 viewDir = SafeNormalize(viewVector);
    float rim = saturate((dot(centerDir, viewDir) - 0.8) * 6.66666651);
    float rimSmooth = rim * rim * (3.0 - 2.0 * rim);
    output.texcoord = input.texcoord;
    output.cubeLookup.xyz = centerDir * 0.5 + 0.5;
    output.cubeLookup.w = rimSmooth;
    output.viewVector = viewVector;
    output.color = 1.0;
    return output;
}
