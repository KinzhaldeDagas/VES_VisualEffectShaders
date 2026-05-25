float4 MVP0 : register(c0);
float4 MVP1 : register(c1);
float4 MVP2 : register(c2);
float4 MVP3 : register(c3);
float4 MoonSugar0 : register(c26);
float4 MoonSugar1 : register(c27);
float4 DecalFade0 : register(c32);
float4 DecalFade1 : register(c33);
float4 DecalFade2 : register(c34);
float4 DecalFade3 : register(c35);
float4 DecalFade4 : register(c36);
float4 DecalFade5 : register(c37);
float4 DecalFade6 : register(c38);
float4 DecalFade7 : register(c39);
float4 DecalProj0_0 : register(c40);
float4 DecalProj0_1 : register(c41);
float4 DecalProj0_2 : register(c42);
float4 DecalProj1_0 : register(c44);
float4 DecalProj1_1 : register(c45);
float4 DecalProj1_2 : register(c46);
float4 DecalProj2_0 : register(c48);
float4 DecalProj2_1 : register(c49);
float4 DecalProj2_2 : register(c50);
float4 DecalProj3_0 : register(c52);
float4 DecalProj3_1 : register(c53);
float4 DecalProj3_2 : register(c54);
float4 DecalProj4_0 : register(c56);
float4 DecalProj4_1 : register(c57);
float4 DecalProj4_2 : register(c58);
float4 DecalProj5_0 : register(c60);
float4 DecalProj5_1 : register(c61);
float4 DecalProj5_2 : register(c62);
float4 DecalProj6_0 : register(c64);
float4 DecalProj6_1 : register(c65);
float4 DecalProj6_2 : register(c66);
float4 DecalProj7_0 : register(c68);
float4 DecalProj7_1 : register(c69);
float4 DecalProj7_2 : register(c70);
struct VSIn
{
    float4 position : POSITION0;
    float3 normal : NORMAL0;
};
struct VSOut
{
    float4 position : POSITION0;
    float3 decal0 : TEXCOORD0;
    float3 decal1 : TEXCOORD1;
    float3 decal2 : TEXCOORD2;
    float3 decal3 : TEXCOORD3;
    float3 decal4 : TEXCOORD4;
    float3 decal5 : TEXCOORD5;
    float3 decal6 : TEXCOORD6;
    float3 decal7 : TEXCOORD7;
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
float3 BuildDecalTangent(float3 normal)
{
    float useZ = abs(normal.z) < 0.75 ? 1.0 : 0.0;
    float3 up = lerp(float3(0.0, 1.0, 0.0), float3(0.0, 0.0, 1.0), useZ);
    return SafeNormalize(cross(up, normal));
}
float3 ApplyMoonSugar(float3 basePos, float3 normal)
{
    float3 n = SafeNormalize(normal);
    float3 tangent = BuildDecalTangent(n);
    float3 binormal = SafeNormalize(cross(n, tangent));
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
    float3 displaced = basePos + n * (waveA * normalAmp * amplitude);
    displaced += tangent * (waveB * tangentAmp * amplitude);
    displaced += binormal * (waveA * waveB * tangentAmp * amplitude * 0.35);
    return displaced;
}
float3 BuildDecal(float3 sourcePosition, float3 nativeNormal, float4 row0, float4 row1, float4 row2, float fade)
{
    float3 decalPosition = sourcePosition + float3(row0.w, row1.w, row2.w);
    float2 projected = float2(dot(row0.xyz, decalPosition), dot(row1.xyz, decalPosition)) * 0.0125000002 + 0.5;
    float depthFade = 1.0 - abs(dot(row2.xyz, decalPosition)) * 0.00390625;
    float normalFacing = max(dot(nativeNormal, row2.xyz), 0.0);
    float normalFade = pow(1.0 - normalFacing, 10.0) * fade;
    return float3(projected, depthFade * normalFade);
}
VSOut MoonSugarVS(VSIn input)
{
    VSOut output;
    float3 displaced = ApplyMoonSugar(input.position.xyz, input.normal);
    float4 pos = float4(displaced, input.position.w);
    output.position = float4(dot(MVP0, pos), dot(MVP1, pos), dot(MVP2, pos), dot(MVP3, pos));
    output.decal0 = BuildDecal(displaced, input.normal, DecalProj0_0, DecalProj0_1, DecalProj0_2, DecalFade0.x);
    output.decal1 = BuildDecal(displaced, input.normal, DecalProj1_0, DecalProj1_1, DecalProj1_2, DecalFade1.x);
    output.decal2 = BuildDecal(displaced, input.normal, DecalProj2_0, DecalProj2_1, DecalProj2_2, DecalFade2.x);
    output.decal3 = BuildDecal(displaced, input.normal, DecalProj3_0, DecalProj3_1, DecalProj3_2, DecalFade3.x);
    output.decal4 = BuildDecal(displaced, input.normal, DecalProj4_0, DecalProj4_1, DecalProj4_2, DecalFade4.x);
    output.decal5 = BuildDecal(displaced, input.normal, DecalProj5_0, DecalProj5_1, DecalProj5_2, DecalFade5.x);
    output.decal6 = BuildDecal(displaced, input.normal, DecalProj6_0, DecalProj6_1, DecalProj6_2, DecalFade6.x);
    output.decal7 = BuildDecal(displaced, input.normal, DecalProj7_0, DecalProj7_1, DecalProj7_2, DecalFade7.x);
    return output;
}
