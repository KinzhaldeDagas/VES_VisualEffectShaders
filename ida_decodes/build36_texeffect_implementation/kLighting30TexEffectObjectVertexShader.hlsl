float4 MVP0 : register(c0);
float4 MVP1 : register(c1);
float4 MVP2 : register(c2);
float4 MVP3 : register(c3);
float4 EyePosition : register(c8);
float4 UOffset : register(c9);
float4 VOffset : register(c10);
float4 FogParam : register(c12);
float4 FogColor : register(c13);
float4 MoonSugar0 : register(c26);
float4 MoonSugar1 : register(c27);
struct VSIn
{
    float4 position : POSITION0;
    float3 tangent : TANGENT0;
    float3 binormal : BINORMAL0;
    float3 normal : NORMAL0;
    float2 texcoord : TEXCOORD0;
};
struct VSOut
{
    float4 position : POSITION0;
    float2 texcoord : TEXCOORD0;
    float2 sourceTexcoord : TEXCOORD1;
    float3 viewVector : TEXCOORD3;
    float4 fogColor : COLOR1;
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
float ApproxTexEffectAngle(float2 xy)
{
    float ax = abs(xy.x);
    float ay = abs(xy.y);
    float minorOverMajor = min(ax, ay) / max(max(ax, ay), 0.000001);
    float squared = minorOverMajor * minorOverMajor;
    float polynomial = (((0.0208350997 * squared - 0.0851330012) * squared + 0.180141002) * squared - 0.330299497) * squared + 0.999866009;
    float baseAngle = minorOverMajor * polynomial;
    float angle = baseAngle + ((ay < ax) ? (1.57079637 - 2.0 * baseAngle) : 0.0);
    angle += (xy.y < -xy.y) ? -3.14159274 : 0.0;
    float oppositeSigns = ((min(xy.y, xy.x) < -min(xy.y, xy.x)) && (max(xy.y, xy.x) >= -max(xy.y, xy.x))) ? 1.0 : 0.0;
    return angle + oppositeSigns * (-2.0 * angle);
}
float2 BuildSourceTexcoord(float3 sourcePosition)
{
    return float2(ApproxTexEffectAngle(sourcePosition.xy) * 0.318471342 + VOffset.x, sourcePosition.z * 0.0250000004 + UOffset.x);
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
float3 BuildViewVector(float3 displaced, float3 tangent, float3 binormal, float3 normal)
{
    float3 view = EyePosition.xyz - displaced;
    float3 orientedView = (dot(normal, view) < 1.0) ? -view : view;
    return SafeNormalize(float3(dot(tangent, orientedView), dot(binormal, orientedView), dot(normal, orientedView)));
}
VSOut MoonSugarVS(VSIn input)
{
    VSOut output;
    float3 displaced = ApplyMoonSugar(input.position.xyz, input.tangent, input.binormal, input.normal);
    float4 pos = float4(displaced, input.position.w);
    float4 clip = float4(dot(MVP0, pos), dot(MVP1, pos), dot(MVP2, pos), dot(MVP3, pos));
    float fogAmount = saturate((FogParam.x - length(clip.xyz)) / max(FogParam.y, 0.000001));
    output.position = clip;
    output.texcoord = input.texcoord;
    output.sourceTexcoord = BuildSourceTexcoord(displaced);
    output.viewVector = BuildViewVector(displaced, input.tangent, input.binormal, input.normal);
    output.fogColor.xyz = FogColor.xyz;
    output.fogColor.w = (1.0 - fogAmount) * ((0.0 < FogParam.z) ? 1.0 : 0.0);
    return output;
}
