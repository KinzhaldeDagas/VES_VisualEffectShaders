// User Defines
#include "config.h"

// OBSE
#include "obse/CommandTable.h"
#include "obse/GameAPI.h"
#include "obse/GameForms.h"
#include "obse/NiRenderer.h"
#include "obse/PluginAPI.h"
#include "obse_common/SafeWrite.h"

// Windows
#include <d3dx9.h>
#include <shlobj.h>
#include <windows.h>

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "MoonSugarFallbackPixelShaderBytecode.h"
#include "MoonSugarVertexShaderBytecode.h"

// ================================
// Handles
// ================================

PluginHandle g_pluginHandle = kPluginHandle_Invalid;

extern CommandInfo kCommandInfo_VESDistortion;
extern CommandInfo kCommandInfo_VESStop;
extern CommandInfo kCommandInfo_VESGetRemaining;
extern CommandInfo kCommandInfo_VESGetIntensity;
extern CommandInfo kCommandInfo_VESReloadSettings;
extern CommandInfo kCommandInfo_VESDumpShaderRenderer;
extern CommandInfo kCommandInfo_VESMoonSugar25;
extern CommandInfo kCommandInfo_VESMoonSugar50;
extern CommandInfo kCommandInfo_VESMoonSugar75;
extern CommandInfo kCommandInfo_VESHeadWound25;
extern CommandInfo kCommandInfo_VESHeadWound50;
extern CommandInfo kCommandInfo_VESHeadWound75;
extern CommandInfo kCommandInfo_VESBlind25;
extern CommandInfo kCommandInfo_VESBlind50;
extern CommandInfo kCommandInfo_VESBlind75;
extern CommandInfo kCommandInfo_VESBlind100;
extern CommandInfo kCommandInfo_VESDim50;
extern CommandInfo kCommandInfo_VESDim100;
extern CommandInfo kCommandInfo_VESDimWhiteInverted;
extern CommandInfo kCommandInfo_VESDimPurple;
extern CommandInfo kCommandInfo_VESDimDarkRed;
extern CommandInfo kCommandInfo_VESOnFire25;
extern CommandInfo kCommandInfo_VESOnFire50;
extern CommandInfo kCommandInfo_VESOnFire75;
extern CommandInfo kCommandInfo_VESOnFire100;
extern CommandInfo kCommandInfo_VESHeatShimmer50;
extern CommandInfo kCommandInfo_VESHeatShimmer100;
extern CommandInfo kCommandInfo_VESDepthMaskDebug;
extern CommandInfo kCommandInfo_VESRain50;
extern CommandInfo kCommandInfo_VESRain75;
extern CommandInfo kCommandInfo_VESRain100;
extern CommandInfo kCommandInfo_VESFrost50;
extern CommandInfo kCommandInfo_VESFrost75;
extern CommandInfo kCommandInfo_VESFrost100;

void __stdcall RenderVESDistortionFrame(NiDX9Renderer* renderer);
void ProcessImageSpaceShaderHook();
void __cdecl BeforeProcessImageSpaceShaderHook(NiDX9Renderer* renderer, void* sourceTexture, void* destinationTexture);
void __cdecl AfterProcessImageSpaceShaderHook(NiDX9Renderer* renderer, void* sourceTexture, void* destinationTexture);
void RenderTriGeometrySetupHook();
void RenderTriGeometryPostSetupHook();
void RenderTriGeometrySkinnedPostSetupHook();
void __cdecl RenderWorldCameraSwayHook(void* camera, void* sceneGraph, void* cullingProcess, void* visibleGeo);

namespace
{
	const char* kShaderDirectory = ".\\Data\\Shaders\\VES\\";
	const char* kDefaultShaderName = "VESDistortion";
	const char* kDefaultShaderDisplayName = "VES Distortion";
	const char* kMoonSugar25ShaderName = "MoonSugar25";
	const char* kMoonSugar25DisplayName = "Moon Sugar 25";
	const char* kMoonSugar50ShaderName = "MoonSugar50";
	const char* kMoonSugar50DisplayName = "Moon Sugar 50";
	const char* kMoonSugar75ShaderName = "MoonSugar75";
	const char* kMoonSugar75DisplayName = "Moon Sugar 75";
	const char* kHeadWound25ShaderName = "HeadWound25";
	const char* kHeadWound25DisplayName = "Head Wound 25";
	const char* kHeadWound50ShaderName = "HeadWound50";
	const char* kHeadWound50DisplayName = "Head Wound 50";
	const char* kHeadWound75ShaderName = "HeadWound75";
	const char* kHeadWound75DisplayName = "Head Wound 75";
	const char* kBlind25ShaderName = "Blind25";
	const char* kBlind25DisplayName = "Blind 25";
	const char* kBlind50ShaderName = "Blind50";
	const char* kBlind50DisplayName = "Blind 50";
	const char* kBlind75ShaderName = "Blind75";
	const char* kBlind75DisplayName = "Blind 75";
	const char* kBlind100ShaderName = "Blind100";
	const char* kBlind100DisplayName = "Blind 100";
	const char* kDim50ShaderName = "Dim50";
	const char* kDim50DisplayName = "Dim 50";
	const char* kDim100ShaderName = "Dim100";
	const char* kDim100DisplayName = "Dim 100";
	const char* kDimWhiteInvertedShaderName = "DimWhiteInverted";
	const char* kDimWhiteInvertedDisplayName = "Dim White/Inverted";
	const char* kDimPurpleShaderName = "DimPurple";
	const char* kDimPurpleDisplayName = "Dim Purple";
	const char* kDimDarkRedShaderName = "DimDarkRed";
	const char* kDimDarkRedDisplayName = "Dim Dark Red";
	const char* kOnFire25ShaderName = "VESOnFire25";
	const char* kOnFire25DisplayName = "On Fire 25";
	const char* kOnFire50ShaderName = "VESOnFire50";
	const char* kOnFire50DisplayName = "On Fire 50";
	const char* kOnFire75ShaderName = "VESOnFire75";
	const char* kOnFire75DisplayName = "On Fire 75";
	const char* kOnFire100ShaderName = "VESOnFire100";
	const char* kOnFire100DisplayName = "On Fire 100";
	const char* kHeatShimmer50ShaderName = "HeatShimmer50";
	const char* kHeatShimmer50DisplayName = "Heat Shimmer 50";
	const char* kHeatShimmer100ShaderName = "HeatShimmer100";
	const char* kHeatShimmer100DisplayName = "Heat Shimmer 100";
	const char* kDepthMaskDebugShaderName = "VESDepthMaskDebug";
	const char* kDepthMaskDebugDisplayName = "Depth Mask Debug";
	const char* kRain50ShaderName = "VESRain50";
	const char* kRain50DisplayName = "Rain 50";
	const char* kRain75ShaderName = "VESRain75";
	const char* kRain75DisplayName = "Rain 75";
	const char* kRain100ShaderName = "VESRain100";
	const char* kRain100DisplayName = "Rain 100";
	const char* kFrost50ShaderName = "VESFrost50";
	const char* kFrost50DisplayName = "Frost 50";
	const char* kFrost75ShaderName = "VESFrost75";
	const char* kFrost75DisplayName = "Frost 75";
	const char* kFrost100ShaderName = "VESFrost100";
	const char* kFrost100DisplayName = "Frost 100";
	const char* kShaderProfile = "ps_3_0";
	const char* kObjectVertexShaderProfile = "vs_2_0";
	const char* kLighting30ObjectVertexShaderProfile = "vs_3_0";

	const UInt32 kPlayerConsumeProcessEffectsCall = 0x00666639;
	const UInt32 kMagicTargetProcessEffectsFromItem = 0x006A23B0;
	const UInt32 kNiRendererRenderProcessImageSpaceShaderCall = 0x0040CF6E;
	const UInt32 kProcessImageSpaceShader = 0x007B48E0;
	const UInt32 kNiRendererRenderWorldCallA = 0x0040CCD3;
	const UInt32 kNiRendererRenderWorldCallB = 0x0040CE48;
	const UInt32 kRenderWorldSceneGraph = 0x0070C0B0;
	const UInt32 kSetCameraViewProj = 0x00701970;
	const UInt32 kRenderTriGeometriesNonSkinnedCall = 0x007694D7;
	const UInt32 kRenderTriGeometrySetup = 0x007672F0;
	const UInt32 kRenderTriGeometryPostSetupPatch = 0x00767410;
	const UInt32 kRenderTriGeometrySkinnedPostSetupPatch = 0x007676F9;
	const UInt32 kLighting30VertexProgramTableAddress = 0x00B47288;
	const UInt32 kLighting30VertexProgramCount = 0x20;
	const UInt32 kLighting30PixelProgramTableAddress = 0x00B46ED8;
	const UInt32 kLighting30PixelProgramCount = 0x27;
	const UInt32 kLighting30LowPixelProgramTableAddress = 0x00B46C20;
	const UInt32 kLighting30LowPixelProgramCount = 0x14;
	const UInt32 kLighting30PassTableAddress = 0x00B473D0;
	const UInt32 kLighting30PassCount = 0x36;
	const UInt32 kParallaxPassTableAddress = 0x00B47620;
	const UInt32 kParallaxPassCount = 0x3C;
	const UInt32 kSkinPassTableAddress = 0x00B47718;
	const UInt32 kSkinPassCount = 0x14;
	const UInt32 kParallaxPass0VertexShaderObjectOffset = 0xDC;
	const UInt32 kParallaxPass0PixelShaderObjectOffset = 0x15C;
	const UInt32 kSkinPass0VertexShaderObjectOffset = 0xBC;
	const UInt32 kSkinPass0PixelShaderObjectOffset = 0xFC;
	const UInt32 kNiD3DShaderCurrentPassIndexOffset = 0x34;
	const UInt32 kNiD3DShaderPassCountOffset = 0x38;
	const UInt32 kNiD3DShaderCurrentPassOffset = 0x3C;
	const UInt32 kNiD3DPassPixelShaderOffset = 0x44;
	const UInt32 kNiD3DPassVertexShaderOffset = 0x58;
	const UInt32 kObjectVertexUnknownPassSlots = 8;
	const UInt32 kObjectVertexPassSampleSlots = 12;
	const UInt32 kDefaultMoonSugarLocalFormID = 0x000A0028;
	const UInt32 kDefaultDurationMs = 45000;
	const UInt32 kDefaultMaxDurationMs = 180000;
	const UInt32 kHeadWoundSmallDurationMs = 22000;
	const UInt32 kHeadWoundBigDurationMs = 38000;
	const UInt32 kBlindDurationMs = 45000;
	const UInt32 kDepthCaptureMaxAgeMs = 50;
	const UInt32 kMagicItemOffsetInObject = 0x24;
	const UInt32 kEngineMagicTypeIngredient = 8;
	const UInt32 kOpcodeBase = 0x2000;
	const UInt32 kRenderModeNormal = 0;
	const UInt32 kRenderModeAddress = 0x00B42EAC;
	const UInt32 kRenderTargetStackDepthAddress = 0x00B45D74;
	const UInt32 kNiScreenElementsRTTI = 0x00B3FAA8;
	const UInt32 kRendererAddress = 0x00B3F928;
	const UInt32 kWorldSceneGraphAddress = 0x00B333CC;
	const UInt32 kSceneGraphCameraOffset = 0xDC;
	const UInt32 kSceneGraphCullingProcessOffset = 0xE4;
	const UInt32 kNiCullingProcessVisibleGeoOffset = 0x08;
	const UInt32 kCameraWorldTransformOffset = 0x64;

	const UInt8 kExpectedPlayerConsumeCallBytes[5] = { 0xE8, 0x72, 0xBD, 0x03, 0x00 };
	const UInt8 kExpectedProcessImageSpaceShaderCallBytes[5] = { 0xE8, 0x6D, 0x79, 0x3A, 0x00 };
	const UInt8 kExpectedRenderTriGeometrySetupCallBytes[5] = { 0xE8, 0x14, 0xDE, 0xFF, 0xFF };
	const UInt8 kExpectedRenderTriGeometryPostSetupBytes[5] = { 0x33, 0xC0, 0x39, 0x46, 0x30 };
	const UInt8 kExpectedRenderTriGeometrySkinnedPostSetupBytes[5] = { 0x33, 0xC0, 0x39, 0x47, 0x44 };
	const UInt8 kExpectedRenderWorldCallABytes[8] = { 0xE8, 0xD8, 0xF3, 0x2F, 0x00, 0x83, 0xC4, 0x10 };
	const UInt8 kExpectedRenderWorldCallBBytes[8] = { 0xE8, 0x63, 0xF2, 0x2F, 0x00, 0x83, 0xC4, 0x10 };

	const char* kLighting30VertexProgramLabels[kLighting30VertexProgramCount] =
	{
		"SM3000 Lighting",
		"SM3001 Lighting SKIN",
		"SM3002 Lighting VC",
		"SM3003 Lighting SKIN VC",
		"SM3004 Lighting PROJSHADOW",
		"SM3005 Lighting SKIN PROJSHADOW",
		"SM3006 Lighting VC PROJSHADOW",
		"SM3007 Lighting SKIN VC PROJSHADOW",
		"SM3008 EnvMap",
		"SM3009 EnvMap VC",
		"SM3010 EnvMap SKIN",
		"SM3011 EnvMap SKIN VC",
		"SM3012 EnvMap special",
		"SM3013 SimpleShadow",
		"SM3014 SimpleShadow VC",
		"SM3015 SimpleShadow SKIN",
		"SM3016 SimpleShadow SKIN VC",
		"SM3017 Decal MAXDECALS8",
		"SM3018 DepthMap",
		"SM3019 DepthMap SKIN",
		"SM3020 RenderNormals",
		"SM3021 RenderNormals SKIN",
		"SM3022 RenderNormals FIRE",
		"SM3023 RenderNormals CLEAR",
		"SM3024 RenderNormals CLEAR SKIN",
		"SM3025 LocalMap",
		"SM3026 LocalMap SKIN",
		"SM3027 LocalMap CLEAR",
		"SM3028 TexEffect",
		"SM3029 TexEffect SKIN",
		"SM3030 ZOnly",
		"SM3031 ZOnly SKIN"
	};

	const char* kLighting30PixelProgramLabels[kLighting30PixelProgramCount] =
	{
		"SM3000 Lighting MAXLIGHTS9",
		"SM3001 Lighting MAXLIGHTS8 SPECULAR",
		"SM3002 Lighting MAXLIGHTS8 HAIR",
		"SM3003 Lighting MAXLIGHTS7 HAIR SPECULAR",
		"SM3004 Lighting MAXLIGHTS8 PARALLAX",
		"SM3005 Lighting MAXLIGHTS8 PARALLAX SPECULAR",
		"SM3006 Lighting MAXLIGHTS8 FACEGENBLEND",
		"SM3007 Lighting MAXLIGHTS8 FACEGENBLEND SPECULAR",
		"SM3008 Lighting MAXLIGHTS8 GLOW",
		"SM3009 Lighting MAXLIGHTS8 GLOW SPECULAR",
		"SM3010 Lighting MAXLIGHTS8 PROJSHADOW",
		"SM3011 Lighting MAXLIGHTS8 SPECULAR PROJSHADOW",
		"SM3012 Lighting MAXLIGHTS8 HAIR PROJSHADOW",
		"SM3013 Lighting MAXLIGHTS7 HAIR SPECULAR PROJSHADOW",
		"SM3014 Lighting MAXLIGHTS8 PARALLAX PROJSHADOW",
		"SM3015 Lighting MAXLIGHTS8 PARALLAX SPECULAR PROJSHADOW",
		"SM3016 Lighting MAXLIGHTS8 FACEGENBLEND PROJSHADOW",
		"SM3017 Lighting MAXLIGHTS8 FACEGENBLEND SPECULAR PROJSHADOW",
		"SM3018 Lighting MAXLIGHTS8 GLOW PROJSHADOW",
		"SM3019 Lighting MAXLIGHTS8 GLOW SPECULAR PROJSHADOW",
		"SM3020 EnvMap",
		"SM3021 EnvMap WINDOW",
		"SM3022 EnvMap special",
		"SM3023 SimpleShadow SOFTSHADOW4 DEPTHBIAS-2",
		"SM3024 Decal MAXDECALS8",
		"SM3025 Decal MAXDECALS8 ALPHA",
		"SM3026 DepthMap",
		"SM3027 DepthMap",
		"SM3028 RenderNormals",
		"SM3029 RenderNormals",
		"SM3030 RenderNormals FIRE",
		"SM3031 RenderNormals CLEAR",
		"SM3032 RenderNormals CLEAR",
		"SM3033 LocalMap",
		"SM3034 LocalMap CLEAR",
		"SM3035 TexEffect HQ",
		"SM3036 TexEffect HQ",
		"SM3037 ZOnly",
		"SM3038 ZOnly"
	};

	const char* kLighting30LowPixelProgramLabels[kLighting30LowPixelProgramCount] =
	{
		"SM3LL000 Lighting MAXLIGHTS9",
		"SM3LL001 Lighting MAXLIGHTS8 SPECULAR",
		"SM3LL002 Lighting MAXLIGHTS8 HAIR",
		"SM3LL003 Lighting MAXLIGHTS7 HAIR SPECULAR",
		"SM3LL004 Lighting MAXLIGHTS8 PARALLAX",
		"SM3LL005 Lighting MAXLIGHTS8 PARALLAX SPECULAR",
		"SM3LL006 Lighting MAXLIGHTS8 FACEGENBLEND",
		"SM3LL007 Lighting MAXLIGHTS8 FACEGENBLEND SPECULAR",
		"SM3LL008 Lighting MAXLIGHTS8 GLOW",
		"SM3LL009 Lighting MAXLIGHTS8 GLOW SPECULAR",
		"SM3LL010 Lighting MAXLIGHTS8 PROJSHADOW",
		"SM3LL011 Lighting MAXLIGHTS8 SPECULAR PROJSHADOW",
		"SM3LL012 Lighting MAXLIGHTS8 HAIR PROJSHADOW",
		"SM3LL013 Lighting MAXLIGHTS7 HAIR SPECULAR PROJSHADOW",
		"SM3LL014 Lighting MAXLIGHTS8 PARALLAX PROJSHADOW",
		"SM3LL015 Lighting MAXLIGHTS8 PARALLAX SPECULAR PROJSHADOW",
		"SM3LL016 Lighting MAXLIGHTS8 FACEGENBLEND PROJSHADOW",
		"SM3LL017 Lighting MAXLIGHTS8 FACEGENBLEND SPECULAR PROJSHADOW",
		"SM3LL018 Lighting MAXLIGHTS8 GLOW PROJSHADOW",
		"SM3LL019 Lighting MAXLIGHTS8 GLOW SPECULAR PROJSHADOW"
	};

	enum Lighting30VertexContractFlags
	{
		kLighting30VertexContract_None = 0,
		kLighting30VertexContract_Skin = 1 << 0,
		kLighting30VertexContract_VertexColor = 1 << 1,
		kLighting30VertexContract_ProjectShadow = 1 << 2,
		kLighting30VertexContract_Special = 1 << 3,
		kLighting30VertexContract_Clear = 1 << 4,
		kLighting30VertexContract_Fire = 1 << 5
	};

	struct Lighting30VertexProgramContract
	{
		const char* family;
		UInt32 flags;
	};

	enum Lighting30PixelContractFlags
	{
		kLighting30PixelContract_None = 0,
		kLighting30PixelContract_Specular = 1 << 0,
		kLighting30PixelContract_Hair = 1 << 1,
		kLighting30PixelContract_Parallax = 1 << 2,
		kLighting30PixelContract_FaceGenBlend = 1 << 3,
		kLighting30PixelContract_Glow = 1 << 4,
		kLighting30PixelContract_ProjectShadow = 1 << 5,
		kLighting30PixelContract_Window = 1 << 6,
		kLighting30PixelContract_Special = 1 << 7,
		kLighting30PixelContract_SoftShadow = 1 << 8,
		kLighting30PixelContract_DepthBias = 1 << 9,
		kLighting30PixelContract_Alpha = 1 << 10,
		kLighting30PixelContract_Fire = 1 << 11,
		kLighting30PixelContract_Clear = 1 << 12,
		kLighting30PixelContract_HQ = 1 << 13
	};

	struct Lighting30PixelProgramContract
	{
		const char* family;
		UInt32 maxLights;
		UInt32 flags;
	};

	const Lighting30VertexProgramContract kLighting30VertexProgramContracts[kLighting30VertexProgramCount] =
	{
		{ "SM3Lighting", kLighting30VertexContract_None },
		{ "SM3Lighting", kLighting30VertexContract_Skin },
		{ "SM3Lighting", kLighting30VertexContract_VertexColor },
		{ "SM3Lighting", kLighting30VertexContract_Skin | kLighting30VertexContract_VertexColor },
		{ "SM3Lighting", kLighting30VertexContract_ProjectShadow },
		{ "SM3Lighting", kLighting30VertexContract_Skin | kLighting30VertexContract_ProjectShadow },
		{ "SM3Lighting", kLighting30VertexContract_VertexColor | kLighting30VertexContract_ProjectShadow },
		{ "SM3Lighting", kLighting30VertexContract_Skin | kLighting30VertexContract_VertexColor | kLighting30VertexContract_ProjectShadow },
		{ "EnvMap", kLighting30VertexContract_None },
		{ "EnvMap", kLighting30VertexContract_VertexColor },
		{ "EnvMap", kLighting30VertexContract_Skin },
		{ "EnvMap", kLighting30VertexContract_Skin | kLighting30VertexContract_VertexColor },
		{ "EnvMap", kLighting30VertexContract_Special },
		{ "SimpleShadow", kLighting30VertexContract_None },
		{ "SimpleShadow", kLighting30VertexContract_VertexColor },
		{ "SimpleShadow", kLighting30VertexContract_Skin },
		{ "SimpleShadow", kLighting30VertexContract_Skin | kLighting30VertexContract_VertexColor },
		{ "Decal", kLighting30VertexContract_None },
		{ "DepthMap", kLighting30VertexContract_None },
		{ "DepthMap", kLighting30VertexContract_Skin },
		{ "RenderNormals", kLighting30VertexContract_None },
		{ "RenderNormals", kLighting30VertexContract_Skin },
		{ "RenderNormals", kLighting30VertexContract_Fire },
		{ "RenderNormals", kLighting30VertexContract_Clear },
		{ "RenderNormals", kLighting30VertexContract_Clear | kLighting30VertexContract_Skin },
		{ "LocalMap", kLighting30VertexContract_None },
		{ "LocalMap", kLighting30VertexContract_Skin },
		{ "LocalMap", kLighting30VertexContract_Clear },
		{ "TexEffect", kLighting30VertexContract_None },
		{ "TexEffect", kLighting30VertexContract_Skin },
		{ "ZOnly", kLighting30VertexContract_None },
		{ "ZOnly", kLighting30VertexContract_Skin }
	};

	const Lighting30PixelProgramContract kLighting30PixelProgramContracts[kLighting30PixelProgramCount] =
	{
		{ "SM3Lighting", 9, kLighting30PixelContract_None },
		{ "SM3Lighting", 8, kLighting30PixelContract_Specular },
		{ "SM3Lighting", 8, kLighting30PixelContract_Hair },
		{ "SM3Lighting", 7, kLighting30PixelContract_Hair | kLighting30PixelContract_Specular },
		{ "SM3Lighting", 8, kLighting30PixelContract_Parallax },
		{ "SM3Lighting", 8, kLighting30PixelContract_Parallax | kLighting30PixelContract_Specular },
		{ "SM3Lighting", 8, kLighting30PixelContract_FaceGenBlend },
		{ "SM3Lighting", 8, kLighting30PixelContract_FaceGenBlend | kLighting30PixelContract_Specular },
		{ "SM3Lighting", 8, kLighting30PixelContract_Glow },
		{ "SM3Lighting", 8, kLighting30PixelContract_Glow | kLighting30PixelContract_Specular },
		{ "SM3Lighting", 8, kLighting30PixelContract_ProjectShadow },
		{ "SM3Lighting", 8, kLighting30PixelContract_Specular | kLighting30PixelContract_ProjectShadow },
		{ "SM3Lighting", 8, kLighting30PixelContract_Hair | kLighting30PixelContract_ProjectShadow },
		{ "SM3Lighting", 7, kLighting30PixelContract_Hair | kLighting30PixelContract_Specular | kLighting30PixelContract_ProjectShadow },
		{ "SM3Lighting", 8, kLighting30PixelContract_Parallax | kLighting30PixelContract_ProjectShadow },
		{ "SM3Lighting", 8, kLighting30PixelContract_Parallax | kLighting30PixelContract_Specular | kLighting30PixelContract_ProjectShadow },
		{ "SM3Lighting", 8, kLighting30PixelContract_FaceGenBlend | kLighting30PixelContract_ProjectShadow },
		{ "SM3Lighting", 8, kLighting30PixelContract_FaceGenBlend | kLighting30PixelContract_Specular | kLighting30PixelContract_ProjectShadow },
		{ "SM3Lighting", 8, kLighting30PixelContract_Glow | kLighting30PixelContract_ProjectShadow },
		{ "SM3Lighting", 8, kLighting30PixelContract_Glow | kLighting30PixelContract_Specular | kLighting30PixelContract_ProjectShadow },
		{ "EnvMap", 0, kLighting30PixelContract_None },
		{ "EnvMap", 0, kLighting30PixelContract_Window },
		{ "EnvMap", 0, kLighting30PixelContract_Special },
		{ "SimpleShadow", 0, kLighting30PixelContract_SoftShadow | kLighting30PixelContract_DepthBias },
		{ "Decal", 0, kLighting30PixelContract_None },
		{ "Decal", 0, kLighting30PixelContract_Alpha },
		{ "DepthMap", 0, kLighting30PixelContract_None },
		{ "DepthMap", 0, kLighting30PixelContract_None },
		{ "RenderNormals", 0, kLighting30PixelContract_None },
		{ "RenderNormals", 0, kLighting30PixelContract_None },
		{ "RenderNormals", 0, kLighting30PixelContract_Fire },
		{ "RenderNormals", 0, kLighting30PixelContract_Clear },
		{ "RenderNormals", 0, kLighting30PixelContract_Clear },
		{ "LocalMap", 0, kLighting30PixelContract_None },
		{ "LocalMap", 0, kLighting30PixelContract_Clear },
		{ "TexEffect", 0, kLighting30PixelContract_HQ },
		{ "TexEffect", 0, kLighting30PixelContract_HQ },
		{ "ZOnly", 0, kLighting30PixelContract_None },
		{ "ZOnly", 0, kLighting30PixelContract_None }
	};

	const Lighting30PixelProgramContract kLighting30LowPixelProgramContracts[kLighting30LowPixelProgramCount] =
	{
		{ "SM3LLLighting", 9, kLighting30PixelContract_None },
		{ "SM3LLLighting", 8, kLighting30PixelContract_Specular },
		{ "SM3LLLighting", 8, kLighting30PixelContract_Hair },
		{ "SM3LLLighting", 7, kLighting30PixelContract_Hair | kLighting30PixelContract_Specular },
		{ "SM3LLLighting", 8, kLighting30PixelContract_Parallax },
		{ "SM3LLLighting", 8, kLighting30PixelContract_Parallax | kLighting30PixelContract_Specular },
		{ "SM3LLLighting", 8, kLighting30PixelContract_FaceGenBlend },
		{ "SM3LLLighting", 8, kLighting30PixelContract_FaceGenBlend | kLighting30PixelContract_Specular },
		{ "SM3LLLighting", 8, kLighting30PixelContract_Glow },
		{ "SM3LLLighting", 8, kLighting30PixelContract_Glow | kLighting30PixelContract_Specular },
		{ "SM3LLLighting", 8, kLighting30PixelContract_ProjectShadow },
		{ "SM3LLLighting", 8, kLighting30PixelContract_Specular | kLighting30PixelContract_ProjectShadow },
		{ "SM3LLLighting", 8, kLighting30PixelContract_Hair | kLighting30PixelContract_ProjectShadow },
		{ "SM3LLLighting", 7, kLighting30PixelContract_Hair | kLighting30PixelContract_Specular | kLighting30PixelContract_ProjectShadow },
		{ "SM3LLLighting", 8, kLighting30PixelContract_Parallax | kLighting30PixelContract_ProjectShadow },
		{ "SM3LLLighting", 8, kLighting30PixelContract_Parallax | kLighting30PixelContract_Specular | kLighting30PixelContract_ProjectShadow },
		{ "SM3LLLighting", 8, kLighting30PixelContract_FaceGenBlend | kLighting30PixelContract_ProjectShadow },
		{ "SM3LLLighting", 8, kLighting30PixelContract_FaceGenBlend | kLighting30PixelContract_Specular | kLighting30PixelContract_ProjectShadow },
		{ "SM3LLLighting", 8, kLighting30PixelContract_Glow | kLighting30PixelContract_ProjectShadow },
		{ "SM3LLLighting", 8, kLighting30PixelContract_Glow | kLighting30PixelContract_Specular | kLighting30PixelContract_ProjectShadow }
	};

	const UInt8 kLighting30PassVertexProgramIndices[kLighting30PassCount] =
	{
		30, 30, 31, 0, 1, 2, 0, 0, 1, 0, 1, 2, 3, 2, 2, 3, 4, 5,
		6, 4, 4, 5, 4, 5, 6, 7, 6, 6, 7, 8, 8, 9, 9, 10, 11, 12,
		13, 14, 15, 16, 17, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27,
		28, 29
	};

	const UInt8 kLighting30PassPixelProgramIndices[kLighting30PassCount] =
	{
		37, 37, 38, 0, 0, 2, 4, 6, 6, 8, 8, 0, 0, 4, 8, 8, 10, 10,
		12, 14, 16, 16, 18, 18, 10, 10, 14, 18, 18, 20, 21, 20, 21, 20, 20, 22,
		23, 23, 23, 23, 24, 25, 26, 26, 28, 29, 30, 31, 32, 33, 33, 34,
		35, 36
	};

	const UInt32 kLighting30PassVertexConstantMasks[kLighting30PassCount] =
	{
		0x00000812, 0x00000002, 0x0000000C, 0x00030002, 0x0003000C, 0x00030002,
		0x00030002, 0x00030002, 0x0003000C, 0x00030002, 0x0003000C, 0x00030002,
		0x0003000C, 0x00030012, 0x00030002, 0x0003000C, 0x0C430002, 0x0C43000C,
		0x0C430002, 0x0C430002, 0x0C430002, 0x0C43000C, 0x0C430002, 0x0C43000C,
		0x0C430002, 0x0C43000C, 0x0C430002, 0x0C430002, 0x0C43000C, 0x00008802,
		0x00008802, 0x00008802, 0x00008802, 0x1000800C, 0x1000800C, 0x00208802,
		0x00030802, 0x00030802, 0x0003080C, 0x0003080C, 0x00000002, 0x00000002,
		0x00000012, 0x0000002C, 0x00000012, 0x0000002C, 0x00108012, 0x00000002,
		0x0000000C, 0x00000012, 0x0000002C, 0x00000002, 0x00000000, 0x00000000
	};

	const UInt32 kLighting30PassPixelConstantMasks[kLighting30PassCount] =
	{
		0x00000000, 0x00000000, 0x00000000, 0x00000016, 0x00000016, 0x0000001E,
		0x00000016, 0x00000016, 0x00000016, 0x00000036, 0x00000036, 0x00000016,
		0x00000016, 0x00000016, 0x00000036, 0x00000036, 0x00000016, 0x00000016,
		0x0000001E, 0x00000016, 0x00000016, 0x00000016, 0x00000036, 0x00000036,
		0x00000016, 0x00000016, 0x00000016, 0x00000036, 0x00000036, 0x00000010,
		0x00000010, 0x00000010, 0x00000010, 0x00000010, 0x00000010, 0x00000010,
		0x00000C10, 0x00000C10, 0x00000C10, 0x00000C10, 0x00000000, 0x00000000,
		0x00000400, 0x00000400, 0x00000200, 0x00000200, 0x00000200, 0x00000000,
		0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
	};

	const UInt32 kLighting30SelectorIdBase = 0x012A;
	const UInt32 kLighting30SelectorAliasNone = 0xFFFFFFFF;
	const UInt32 kLighting30PlainSm3000PassIndex = 3;
	const UInt32 kLighting30PlainSm3000VertexProgramIndex = 0;
	const UInt32 kLighting30PlainSm3000PixelProgramIndex = 0;
	const UInt32 kLighting30ObjectVertexShaderVariantCount = 8;
	const UInt32 kLighting30EnvMapVertexShaderVariantCount = 5;
	const UInt32 kLighting30TexEffectVertexShaderVariantCount = 2;
	const UInt32 kLighting30DecalVertexShaderVariantCount = 1;
	const UInt32 kLighting30DepthMapVertexShaderVariantCount = 2;
	const UInt32 kLighting30SupportVertexShaderVariantCount = 11;
	const UInt32 kLegacyObjectVertexShaderVariantCount = 2;
	const UInt32 kLighting30DepthMapObjectPassIndex = 42;
	const UInt32 kLighting30DepthMapSkinPassIndex = 43;
	const UInt32 kLighting30DepthMapObjectVertexProgramIndex = 18;
	const UInt32 kLighting30DepthMapSkinVertexProgramIndex = 19;
	const UInt32 kLighting30DepthMapPixelProgramIndex = 26;
	const UInt32 kLighting30DepthMapObjectVertexConstantMask = 0x00000012;
	const UInt32 kLighting30DepthMapSkinVertexConstantMask = 0x0000002C;
	const UInt32 kLighting30DepthMapPixelConstantMask = 0x00000400;
	const UInt32 kLighting30SimpleShadowPixelConstantMask = 0x00000C10;
	const UInt32 kLighting30ZOnlyPixelConstantMask = 0x00000000;
	const UInt32 kLighting30RenderNormalsPixelConstantMask = 0x00000200;
	const UInt32 kLighting30LocalMapPixelConstantMask = 0x00000000;
	const D3DFORMAT kTextureBackedDepthFormats[] =
	{
		static_cast<D3DFORMAT>(MAKEFOURCC('I', 'N', 'T', 'Z')),
		static_cast<D3DFORMAT>(MAKEFOURCC('D', 'F', '2', '4')),
		static_cast<D3DFORMAT>(MAKEFOURCC('R', 'A', 'W', 'Z'))
	};
	const UInt32 kTextureBackedDepthFormatCount = sizeof(kTextureBackedDepthFormats) / sizeof(kTextureBackedDepthFormats[0]);

	enum DepthSampleSource
	{
		kDepthSampleSource_None = 0,
		kDepthSampleSource_CapturedWorld = 1,
		kDepthSampleSource_ActiveFallback = 2
	};

	const char* kFallbackPixelShader =
		"sampler2D SceneSampler : register(s0);\n"
		"sampler2D DepthSampler : register(s1);\n"
		"float4 MoonSugarParams : register(c0);\n"
		"float4 MoonSugarScreen : register(c1);\n"
		"float4 MoonSugarTuning : register(c2);\n"
		"float4 MoonSugarProfile : register(c3);\n"
		"float4 MoonSugarViewport : register(c4);\n"
		"float4 MoonSugarDepthState : register(c5);\n"
		"\n"
		"float MoonSugarLuma(float3 c)\n"
		"{\n"
		"    return dot(c, float3(0.299, 0.587, 0.114));\n"
		"}\n"
		"\n"
		"float2 MoonSugarLocalUV(float2 uv)\n"
		"{\n"
		"    float2 extent = max(MoonSugarViewport.zw, float2(0.0005, 0.0005));\n"
		"    return saturate((uv - MoonSugarViewport.xy) / extent);\n"
		"}\n"
		"\n"
		"float2 MoonSugarViewportClamp(float2 uv)\n"
		"{\n"
		"    float2 px = max(MoonSugarScreen.xy, float2(0.0005, 0.0005));\n"
		"    float2 minUv = MoonSugarViewport.xy + px * 0.5;\n"
		"    float2 maxUv = MoonSugarViewport.xy + max(MoonSugarViewport.zw - px * 0.5, px);\n"
		"    return clamp(uv, minUv, maxUv);\n"
		"}\n"
		"\n"
		"float3 MoonSugarSceneSample(float2 uv)\n"
		"{\n"
		"    return tex2D(SceneSampler, MoonSugarViewportClamp(uv)).rgb;\n"
		"}\n"
		"\n"
		"float3 MoonSugarStableSceneSample(float2 uv, float3 fallback)\n"
		"{\n"
		"    float3 sampleColor = MoonSugarSceneSample(uv);\n"
		"    float sampleLuma = MoonSugarLuma(sampleColor);\n"
		"    float fallbackLuma = MoonSugarLuma(fallback);\n"
		"    float lowChannel = min(sampleColor.r, min(sampleColor.g, sampleColor.b));\n"
		"    float nearWhite = smoothstep(0.90, 0.985, sampleLuma) * smoothstep(0.68, 0.95, lowChannel);\n"
		"    float mismatch = smoothstep(0.20, 0.52, abs(sampleLuma - fallbackLuma));\n"
		"    float fallbackNotWhite = 1.0 - smoothstep(0.78, 0.94, fallbackLuma);\n"
		"    return lerp(sampleColor, fallback, nearWhite * mismatch * fallbackNotWhite);\n"
		"}\n"
		"\n"
		"float3 MoonSugarSceneEdge(float2 uv)\n"
		"{\n"
		"    float2 px = max(MoonSugarScreen.xy, float2(0.0005, 0.0005));\n"
		"    float l = MoonSugarLuma(MoonSugarSceneSample(uv - float2(px.x, 0.0)));\n"
		"    float r = MoonSugarLuma(MoonSugarSceneSample(uv + float2(px.x, 0.0)));\n"
		"    float u = MoonSugarLuma(MoonSugarSceneSample(uv - float2(0.0, px.y)));\n"
		"    float d = MoonSugarLuma(MoonSugarSceneSample(uv + float2(0.0, px.y)));\n"
		"    float dl = MoonSugarLuma(MoonSugarSceneSample(uv - px));\n"
		"    float dr = MoonSugarLuma(MoonSugarSceneSample(uv + px));\n"
		"    float ul = MoonSugarLuma(MoonSugarSceneSample(uv + float2(-px.x, px.y)));\n"
		"    float ur = MoonSugarLuma(MoonSugarSceneSample(uv + float2(px.x, -px.y)));\n"
		"    float2 g = float2(r - l, d - u);\n"
		"    float diagonal = abs(dr - dl) + abs(ur - ul);\n"
		"    return float3(g, saturate(length(g) * 4.4 + diagonal * 2.2));\n"
		"}\n"
		"\n"
		"float MoonSugarDepthValid(float d)\n"
		"{\n"
		"    return smoothstep(0.00005, 0.0020, d) * (1.0 - smoothstep(0.99920, 0.99998, d));\n"
		"}\n"
		"\n"
		"float MoonSugarDepthAvailable()\n"
		"{\n"
		"    return saturate(max(MoonSugarProfile.z, MoonSugarDepthState.x));\n"
		"}\n"
		"\n"
		"float MoonSugarCapturedDepthTrust()\n"
		"{\n"
		"    return saturate(MoonSugarDepthState.y);\n"
		"}\n"
		"\n"
		"float4 MoonSugarDepthSurfaceMask(float2 uv, float edgePresence)\n"
		"{\n"
		"    float2 px = max(MoonSugarScreen.xy, float2(0.0005, 0.0005));\n"
		"    float c = tex2D(DepthSampler, uv).r;\n"
		"    float l = tex2D(DepthSampler, uv - float2(px.x, 0.0)).r;\n"
		"    float r = tex2D(DepthSampler, uv + float2(px.x, 0.0)).r;\n"
		"    float u = tex2D(DepthSampler, uv - float2(0.0, px.y)).r;\n"
		"    float d = tex2D(DepthSampler, uv + float2(0.0, px.y)).r;\n"
		"    float centerValid = MoonSugarDepthValid(c);\n"
		"    float crossValid = min(min(MoonSugarDepthValid(l), MoonSugarDepthValid(r)), min(MoonSugarDepthValid(u), MoonSugarDepthValid(d)));\n"
		"    float span = max(max(abs(c - l), abs(c - r)), max(abs(c - u), abs(c - d)));\n"
		"    float depthEdge = saturate((abs(r - l) + abs(d - u)) * 72.0);\n"
		"    float coherence = 1.0 - smoothstep(0.010, 0.080, span);\n"
		"    float interior = centerValid * crossValid * coherence;\n"
		"    float boundary = centerValid * depthEdge * smoothstep(0.65, 1.0, edgePresence);\n"
		"    float surface = saturate(interior * 0.94 + boundary * 0.16);\n"
		"    return float4(c, centerValid, depthEdge, surface);\n"
		"}\n"
		"\n"
		"float4 HeadWoundPS(float2 uv)\n"
		"{\n"
		"    float t = MoonSugarParams.x;\n"
		"    float i = saturate(MoonSugarParams.y);\n"
		"    float severity = saturate(MoonSugarProfile.y);\n"
		"    float2 localUv = MoonSugarLocalUV(uv);\n"
		"    float2 p = localUv - 0.5;\n"
		"    float r2 = dot(p, p);\n"
		"    float radius = sqrt(r2 + 0.00001);\n"
		"    float edge = saturate((r2 - 0.035) * 2.40);\n"
		"    float heartbeat = pow(sin(t * 3.45) * 0.5 + 0.5, 2.7);\n"
		"    float pulse = pow(sin(t * 4.15 + radius * 2.0) * 0.5 + 0.5, 2.0);\n"
		"    float ring = sin(t * 8.0 - radius * 31.0) * 0.5 + 0.5;\n"
		"    float shock = saturate(1.0 - abs(frac(t * 0.37) - 0.08) * 10.5);\n"
		"    float2 dir = normalize(p + float2(0.0001, -0.0001));\n"
		"    float3 sceneEdge = MoonSugarSceneEdge(uv);\n"
		"    float objectEdge = saturate(sceneEdge.z * (0.95 + edge * 0.45));\n"
		"    float2 edgeDir = normalize(sceneEdge.xy + dir * 0.012 + float2(0.0001, -0.0001));\n"
		"    float2 edgeTangent = float2(-edgeDir.y, edgeDir.x);\n"
		"    float edgeCrawl = sin(t * 16.0 + localUv.x * 41.0 - localUv.y * 37.0);\n"
		"    float2 drift = float2(sin(t * 2.6 + localUv.y * 3.1), cos(t * 2.1 + localUv.x * 2.4)) * (0.0018 + 0.0054 * severity) * i;\n"
		"    float2 tremor = float2(sin(t * 21.0 + localUv.y * 17.0), cos(t * 19.0 - localUv.x * 13.0)) * (0.0009 + 0.0018 * severity) * i;\n"
		"    float2 edgeWarp = (edgeDir * edgeCrawl + edgeTangent * cos(t * 11.5 + localUv.x * 19.0 + localUv.y * 23.0) * 0.55) * objectEdge * (0.0016 + 0.0046 * severity) * i;\n"
		"    float radialBlur = (0.0014 + severity * 0.0058) * (0.30 + pulse * 0.52 + heartbeat * 0.18 + shock * 0.24) * i;\n"
		"    float2 blurVec = dir * radialBlur + tremor;\n"
		"    float focus = saturate(1.0 - edge * (0.45 + severity * 0.30));\n"
		"    float3 center = MoonSugarSceneSample(uv + drift * 0.34 + edgeWarp * 0.45);\n"
		"    float3 nearA = MoonSugarStableSceneSample(uv + blurVec + drift + edgeWarp, center);\n"
		"    float3 nearB = MoonSugarStableSceneSample(uv - blurVec * 0.75 - drift * 0.35 - edgeWarp * 0.55, center);\n"
		"    float3 farA = MoonSugarStableSceneSample(uv + blurVec * 2.15 + drift * 1.35 + edgeWarp * 1.40, center);\n"
		"    float3 farB = MoonSugarStableSceneSample(uv - blurVec * 1.70 - drift - edgeWarp, center);\n"
		"    float3 color = center * (0.44 + focus * 0.08) + (nearA + nearB) * 0.205 + (farA + farB) * (0.065 + severity * 0.015);\n"
		"    float2 echoOffset = float2(sin(t * 3.35), cos(t * 2.85)) * (0.0042 + severity * 0.0100) * i * (0.55 + shock * 0.45);\n"
		"    float3 echoA = MoonSugarStableSceneSample(uv + echoOffset + edgeWarp * 0.65, center);\n"
		"    float3 echoB = MoonSugarStableSceneSample(uv - echoOffset * 0.85 - edgeWarp * 0.40, center);\n"
		"    float3 edgeEcho = MoonSugarStableSceneSample(uv - edgeWarp * 2.15 + tremor * 0.45, center);\n"
		"    color = lerp(color, (echoA + echoB) * 0.5, (0.16 + severity * 0.20) * i * (1.0 - edge * 0.18));\n"
		"    color = lerp(color, edgeEcho, objectEdge * (0.16 + heartbeat * 0.08 + severity * 0.10) * i);\n"
		"    float2 splitOffset = (dir * (0.0020 + severity * 0.0050) + edgeTangent * objectEdge * 0.0022) * i;\n"
		"    float3 redSplit = MoonSugarStableSceneSample(uv + splitOffset + drift * 0.45, center);\n"
		"    float3 blueSplit = MoonSugarStableSceneSample(uv - splitOffset * 0.85 - drift * 0.25, center);\n"
		"    float luma = MoonSugarLuma(color);\n"
		"    color.r = lerp(color.r, redSplit.r, (0.16 + objectEdge * 0.20) * severity * i);\n"
		"    color.b = lerp(color.b, blueSplit.b, (0.18 + objectEdge * 0.22) * severity * i);\n"
		"    color = lerp(color, float3(luma, luma, luma), (0.28 + severity * 0.32) * i);\n"
		"    color = (color - 0.5) * (1.0 - (0.10 + severity * 0.16) * i) + 0.5;\n"
		"    color.r += (edge * 0.18 + pulse * 0.040 + ring * edge * 0.035 + objectEdge * 0.055) * severity * i;\n"
		"    color.g -= (edge * 0.080 + pulse * 0.018 + objectEdge * 0.028) * severity * i;\n"
		"    color.b -= (edge * 0.105 + pulse * 0.028 + objectEdge * 0.038) * severity * i;\n"
		"    color *= 1.0 - edge * (0.38 + severity * 0.26) * i;\n"
		"    color += (heartbeat * 0.020 + shock * 0.035 + pulse * 0.018) * i;\n"
		"    return float4(saturate(color), 1.0);\n"
		"}\n"
		"\n"
		"float4 BlindPS(float2 uv)\n"
		"{\n"
		"    float t = MoonSugarParams.x;\n"
		"    float effect = saturate(MoonSugarParams.y);\n"
		"    float blind = saturate(MoonSugarProfile.y) * effect;\n"
		"    float2 localUv = MoonSugarLocalUV(uv);\n"
		"    float2 p = localUv - 0.5;\n"
		"    p.x *= MoonSugarScreen.z / max(MoonSugarScreen.w, 1.0);\n"
		"    float radius = length(p);\n"
		"    float peripheral = smoothstep(0.16, 0.82, radius);\n"
		"    float centerBlur = blind * (0.28 + blind * 0.26);\n"
		"    float edgeBlur = blind * (0.82 + peripheral * 0.98);\n"
		"    float2 dir = normalize(p + float2(0.0001, -0.0001));\n"
		"    float3 sceneEdge = MoonSugarSceneEdge(uv);\n"
		"    float edgePresence = saturate(sceneEdge.z * (0.60 + blind * 0.85));\n"
		"    float verticalFar = 1.0 - smoothstep(0.24, 0.96, localUv.y);\n"
		"    float lowDetailFar = 1.0 - saturate(edgePresence * 1.75);\n"
		"    float screenDistanceCue = verticalFar * 0.56 + lowDetailFar * verticalFar * 0.28 + peripheral * 0.16;\n"
		"    float distanceCue = saturate(screenDistanceCue * blind);\n"
		"    float2 edgeDir = normalize(sceneEdge.xy + dir * 0.010 + float2(0.0001, -0.0001));\n"
		"    float2 tangent = float2(-edgeDir.y, edgeDir.x);\n"
		"    float2 motionDir = normalize(float2(sin(t * 1.23) + 0.35 * cos(t * 0.61), cos(t * 0.97) - 0.25 * sin(t * 0.77)) + float2(0.0001, 0.0002));\n"
		"    float shimmer = sin(t * 1.10 + radius * 6.0 + localUv.x * 2.0) * 0.5 + 0.5;\n"
		"    float blur = (0.0022 + blind * 0.0145) * (0.40 + edgeBlur + edgePresence * 0.42) + distanceCue * (0.0018 + blind * 0.0050);\n"
		"    float motion = (0.0016 + blind * 0.0095) * (0.48 + shimmer * 0.38 + peripheral * 0.34);\n"
		"    float2 softDrift = (dir * (shimmer - 0.5) + tangent * (sin(t * 0.71 + localUv.y * 4.0) * 0.5)) * blind * peripheral * 0.0040;\n"
		"    float2 blurVec = dir * blur + softDrift;\n"
		"    float2 motionVec = motionDir * motion;\n"
		"    float3 center = tex2D(SceneSampler, uv + softDrift * 0.25).rgb;\n"
		"    float3 radialA = tex2D(SceneSampler, uv + blurVec).rgb;\n"
		"    float3 radialB = tex2D(SceneSampler, uv - blurVec * 0.85).rgb;\n"
		"    float3 tangentA = tex2D(SceneSampler, uv + tangent * blur * 0.90 + softDrift).rgb;\n"
		"    float3 tangentB = tex2D(SceneSampler, uv - tangent * blur * 0.75 - softDrift * 0.40).rgb;\n"
		"    float3 motionA = tex2D(SceneSampler, uv - motionVec).rgb;\n"
		"    float3 motionB = tex2D(SceneSampler, uv - motionVec * 2.10 + softDrift * 0.50).rgb;\n"
		"    float3 motionC = tex2D(SceneSampler, uv - motionVec * 3.35).rgb;\n"
		"    float3 softBlur = center * 0.22 + (radialA + radialB + tangentA + tangentB) * 0.155 + motionA * 0.095 + motionB * 0.045 + motionC * 0.020;\n"
		"    float blurMix = saturate(0.30 + blind * 0.68 + peripheral * blind * 0.30 + centerBlur);\n"
		"    float3 color = lerp(center, softBlur, blurMix);\n"
		"    float3 edgeSoft = tex2D(SceneSampler, uv + edgeDir * blur * 1.35 - motionVec * 0.85).rgb;\n"
		"    color = lerp(color, edgeSoft, edgePresence * blind * 0.16);\n"
		"    float ghostPulse = sin(t * 0.82 + radius * 5.5 + localUv.y * 2.0) * 0.5 + 0.5;\n"
		"    float2 ghostVec = (motionVec * (3.35 + ghostPulse * 1.75) + dir * blur * (1.15 + peripheral) + tangent * blur * (0.50 - ghostPulse)) * (0.75 + peripheral * 0.55);\n"
		"    float3 ghostA = tex2D(SceneSampler, uv - ghostVec).rgb;\n"
		"    float3 ghostB = tex2D(SceneSampler, uv - ghostVec * 1.65 + tangent * blur * 1.25 + softDrift * 0.30).rgb;\n"
		"    float3 ghostC = tex2D(SceneSampler, uv + ghostVec * 0.70 - dir * blur * 0.85).rgb;\n"
		"    float3 ghost = ghostA * 0.45 + ghostB * 0.35 + ghostC * 0.20;\n"
		"    float ghostLuma = MoonSugarLuma(ghost);\n"
		"    ghost = lerp(float3(ghostLuma, ghostLuma, ghostLuma), float3(ghostLuma * 0.58, ghostLuma * 0.62, ghostLuma * 0.68), 0.48);\n"
		"    ghost *= 0.56;\n"
		"    float ghostStrength = saturate((0.16 + peripheral * 0.34 + edgePresence * 0.22) * blind + distanceCue * 0.18);\n"
		"    color = lerp(color, ghost, ghostStrength);\n"
		"    float luma = MoonSugarLuma(color);\n"
		"    float3 gray = float3(luma, luma, luma);\n"
		"    float desat = saturate(0.34 * blind + peripheral * blind * 0.24);\n"
		"    color = lerp(color, gray, desat);\n"
		"    float contrast = 1.0 - saturate(blind * 0.42 + peripheral * blind * 0.24);\n"
		"    color = (color - 0.5) * contrast + 0.5;\n"
		"    float wash = saturate(0.08 + blind * 0.14 + shimmer * blind * 0.025);\n"
		"    color = lerp(color, float3(0.42, 0.44, 0.46), wash);\n"
		"    float distanceDark = saturate(distanceCue * (0.36 + blind * 0.24));\n"
		"    color = lerp(color, float3(0.012, 0.014, 0.018), distanceDark);\n"
		"    color *= 1.0 - distanceCue * 0.25;\n"
		"    color *= 1.0 - blind * (0.261 + peripheral * 0.348);\n"
		"    color -= float3(0.0261, 0.0290, 0.0348) * blind * (0.45 + peripheral * 0.55);\n"
		"    color *= lerp(1.0, 0.55, effect);\n"
		"    return float4(saturate(color), 1.0);\n"
		"}\n"
		"\n"
		"float4 DimPS(float2 uv)\n"
		"{\n"
		"    float effect = saturate(MoonSugarParams.y);\n"
		"    float dim = saturate(MoonSugarProfile.y) * effect;\n"
		"    float variant = MoonSugarProfile.w;\n"
		"    float dimBoost = (variant > 0.5) ? 1.35 : 1.0;\n"
		"    float3 scene = MoonSugarSceneSample(uv);\n"
		"    float2 localUv = MoonSugarLocalUV(uv);\n"
		"    float2 p = localUv - 0.5;\n"
		"    p.x *= MoonSugarScreen.z / max(MoonSugarScreen.w, 1.0);\n"
		"    float radius = length(p);\n"
		"    float vignette = smoothstep(0.56, 1.08, radius);\n"
		"    float luma = MoonSugarLuma(scene);\n"
		"    float desat = saturate(dim * 0.08);\n"
		"    float darkness = saturate((dim * 0.58 + dim * vignette * 0.08) * dimBoost);\n"
		"    float blackMix = saturate((dim * 0.04 + dim * vignette * 0.035) * dimBoost);\n"
		"    float3 color = lerp(scene, float3(luma, luma, luma), desat);\n"
		"    color *= 1.0 - darkness;\n"
		"    color = lerp(color, color * float3(0.94, 0.96, 1.0), dim * 0.10);\n"
		"    color = lerp(color, float3(0.006, 0.007, 0.010), blackMix);\n"
		"    if (variant > 3.5)\n"
		"    {\n"
		"        float3 redDim = float3(luma * 0.36 + 0.018, luma * 0.060 + 0.003, luma * 0.040 + 0.002);\n"
		"        redDim *= 1.0 - vignette * 0.22;\n"
		"        color = lerp(color, redDim, saturate(0.72 + dim * 0.20));\n"
		"    }\n"
		"    else if (variant > 2.5)\n"
		"    {\n"
		"        float3 purpleDim = float3(luma * 0.28 + 0.018, luma * 0.090 + 0.006, luma * 0.42 + 0.030);\n"
		"        purpleDim *= 1.0 - vignette * 0.20;\n"
		"        color = lerp(color, purpleDim, saturate(0.70 + dim * 0.20));\n"
		"    }\n"
		"    else if (variant > 1.5)\n"
		"    {\n"
		"        float3 inverted = 1.0 - scene;\n"
		"        float invLuma = MoonSugarLuma(inverted);\n"
		"        float3 whiteInverted = lerp(float3(invLuma, invLuma, invLuma), inverted, 0.22);\n"
		"        whiteInverted = lerp(whiteInverted, float3(invLuma * 0.72 + 0.08, invLuma * 0.76 + 0.09, invLuma * 0.84 + 0.10), 0.62);\n"
		"        whiteInverted *= 0.54 - dim * 0.18;\n"
		"        whiteInverted *= 1.0 - vignette * 0.16;\n"
		"        color = lerp(color, whiteInverted, saturate(0.76 + dim * 0.16));\n"
		"    }\n"
		"    return float4(saturate(color), 1.0);\n"
		"}\n"
		"\n"
		"float OnFireHash(float2 p)\n"
		"{\n"
		"    return frac(sin(dot(p, float2(127.1, 311.7))) * 43758.5453);\n"
		"}\n"
		"\n"
		"float OnFireNoise(float2 p)\n"
		"{\n"
		"    float2 ip = floor(p);\n"
		"    float2 fp = frac(p);\n"
		"    fp = fp * fp * (3.0 - 2.0 * fp);\n"
		"    float a = OnFireHash(ip);\n"
		"    float b = OnFireHash(ip + float2(1.0, 0.0));\n"
		"    float c = OnFireHash(ip + float2(0.0, 1.0));\n"
		"    float d = OnFireHash(ip + float2(1.0, 1.0));\n"
		"    return lerp(lerp(a, b, fp.x), lerp(c, d, fp.x), fp.y);\n"
		"}\n"
		"\n"
		"float FireHashFast(float2 p)\n"
		"{\n"
		"    float3 p3 = frac(float3(p.x, p.y, p.x) * float3(0.1031, 0.11369, 0.13787));\n"
		"    p3 += dot(p3, p3.yzx + float3(19.19, 19.19, 19.19));\n"
		"    return frac((p3.x + p3.y) * p3.z);\n"
		"}\n"
		"\n"
		"float FireNoiseFast(float2 p)\n"
		"{\n"
		"    float2 ip = floor(p);\n"
		"    float2 fp = frac(p);\n"
		"    fp = fp * fp * (3.0 - 2.0 * fp);\n"
		"    float a = FireHashFast(ip);\n"
		"    float b = FireHashFast(ip + float2(1.0, 0.0));\n"
		"    float c = FireHashFast(ip + float2(0.0, 1.0));\n"
		"    float d = FireHashFast(ip + float2(1.0, 1.0));\n"
		"    return lerp(lerp(a, b, fp.x), lerp(c, d, fp.x), fp.y);\n"
		"}\n"
		"\n"
		"float4 HeatShimmerPS(float2 uv)\n"
		"{\n"
		"    float t = MoonSugarParams.x;\n"
		"    float effect = saturate(MoonSugarParams.y);\n"
		"    float severity = saturate(MoonSugarProfile.y);\n"
		"    float heat = severity * effect;\n"
		"    float2 localUv = MoonSugarLocalUV(uv);\n"
		"    float2 p = localUv - 0.5;\n"
		"    p.x *= MoonSugarScreen.z / max(MoonSugarScreen.w, 1.0);\n"
		"    float3 scene = MoonSugarSceneSample(uv);\n"
		"    float3 sceneEdge = MoonSugarSceneEdge(uv);\n"
		"    float edgePresence = saturate(sceneEdge.z * (0.85 + severity * 0.45));\n"
		"    float groundBand = smoothstep(0.36, 0.94, localUv.y);\n"
		"    float horizonFeather = smoothstep(0.24, 0.56, localUv.y);\n"
		"    float depthBound = MoonSugarCapturedDepthTrust();\n"
		"    float4 depthMask = MoonSugarDepthSurfaceMask(uv, edgePresence);\n"
		"    float worldSurfaceMask = depthMask.w;\n"
		"    float groundMask = saturate(groundBand * horizonFeather * worldSurfaceMask * depthBound);\n"
		"    float n0 = OnFireNoise(float2(localUv.x * 6.5 + sin(t * 0.62 + localUv.y * 5.0) * 0.42, localUv.y * 11.5 - t * (1.55 + severity * 1.10)));\n"
		"    float n1 = OnFireNoise(float2(localUv.x * 17.0 - t * 0.74, localUv.y * 26.0 - t * (3.80 + severity * 2.50)));\n"
		"    float n2 = OnFireNoise(float2(localUv.x * 39.0 + t * 1.10, localUv.y * 52.0 - t * (8.40 + severity * 4.20)));\n"
		"    float wave = sin(localUv.y * (88.0 + severity * 58.0) - t * (15.0 + severity * 15.0) + n0 * 6.0 + p.x * 3.0) * 0.5 + 0.5;\n"
		"    float boil = saturate(n0 * 0.48 + n1 * 0.34 + n2 * 0.18);\n"
		"    float cell = smoothstep(0.30, 0.92, boil) * (1.0 - smoothstep(0.93, 1.0, boil));\n"
		"    float heatMask = saturate(groundMask * heat * (0.44 + boil * 0.52 + wave * 0.26 + cell * 0.22));\n"
		"    float2 edgeDir = normalize(sceneEdge.xy + float2(0.0001, -0.0001));\n"
		"    float horizontalWaver = (n0 - 0.5) * 1.60 + sin(t * 8.0 + localUv.y * 72.0 + n1 * 5.0) * 0.42;\n"
		"    float upwardWaver = -abs(n1 - 0.5) * 0.78 - wave * 0.18;\n"
		"    float2 shimmerOffset = float2(horizontalWaver, upwardWaver) * heatMask * (0.0026 + severity * 0.0148);\n"
		"    shimmerOffset += edgeDir * (n2 - 0.5) * heatMask * (0.0016 + severity * 0.0058);\n"
		"    float2 bandOffset = float2(sin(t * 11.0 + localUv.y * 118.0 + n2 * 7.0), 0.0) * heatMask * (0.0009 + severity * 0.0044);\n"
		"    float3 warpA = MoonSugarStableSceneSample(uv + shimmerOffset + bandOffset, scene);\n"
		"    float3 warpB = MoonSugarStableSceneSample(uv - shimmerOffset * 0.55 + bandOffset * 0.60, scene);\n"
		"    float3 glint = MoonSugarStableSceneSample(uv + float2(shimmerOffset.x * 1.45, shimmerOffset.y * 0.35), scene);\n"
		"    float3 refracted = warpA * 0.54 + warpB * 0.30 + glint * 0.16;\n"
		"    float refractMix = saturate(heatMask * (0.46 + severity * 0.38 + wave * 0.10));\n"
		"    float3 color = lerp(scene, refracted, refractMix);\n"
		"    float lens = pow(saturate(boil * wave + cell * 0.22), 2.4) * heatMask;\n"
		"    color = lerp(color, color * float3(1.055, 1.010, 0.940) + float3(0.022, 0.010, 0.002), heatMask * (0.18 + severity * 0.16));\n"
		"    color += float3(1.0, 0.58, 0.20) * lens * (0.035 + severity * 0.055);\n"
		"    color = lerp(color, scene, saturate((1.0 - groundMask) * 0.12));\n"
		"    return float4(saturate(color), 1.0);\n"
		"}\n"
		"\n"
		"float4 DepthMaskDebugPS(float2 uv)\n"
		"{\n"
		"    float2 localUv = MoonSugarLocalUV(uv);\n"
		"    float3 scene = MoonSugarSceneSample(uv);\n"
		"    float3 sceneEdge = MoonSugarSceneEdge(uv);\n"
		"    float4 depthMask = MoonSugarDepthSurfaceMask(uv, saturate(sceneEdge.z));\n"
		"    float depthAvailable = MoonSugarDepthAvailable();\n"
		"    float capturedTrust = MoonSugarCapturedDepthTrust();\n"
		"    float activeFallback = saturate(MoonSugarDepthState.z);\n"
		"    float depthValid = depthMask.y * depthAvailable;\n"
		"    float raw = saturate(depthMask.x);\n"
		"    float surface = depthMask.w * capturedTrust;\n"
		"    float depthEdge = depthMask.z * depthAvailable;\n"
		"    float3 rawDepth = lerp(float3(0.035, 0.035, 0.045), float3(raw, raw, raw), depthValid);\n"
		"    float3 maskColor = rawDepth * 0.42 + float3(surface, depthEdge * 0.85, depthValid) * 0.95;\n"
		"    float3 sourceColor = float3(0.90, 0.10, 0.08);\n"
		"    sourceColor = lerp(sourceColor, float3(1.00, 0.72, 0.10), activeFallback);\n"
		"    sourceColor = lerp(sourceColor, float3(0.05, 0.95, 0.42), capturedTrust);\n"
		"    float band = 1.0 - smoothstep(0.035, 0.055, localUv.y);\n"
		"    float3 color = lerp(scene * 0.18 + maskColor * 0.82, sourceColor, band * 0.86);\n"
		"    color += depthEdge * float3(0.00, 0.12, 0.28);\n"
		"    color = lerp(color, scene * 0.18 + float3(0.38, 0.03, 0.03), saturate((1.0 - depthAvailable) * 0.78));\n"
		"    return float4(saturate(color), 1.0);\n"
		"}\n"
		"\n"
		"float4 OnFirePS(float2 uv)\n"
		"{\n"
		"    float t = MoonSugarParams.x;\n"
		"    float effect = saturate(MoonSugarParams.y);\n"
		"    float severity = saturate(MoonSugarProfile.y);\n"
		"    float fire = severity * effect;\n"
		"    float2 localUv = MoonSugarLocalUV(uv);\n"
		"    float height = saturate(1.0 - localUv.y);\n"
		"    float aspect = MoonSugarScreen.z / max(MoonSugarScreen.w, 1.0);\n"
		"    float centerX = (localUv.x - 0.5) * aspect;\n"
		"    float riseLimit = 0.48 + severity * 0.33;\n"
		"    float verticalEnvelope = 1.0 - smoothstep(riseLimit, riseLimit + 0.34, height);\n"
		"    float baseHeat = 1.0 - smoothstep(0.00, 0.18 + severity * 0.08, height);\n"
		"    float topFeather = 1.0 - smoothstep(0.74 + severity * 0.12, 1.0, height);\n"
		"    float sideFalloff = 1.0 - smoothstep(0.50 + severity * 0.18, 0.96 + severity * 0.16, abs(centerX));\n"
		"    float sway = sin(t * 1.22 + height * 9.5 + localUv.x * 2.6) * (0.060 + height * 0.050);\n"
		"    float x = localUv.x + sway * (0.28 + height * 0.72);\n"
		"    float n0 = FireNoiseFast(float2(x * 4.2 + t * 0.18, height * 5.8 - t * (0.88 + severity * 0.28)));\n"
		"    float n1 = FireNoiseFast(float2(x * 11.0 - t * 0.34 + n0 * 0.55, height * 14.0 - t * (2.10 + severity * 0.70)));\n"
		"    float columns = sin((x + n0 * 0.13) * (20.0 + severity * 9.0) + height * 7.0 - t * 1.2) * 0.5 + 0.5;\n"
		"    float curl = (n1 - 0.5) * 0.105 + sin(t * 2.75 + height * 16.0 + x * 6.5) * 0.040;\n"
		"    float tongueNoise = saturate(n0 * 0.52 + n1 * 0.34 + columns * 0.14);\n"
		"    float tongueThreshold = 0.38 + height * (0.52 + severity * 0.18) - baseHeat * 0.24;\n"
		"    float softTongue = smoothstep(tongueThreshold - 0.22, tongueThreshold + 0.24, tongueNoise + curl);\n"
		"    float innerTongue = smoothstep(tongueThreshold + 0.06, tongueThreshold + 0.43, tongueNoise + curl * 0.70);\n"
		"    float flameMask = saturate(softTongue * verticalEnvelope * topFeather * sideFalloff);\n"
		"    float lick = saturate(flameMask * (0.62 + n1 * 0.50 + baseHeat * 0.35));\n"
		"    float coreBase = saturate(innerTongue * flameMask * 1.28 + baseHeat * 0.42 - height * 0.18);\n"
		"    float core = coreBase * coreBase * (1.55 - coreBase * 0.55);\n"
		"    float hotBase = saturate(core * 1.42 + baseHeat * 0.38 - height * 0.34);\n"
		"    float hot = hotBase * hotBase;\n"
		"    float redEdge = saturate(lick - core * 0.52);\n"
		"    float heatMask = saturate((flameMask * 0.70 + core * 0.35 + baseHeat * 0.18) * fire);\n"
		"    float2 heatOffset = float2((n1 - 0.5) * 1.25 + sin(t * 5.4 + height * 28.0) * 0.25, -abs(n0 - 0.5) * 0.55 - flameMask * 0.14);\n"
		"    heatOffset *= heatMask * (0.0025 + severity * 0.0140);\n"
		"    heatOffset.x += curl * heatMask * (0.010 + severity * 0.014);\n"
		"    float3 scene = tex2D(SceneSampler, uv).rgb;\n"
		"    float2 blurStep = float2(MoonSugarScreen.x * (2.0 + severity * 5.0), MoonSugarScreen.y * (2.0 + severity * 6.0));\n"
		"    float3 blurA = tex2D(SceneSampler, uv + heatOffset).rgb;\n"
		"    float3 blurB = tex2D(SceneSampler, uv - heatOffset * 0.45 + float2(blurStep.x, -blurStep.y * 0.55)).rgb;\n"
		"    float3 blurred = scene * 0.46 + (blurA + blurB) * 0.27;\n"
		"    float3 color = lerp(scene, blurred, saturate(heatMask * (0.32 + severity * 0.42)));\n"
		"    float blueBase = baseHeat * hot * (0.20 + severity * 0.10);\n"
		"    float3 flameColor = float3(0.55, 0.045, 0.010) * redEdge;\n"
		"    flameColor += float3(0.96, 0.18, 0.018) * lick;\n"
		"    flameColor += float3(1.00, 0.48, 0.060) * core;\n"
		"    flameColor += float3(1.00, 0.84, 0.34) * hot;\n"
		"    flameColor += float3(0.54, 0.72, 1.00) * blueBase;\n"
		"    float glow = saturate((flameMask * 0.42 + core * 0.48 + baseHeat * 0.22) * fire);\n"
		"    float3 warmBleed = scene * float3(1.08, 0.98, 0.86) + float3(0.10, 0.035, 0.006) * glow;\n"
		"    color = lerp(color, warmBleed, saturate(glow * 0.16 + heatMask * 0.035));\n"
		"    color += flameColor * (0.20 + severity * 0.46) * fire;\n"
		"    color += float3(1.0, 0.38, 0.07) * glow * (0.10 + severity * 0.10);\n"
		"    float smokeBand = smoothstep(0.30, 0.82, height) * (1.0 - smoothstep(0.90, 1.0, height));\n"
		"    float smoke = saturate((n1 * 0.54 + n0 * 0.30 - 0.48) * smokeBand * (0.38 + flameMask * 0.62) * fire);\n"
		"    color = lerp(color, color * float3(0.60, 0.55, 0.50), smoke * 0.20);\n"
		"    color -= float3(0.026, 0.022, 0.018) * smoke;\n"
		"    float2 sparkCell = float2(localUv.x * 72.0 + sway * 10.0 + t * 2.4, height * 76.0 - t * (10.0 + severity * 7.0));\n"
		"    float sparkSeed = FireHashFast(floor(sparkCell));\n"
		"    float2 sparkDelta = frac(sparkCell) - 0.5;\n"
		"    float sparkDot = 1.0 - smoothstep(0.0, 0.0072, dot(sparkDelta, sparkDelta));\n"
		"    float sparkAge = frac(t * (0.52 + sparkSeed * 1.35) + sparkSeed);\n"
		"    float spark = sparkDot * step(0.984 - severity * 0.020, sparkSeed) * flameMask * fire * (1.0 - sparkAge) * (1.0 - smoothstep(0.76, 1.0, height));\n"
		"    color += spark * float3(1.0, 0.70, 0.22) * (0.35 + severity * 0.65);\n"
		"    float luma = MoonSugarLuma(color);\n"
		"    color = lerp(color, float3(luma, luma * 0.92, luma * 0.82), smoke * 0.10);\n"
		"    color = lerp(color, scene, saturate((1.0 - heatMask) * 0.06));\n"
		"    color *= 1.0 + glow * 0.12;\n"
		"    return float4(saturate(color), 1.0);\n"
		"}\n"
		"\n"
		"float4 RainLayer(float2 localUv, float2 scale, float speed, float t, float aspect, float seedOffset)\n"
		"{\n"
		"    float2 gridUv = float2(localUv.x * scale.x, localUv.y * scale.y - t * speed);\n"
		"    float2 cell = floor(gridUv);\n"
		"    float2 f = frac(gridUv);\n"
		"    float seed = FireHashFast(cell + seedOffset);\n"
		"    float active = step(0.18, seed);\n"
		"    float slide = frac(t * (0.10 + seed * 0.18) + seed * 1.37);\n"
		"    float centerX = 0.18 + FireHashFast(cell + seedOffset + float2(3.1, 7.7)) * 0.64;\n"
		"    float centerY = frac(0.10 + slide * 0.92 + FireHashFast(cell + seedOffset + float2(11.7, 2.3)) * 0.10);\n"
		"    float wobble = sin(t * (1.6 + seed * 1.2) + centerY * 8.0 + seed * 6.0) * 0.050;\n"
		"    float2 delta = f - float2(centerX + wobble, centerY);\n"
		"    float2 oval = float2(delta.x * (1.30 + aspect * 0.20), delta.y * 2.45);\n"
		"    float d = dot(oval, oval);\n"
		"    float size = 0.018 + FireHashFast(cell + seedOffset + float2(5.3, 9.1)) * 0.050;\n"
		"    float drop = (1.0 - smoothstep(size, size * 2.35, d)) * active;\n"
		"    float core = 1.0 - smoothstep(0.0, size * 0.52, d);\n"
		"    float rim = saturate(drop - core * 0.58);\n"
		"    float trailSpan = 0.30 + seed * 0.36;\n"
		"    float trailGate = smoothstep(0.01, 0.06, delta.y) * (1.0 - smoothstep(trailSpan, trailSpan + 0.18, delta.y));\n"
		"    float trailWobble = sin(f.y * 13.0 + t * (1.3 + seed) + seed * 5.0) * 0.020;\n"
		"    float trailX = delta.x + trailWobble;\n"
		"    float trailWidth = 0.014 + seed * 0.025;\n"
		"    float trail = (1.0 - smoothstep(trailWidth, trailWidth * 3.1, abs(trailX))) * trailGate * active * (0.42 + seed * 0.48);\n"
		"    float2 refract = float2(delta.x * (drop * 2.0 + trail * 1.3) + trailX * trail * 0.9, delta.y * drop * 0.75 - trail * 0.20);\n"
		"    float mask = saturate(drop + trail);\n"
		"    float glint = saturate(rim * 1.45 + trail * 0.32);\n"
		"    return float4(refract, mask, glint);\n"
		"}\n"
		"\n"
		"float4 RainPS(float2 uv)\n"
		"{\n"
		"    float t = MoonSugarParams.x;\n"
		"    float effect = saturate(MoonSugarParams.y);\n"
		"    float severity = saturate(MoonSugarProfile.y);\n"
		"    float rain = severity * effect;\n"
		"    float2 localUv = MoonSugarLocalUV(uv);\n"
		"    float aspect = MoonSugarScreen.z / max(MoonSugarScreen.w, 1.0);\n"
		"    float3 scene = tex2D(SceneSampler, uv).rgb;\n"
		"    float4 nearDrops = RainLayer(localUv, float2(8.0, 6.0), 0.72 + severity * 0.55, t, aspect, 13.0);\n"
		"    float4 fineDrops = RainLayer(localUv + float2(0.037, 0.011), float2(17.0, 12.0), 1.18 + severity * 0.86, t, aspect, 47.0);\n"
		"    float2 impactGrid = float2(localUv.x * 24.0 + t * 0.07, localUv.y * 15.0 - t * (1.65 + severity));\n"
		"    float2 impactCell = floor(impactGrid);\n"
		"    float2 impactF = frac(impactGrid) - 0.5;\n"
		"    float impactSeed = FireHashFast(impactCell + 91.0);\n"
		"    float impactPhase = frac(t * (1.6 + impactSeed * 1.8) + impactSeed);\n"
		"    float impactDist = dot(impactF * float2(1.25, 1.0), impactF * float2(1.25, 1.0));\n"
		"    float ringRadius = 0.018 + impactPhase * (0.072 + severity * 0.035);\n"
		"    float impactRing = (1.0 - smoothstep(0.0, 0.010 + severity * 0.005, abs(impactDist - ringRadius))) * (1.0 - impactPhase);\n"
		"    impactRing *= step(0.965 - severity * 0.045, impactSeed);\n"
		"    float waterMask = saturate((nearDrops.z + fineDrops.z * 0.72 + impactRing * 0.55) * rain);\n"
		"    float glint = saturate((nearDrops.w + fineDrops.w * 0.68 + impactRing * 0.85) * rain);\n"
		"    float2 waterOffset = nearDrops.xy * 0.95 + fineDrops.xy * 0.55 + impactF * impactRing * 0.36;\n"
		"    waterOffset *= rain * (0.0028 + severity * 0.0115);\n"
		"    waterOffset.y += (nearDrops.z * 0.35 + fineDrops.z * 0.18) * rain * (0.0008 + severity * 0.0026);\n"
		"    float2 px = max(MoonSugarScreen.xy, float2(0.0005, 0.0005));\n"
		"    float3 refrA = tex2D(SceneSampler, uv + waterOffset).rgb;\n"
		"    float3 refrB = tex2D(SceneSampler, uv + waterOffset * 0.45 + float2(px.x * 1.7, -px.y * 0.9)).rgb;\n"
		"    float3 refracted = refrA * 0.72 + refrB * 0.20 + scene * 0.08;\n"
		"    float3 color = lerp(scene, refracted, saturate(waterMask * (0.55 + severity * 0.28)));\n"
		"    float3 coolScene = color * float3(0.88, 0.94, 1.04);\n"
		"    color = lerp(color, coolScene, rain * 0.12);\n"
		"    color += glint * float3(0.16, 0.20, 0.23) * (0.45 + severity * 0.50);\n"
		"    color += impactRing * rain * float3(0.08, 0.10, 0.12);\n"
		"    float sheen = saturate((nearDrops.z * 0.25 + fineDrops.z * 0.18) * rain);\n"
		"    color = lerp(color, color + float3(0.030, 0.040, 0.050), sheen);\n"
		"    color *= 1.0 - rain * (0.045 + waterMask * 0.070);\n"
		"    return float4(saturate(color), 1.0);\n"
		"}\n"
		"\n"
		"float4 FrostPS(float2 uv)\n"
		"{\n"
		"    float t = MoonSugarParams.x;\n"
		"    float effect = saturate(MoonSugarParams.y);\n"
		"    float severity = saturate(MoonSugarProfile.y);\n"
		"    float cold = severity * effect;\n"
		"    float2 localUv = MoonSugarLocalUV(uv);\n"
		"    float aspect = MoonSugarScreen.z / max(MoonSugarScreen.w, 1.0);\n"
		"    float2 p = localUv - 0.5;\n"
		"    p.x *= aspect;\n"
		"    float2 edgeDist = min(localUv, 1.0 - localUv);\n"
		"    float edgeNear = min(edgeDist.x, edgeDist.y);\n"
		"    float edgeMask = 1.0 - smoothstep(0.035 + severity * 0.010, 0.34 + severity * 0.16, edgeNear);\n"
		"    float cornerMask = 1.0 - smoothstep(0.10, 0.52 + severity * 0.08, min(length(localUv), min(length(localUv - float2(1.0, 0.0)), min(length(localUv - float2(0.0, 1.0)), length(localUv - 1.0)))));\n"
		"    float pulse = sin(t * 0.62) * 0.5 + 0.5;\n"
		"    float2 frostUv = localUv * float2(15.0, 10.5) + float2(t * 0.020, -t * 0.014);\n"
		"    float n0 = FireNoiseFast(frostUv);\n"
		"    float n1 = FireNoiseFast(frostUv * 2.15 + float2(8.7, 3.1) - t * 0.035);\n"
		"    float2 veinUv = localUv + float2(n0 - 0.5, n1 - 0.5) * 0.040;\n"
		"    float verticalNeedle = 1.0 - smoothstep(0.012, 0.072, abs(frac(veinUv.x * (21.0 + severity * 7.0) + n1 * 0.33) - 0.5));\n"
		"    float diagonalNeedle = 1.0 - smoothstep(0.014, 0.068, abs(frac((veinUv.x * 0.82 + veinUv.y * 1.18) * (16.0 + severity * 5.0) + n0 * 0.27) - 0.5));\n"
		"    float crossNeedle = 1.0 - smoothstep(0.016, 0.080, abs(frac((veinUv.x * 1.12 - veinUv.y * 0.94) * (13.0 + severity * 4.0) + n1 * 0.31) - 0.5));\n"
		"    float crystal = saturate(max(verticalNeedle, max(diagonalNeedle, crossNeedle)) * (0.38 + n1 * 0.62));\n"
		"    float frostCloud = saturate(edgeMask * (0.52 + n0 * 0.34 + n1 * 0.22) + cornerMask * (0.18 + severity * 0.18));\n"
		"    float frostMask = saturate((frostCloud + crystal * edgeMask * (0.72 + severity * 0.35)) * cold);\n"
		"    float rimPulse = edgeMask * cold * (0.20 + pulse * (0.25 + severity * 0.18));\n"
		"    float2 frostNormal = float2(n0 - 0.5 + (diagonalNeedle - crossNeedle) * 0.18, n1 - 0.5 + verticalNeedle * 0.10);\n"
		"    float2 frostOffset = frostNormal * frostMask * (0.0024 + severity * 0.0068);\n"
		"    float2 px = max(MoonSugarScreen.xy, float2(0.0005, 0.0005));\n"
		"    float3 scene = tex2D(SceneSampler, uv).rgb;\n"
		"    float3 refrA = tex2D(SceneSampler, uv + frostOffset).rgb;\n"
		"    float3 refrB = tex2D(SceneSampler, uv - frostOffset * 0.58 + float2(px.x * 1.4, px.y * 0.8)).rgb;\n"
		"    float3 refracted = scene * 0.28 + refrA * 0.52 + refrB * 0.20;\n"
		"    float luma = MoonSugarLuma(refracted);\n"
		"    float3 icy = float3(luma * 0.70 + 0.045, luma * 0.86 + 0.090, luma * 1.10 + 0.185);\n"
		"    float3 color = lerp(scene, refracted, saturate(frostMask * (0.32 + severity * 0.22)));\n"
		"    color = lerp(color, icy, saturate(frostMask * (0.48 + severity * 0.26)));\n"
		"    float crystalGlint = crystal * frostMask * (0.34 + severity * 0.34);\n"
		"    color += float3(0.44, 0.72, 1.00) * rimPulse;\n"
		"    color += float3(0.82, 0.94, 1.00) * crystalGlint;\n"
		"    color += float3(0.16, 0.34, 0.58) * edgeMask * cold * (0.035 + pulse * 0.050);\n"
		"    color *= 1.0 - edgeMask * cold * (0.06 + severity * 0.045);\n"
		"    color = lerp(color, scene, saturate((1.0 - frostMask) * 0.045));\n"
		"    return float4(saturate(color), 1.0);\n"
		"}\n"
		"\n"
		"float4 MoonSugarDefaultPS(float2 uv)\n"
		"{\n"
		"    float t = MoonSugarParams.x;\n"
		"    float i = saturate(MoonSugarParams.y) * 0.55;\n"
		"    float dose = saturate(MoonSugarParams.w * 0.18);\n"
		"    float2 localUv = MoonSugarLocalUV(uv);\n"
		"    float2 p = localUv - 0.5;\n"
		"    float r2 = dot(p, p);\n"
		"    float edge = saturate(r2 * 2.05);\n"
		"    float pulse = sin(t * 5.8 + r2 * 12.0) * 0.5 + 0.5;\n"
		"    float3 sceneEdge = MoonSugarSceneEdge(uv);\n"
		"    float objectEdge = saturate(sceneEdge.z * (0.75 + edge * 0.35));\n"
		"    float2 edgeDir = normalize(sceneEdge.xy + float2(0.0001, -0.0001));\n"
		"    float2 edgeTangent = float2(-edgeDir.y, edgeDir.x);\n"
		"    float edgePulse = sin(t * 18.0 + localUv.x * 43.0 + localUv.y * 37.0);\n"
		"    float edgeCrawl = cos(t * 9.0 + localUv.x * 17.0 - localUv.y * 29.0);\n"
		"    float2 objectWarp = (edgeDir * edgePulse + edgeTangent * edgeCrawl * 0.45) * objectEdge * (0.0034 + MoonSugarTuning.x * 0.12) * i;\n"
		"    float2 tremor = float2(sin(t * 13.0 + localUv.y * 21.0), cos(t * 11.0 + localUv.x * 17.0)) * 0.00125 * i;\n"
		"    float2 tunnel = p * edge * (0.0020 + 0.0010 * pulse) * i;\n"
		"    float3 sharp = tex2D(SceneSampler, uv + objectWarp + tremor - tunnel).rgb;\n"
		"    float3 soft = tex2D(SceneSampler, uv + objectWarp * 0.35 + p * 0.006 * edge * i).rgb;\n"
		"    float3 split = tex2D(SceneSampler, uv - objectWarp * 1.2 - tremor * 2.0 + p * MoonSugarTuning.z * 0.18 * i).rgb;\n"
		"    float3 edgeEcho = tex2D(SceneSampler, uv - objectWarp * 1.8 + tremor * 0.5).rgb;\n"
		"    float luma = MoonSugarLuma(sharp);\n"
		"    float3 color = lerp(sharp, soft, edge * 0.24 * i);\n"
		"    color = lerp(color, edgeEcho, objectEdge * (0.22 + pulse * 0.10) * i);\n"
		"    color = lerp(color, float3(luma, luma, luma), 0.12 * i);\n"
		"    color = (color - 0.5) * (1.0 + (0.42 + dose * 0.20) * i) + 0.5;\n"
		"    color.r = lerp(color.r, split.b, 0.06 * i);\n"
		"    color.b = lerp(color.b, split.r, 0.07 * i);\n"
		"    color += float3(0.08, 0.10, 0.14) * (pulse + objectEdge * 0.55) * i;\n"
		"    color *= 1.0 - edge * (0.28 + pulse * 0.08) * i;\n"
		"    return float4(saturate(color), 1.0);\n"
		"}\n"
		"\n"
		"float4 VESMoonSugarPS(float2 uv : TEXCOORD0) : COLOR0\n"
		"{\n"
		"    return MoonSugarDefaultPS(uv);\n"
		"}\n"
		"\n"
		"float4 VESHeadWoundPS(float2 uv : TEXCOORD0) : COLOR0\n"
		"{\n"
		"    return HeadWoundPS(uv);\n"
		"}\n"
		"\n"
		"float4 VESBlindPS(float2 uv : TEXCOORD0) : COLOR0\n"
		"{\n"
		"    return BlindPS(uv);\n"
		"}\n"
		"\n"
		"float4 VESDimPS(float2 uv : TEXCOORD0) : COLOR0\n"
		"{\n"
		"    return DimPS(uv);\n"
		"}\n"
		"\n"
		"float4 VESOnFirePS(float2 uv : TEXCOORD0) : COLOR0\n"
		"{\n"
		"    return OnFirePS(uv);\n"
		"}\n"
		"\n"
		"float4 VESHeatShimmerPS(float2 uv : TEXCOORD0) : COLOR0\n"
		"{\n"
		"    return HeatShimmerPS(uv);\n"
		"}\n"
		"\n"
		"float4 VESDepthMaskDebugPS(float2 uv : TEXCOORD0) : COLOR0\n"
		"{\n"
		"    return DepthMaskDebugPS(uv);\n"
		"}\n"
		"\n"
		"float4 VESRainPS(float2 uv : TEXCOORD0) : COLOR0\n"
		"{\n"
		"    return RainPS(uv);\n"
		"}\n"
		"\n"
		"float4 VESFrostPS(float2 uv : TEXCOORD0) : COLOR0\n"
		"{\n"
		"    return FrostPS(uv);\n"
		"}\n"
		"\n"
		"float4 MoonSugarPS(float2 uv : TEXCOORD0) : COLOR0\n"
		"{\n"
		"    if (MoonSugarProfile.x > 8.5)\n"
		"        return DepthMaskDebugPS(uv);\n"
		"    if (MoonSugarProfile.x > 7.5)\n"
		"        return FrostPS(uv);\n"
		"    if (MoonSugarProfile.x > 6.5)\n"
		"        return RainPS(uv);\n"
		"    if (MoonSugarProfile.x > 5.5)\n"
		"        return HeatShimmerPS(uv);\n"
		"    if (MoonSugarProfile.x > 4.5)\n"
		"        return OnFirePS(uv);\n"
		"    if (MoonSugarProfile.x > 3.5)\n"
		"        return DimPS(uv);\n"
		"    if (MoonSugarProfile.x > 2.5)\n"
		"        return BlindPS(uv);\n"
		"    if (MoonSugarProfile.x > 0.5)\n"
		"        return HeadWoundPS(uv);\n"
		"    return MoonSugarDefaultPS(uv);\n"
		"}\n";
	const char* kObjectVertexShader =
		"float4 MVP0 : register(c0);\n"
		"float4 MVP1 : register(c1);\n"
		"float4 MVP2 : register(c2);\n"
		"float4 MVP3 : register(c3);\n"
		"float4 LightDirection : register(c13);\n"
		"float4 LightPosition : register(c17);\n"
		"float4 EyePosition : register(c25);\n"
		"float4 MoonSugar0 : register(c26);\n"
		"float4 MoonSugar1 : register(c27);\n"
		"struct VSIn\n"
		"{\n"
		"    float4 position : POSITION0;\n"
		"    float3 tangent : TANGENT0;\n"
		"    float3 binormal : BINORMAL0;\n"
		"    float3 normal : NORMAL0;\n"
		"    float2 texcoord : TEXCOORD0;\n"
		"};\n"
		"struct VSOut\n"
		"{\n"
		"    float4 position : POSITION0;\n"
		"    float2 texcoord : TEXCOORD0;\n"
		"    float3 lightDir : TEXCOORD1;\n"
		"    float3 pointLight : TEXCOORD2;\n"
		"    float4 atten : TEXCOORD4;\n"
		"    float3 viewDir : TEXCOORD7;\n"
		"};\n"
		"float SmoothTri(float x)\n"
		"{\n"
		"    float y = abs(frac(x) * 2.0 - 1.0);\n"
		"    y = y * y * (3.0 - 2.0 * y);\n"
		"    return y * 2.0 - 1.0;\n"
		"}\n"
		"float3 SafeNormalize(float3 v)\n"
		"{\n"
		"    return v * rsqrt(max(dot(v, v), 0.000001));\n"
		"}\n"
		"VSOut MoonSugarVS(VSIn input)\n"
		"{\n"
		"    VSOut output;\n"
		"    float3 tangent = input.tangent;\n"
		"    float3 binormal = input.binormal;\n"
		"    float3 normal = input.normal;\n"
		"    float3 axisTangent = SafeNormalize(input.tangent);\n"
		"    float3 axisBinormal = SafeNormalize(input.binormal);\n"
		"    float3 axisNormal = SafeNormalize(input.normal);\n"
		"    float3 basePos = input.position.xyz;\n"
		"    float time = MoonSugar0.x;\n"
		"    float intensity = saturate(MoonSugar0.y);\n"
		"    float amplitude = MoonSugar0.z * intensity;\n"
		"    float speed = MoonSugar0.w;\n"
		"    float normalAmp = MoonSugar1.x;\n"
		"    float tangentAmp = MoonSugar1.y;\n"
		"    float frequency = MoonSugar1.z;\n"
		"    float phase = MoonSugar1.w;\n"
		"    float waveA = SmoothTri(dot(basePos, float3(0.017, 0.011, 0.007)) * frequency + time * speed + phase);\n"
		"    float waveB = SmoothTri(dot(basePos, float3(-0.009, 0.015, 0.013)) * frequency - time * speed * 0.63 + phase * 1.71);\n"
		"    float3 displaced = basePos + axisNormal * (waveA * normalAmp * amplitude);\n"
		"    displaced += axisTangent * (waveB * tangentAmp * amplitude);\n"
		"    displaced += axisBinormal * (waveA * waveB * tangentAmp * amplitude * 0.35);\n"
		"    float4 pos = float4(displaced, input.position.w);\n"
		"    output.position = float4(dot(MVP0, pos), dot(MVP1, pos), dot(MVP2, pos), dot(MVP3, pos));\n"
		"    float3 lightTangent = float3(dot(tangent, LightDirection.xyz), dot(binormal, LightDirection.xyz), dot(normal, LightDirection.xyz));\n"
		"    output.lightDir = SafeNormalize(lightTangent);\n"
		"    float3 eyeVec = SafeNormalize(EyePosition.xyz - displaced);\n"
		"    float3 viewTangent = float3(dot(tangent, eyeVec), dot(binormal, eyeVec), dot(normal, eyeVec));\n"
		"    output.viewDir = SafeNormalize(viewTangent);\n"
		"    float3 pointVec = LightPosition.xyz - displaced;\n"
		"    float3 pointNorm = SafeNormalize(pointVec);\n"
		"    output.pointLight = float3(dot(tangent, pointNorm), dot(binormal, pointNorm), dot(normal, pointNorm));\n"
		"    float invRange = rcp(max(LightPosition.w, 0.0001));\n"
		"    output.atten.xyz = pointVec * invRange * 0.5 + 0.5;\n"
		"    output.atten.w = 0.5;\n"
		"    output.texcoord = input.texcoord;\n"
		"    return output;\n"
		"}\n"
		"\n";

	const char* kLighting30ObjectVertexShader =
		"float4 MVP0 : register(c0);\n"
		"float4 MVP1 : register(c1);\n"
		"float4 MVP2 : register(c2);\n"
		"float4 MVP3 : register(c3);\n"
		"float4 FogParam : register(c15);\n"
		"float4 FogColor : register(c16);\n"
		"#ifdef USE_PROJ_SHADOW\n"
		"float4 ShadowProj0 : register(c21);\n"
		"float4 ShadowProj1 : register(c22);\n"
		"float4 ShadowProj3 : register(c24);\n"
		"float4 ShadowProjData : register(c25);\n"
		"float4 ShadowProjTransform : register(c26);\n"
		"float4 MoonSugar0 : register(c27);\n"
		"float4 MoonSugar1 : register(c28);\n"
		"#else\n"
		"float4 MoonSugar0 : register(c26);\n"
		"float4 MoonSugar1 : register(c27);\n"
		"#endif\n"
		"struct VSIn\n"
		"{\n"
		"    float4 position : POSITION0;\n"
		"    float3 tangent : TANGENT0;\n"
		"    float3 binormal : BINORMAL0;\n"
		"    float3 normal : NORMAL0;\n"
		"    float2 texcoord : TEXCOORD0;\n"
		"#ifdef USE_VERTEX_COLOR\n"
		"    float4 color : COLOR0;\n"
		"#endif\n"
		"};\n"
		"struct VSOut\n"
		"{\n"
		"    float4 position : POSITION0;\n"
		"    float2 texcoord : TEXCOORD0;\n"
		"    float4 color : COLOR0;\n"
		"    float3 tangent : TEXCOORD3;\n"
		"    float3 binormal : TEXCOORD4;\n"
		"    float3 normal : TEXCOORD5;\n"
		"    float3 sourcePosition : TEXCOORD6;\n"
		"#ifdef USE_PROJ_SHADOW\n"
		"    float4 shadow : TEXCOORD1;\n"
		"#endif\n"
		"    float4 fog : TEXCOORD7;\n"
		"};\n"
		"float SmoothTri(float x)\n"
		"{\n"
		"    float y = abs(frac(x) * 2.0 - 1.0);\n"
		"    y = y * y * (3.0 - 2.0 * y);\n"
		"    return y * 2.0 - 1.0;\n"
		"}\n"
		"float3 SafeNormalize(float3 v)\n"
		"{\n"
		"    return v * rsqrt(max(dot(v, v), 0.000001));\n"
		"}\n"
		"VSOut MoonSugarVS(VSIn input)\n"
		"{\n"
		"    VSOut output;\n"
		"    float3 basePos = input.position.xyz;\n"
		"    float3 axisTangent = SafeNormalize(input.tangent);\n"
		"    float3 axisBinormal = SafeNormalize(input.binormal);\n"
		"    float3 axisNormal = SafeNormalize(input.normal);\n"
		"    float time = MoonSugar0.x;\n"
		"    float intensity = saturate(MoonSugar0.y);\n"
		"    float amplitude = MoonSugar0.z * intensity;\n"
		"    float speed = MoonSugar0.w;\n"
		"    float normalAmp = MoonSugar1.x;\n"
		"    float tangentAmp = MoonSugar1.y;\n"
		"    float frequency = MoonSugar1.z;\n"
		"    float phase = MoonSugar1.w;\n"
		"    float waveA = SmoothTri(dot(basePos, float3(0.017, 0.011, 0.007)) * frequency + time * speed + phase);\n"
		"    float waveB = SmoothTri(dot(basePos, float3(-0.009, 0.015, 0.013)) * frequency - time * speed * 0.63 + phase * 1.71);\n"
		"    float3 displaced = basePos + axisNormal * (waveA * normalAmp * amplitude);\n"
		"    displaced += axisTangent * (waveB * tangentAmp * amplitude);\n"
		"    displaced += axisBinormal * (waveA * waveB * tangentAmp * amplitude * 0.35);\n"
		"    float4 pos = float4(displaced, input.position.w);\n"
		"    float4 clip = float4(dot(MVP0, pos), dot(MVP1, pos), dot(MVP2, pos), dot(MVP3, pos));\n"
		"    float fogDistance = length(clip.xyz);\n"
		"    float fogAmount = saturate((FogParam.x - fogDistance) / max(FogParam.y, 0.000001));\n"
		"    float fogKeep = 1.0 - fogAmount;\n"
		"    output.position = clip;\n"
		"    output.texcoord = input.texcoord;\n"
		"#ifdef USE_VERTEX_COLOR\n"
		"    output.color = input.color;\n"
		"#else\n"
		"    output.color = 1.0;\n"
		"#endif\n"
		"    output.tangent = input.tangent;\n"
		"    output.binormal = input.binormal;\n"
		"    output.normal = input.normal;\n"
		"    output.sourcePosition = displaced;\n"
		"#ifdef USE_PROJ_SHADOW\n"
		"    float shadowW = dot(ShadowProj3, pos);\n"
		"    float3 shadowTransform = shadowW * ShadowProjTransform.xyw;\n"
		"    float2 shadowClip = float2(dot(ShadowProj0, pos), dot(ShadowProj1, pos));\n"
		"    float2 shadowProjected = shadowClip - ShadowProjData.xy;\n"
		"    float invShadowW = rcp(max(abs(shadowTransform.z), 0.000001)) * (shadowTransform.z < 0.0 ? -1.0 : 1.0);\n"
		"    float invShadowDataW = rcp(max(abs(ShadowProjData.w), 0.000001)) * (ShadowProjData.w < 0.0 ? -1.0 : 1.0);\n"
		"    output.shadow.xy = (shadowTransform.xy + shadowClip) * invShadowW;\n"
		"    output.shadow.z = shadowProjected.x * invShadowDataW;\n"
		"    output.shadow.w = 1.0 - shadowProjected.y * invShadowDataW;\n"
		"#endif\n"
		"    output.fog.xyz = FogColor.xyz;\n"
		"    output.fog.w = fogKeep * FogParam.z;\n"
		"    return output;\n"
		"}\n"
		"\n";

	const char* kLighting30SkinnedObjectVertexShader =
		"float4 SkinMVP0 : register(c1);\n"
		"float4 SkinMVP1 : register(c2);\n"
		"float4 SkinMVP2 : register(c3);\n"
		"float4 SkinMVP3 : register(c4);\n"
		"float4 FogParam : register(c15);\n"
		"float4 FogColor : register(c16);\n"
		"#ifdef USE_PROJ_SHADOW\n"
		"float4 ShadowProj0 : register(c21);\n"
		"float4 ShadowProj1 : register(c22);\n"
		"float4 ShadowProj3 : register(c24);\n"
		"float4 ShadowProjData : register(c25);\n"
		"float4 ShadowProjTransform : register(c26);\n"
		"#endif\n"
		"float4 MoonSugar0 : register(c27);\n"
		"float4 MoonSugar1 : register(c28);\n"
		"float4 Bones[54] : register(c31);\n"
		"struct VSIn\n"
		"{\n"
		"    float4 position : POSITION0;\n"
		"    float3 tangent : TANGENT0;\n"
		"    float3 binormal : BINORMAL0;\n"
		"    float3 normal : NORMAL0;\n"
		"    float2 texcoord : TEXCOORD0;\n"
		"#ifdef USE_VERTEX_COLOR\n"
		"    float4 color : COLOR0;\n"
		"#endif\n"
		"    float4 blendWeights : BLENDWEIGHT0;\n"
		"    float4 blendIndices : BLENDINDICES0;\n"
		"};\n"
		"struct VSOut\n"
		"{\n"
		"    float4 position : POSITION0;\n"
		"    float2 texcoord : TEXCOORD0;\n"
		"    float4 color : COLOR0;\n"
		"    float3 tangent : TEXCOORD3;\n"
		"    float3 binormal : TEXCOORD4;\n"
		"    float3 normal : TEXCOORD5;\n"
		"    float3 sourcePosition : TEXCOORD6;\n"
		"#ifdef USE_PROJ_SHADOW\n"
		"    float4 shadow : TEXCOORD1;\n"
		"#endif\n"
		"    float4 fog : TEXCOORD7;\n"
		"};\n"
		"float SmoothTri(float x)\n"
		"{\n"
		"    float y = abs(frac(x) * 2.0 - 1.0);\n"
		"    y = y * y * (3.0 - 2.0 * y);\n"
		"    return y * 2.0 - 1.0;\n"
		"}\n"
		"float3 SafeNormalize(float3 v)\n"
		"{\n"
		"    return v * rsqrt(max(dot(v, v), 0.000001));\n"
		"}\n"
		"float3 SkinVector(float3 value, float index)\n"
		"{\n"
		"    int row = (int)index;\n"
		"    return float3(dot(Bones[row].xyz, value), dot(Bones[row + 1].xyz, value), dot(Bones[row + 2].xyz, value));\n"
		"}\n"
		"float3 SkinPosition(float3 value, float index)\n"
		"{\n"
		"    int row = (int)index;\n"
		"    float4 pos = float4(value, 1.0);\n"
		"    return float3(dot(Bones[row], pos), dot(Bones[row + 1], pos), dot(Bones[row + 2], pos));\n"
		"}\n"
		"float3 BlendVector(float3 value, float4 indices, float4 weights)\n"
		"{\n"
		"    float3 blended = SkinVector(value, indices.y) * weights.y;\n"
		"    blended += SkinVector(value, indices.x) * weights.x;\n"
		"    blended += SkinVector(value, indices.z) * weights.z;\n"
		"    blended += SkinVector(value, indices.w) * weights.w;\n"
		"    return blended;\n"
		"}\n"
		"float3 BlendPosition(float3 value, float4 indices, float4 weights)\n"
		"{\n"
		"    float3 blended = SkinPosition(value, indices.y) * weights.y;\n"
		"    blended += SkinPosition(value, indices.x) * weights.x;\n"
		"    blended += SkinPosition(value, indices.z) * weights.z;\n"
		"    blended += SkinPosition(value, indices.w) * weights.w;\n"
		"    return blended;\n"
		"}\n"
		"VSOut MoonSugarVS(VSIn input)\n"
		"{\n"
		"    VSOut output;\n"
		"    float4 indices = floor(input.blendIndices.zyxw * 765.01001);\n"
		"    float4 weights = float4(input.blendWeights.xyz, 1.0 - dot(input.blendWeights.xyz, 1.0));\n"
		"    float3 skinnedNormal = SafeNormalize(BlendVector(input.normal, indices, weights));\n"
		"    float3 skinnedTangent = SafeNormalize(BlendVector(input.tangent, indices, weights));\n"
		"    float3 skinnedBinormal = SafeNormalize(BlendVector(input.binormal, indices, weights));\n"
		"    float3 basePos = BlendPosition(input.position.xyz, indices, weights);\n"
		"    float time = MoonSugar0.x;\n"
		"    float intensity = saturate(MoonSugar0.y);\n"
		"    float amplitude = MoonSugar0.z * intensity;\n"
		"    float speed = MoonSugar0.w;\n"
		"    float normalAmp = MoonSugar1.x;\n"
		"    float tangentAmp = MoonSugar1.y;\n"
		"    float frequency = MoonSugar1.z;\n"
		"    float phase = MoonSugar1.w;\n"
		"    float waveA = SmoothTri(dot(basePos, float3(0.017, 0.011, 0.007)) * frequency + time * speed + phase);\n"
		"    float waveB = SmoothTri(dot(basePos, float3(-0.009, 0.015, 0.013)) * frequency - time * speed * 0.63 + phase * 1.71);\n"
		"    float3 displaced = basePos + skinnedNormal * (waveA * normalAmp * amplitude);\n"
		"    displaced += skinnedTangent * (waveB * tangentAmp * amplitude);\n"
		"    displaced += skinnedBinormal * (waveA * waveB * tangentAmp * amplitude * 0.35);\n"
		"    float4 pos = float4(displaced, 1.0);\n"
		"    float4 clip = float4(dot(SkinMVP0, pos), dot(SkinMVP1, pos), dot(SkinMVP2, pos), dot(SkinMVP3, pos));\n"
		"    float fogDistance = length(clip.xyz);\n"
		"    float fogAmount = saturate((FogParam.x - fogDistance) / max(FogParam.y, 0.000001));\n"
		"    float fogKeep = 1.0 - fogAmount;\n"
		"    output.position = clip;\n"
		"    output.texcoord = input.texcoord;\n"
		"#ifdef USE_VERTEX_COLOR\n"
		"    output.color = input.color;\n"
		"#else\n"
		"    output.color = 1.0;\n"
		"#endif\n"
		"    output.tangent = skinnedTangent;\n"
		"    output.binormal = skinnedBinormal;\n"
		"    output.normal = skinnedNormal;\n"
		"    output.sourcePosition = displaced;\n"
		"#ifdef USE_PROJ_SHADOW\n"
		"    float shadowW = dot(ShadowProj3, pos);\n"
		"    float3 shadowTransform = shadowW * ShadowProjTransform.xyw;\n"
		"    float2 shadowClip = float2(dot(ShadowProj0, pos), dot(ShadowProj1, pos));\n"
		"    float2 shadowProjected = shadowClip - ShadowProjData.xy;\n"
		"    float invShadowW = rcp(max(abs(shadowTransform.z), 0.000001)) * (shadowTransform.z < 0.0 ? -1.0 : 1.0);\n"
		"    float invShadowDataW = rcp(max(abs(ShadowProjData.w), 0.000001)) * (ShadowProjData.w < 0.0 ? -1.0 : 1.0);\n"
		"    output.shadow.xy = (shadowTransform.xy + shadowClip) * invShadowW;\n"
		"    output.shadow.z = shadowProjected.x * invShadowDataW;\n"
		"    output.shadow.w = 1.0 - shadowProjected.y * invShadowDataW;\n"
		"#endif\n"
		"    output.fog.xyz = FogColor.xyz;\n"
		"    output.fog.w = fogKeep * FogParam.z;\n"
		"    return output;\n"
		"}\n"
		"\n";

	const char* kLighting30EnvMapObjectVertexShader =
		"float4 MVP0 : register(c0);\n"
		"float4 MVP1 : register(c1);\n"
		"float4 MVP2 : register(c2);\n"
		"float4 MVP3 : register(c3);\n"
		"float4 ObjToCube0 : register(c10);\n"
		"float4 ObjToCube1 : register(c11);\n"
		"float4 ObjToCube2 : register(c12);\n"
		"float4 EyePosition : register(c14);\n"
		"float4 MoonSugar0 : register(c26);\n"
		"float4 MoonSugar1 : register(c27);\n"
		"struct VSIn\n"
		"{\n"
		"    float4 position : POSITION0;\n"
		"    float2 texcoord : TEXCOORD0;\n"
		"    float3 normal : NORMAL0;\n"
		"    float3 tangent : TANGENT0;\n"
		"    float3 binormal : BINORMAL0;\n"
		"#ifdef USE_VERTEX_COLOR\n"
		"    float4 color : COLOR0;\n"
		"#endif\n"
		"};\n"
		"struct VSOut\n"
		"{\n"
		"    float4 position : POSITION0;\n"
		"    float2 texcoord : TEXCOORD0;\n"
		"    float4 cubeRow0 : TEXCOORD1;\n"
		"    float4 cubeRow1 : TEXCOORD2;\n"
		"    float4 cubeRow2 : TEXCOORD3;\n"
		"    float3 color : COLOR0;\n"
		"};\n"
		"float SmoothTri(float x)\n"
		"{\n"
		"    float y = abs(frac(x) * 2.0 - 1.0);\n"
		"    y = y * y * (3.0 - 2.0 * y);\n"
		"    return y * 2.0 - 1.0;\n"
		"}\n"
		"float3 SafeNormalize(float3 v)\n"
		"{\n"
		"    return v * rsqrt(max(dot(v, v), 0.000001));\n"
		"}\n"
		"float3 ApplyMoonSugar(float3 basePos, float3 tangent, float3 binormal, float3 normal)\n"
		"{\n"
		"    float time = MoonSugar0.x;\n"
		"    float intensity = saturate(MoonSugar0.y);\n"
		"    float amplitude = MoonSugar0.z * intensity;\n"
		"    float speed = MoonSugar0.w;\n"
		"    float normalAmp = MoonSugar1.x;\n"
		"    float tangentAmp = MoonSugar1.y;\n"
		"    float frequency = MoonSugar1.z;\n"
		"    float phase = MoonSugar1.w;\n"
		"    float waveA = SmoothTri(dot(basePos, float3(0.017, 0.011, 0.007)) * frequency + time * speed + phase);\n"
		"    float waveB = SmoothTri(dot(basePos, float3(-0.009, 0.015, 0.013)) * frequency - time * speed * 0.63 + phase * 1.71);\n"
		"    float3 displaced = basePos + SafeNormalize(normal) * (waveA * normalAmp * amplitude);\n"
		"    displaced += SafeNormalize(tangent) * (waveB * tangentAmp * amplitude);\n"
		"    displaced += SafeNormalize(binormal) * (waveA * waveB * tangentAmp * amplitude * 0.35);\n"
		"    return displaced;\n"
		"}\n"
		"VSOut MoonSugarVS(VSIn input)\n"
		"{\n"
		"    VSOut output;\n"
		"    float3 displaced = ApplyMoonSugar(input.position.xyz, input.tangent, input.binormal, input.normal);\n"
		"    float4 pos = float4(displaced, input.position.w);\n"
		"    output.position = float4(dot(MVP0, pos), dot(MVP1, pos), dot(MVP2, pos), dot(MVP3, pos));\n"
		"    float3 cubePos = float3(dot(ObjToCube0, pos), dot(ObjToCube1, pos), dot(ObjToCube2, pos));\n"
		"    float3 viewCube = EyePosition.xyz - cubePos;\n"
		"    output.texcoord = input.texcoord;\n"
		"    output.cubeRow0 = float4(dot(input.tangent, ObjToCube0.xyz), dot(input.binormal, ObjToCube0.xyz), dot(input.normal, ObjToCube0.xyz), viewCube.x);\n"
		"    output.cubeRow1 = float4(dot(input.tangent, ObjToCube1.xyz), dot(input.binormal, ObjToCube1.xyz), dot(input.normal, ObjToCube1.xyz), viewCube.y);\n"
		"    output.cubeRow2 = float4(dot(input.tangent, ObjToCube2.xyz), dot(input.binormal, ObjToCube2.xyz), dot(input.normal, ObjToCube2.xyz), viewCube.z);\n"
		"#ifdef USE_VERTEX_COLOR\n"
		"    output.color = input.color.xyz;\n"
		"#else\n"
		"    output.color = 1.0;\n"
		"#endif\n"
		"    return output;\n"
		"}\n"
		"\n";

	const char* kLighting30EnvMapSkinnedObjectVertexShader =
		"float4 SkinMVP0 : register(c1);\n"
		"float4 SkinMVP1 : register(c2);\n"
		"float4 SkinMVP2 : register(c3);\n"
		"float4 SkinMVP3 : register(c4);\n"
		"float4 EyePosition : register(c14);\n"
		"float4 MoonSugar0 : register(c24);\n"
		"float4 MoonSugar1 : register(c25);\n"
		"float4 SkinToCube0 : register(c27);\n"
		"float4 SkinToCube1 : register(c28);\n"
		"float4 SkinToCube2 : register(c29);\n"
		"float4 Bones[54] : register(c31);\n"
		"struct VSIn\n"
		"{\n"
		"    float4 position : POSITION0;\n"
		"    float2 texcoord : TEXCOORD0;\n"
		"    float3 normal : NORMAL0;\n"
		"    float3 tangent : TANGENT0;\n"
		"    float3 binormal : BINORMAL0;\n"
		"#ifdef USE_VERTEX_COLOR\n"
		"    float4 color : COLOR0;\n"
		"#endif\n"
		"    float4 blendWeights : BLENDWEIGHT0;\n"
		"    float4 blendIndices : BLENDINDICES0;\n"
		"};\n"
		"struct VSOut\n"
		"{\n"
		"    float4 position : POSITION0;\n"
		"    float2 texcoord : TEXCOORD0;\n"
		"    float4 cubeRow0 : TEXCOORD1;\n"
		"    float4 cubeRow1 : TEXCOORD2;\n"
		"    float4 cubeRow2 : TEXCOORD3;\n"
		"    float3 color : COLOR0;\n"
		"};\n"
		"float SmoothTri(float x)\n"
		"{\n"
		"    float y = abs(frac(x) * 2.0 - 1.0);\n"
		"    y = y * y * (3.0 - 2.0 * y);\n"
		"    return y * 2.0 - 1.0;\n"
		"}\n"
		"float3 SafeNormalize(float3 v)\n"
		"{\n"
		"    return v * rsqrt(max(dot(v, v), 0.000001));\n"
		"}\n"
		"float3 SkinVector(float3 value, float index)\n"
		"{\n"
		"    int row = (int)index;\n"
		"    return float3(dot(Bones[row].xyz, value), dot(Bones[row + 1].xyz, value), dot(Bones[row + 2].xyz, value));\n"
		"}\n"
		"float3 SkinPosition(float3 value, float index)\n"
		"{\n"
		"    int row = (int)index;\n"
		"    float4 pos = float4(value, 1.0);\n"
		"    return float3(dot(Bones[row], pos), dot(Bones[row + 1], pos), dot(Bones[row + 2], pos));\n"
		"}\n"
		"float3 BlendVector(float3 value, float4 indices, float4 weights)\n"
		"{\n"
		"    float3 blended = SkinVector(value, indices.y) * weights.y;\n"
		"    blended += SkinVector(value, indices.x) * weights.x;\n"
		"    blended += SkinVector(value, indices.z) * weights.z;\n"
		"    blended += SkinVector(value, indices.w) * weights.w;\n"
		"    return blended;\n"
		"}\n"
		"float3 BlendPosition(float3 value, float4 indices, float4 weights)\n"
		"{\n"
		"    float3 blended = SkinPosition(value, indices.y) * weights.y;\n"
		"    blended += SkinPosition(value, indices.x) * weights.x;\n"
		"    blended += SkinPosition(value, indices.z) * weights.z;\n"
		"    blended += SkinPosition(value, indices.w) * weights.w;\n"
		"    return blended;\n"
		"}\n"
		"float3 ApplyMoonSugar(float3 basePos, float3 tangent, float3 binormal, float3 normal)\n"
		"{\n"
		"    float time = MoonSugar0.x;\n"
		"    float intensity = saturate(MoonSugar0.y);\n"
		"    float amplitude = MoonSugar0.z * intensity;\n"
		"    float speed = MoonSugar0.w;\n"
		"    float normalAmp = MoonSugar1.x;\n"
		"    float tangentAmp = MoonSugar1.y;\n"
		"    float frequency = MoonSugar1.z;\n"
		"    float phase = MoonSugar1.w;\n"
		"    float waveA = SmoothTri(dot(basePos, float3(0.017, 0.011, 0.007)) * frequency + time * speed + phase);\n"
		"    float waveB = SmoothTri(dot(basePos, float3(-0.009, 0.015, 0.013)) * frequency - time * speed * 0.63 + phase * 1.71);\n"
		"    float3 displaced = basePos + normal * (waveA * normalAmp * amplitude);\n"
		"    displaced += tangent * (waveB * tangentAmp * amplitude);\n"
		"    displaced += binormal * (waveA * waveB * tangentAmp * amplitude * 0.35);\n"
		"    return displaced;\n"
		"}\n"
		"VSOut MoonSugarVS(VSIn input)\n"
		"{\n"
		"    VSOut output;\n"
		"    float4 indices = floor(input.blendIndices.zyxw * 765.01001);\n"
		"    float4 weights = float4(input.blendWeights.xyz, 1.0 - dot(input.blendWeights.xyz, 1.0));\n"
		"    float3 skinnedPos = BlendPosition(input.position.xyz, indices, weights);\n"
		"    float3 skinnedTangent = SafeNormalize(BlendVector(input.tangent, indices, weights));\n"
		"    float3 skinnedBinormal = SafeNormalize(BlendVector(input.binormal, indices, weights));\n"
		"    float3 skinnedNormal = SafeNormalize(BlendVector(input.normal, indices, weights));\n"
		"    float3 displaced = ApplyMoonSugar(skinnedPos, skinnedTangent, skinnedBinormal, skinnedNormal);\n"
		"    float4 pos = float4(displaced, 1.0);\n"
		"    output.position = float4(dot(SkinMVP0, pos), dot(SkinMVP1, pos), dot(SkinMVP2, pos), dot(SkinMVP3, pos));\n"
		"    float3 cubePos = float3(dot(SkinToCube0, pos), dot(SkinToCube1, pos), dot(SkinToCube2, pos));\n"
		"    float3 viewCube = EyePosition.xyz - cubePos;\n"
		"    output.texcoord = input.texcoord;\n"
		"    output.cubeRow0 = float4(dot(skinnedTangent, SkinToCube0.xyz), dot(skinnedBinormal, SkinToCube0.xyz), dot(skinnedNormal, SkinToCube0.xyz), viewCube.x);\n"
		"    output.cubeRow1 = float4(dot(skinnedTangent, SkinToCube1.xyz), dot(skinnedBinormal, SkinToCube1.xyz), dot(skinnedNormal, SkinToCube1.xyz), viewCube.y);\n"
		"    output.cubeRow2 = float4(dot(skinnedTangent, SkinToCube2.xyz), dot(skinnedBinormal, SkinToCube2.xyz), dot(skinnedNormal, SkinToCube2.xyz), viewCube.z);\n"
		"#ifdef USE_VERTEX_COLOR\n"
		"    output.color = input.color.xyz;\n"
		"#else\n"
		"    output.color = 1.0;\n"
		"#endif\n"
		"    return output;\n"
		"}\n"
		"\n";

	const char* kLighting30EnvMapSpecialObjectVertexShader =
		"float4 MVP0 : register(c0);\n"
		"float4 MVP1 : register(c1);\n"
		"float4 MVP2 : register(c2);\n"
		"float4 MVP3 : register(c3);\n"
		"float4 ObjToCube0 : register(c10);\n"
		"float4 ObjToCube1 : register(c11);\n"
		"float4 ObjToCube2 : register(c12);\n"
		"float4 EyePosition : register(c14);\n"
		"float4 BoundWorldCenter : register(c20);\n"
		"float4 MoonSugar0 : register(c26);\n"
		"float4 MoonSugar1 : register(c27);\n"
		"struct VSIn\n"
		"{\n"
		"    float4 position : POSITION0;\n"
		"    float2 texcoord : TEXCOORD0;\n"
		"};\n"
		"struct VSOut\n"
		"{\n"
		"    float4 position : POSITION0;\n"
		"    float2 texcoord : TEXCOORD0;\n"
		"    float4 cubeLookup : TEXCOORD1;\n"
		"    float3 viewVector : TEXCOORD2;\n"
		"    float3 color : COLOR0;\n"
		"};\n"
		"float SmoothTri(float x)\n"
		"{\n"
		"    float y = abs(frac(x) * 2.0 - 1.0);\n"
		"    y = y * y * (3.0 - 2.0 * y);\n"
		"    return y * 2.0 - 1.0;\n"
		"}\n"
		"float3 SafeNormalize(float3 v)\n"
		"{\n"
		"    return v * rsqrt(max(dot(v, v), 0.000001));\n"
		"}\n"
		"VSOut MoonSugarVS(VSIn input)\n"
		"{\n"
		"    VSOut output;\n"
		"    float3 basePos = input.position.xyz;\n"
		"    float time = MoonSugar0.x;\n"
		"    float intensity = saturate(MoonSugar0.y);\n"
		"    float amplitude = MoonSugar0.z * intensity;\n"
		"    float speed = MoonSugar0.w;\n"
		"    float normalAmp = MoonSugar1.x;\n"
		"    float frequency = MoonSugar1.z;\n"
		"    float phase = MoonSugar1.w;\n"
		"    float wave = SmoothTri(dot(basePos, float3(0.017, 0.011, 0.007)) * frequency + time * speed + phase);\n"
		"    float3 displaced = basePos + SafeNormalize(basePos) * (wave * normalAmp * amplitude);\n"
		"    float4 pos = float4(displaced, input.position.w);\n"
		"    output.position = float4(dot(MVP0, pos), dot(MVP1, pos), dot(MVP2, pos), dot(MVP3, pos));\n"
		"    float3 cubePos = float3(dot(ObjToCube0, pos), dot(ObjToCube1, pos), dot(ObjToCube2, pos));\n"
		"    float3 fromCenter = cubePos - BoundWorldCenter.xyz;\n"
		"    float3 viewVector = EyePosition.xyz - cubePos;\n"
		"    float3 centerDir = SafeNormalize(fromCenter);\n"
		"    float3 viewDir = SafeNormalize(viewVector);\n"
		"    float rim = saturate((dot(centerDir, viewDir) - 0.8) * 6.66666651);\n"
		"    float rimSmooth = rim * rim * (3.0 - 2.0 * rim);\n"
		"    output.texcoord = input.texcoord;\n"
		"    output.cubeLookup.xyz = centerDir * 0.5 + 0.5;\n"
		"    output.cubeLookup.w = rimSmooth;\n"
		"    output.viewVector = viewVector;\n"
		"    output.color = 1.0;\n"
		"    return output;\n"
		"}\n"
		"\n";

	const char* kLighting30TexEffectObjectVertexShader =
		"float4 MVP0 : register(c0);\n"
		"float4 MVP1 : register(c1);\n"
		"float4 MVP2 : register(c2);\n"
		"float4 MVP3 : register(c3);\n"
		"float4 EyePosition : register(c8);\n"
		"float4 UOffset : register(c9);\n"
		"float4 VOffset : register(c10);\n"
		"float4 FogParam : register(c12);\n"
		"float4 FogColor : register(c13);\n"
		"float4 MoonSugar0 : register(c26);\n"
		"float4 MoonSugar1 : register(c27);\n"
		"struct VSIn\n"
		"{\n"
		"    float4 position : POSITION0;\n"
		"    float3 tangent : TANGENT0;\n"
		"    float3 binormal : BINORMAL0;\n"
		"    float3 normal : NORMAL0;\n"
		"    float2 texcoord : TEXCOORD0;\n"
		"};\n"
		"struct VSOut\n"
		"{\n"
		"    float4 position : POSITION0;\n"
		"    float2 texcoord : TEXCOORD0;\n"
		"    float2 sourceTexcoord : TEXCOORD1;\n"
		"    float3 viewVector : TEXCOORD3;\n"
		"    float4 fogColor : COLOR1;\n"
		"};\n"
		"float SmoothTri(float x)\n"
		"{\n"
		"    float y = abs(frac(x) * 2.0 - 1.0);\n"
		"    y = y * y * (3.0 - 2.0 * y);\n"
		"    return y * 2.0 - 1.0;\n"
		"}\n"
		"float3 SafeNormalize(float3 v)\n"
		"{\n"
		"    return v * rsqrt(max(dot(v, v), 0.000001));\n"
		"}\n"
		"float ApproxTexEffectAngle(float2 xy)\n"
		"{\n"
		"    float ax = abs(xy.x);\n"
		"    float ay = abs(xy.y);\n"
		"    float minorOverMajor = min(ax, ay) / max(max(ax, ay), 0.000001);\n"
		"    float squared = minorOverMajor * minorOverMajor;\n"
		"    float polynomial = (((0.0208350997 * squared - 0.0851330012) * squared + 0.180141002) * squared - 0.330299497) * squared + 0.999866009;\n"
		"    float baseAngle = minorOverMajor * polynomial;\n"
		"    float angle = baseAngle + ((ay < ax) ? (1.57079637 - 2.0 * baseAngle) : 0.0);\n"
		"    angle += (xy.y < -xy.y) ? -3.14159274 : 0.0;\n"
		"    float oppositeSigns = ((min(xy.y, xy.x) < -min(xy.y, xy.x)) && (max(xy.y, xy.x) >= -max(xy.y, xy.x))) ? 1.0 : 0.0;\n"
		"    return angle + oppositeSigns * (-2.0 * angle);\n"
		"}\n"
		"float2 BuildSourceTexcoord(float3 sourcePosition)\n"
		"{\n"
		"    return float2(ApproxTexEffectAngle(sourcePosition.xy) * 0.318471342 + VOffset.x, sourcePosition.z * 0.0250000004 + UOffset.x);\n"
		"}\n"
		"float3 ApplyMoonSugar(float3 basePos, float3 tangent, float3 binormal, float3 normal)\n"
		"{\n"
		"    float time = MoonSugar0.x;\n"
		"    float intensity = saturate(MoonSugar0.y);\n"
		"    float amplitude = MoonSugar0.z * intensity;\n"
		"    float speed = MoonSugar0.w;\n"
		"    float normalAmp = MoonSugar1.x;\n"
		"    float tangentAmp = MoonSugar1.y;\n"
		"    float frequency = MoonSugar1.z;\n"
		"    float phase = MoonSugar1.w;\n"
		"    float waveA = SmoothTri(dot(basePos, float3(0.017, 0.011, 0.007)) * frequency + time * speed + phase);\n"
		"    float waveB = SmoothTri(dot(basePos, float3(-0.009, 0.015, 0.013)) * frequency - time * speed * 0.63 + phase * 1.71);\n"
		"    float3 displaced = basePos + SafeNormalize(normal) * (waveA * normalAmp * amplitude);\n"
		"    displaced += SafeNormalize(tangent) * (waveB * tangentAmp * amplitude);\n"
		"    displaced += SafeNormalize(binormal) * (waveA * waveB * tangentAmp * amplitude * 0.35);\n"
		"    return displaced;\n"
		"}\n"
		"float3 BuildViewVector(float3 displaced, float3 tangent, float3 binormal, float3 normal)\n"
		"{\n"
		"    float3 view = EyePosition.xyz - displaced;\n"
		"    float3 orientedView = (dot(normal, view) < 1.0) ? -view : view;\n"
		"    return SafeNormalize(float3(dot(tangent, orientedView), dot(binormal, orientedView), dot(normal, orientedView)));\n"
		"}\n"
		"VSOut MoonSugarVS(VSIn input)\n"
		"{\n"
		"    VSOut output;\n"
		"    float3 displaced = ApplyMoonSugar(input.position.xyz, input.tangent, input.binormal, input.normal);\n"
		"    float4 pos = float4(displaced, input.position.w);\n"
		"    float4 clip = float4(dot(MVP0, pos), dot(MVP1, pos), dot(MVP2, pos), dot(MVP3, pos));\n"
		"    float fogAmount = saturate((FogParam.x - length(clip.xyz)) / max(FogParam.y, 0.000001));\n"
		"    output.position = clip;\n"
		"    output.texcoord = input.texcoord;\n"
		"    output.sourceTexcoord = BuildSourceTexcoord(displaced);\n"
		"    output.viewVector = BuildViewVector(displaced, input.tangent, input.binormal, input.normal);\n"
		"    output.fogColor.xyz = FogColor.xyz;\n"
		"    output.fogColor.w = (1.0 - fogAmount) * ((0.0 < FogParam.z) ? 1.0 : 0.0);\n"
		"    return output;\n"
		"}\n"
		"\n";

	const char* kLighting30TexEffectSkinnedObjectVertexShader =
		"float4 SkinMVP0 : register(c4);\n"
		"float4 SkinMVP1 : register(c5);\n"
		"float4 SkinMVP2 : register(c6);\n"
		"float4 SkinMVP3 : register(c7);\n"
		"float4 EyePosition : register(c8);\n"
		"float4 UOffset : register(c9);\n"
		"float4 VOffset : register(c10);\n"
		"float4 FogParam : register(c12);\n"
		"float4 FogColor : register(c13);\n"
		"float4 Bones[54] : register(c14);\n"
		"float4 MoonSugar0 : register(c68);\n"
		"float4 MoonSugar1 : register(c69);\n"
		"struct VSIn\n"
		"{\n"
		"    float4 position : POSITION0;\n"
		"    float3 tangent : TANGENT0;\n"
		"    float3 binormal : BINORMAL0;\n"
		"    float3 normal : NORMAL0;\n"
		"    float2 texcoord : TEXCOORD0;\n"
		"    float4 blendWeights : BLENDWEIGHT0;\n"
		"    float4 blendIndices : BLENDINDICES0;\n"
		"};\n"
		"struct VSOut\n"
		"{\n"
		"    float4 position : POSITION0;\n"
		"    float2 texcoord : TEXCOORD0;\n"
		"    float2 sourceTexcoord : TEXCOORD1;\n"
		"    float3 viewVector : TEXCOORD3;\n"
		"    float4 fogColor : COLOR1;\n"
		"};\n"
		"float SmoothTri(float x)\n"
		"{\n"
		"    float y = abs(frac(x) * 2.0 - 1.0);\n"
		"    y = y * y * (3.0 - 2.0 * y);\n"
		"    return y * 2.0 - 1.0;\n"
		"}\n"
		"float3 SafeNormalize(float3 v)\n"
		"{\n"
		"    return v * rsqrt(max(dot(v, v), 0.000001));\n"
		"}\n"
		"float3 SkinVector(float3 value, float index)\n"
		"{\n"
		"    int row = (int)index;\n"
		"    return float3(dot(Bones[row].xyz, value), dot(Bones[row + 1].xyz, value), dot(Bones[row + 2].xyz, value));\n"
		"}\n"
		"float3 SkinPosition(float3 value, float index)\n"
		"{\n"
		"    int row = (int)index;\n"
		"    float4 pos = float4(value, 1.0);\n"
		"    return float3(dot(Bones[row], pos), dot(Bones[row + 1], pos), dot(Bones[row + 2], pos));\n"
		"}\n"
		"float3 BlendVector(float3 value, float4 indices, float4 weights)\n"
		"{\n"
		"    float3 blended = SkinVector(value, indices.y) * weights.y;\n"
		"    blended += SkinVector(value, indices.x) * weights.x;\n"
		"    blended += SkinVector(value, indices.z) * weights.z;\n"
		"    blended += SkinVector(value, indices.w) * weights.w;\n"
		"    return blended;\n"
		"}\n"
		"float3 BlendPosition(float3 value, float4 indices, float4 weights)\n"
		"{\n"
		"    float3 blended = SkinPosition(value, indices.y) * weights.y;\n"
		"    blended += SkinPosition(value, indices.x) * weights.x;\n"
		"    blended += SkinPosition(value, indices.z) * weights.z;\n"
		"    blended += SkinPosition(value, indices.w) * weights.w;\n"
		"    return blended;\n"
		"}\n"
		"float ApproxTexEffectAngle(float2 xy)\n"
		"{\n"
		"    float ax = abs(xy.x);\n"
		"    float ay = abs(xy.y);\n"
		"    float minorOverMajor = min(ax, ay) / max(max(ax, ay), 0.000001);\n"
		"    float squared = minorOverMajor * minorOverMajor;\n"
		"    float polynomial = (((0.0208350997 * squared - 0.0851330012) * squared + 0.180141002) * squared - 0.330299497) * squared + 0.999866009;\n"
		"    float baseAngle = minorOverMajor * polynomial;\n"
		"    float angle = baseAngle + ((ay < ax) ? (1.57079637 - 2.0 * baseAngle) : 0.0);\n"
		"    angle += (xy.y < -xy.y) ? -3.14159274 : 0.0;\n"
		"    float oppositeSigns = ((min(xy.y, xy.x) < -min(xy.y, xy.x)) && (max(xy.y, xy.x) >= -max(xy.y, xy.x))) ? 1.0 : 0.0;\n"
		"    return angle + oppositeSigns * (-2.0 * angle);\n"
		"}\n"
		"float2 BuildSourceTexcoord(float3 sourcePosition)\n"
		"{\n"
		"    return float2(ApproxTexEffectAngle(sourcePosition.xy) * 0.318471342 + VOffset.x, sourcePosition.z * 0.0250000004 + UOffset.x);\n"
		"}\n"
		"float3 ApplyMoonSugar(float3 basePos, float3 tangent, float3 binormal, float3 normal)\n"
		"{\n"
		"    float time = MoonSugar0.x;\n"
		"    float intensity = saturate(MoonSugar0.y);\n"
		"    float amplitude = MoonSugar0.z * intensity;\n"
		"    float speed = MoonSugar0.w;\n"
		"    float normalAmp = MoonSugar1.x;\n"
		"    float tangentAmp = MoonSugar1.y;\n"
		"    float frequency = MoonSugar1.z;\n"
		"    float phase = MoonSugar1.w;\n"
		"    float waveA = SmoothTri(dot(basePos, float3(0.017, 0.011, 0.007)) * frequency + time * speed + phase);\n"
		"    float waveB = SmoothTri(dot(basePos, float3(-0.009, 0.015, 0.013)) * frequency - time * speed * 0.63 + phase * 1.71);\n"
		"    float3 displaced = basePos + normal * (waveA * normalAmp * amplitude);\n"
		"    displaced += tangent * (waveB * tangentAmp * amplitude);\n"
		"    displaced += binormal * (waveA * waveB * tangentAmp * amplitude * 0.35);\n"
		"    return displaced;\n"
		"}\n"
		"float3 BuildViewVector(float3 displaced, float3 tangent, float3 binormal, float3 normal)\n"
		"{\n"
		"    float3 view = EyePosition.xyz - displaced;\n"
		"    float3 orientedView = (dot(normal, view) < 1.0) ? -view : view;\n"
		"    return SafeNormalize(float3(dot(tangent, orientedView), dot(binormal, orientedView), dot(normal, orientedView)));\n"
		"}\n"
		"VSOut MoonSugarVS(VSIn input)\n"
		"{\n"
		"    VSOut output;\n"
		"    float4 indices = floor(input.blendIndices.zyxw * 765.01001);\n"
		"    float4 weights = float4(input.blendWeights.xyz, 1.0 - dot(input.blendWeights.xyz, 1.0));\n"
		"    float3 skinnedPos = BlendPosition(input.position.xyz, indices, weights);\n"
		"    float3 skinnedTangent = SafeNormalize(BlendVector(input.tangent, indices, weights));\n"
		"    float3 skinnedBinormal = SafeNormalize(BlendVector(input.binormal, indices, weights));\n"
		"    float3 skinnedNormal = SafeNormalize(BlendVector(input.normal, indices, weights));\n"
		"    float3 displaced = ApplyMoonSugar(skinnedPos, skinnedTangent, skinnedBinormal, skinnedNormal);\n"
		"    float4 pos = float4(displaced, 1.0);\n"
		"    float4 clip = float4(dot(SkinMVP0, pos), dot(SkinMVP1, pos), dot(SkinMVP2, pos), dot(SkinMVP3, pos));\n"
		"    float fogAmount = saturate((FogParam.x - length(clip.xyz)) / max(FogParam.y, 0.000001));\n"
		"    output.position = clip;\n"
		"    output.texcoord = input.texcoord;\n"
		"    output.sourceTexcoord = BuildSourceTexcoord(displaced);\n"
		"    output.viewVector = BuildViewVector(displaced, skinnedTangent, skinnedBinormal, skinnedNormal);\n"
		"    output.fogColor.xyz = FogColor.xyz;\n"
		"    output.fogColor.w = (1.0 - fogAmount) * ((0.0 < FogParam.z) ? 1.0 : 0.0);\n"
		"    return output;\n"
		"}\n"
		"\n";

	const char* kLighting30DepthMapObjectVertexShader =
		"float4 MVP0 : register(c0);\n"
		"float4 MVP1 : register(c1);\n"
		"float4 MVP2 : register(c2);\n"
		"float4 MVP3 : register(c3);\n"
		"float4 WorldView0 : register(c5);\n"
		"float4 WorldView1 : register(c6);\n"
		"float4 WorldView2 : register(c7);\n"
		"float4 MoonSugar0 : register(c26);\n"
		"float4 MoonSugar1 : register(c27);\n"
		"struct VSIn\n"
		"{\n"
		"    float4 position : POSITION0;\n"
		"    float2 texcoord : TEXCOORD0;\n"
		"};\n"
		"struct VSOut\n"
		"{\n"
		"    float4 position : POSITION0;\n"
		"    float2 texcoord : TEXCOORD0;\n"
		"    float4 viewDepth : TEXCOORD1;\n"
		"};\n"
		"float SmoothTri(float x)\n"
		"{\n"
		"    float y = abs(frac(x) * 2.0 - 1.0);\n"
		"    y = y * y * (3.0 - 2.0 * y);\n"
		"    return y * 2.0 - 1.0;\n"
		"}\n"
		"float3 SafeNormalize(float3 v)\n"
		"{\n"
		"    return v * rsqrt(max(dot(v, v), 0.000001));\n"
		"}\n"
		"float3 ApplyMoonSugar(float3 basePos)\n"
		"{\n"
		"    float3 axisNormal = SafeNormalize(basePos);\n"
		"    float3 axisTangent = SafeNormalize(float3(axisNormal.y + 0.11, -axisNormal.x + 0.17, axisNormal.z * 0.31 + 0.07));\n"
		"    float3 axisBinormal = SafeNormalize(float3(-axisNormal.z + 0.13, axisNormal.y * 0.37 + 0.19, axisNormal.x + 0.23));\n"
		"    float time = MoonSugar0.x;\n"
		"    float intensity = saturate(MoonSugar0.y);\n"
		"    float amplitude = MoonSugar0.z * intensity;\n"
		"    float speed = MoonSugar0.w;\n"
		"    float normalAmp = MoonSugar1.x;\n"
		"    float tangentAmp = MoonSugar1.y;\n"
		"    float frequency = MoonSugar1.z;\n"
		"    float phase = MoonSugar1.w;\n"
		"    float waveA = SmoothTri(dot(basePos, float3(0.017, 0.011, 0.007)) * frequency + time * speed + phase);\n"
		"    float waveB = SmoothTri(dot(basePos, float3(-0.009, 0.015, 0.013)) * frequency - time * speed * 0.63 + phase * 1.71);\n"
		"    float3 displaced = basePos + axisNormal * (waveA * normalAmp * amplitude);\n"
		"    displaced += axisTangent * (waveB * tangentAmp * amplitude);\n"
		"    displaced += axisBinormal * (waveA * waveB * tangentAmp * amplitude * 0.35);\n"
		"    return displaced;\n"
		"}\n"
		"VSOut MoonSugarVS(VSIn input)\n"
		"{\n"
		"    VSOut output;\n"
		"    float3 displaced = ApplyMoonSugar(input.position.xyz);\n"
		"    float4 pos = float4(displaced, input.position.w);\n"
		"    output.position = float4(dot(MVP0, pos), dot(MVP1, pos), dot(MVP2, pos), dot(MVP3, pos));\n"
		"    output.texcoord = input.texcoord;\n"
		"    output.viewDepth.x = dot(WorldView0, pos);\n"
		"    output.viewDepth.y = dot(WorldView1, pos);\n"
		"    output.viewDepth.z = dot(WorldView2, pos);\n"
		"    output.viewDepth.w = 0.0;\n"
		"    return output;\n"
		"}\n"
		"\n";

	const char* kLighting30DepthMapSkinnedObjectVertexShader =
		"float4 SkinMVP0 : register(c1);\n"
		"float4 SkinMVP1 : register(c2);\n"
		"float4 SkinMVP2 : register(c3);\n"
		"float4 SkinMVP3 : register(c4);\n"
		"float4 SkinWorldView0 : register(c6);\n"
		"float4 SkinWorldView1 : register(c7);\n"
		"float4 SkinWorldView2 : register(c8);\n"
		"float4 MoonSugar0 : register(c27);\n"
		"float4 MoonSugar1 : register(c28);\n"
		"float4 Bones[54] : register(c31);\n"
		"struct VSIn\n"
		"{\n"
		"    float4 position : POSITION0;\n"
		"    float2 texcoord : TEXCOORD0;\n"
		"    float4 blendWeights : BLENDWEIGHT0;\n"
		"    float4 blendIndices : BLENDINDICES0;\n"
		"};\n"
		"struct VSOut\n"
		"{\n"
		"    float4 position : POSITION0;\n"
		"    float2 texcoord : TEXCOORD0;\n"
		"    float4 viewDepth : TEXCOORD1;\n"
		"};\n"
		"float SmoothTri(float x)\n"
		"{\n"
		"    float y = abs(frac(x) * 2.0 - 1.0);\n"
		"    y = y * y * (3.0 - 2.0 * y);\n"
		"    return y * 2.0 - 1.0;\n"
		"}\n"
		"float3 SafeNormalize(float3 v)\n"
		"{\n"
		"    return v * rsqrt(max(dot(v, v), 0.000001));\n"
		"}\n"
		"float3 SkinPosition(float3 value, float index)\n"
		"{\n"
		"    int row = (int)index;\n"
		"    float4 pos = float4(value, 1.0);\n"
		"    return float3(dot(Bones[row], pos), dot(Bones[row + 1], pos), dot(Bones[row + 2], pos));\n"
		"}\n"
		"float3 BlendPosition(float3 value, float4 indices, float4 weights)\n"
		"{\n"
		"    float3 blended = SkinPosition(value, indices.y) * weights.y;\n"
		"    blended += SkinPosition(value, indices.x) * weights.x;\n"
		"    blended += SkinPosition(value, indices.z) * weights.z;\n"
		"    blended += SkinPosition(value, indices.w) * weights.w;\n"
		"    return blended;\n"
		"}\n"
		"float3 ApplyMoonSugar(float3 basePos)\n"
		"{\n"
		"    float3 axisNormal = SafeNormalize(basePos);\n"
		"    float3 axisTangent = SafeNormalize(float3(axisNormal.y + 0.11, -axisNormal.x + 0.17, axisNormal.z * 0.31 + 0.07));\n"
		"    float3 axisBinormal = SafeNormalize(float3(-axisNormal.z + 0.13, axisNormal.y * 0.37 + 0.19, axisNormal.x + 0.23));\n"
		"    float time = MoonSugar0.x;\n"
		"    float intensity = saturate(MoonSugar0.y);\n"
		"    float amplitude = MoonSugar0.z * intensity;\n"
		"    float speed = MoonSugar0.w;\n"
		"    float normalAmp = MoonSugar1.x;\n"
		"    float tangentAmp = MoonSugar1.y;\n"
		"    float frequency = MoonSugar1.z;\n"
		"    float phase = MoonSugar1.w;\n"
		"    float waveA = SmoothTri(dot(basePos, float3(0.017, 0.011, 0.007)) * frequency + time * speed + phase);\n"
		"    float waveB = SmoothTri(dot(basePos, float3(-0.009, 0.015, 0.013)) * frequency - time * speed * 0.63 + phase * 1.71);\n"
		"    float3 displaced = basePos + axisNormal * (waveA * normalAmp * amplitude);\n"
		"    displaced += axisTangent * (waveB * tangentAmp * amplitude);\n"
		"    displaced += axisBinormal * (waveA * waveB * tangentAmp * amplitude * 0.35);\n"
		"    return displaced;\n"
		"}\n"
		"VSOut MoonSugarVS(VSIn input)\n"
		"{\n"
		"    VSOut output;\n"
		"    float4 indices = floor(input.blendIndices.zyxw * 765.01001);\n"
		"    float4 weights = float4(input.blendWeights.xyz, 1.0 - dot(input.blendWeights.xyz, 1.0));\n"
		"    float3 skinnedPos = BlendPosition(input.position.xyz, indices, weights);\n"
		"    float3 displaced = ApplyMoonSugar(skinnedPos);\n"
		"    float4 pos = float4(displaced, 1.0);\n"
		"    output.position = float4(dot(SkinMVP0, pos), dot(SkinMVP1, pos), dot(SkinMVP2, pos), dot(SkinMVP3, pos));\n"
		"    output.texcoord = input.texcoord;\n"
		"    output.viewDepth.x = dot(SkinWorldView0, pos);\n"
		"    output.viewDepth.y = dot(SkinWorldView1, pos);\n"
		"    output.viewDepth.z = dot(SkinWorldView2, pos);\n"
		"    output.viewDepth.w = 0.0;\n"
		"    return output;\n"
		"}\n"
		"\n";

	const char* kLighting30SupportObjectVertexShader =
		"#ifdef SKIN\n"
		"float4 SkinMVP0 : register(c1);\n"
		"float4 SkinMVP1 : register(c2);\n"
		"float4 SkinMVP2 : register(c3);\n"
		"float4 SkinMVP3 : register(c4);\n"
		"float4 SkinWorldViewTranspose0 : register(c6);\n"
		"float4 SkinWorldViewTranspose1 : register(c7);\n"
		"float4 SkinWorldViewTranspose2 : register(c8);\n"
		"float4 MoonSugar0 : register(c27);\n"
		"float4 MoonSugar1 : register(c28);\n"
		"float4 Bones[54] : register(c31);\n"
		"#else\n"
		"float4 MVP0 : register(c0);\n"
		"float4 MVP1 : register(c1);\n"
		"float4 MVP2 : register(c2);\n"
		"float4 MVP3 : register(c3);\n"
		"float4 WorldViewTranspose0 : register(c5);\n"
		"float4 WorldViewTranspose1 : register(c6);\n"
		"float4 WorldViewTranspose2 : register(c7);\n"
		"float4 EyePosition : register(c14);\n"
		"float4 TimeParam : register(c19);\n"
		"float4 MoonSugar0 : register(c26);\n"
		"float4 MoonSugar1 : register(c27);\n"
		"#endif\n"
		"#ifdef MODE_SIMPLE_SHADOW\n"
		"float4 ObjToCubeMap0 : register(c10);\n"
		"float4 ObjToCubeMap1 : register(c11);\n"
		"float4 ObjToCubeMap2 : register(c12);\n"
		"float4 ObjToCubeMap3 : register(c13);\n"
		"float4 FogParam : register(c15);\n"
		"float4 FogColor : register(c16);\n"
		"#endif\n"
		"struct VSIn\n"
		"{\n"
		"    float4 position : POSITION0;\n"
		"#ifdef HAS_NORMAL\n"
		"    float3 normal : NORMAL0;\n"
		"#endif\n"
		"#ifdef HAS_UV\n"
		"    float2 texcoord : TEXCOORD0;\n"
		"#endif\n"
		"#ifdef SKIN\n"
		"    float4 blendWeights : BLENDWEIGHT0;\n"
		"    float4 blendIndices : BLENDINDICES0;\n"
		"#endif\n"
		"};\n"
		"struct VSOut\n"
		"{\n"
		"    float4 position : POSITION0;\n"
		"#ifdef MODE_SIMPLE_SHADOW\n"
		"    float2 texcoord : TEXCOORD0;\n"
		"    float3 sourcePosition : TEXCOORD6;\n"
		"    float4 cubeProjection : TEXCOORD1;\n"
		"    float4 fog : TEXCOORD2;\n"
		"#endif\n"
		"#ifdef MODE_ZONLY\n"
		"    float2 texcoord : TEXCOORD0;\n"
		"    float4 color : COLOR0;\n"
		"#endif\n"
		"#ifdef MODE_RENDER_NORMALS\n"
		"    float3 normalTexcoord : TEXCOORD0;\n"
		"    float2 refraction : TEXCOORD1;\n"
		"#endif\n"
		"#ifdef MODE_RENDER_NORMALS_FIRE\n"
		"    float4 fireData : TEXCOORD0;\n"
		"    float firePower : TEXCOORD1;\n"
		"#endif\n"
		"#ifdef MODE_LOCALMAP\n"
		"    float3 localNormal : TEXCOORD0;\n"
		"    float localDepth : TEXCOORD1;\n"
		"#endif\n"
		"};\n"
		"float SmoothTri(float x)\n"
		"{\n"
		"    float y = abs(frac(x) * 2.0 - 1.0);\n"
		"    y = y * y * (3.0 - 2.0 * y);\n"
		"    return y * 2.0 - 1.0;\n"
		"}\n"
		"float3 SafeNormalize(float3 v)\n"
		"{\n"
		"    return v * rsqrt(max(dot(v, v), 0.000001));\n"
		"}\n"
		"float3 BuildFallbackTangent(float3 n)\n"
		"{\n"
		"    float3 helper = (abs(n.z) < 0.75) ? float3(0.0, 0.0, 1.0) : float3(0.0, 1.0, 0.0);\n"
		"    return SafeNormalize(cross(helper, n));\n"
		"}\n"
		"float3 ApplyMoonSugarWithBasis(float3 basePos, float3 axisNormal, float3 axisTangent, float3 axisBinormal)\n"
		"{\n"
		"    float time = MoonSugar0.x;\n"
		"    float intensity = saturate(MoonSugar0.y);\n"
		"    float amplitude = MoonSugar0.z * intensity;\n"
		"    float speed = MoonSugar0.w;\n"
		"    float normalAmp = MoonSugar1.x;\n"
		"    float tangentAmp = MoonSugar1.y;\n"
		"    float frequency = MoonSugar1.z;\n"
		"    float phase = MoonSugar1.w;\n"
		"    float waveA = SmoothTri(dot(basePos, float3(0.017, 0.011, 0.007)) * frequency + time * speed + phase);\n"
		"    float waveB = SmoothTri(dot(basePos, float3(-0.009, 0.015, 0.013)) * frequency - time * speed * 0.63 + phase * 1.71);\n"
		"    float3 displaced = basePos + axisNormal * (waveA * normalAmp * amplitude);\n"
		"    displaced += axisTangent * (waveB * tangentAmp * amplitude);\n"
		"    displaced += axisBinormal * (waveA * waveB * tangentAmp * amplitude * 0.35);\n"
		"    return displaced;\n"
		"}\n"
		"float3 ApplyMoonSugarPositionOnly(float3 basePos)\n"
		"{\n"
		"    float3 axisNormal = SafeNormalize(basePos);\n"
		"    float3 axisTangent = SafeNormalize(float3(axisNormal.y + 0.11, -axisNormal.x + 0.17, axisNormal.z * 0.31 + 0.07));\n"
		"    float3 axisBinormal = SafeNormalize(float3(-axisNormal.z + 0.13, axisNormal.y * 0.37 + 0.19, axisNormal.x + 0.23));\n"
		"    return ApplyMoonSugarWithBasis(basePos, axisNormal, axisTangent, axisBinormal);\n"
		"}\n"
		"float3 ApplyMoonSugarWithNormal(float3 basePos, float3 normal)\n"
		"{\n"
		"    float3 axisNormal = SafeNormalize(normal);\n"
		"    float3 axisTangent = BuildFallbackTangent(axisNormal);\n"
		"    float3 axisBinormal = SafeNormalize(cross(axisNormal, axisTangent));\n"
		"    return ApplyMoonSugarWithBasis(basePos, axisNormal, axisTangent, axisBinormal);\n"
		"}\n"
		"#ifdef SKIN\n"
		"float3 SkinVector(float3 value, float index)\n"
		"{\n"
		"    int row = (int)index;\n"
		"    return float3(dot(Bones[row].xyz, value), dot(Bones[row + 1].xyz, value), dot(Bones[row + 2].xyz, value));\n"
		"}\n"
		"float3 SkinPosition(float3 value, float index)\n"
		"{\n"
		"    int row = (int)index;\n"
		"    float4 pos = float4(value, 1.0);\n"
		"    return float3(dot(Bones[row], pos), dot(Bones[row + 1], pos), dot(Bones[row + 2], pos));\n"
		"}\n"
		"float3 BlendPosition(float3 value, float4 indices, float4 weights)\n"
		"{\n"
		"    float3 blended = SkinPosition(value, indices.y) * weights.y;\n"
		"    blended += SkinPosition(value, indices.x) * weights.x;\n"
		"    blended += SkinPosition(value, indices.z) * weights.z;\n"
		"    blended += SkinPosition(value, indices.w) * weights.w;\n"
		"    return blended;\n"
		"}\n"
		"#ifdef HAS_NORMAL\n"
		"float3 BlendVector(float3 value, float4 indices, float4 weights)\n"
		"{\n"
		"    float3 blended = SkinVector(value, indices.y) * weights.y;\n"
		"    blended += SkinVector(value, indices.x) * weights.x;\n"
		"    blended += SkinVector(value, indices.z) * weights.z;\n"
		"    blended += SkinVector(value, indices.w) * weights.w;\n"
		"    return blended;\n"
		"}\n"
		"#endif\n"
		"#endif\n"
		"float4 BuildClip(float3 displaced, float w)\n"
		"{\n"
		"    float4 pos = float4(displaced, w);\n"
		"#ifdef SKIN\n"
		"    return float4(dot(SkinMVP0, pos), dot(SkinMVP1, pos), dot(SkinMVP2, pos), dot(SkinMVP3, pos));\n"
		"#else\n"
		"    return float4(dot(MVP0, pos), dot(MVP1, pos), dot(MVP2, pos), dot(MVP3, pos));\n"
		"#endif\n"
		"}\n"
		"#ifdef HAS_NORMAL\n"
		"float3 BuildViewNormal(float3 normal)\n"
		"{\n"
		"#ifdef SKIN\n"
		"    return float3(dot(SkinWorldViewTranspose0.xyz, normal), dot(SkinWorldViewTranspose1.xyz, normal), dot(SkinWorldViewTranspose2.xyz, normal));\n"
		"#else\n"
		"    return float3(dot(WorldViewTranspose0.xyz, normal), dot(WorldViewTranspose1.xyz, normal), dot(WorldViewTranspose2.xyz, normal));\n"
		"#endif\n"
		"}\n"
		"#endif\n"
		"VSOut MoonSugarVS(VSIn input)\n"
		"{\n"
		"    VSOut output;\n"
		"#ifdef SKIN\n"
		"    float4 indices = floor(input.blendIndices.zyxw * 765.01001);\n"
		"    float4 weights = float4(input.blendWeights.xyz, 1.0 - dot(input.blendWeights.xyz, 1.0));\n"
		"    float3 basePos = BlendPosition(input.position.xyz, indices, weights);\n"
		"#ifdef HAS_NORMAL\n"
		"    float3 normal = SafeNormalize(BlendVector(input.normal, indices, weights));\n"
		"#endif\n"
		"#else\n"
		"    float3 basePos = input.position.xyz;\n"
		"#ifdef HAS_NORMAL\n"
		"    float3 normal = input.normal;\n"
		"#endif\n"
		"#endif\n"
		"#ifdef SKIN\n"
		"    float sourceW = 1.0;\n"
		"#else\n"
		"    float sourceW = input.position.w;\n"
		"#endif\n"
		"#ifdef HAS_NORMAL\n"
		"    float3 displaced = ApplyMoonSugarWithNormal(basePos, normal);\n"
		"#else\n"
		"    float3 displaced = ApplyMoonSugarPositionOnly(basePos);\n"
		"#endif\n"
		"    float4 clip = BuildClip(displaced, sourceW);\n"
		"    output.position = clip;\n"
		"#ifdef MODE_SIMPLE_SHADOW\n"
		"    float4 sourcePos = float4(displaced, sourceW);\n"
		"    float fogBlend = saturate((FogParam.x - length(clip.xyz)) / FogParam.y);\n"
		"    output.texcoord = input.texcoord;\n"
		"    output.sourcePosition = displaced;\n"
		"    output.cubeProjection.x = dot(ObjToCubeMap0, sourcePos);\n"
		"    output.cubeProjection.y = dot(ObjToCubeMap1, sourcePos);\n"
		"    output.cubeProjection.z = dot(ObjToCubeMap2, sourcePos);\n"
		"    output.cubeProjection.w = dot(ObjToCubeMap3, sourcePos);\n"
		"    output.fog.xyz = FogColor.xyz;\n"
		"    output.fog.w = (1.0 - fogBlend) * FogParam.z;\n"
		"#endif\n"
		"#ifdef MODE_ZONLY\n"
		"    output.texcoord = input.texcoord;\n"
		"    output.color = 1.0;\n"
		"#endif\n"
		"#ifdef MODE_RENDER_NORMALS\n"
		"    float3 viewNormal = BuildViewNormal(normal);\n"
		"    output.normalTexcoord.xy = input.texcoord;\n"
		"    output.normalTexcoord.z = max(clip.z * 0.00133333332 + 0.800000012, 1.0);\n"
		"    output.refraction = clamp(viewNormal.xy, -0.100000001, 0.100000001);\n"
		"#endif\n"
		"#ifdef MODE_RENDER_NORMALS_FIRE\n"
		"    float4 firePos = float4(displaced, input.position.w) * 0.00333333341;\n"
		"    float fireZ = dot(WorldViewTranspose2, firePos);\n"
		"    output.fireData.x = dot(WorldViewTranspose0, firePos) - TimeParam.x;\n"
		"    output.fireData.y = dot(WorldViewTranspose1, firePos) - TimeParam.x;\n"
		"    output.fireData.z = fireZ;\n"
		"    output.fireData.w = max(fireZ * 0.0199999996, 1.0);\n"
		"    output.firePower = dot(input.normal, SafeNormalize(EyePosition.xyz - displaced));\n"
		"#endif\n"
		"#ifdef MODE_LOCALMAP\n"
		"    float3 viewNormal = BuildViewNormal(normal);\n"
		"    output.localNormal = viewNormal * 0.5 + 0.5;\n"
		"    output.localDepth = clip.z * 5.0 - 4.4000001;\n"
		"#endif\n"
		"    return output;\n"
		"}\n"
		"\n";

	const char* kLighting30DecalObjectVertexShader =
		"float4 MVP0 : register(c0);\n"
		"float4 MVP1 : register(c1);\n"
		"float4 MVP2 : register(c2);\n"
		"float4 MVP3 : register(c3);\n"
		"float4 MoonSugar0 : register(c26);\n"
		"float4 MoonSugar1 : register(c27);\n"
		"float4 DecalFade0 : register(c32);\n"
		"float4 DecalFade1 : register(c33);\n"
		"float4 DecalFade2 : register(c34);\n"
		"float4 DecalFade3 : register(c35);\n"
		"float4 DecalFade4 : register(c36);\n"
		"float4 DecalFade5 : register(c37);\n"
		"float4 DecalFade6 : register(c38);\n"
		"float4 DecalFade7 : register(c39);\n"
		"float4 DecalProj0_0 : register(c40);\n"
		"float4 DecalProj0_1 : register(c41);\n"
		"float4 DecalProj0_2 : register(c42);\n"
		"float4 DecalProj1_0 : register(c44);\n"
		"float4 DecalProj1_1 : register(c45);\n"
		"float4 DecalProj1_2 : register(c46);\n"
		"float4 DecalProj2_0 : register(c48);\n"
		"float4 DecalProj2_1 : register(c49);\n"
		"float4 DecalProj2_2 : register(c50);\n"
		"float4 DecalProj3_0 : register(c52);\n"
		"float4 DecalProj3_1 : register(c53);\n"
		"float4 DecalProj3_2 : register(c54);\n"
		"float4 DecalProj4_0 : register(c56);\n"
		"float4 DecalProj4_1 : register(c57);\n"
		"float4 DecalProj4_2 : register(c58);\n"
		"float4 DecalProj5_0 : register(c60);\n"
		"float4 DecalProj5_1 : register(c61);\n"
		"float4 DecalProj5_2 : register(c62);\n"
		"float4 DecalProj6_0 : register(c64);\n"
		"float4 DecalProj6_1 : register(c65);\n"
		"float4 DecalProj6_2 : register(c66);\n"
		"float4 DecalProj7_0 : register(c68);\n"
		"float4 DecalProj7_1 : register(c69);\n"
		"float4 DecalProj7_2 : register(c70);\n"
		"struct VSIn\n"
		"{\n"
		"    float4 position : POSITION0;\n"
		"    float3 normal : NORMAL0;\n"
		"};\n"
		"struct VSOut\n"
		"{\n"
		"    float4 position : POSITION0;\n"
		"    float3 decal0 : TEXCOORD0;\n"
		"    float3 decal1 : TEXCOORD1;\n"
		"    float3 decal2 : TEXCOORD2;\n"
		"    float3 decal3 : TEXCOORD3;\n"
		"    float3 decal4 : TEXCOORD4;\n"
		"    float3 decal5 : TEXCOORD5;\n"
		"    float3 decal6 : TEXCOORD6;\n"
		"    float3 decal7 : TEXCOORD7;\n"
		"};\n"
		"float SmoothTri(float x)\n"
		"{\n"
		"    float y = abs(frac(x) * 2.0 - 1.0);\n"
		"    y = y * y * (3.0 - 2.0 * y);\n"
		"    return y * 2.0 - 1.0;\n"
		"}\n"
		"float3 SafeNormalize(float3 v)\n"
		"{\n"
		"    return v * rsqrt(max(dot(v, v), 0.000001));\n"
		"}\n"
		"float3 BuildDecalTangent(float3 normal)\n"
		"{\n"
		"    float useZ = abs(normal.z) < 0.75 ? 1.0 : 0.0;\n"
		"    float3 up = lerp(float3(0.0, 1.0, 0.0), float3(0.0, 0.0, 1.0), useZ);\n"
		"    return SafeNormalize(cross(up, normal));\n"
		"}\n"
		"float3 ApplyMoonSugar(float3 basePos, float3 normal)\n"
		"{\n"
		"    float3 n = SafeNormalize(normal);\n"
		"    float3 tangent = BuildDecalTangent(n);\n"
		"    float3 binormal = SafeNormalize(cross(n, tangent));\n"
		"    float time = MoonSugar0.x;\n"
		"    float intensity = saturate(MoonSugar0.y);\n"
		"    float amplitude = MoonSugar0.z * intensity;\n"
		"    float speed = MoonSugar0.w;\n"
		"    float normalAmp = MoonSugar1.x;\n"
		"    float tangentAmp = MoonSugar1.y;\n"
		"    float frequency = MoonSugar1.z;\n"
		"    float phase = MoonSugar1.w;\n"
		"    float waveA = SmoothTri(dot(basePos, float3(0.017, 0.011, 0.007)) * frequency + time * speed + phase);\n"
		"    float waveB = SmoothTri(dot(basePos, float3(-0.009, 0.015, 0.013)) * frequency - time * speed * 0.63 + phase * 1.71);\n"
		"    float3 displaced = basePos + n * (waveA * normalAmp * amplitude);\n"
		"    displaced += tangent * (waveB * tangentAmp * amplitude);\n"
		"    displaced += binormal * (waveA * waveB * tangentAmp * amplitude * 0.35);\n"
		"    return displaced;\n"
		"}\n"
		"float3 BuildDecal(float3 sourcePosition, float3 nativeNormal, float4 row0, float4 row1, float4 row2, float fade)\n"
		"{\n"
		"    float3 decalPosition = sourcePosition + float3(row0.w, row1.w, row2.w);\n"
		"    float2 projected = float2(dot(row0.xyz, decalPosition), dot(row1.xyz, decalPosition)) * 0.0125000002 + 0.5;\n"
		"    float depthFade = 1.0 - abs(dot(row2.xyz, decalPosition)) * 0.00390625;\n"
		"    float normalFacing = max(dot(nativeNormal, row2.xyz), 0.0);\n"
		"    float normalFade = pow(1.0 - normalFacing, 10.0) * fade;\n"
		"    return float3(projected, depthFade * normalFade);\n"
		"}\n"
		"VSOut MoonSugarVS(VSIn input)\n"
		"{\n"
		"    VSOut output;\n"
		"    float3 displaced = ApplyMoonSugar(input.position.xyz, input.normal);\n"
		"    float4 pos = float4(displaced, input.position.w);\n"
		"    output.position = float4(dot(MVP0, pos), dot(MVP1, pos), dot(MVP2, pos), dot(MVP3, pos));\n"
		"    output.decal0 = BuildDecal(displaced, input.normal, DecalProj0_0, DecalProj0_1, DecalProj0_2, DecalFade0.x);\n"
		"    output.decal1 = BuildDecal(displaced, input.normal, DecalProj1_0, DecalProj1_1, DecalProj1_2, DecalFade1.x);\n"
		"    output.decal2 = BuildDecal(displaced, input.normal, DecalProj2_0, DecalProj2_1, DecalProj2_2, DecalFade2.x);\n"
		"    output.decal3 = BuildDecal(displaced, input.normal, DecalProj3_0, DecalProj3_1, DecalProj3_2, DecalFade3.x);\n"
		"    output.decal4 = BuildDecal(displaced, input.normal, DecalProj4_0, DecalProj4_1, DecalProj4_2, DecalFade4.x);\n"
		"    output.decal5 = BuildDecal(displaced, input.normal, DecalProj5_0, DecalProj5_1, DecalProj5_2, DecalFade5.x);\n"
		"    output.decal6 = BuildDecal(displaced, input.normal, DecalProj6_0, DecalProj6_1, DecalProj6_2, DecalFade6.x);\n"
		"    output.decal7 = BuildDecal(displaced, input.normal, DecalProj7_0, DecalProj7_1, DecalProj7_2, DecalFade7.x);\n"
		"    return output;\n"
		"}\n";

	typedef void (__thiscall * ProcessEffectsFromItemFn)(void* magicTarget, MagicItem* item);
	typedef UInt32 (__thiscall * GetEngineMagicTypeFn)(MagicItem* item);
	typedef UInt32 (__thiscall * GetNiRTTIFn)(void* object);
	typedef HRESULT (WINAPI * D3DXCompileShaderPtr)(
		LPCSTR sourceData,
		UINT sourceDataLen,
		const D3DXMACRO* defines,
		LPD3DXINCLUDE include,
		LPCSTR functionName,
		LPCSTR profile,
		DWORD flags,
		LPD3DXBUFFER* shader,
		LPD3DXBUFFER* errorMsgs,
		LPD3DXCONSTANTTABLE* constantTable);
	typedef HRESULT (WINAPI * D3DXCompileShaderFromFileAPtr)(
		LPCSTR srcFile,
		const D3DXMACRO* defines,
		LPD3DXINCLUDE include,
		LPCSTR functionName,
		LPCSTR profile,
		DWORD flags,
		LPD3DXBUFFER* shader,
		LPD3DXBUFFER* errorMsgs,
		LPD3DXCONSTANTTABLE* constantTable);
	typedef void (__cdecl * RenderWorldSceneGraphFn)(void* camera, void* sceneGraph, void* cullingProcess, void* visibleGeo);
	typedef void* (__thiscall * SetCameraViewProjFn)(NiDX9Renderer* renderer, void* camera);

	ProcessEffectsFromItemFn s_processEffectsFromItem =
		reinterpret_cast<ProcessEffectsFromItemFn>(kMagicTargetProcessEffectsFromItem);
	RenderWorldSceneGraphFn s_renderWorldSceneGraph =
		reinterpret_cast<RenderWorldSceneGraphFn>(kRenderWorldSceneGraph);
	SetCameraViewProjFn s_setCameraViewProj =
		reinterpret_cast<SetCameraViewProjFn>(kSetCameraViewProj);
	bool s_hookInstalled = false;
	bool s_rendererHookInstalled = false;
	bool s_geometryHookInstalled = false;
	bool s_objectVertexHookInstalled = false;
	bool s_objectVertexSkinnedHookInstalled = false;
	bool s_cameraHookInstalled = false;
	bool s_allowOffscreenDistortion = false;
	bool s_embeddedPixelShaderOnly = false;
	HMODULE s_d3dxModule = nullptr;
	D3DXCompileShaderPtr s_d3dxCompileShader = nullptr;
	D3DXCompileShaderFromFileAPtr s_d3dxCompileShaderFromFileA = nullptr;
	char s_shaderName[64] = "VESDistortion";
	char s_shaderPath[MAX_PATH] = ".\\Data\\Shaders\\VES\\VESDistortion.fx";
	char s_shaderBytecodePath[MAX_PATH] = ".\\Data\\Shaders\\VES\\VESDistortion.pso";

	struct Settings
	{
		UInt32 moonSugarLocalFormID;
		UInt32 moonSugarFullFormID;
		bool matchLocalFormID;
		bool matchFullFormID;
		bool debugLog;
		UInt32 durationMs;
		UInt32 maxDurationMs;
		float intensity;
		bool rendererEnabled;
		bool preferCompiledShader;
		bool preferShaderFile;
		float fadeOutSeconds;
		float waveStrength;
		float swirlStrength;
		float chromaStrength;
		float colorShift;
		bool rendererDebugLog;
		bool cameraSwayEnabled;
		float cameraSwayStrength;
		bool geometryWobbleEnabled;
		float geometryWobbleStrength;
	};

	enum EffectProfile
	{
		kEffectProfile_MoonSugar25 = 0,
		kEffectProfile_MoonSugar50 = 1,
		kEffectProfile_MoonSugar75 = 2,
		kEffectProfile_HeadWound25 = 3,
		kEffectProfile_HeadWound50 = 4,
		kEffectProfile_HeadWound75 = 5,
		kEffectProfile_Blind25 = 6,
		kEffectProfile_Blind50 = 7,
		kEffectProfile_Blind75 = 8,
		kEffectProfile_Blind100 = 9,
		kEffectProfile_Dim50 = 10,
		kEffectProfile_Dim100 = 11,
		kEffectProfile_OnFire25 = 12,
		kEffectProfile_OnFire50 = 13,
		kEffectProfile_OnFire75 = 14,
		kEffectProfile_OnFire100 = 15,
		kEffectProfile_HeatShimmer50 = 16,
		kEffectProfile_HeatShimmer100 = 17,
		kEffectProfile_Rain50 = 18,
		kEffectProfile_Rain75 = 19,
		kEffectProfile_Rain100 = 20,
		kEffectProfile_Frost50 = 21,
		kEffectProfile_Frost75 = 22,
		kEffectProfile_Frost100 = 23,
		kEffectProfile_DepthMaskDebug = 24,
		kEffectProfile_DimWhiteInverted = 25,
		kEffectProfile_DimPurple = 26,
		kEffectProfile_DimDarkRed = 27
	};

	enum EffectShaderFamily
	{
		kEffectShaderFamily_MoonSugar = 0,
		kEffectShaderFamily_HeadWound = 1,
		kEffectShaderFamily_Blind = 3,
		kEffectShaderFamily_Dim = 4,
		kEffectShaderFamily_OnFire = 5,
		kEffectShaderFamily_HeatShimmer = 6,
		kEffectShaderFamily_Rain = 7,
		kEffectShaderFamily_Frost = 8,
		kEffectShaderFamily_DepthMaskDebug = 9
	};

	enum EffectPixelShaderSlot
	{
		kEffectPixelShaderSlot_MoonSugar = 0,
		kEffectPixelShaderSlot_HeadWound,
		kEffectPixelShaderSlot_Blind,
		kEffectPixelShaderSlot_Dim,
		kEffectPixelShaderSlot_OnFire,
		kEffectPixelShaderSlot_HeatShimmer,
		kEffectPixelShaderSlot_Rain,
		kEffectPixelShaderSlot_Frost,
		kEffectPixelShaderSlot_DepthMaskDebug,
		kEffectPixelShaderSlot_Count
	};

	const char* kEffectPixelShaderEntries[kEffectPixelShaderSlot_Count] =
	{
		"VESMoonSugarPS",
		"VESHeadWoundPS",
		"VESBlindPS",
		"VESDimPS",
		"VESOnFirePS",
		"VESHeatShimmerPS",
		"VESRainPS",
		"VESFrostPS",
		"VESDepthMaskDebugPS"
	};

	const char* kEffectPixelShaderBytecodeFiles[kEffectPixelShaderSlot_Count] =
	{
		".\\Data\\Shaders\\VES\\VESMoonSugarPS.pso",
		".\\Data\\Shaders\\VES\\VESHeadWoundPS.pso",
		".\\Data\\Shaders\\VES\\VESBlindPS.pso",
		".\\Data\\Shaders\\VES\\VESDimPS.pso",
		".\\Data\\Shaders\\VES\\VESOnFirePS.pso",
		".\\Data\\Shaders\\VES\\VESHeatShimmerPS.pso",
		".\\Data\\Shaders\\VES\\VESRainPS.pso",
		".\\Data\\Shaders\\VES\\VESFrostPS.pso",
		".\\Data\\Shaders\\VES\\VESDepthMaskDebugPS.pso"
	};

	struct EffectState
	{
		bool active;
		UInt32 startTick;
		UInt32 expireTick;
		UInt32 doseCount;
		UInt32 lastFormID;
		float intensity;
		UInt32 profile;
	};

	struct RendererState
	{
		IDirect3DPixelShader9* pixelShader;
		IDirect3DPixelShader9* profilePixelShaders[kEffectPixelShaderSlot_Count];
		IDirect3DTexture9* capturedDepthTexture;
		IDirect3DSurface9* capturedDepthSurface;
		UInt32 shaderFailures;
		UInt32 renderFailures;
		UInt32 renderedFrames;
		bool fallbackShaderUsed;
		bool shaderCompileAttempted;
		bool shaderCompileFailed;
		UInt32 lastSkipReason;
		UInt32 lastSkipTick;
		UInt32 imageSpaceCalls;
		UInt32 lastRenderContext;
		UInt32 depthBindAttempts;
		UInt32 depthBindSuccess;
		UInt32 depthBindFailures;
		UInt32 depthLastFormat;
		UInt32 depthLastHr;
		UInt32 depthCaptureAttempts;
		UInt32 depthCaptureSuccess;
		UInt32 depthCaptureFailures;
		UInt32 depthCaptureLastHr;
		UInt32 depthCaptureAttemptedFormatMask;
		UInt32 depthCapturePreflightPassFormatMask;
		UInt32 depthCapturePreflightRejectFormatMask;
		UInt32 capturedDepthWidth;
		UInt32 capturedDepthHeight;
		UInt32 capturedDepthFormat;
		UInt32 capturedDepthTick;
		UInt32 depthLastSource;
		UInt32 depthCapturedSourceFrames;
		UInt32 depthActiveFallbackFrames;
		UInt32 depthUnavailableFrames;
		UInt32 depthMaskTrustedFrames;
		UInt32 depthMaskUntrustedFrames;
		UInt32 depthCaptureGuardNoRenderer;
		UInt32 depthCaptureGuardNoEffect;
		UInt32 depthCaptureGuardProfileNoDepth;
		UInt32 depthCaptureGuardCameraMismatch;
		UInt32 depthCaptureGuardRenderMode;
		UInt32 depthCaptureGuardBeginFailed;
		bool depthAvailableLastFrame;
		bool depthUnavailableLogged;
		bool depthCaptureActiveLastFrame;
		bool depthCaptureUnsupportedLogged;
		bool depthCaptureFirstLogged;
	};

	struct GeometryWobbleState
	{
		UInt32 calls;
		UInt32 applied;
		UInt32 skippedInactive;
		UInt32 skippedScreenElements;
		UInt32 skippedSkinned;
		bool firstAppliedLogged;
	};

	struct ObjectVertexShaderState
	{
		IDirect3DVertexShader9* vertexShader;
		IDirect3DVertexShader9* lighting30VertexShaders[kLighting30ObjectVertexShaderVariantCount];
		IDirect3DVertexShader9* lighting30EnvMapVertexShaders[kLighting30EnvMapVertexShaderVariantCount];
		IDirect3DVertexShader9* lighting30TexEffectVertexShaders[kLighting30TexEffectVertexShaderVariantCount];
		IDirect3DVertexShader9* lighting30DecalVertexShaders[kLighting30DecalVertexShaderVariantCount];
		IDirect3DVertexShader9* lighting30DepthMapVertexShaders[kLighting30DepthMapVertexShaderVariantCount];
		IDirect3DVertexShader9* lighting30SupportVertexShaders[kLighting30SupportVertexShaderVariantCount];
		IDirect3DDevice9* device;
		UInt32 calls;
		UInt32 applied;
		UInt32 skippedInactive;
		UInt32 skippedPass;
		UInt32 skippedScreenElements;
		UInt32 shaderFailures;
		bool firstAppliedLogged;
		bool compileAttempted;
		bool compileFailed;
		bool lighting30FirstAppliedLogged[kLighting30ObjectVertexShaderVariantCount];
		UInt32 lighting30Applied[kLighting30ObjectVertexShaderVariantCount];
		bool lighting30CompileAttempted[kLighting30ObjectVertexShaderVariantCount];
		bool lighting30CompileFailed[kLighting30ObjectVertexShaderVariantCount];
		bool lighting30EnvMapFirstAppliedLogged[kLighting30EnvMapVertexShaderVariantCount];
		UInt32 lighting30EnvMapApplied[kLighting30EnvMapVertexShaderVariantCount];
		bool lighting30EnvMapCompileAttempted[kLighting30EnvMapVertexShaderVariantCount];
		bool lighting30EnvMapCompileFailed[kLighting30EnvMapVertexShaderVariantCount];
		bool lighting30TexEffectFirstAppliedLogged[kLighting30TexEffectVertexShaderVariantCount];
		UInt32 lighting30TexEffectApplied[kLighting30TexEffectVertexShaderVariantCount];
		bool lighting30TexEffectCompileAttempted[kLighting30TexEffectVertexShaderVariantCount];
		bool lighting30TexEffectCompileFailed[kLighting30TexEffectVertexShaderVariantCount];
		bool lighting30DecalFirstAppliedLogged[kLighting30DecalVertexShaderVariantCount];
		UInt32 lighting30DecalApplied[kLighting30DecalVertexShaderVariantCount];
		bool lighting30DecalCompileAttempted[kLighting30DecalVertexShaderVariantCount];
		bool lighting30DecalCompileFailed[kLighting30DecalVertexShaderVariantCount];
		bool lighting30DepthMapCompileAttempted[kLighting30DepthMapVertexShaderVariantCount];
		bool lighting30DepthMapCompileFailed[kLighting30DepthMapVertexShaderVariantCount];
		bool lighting30SupportCompileAttempted[kLighting30SupportVertexShaderVariantCount];
		bool lighting30SupportCompileFailed[kLighting30SupportVertexShaderVariantCount];
		bool lighting30SupportFirstAppliedLogged[kLighting30SupportVertexShaderVariantCount];
		UInt32 lighting30SupportApplied[kLighting30SupportVertexShaderVariantCount];
		bool lighting30DepthMapFirstAppliedLogged[kLighting30DepthMapVertexShaderVariantCount];
		UInt32 lighting30DepthMapApplied[kLighting30DepthMapVertexShaderVariantCount];
		bool legacyFirstAppliedLogged[kLegacyObjectVertexShaderVariantCount];
		UInt32 legacyApplied[kLegacyObjectVertexShaderVariantCount];
		UInt32 passCensusSamples;
		UInt32 lighting30PassCounts[kLighting30PassCount];
		UInt32 lighting30VertexProgramCounts[kLighting30VertexProgramCount];
		UInt32 lighting30PixelProgramCounts[kLighting30PixelProgramCount];
		UInt32 lighting30LowPixelProgramCounts[kLighting30LowPixelProgramCount];
		UInt32 parallaxPassCounts[kParallaxPassCount];
		UInt32 skinPassCounts[kSkinPassCount];
		UInt32 unknownPassOverflow;
		UInt32 skinnedCalls;
		UInt32 skinnedApplied;
	};

	struct ObjectVertexUnknownPass
	{
		void* pass;
		void* shader;
		void* vertexShader;
		void* pixelShader;
		UInt32 currentPassIndex;
		UInt32 count;
	};

	enum ObjectVertexProgramFamily
	{
		kObjectVertexProgram_Unknown = 0,
		kObjectVertexProgram_Lighting30VS,
		kObjectVertexProgram_Lighting30PS,
		kObjectVertexProgram_Lighting30LowPS
	};

	enum LegacyObjectVertexShaderVariant
	{
		kLegacyObjectVertexShader_Par2016 = 0,
		kLegacyObjectVertexShader_Skin2008
	};

	enum ObjectVertexReplacementKind
	{
		kObjectVertexReplacement_None = 0,
		kObjectVertexReplacement_ParallaxSkinVs20,
		kObjectVertexReplacement_Lighting30Sm3Vs30,
		kObjectVertexReplacement_Lighting30EnvMapVs30,
		kObjectVertexReplacement_Lighting30TexEffectVs30,
		kObjectVertexReplacement_Lighting30DecalVs30,
		kObjectVertexReplacement_Lighting30DepthMapVs30,
		kObjectVertexReplacement_Lighting30SupportVs30
	};

	enum Lighting30ObjectVertexShaderVariant
	{
		kLighting30ObjectVertexShader_Sm3000 = 0,
		kLighting30ObjectVertexShader_Sm3002Vc,
		kLighting30ObjectVertexShader_Sm3004Proj,
		kLighting30ObjectVertexShader_Sm3006VcProj,
		kLighting30ObjectVertexShader_Sm3001Skin,
		kLighting30ObjectVertexShader_Sm3003SkinVc,
		kLighting30ObjectVertexShader_Sm3005SkinProj,
		kLighting30ObjectVertexShader_Sm3007SkinVcProj
	};

	enum Lighting30EnvMapVertexShaderVariant
	{
		kLighting30EnvMapVertexShader_Sm3008 = 0,
		kLighting30EnvMapVertexShader_Sm3009Vc,
		kLighting30EnvMapVertexShader_Sm3010Skin,
		kLighting30EnvMapVertexShader_Sm3011SkinVc,
		kLighting30EnvMapVertexShader_Sm3012Special
	};

	enum Lighting30TexEffectVertexShaderVariant
	{
		kLighting30TexEffectVertexShader_Sm3028 = 0,
		kLighting30TexEffectVertexShader_Sm3029Skin
	};

	enum Lighting30DecalVertexShaderVariant
	{
		kLighting30DecalVertexShader_Sm3017 = 0
	};

	enum Lighting30DepthMapVertexShaderVariant
	{
		kLighting30DepthMapVertexShader_Sm3018 = 0,
		kLighting30DepthMapVertexShader_Sm3019Skin
	};

	enum Lighting30SupportVertexShaderVariant
	{
		kLighting30SupportVertexShader_Sm3030ZOnly = 0,
		kLighting30SupportVertexShader_Sm3031ZOnlySkin,
		kLighting30SupportVertexShader_Sm3020RenderNormals,
		kLighting30SupportVertexShader_Sm3021RenderNormalsSkin,
		kLighting30SupportVertexShader_Sm3022RenderNormalsFire,
		kLighting30SupportVertexShader_Sm3025LocalMap,
		kLighting30SupportVertexShader_Sm3026LocalMapSkin,
		kLighting30SupportVertexShader_Sm3013SimpleShadow,
		kLighting30SupportVertexShader_Sm3014SimpleShadowVc,
		kLighting30SupportVertexShader_Sm3015SimpleShadowSkin,
		kLighting30SupportVertexShader_Sm3016SimpleShadowSkinVc
	};

	struct ObjectVertexPassSample
	{
		void* pass;
		void* shader;
		void* vertexShader;
		void* pixelShader;
		UInt32 currentPassIndex;
		UInt32 passCount;
		UInt32 passFamily;
		UInt32 passIndex;
		UInt32 vertexProgramFamily;
		UInt32 vertexProgramIndex;
		UInt32 pixelProgramFamily;
		UInt32 pixelProgramIndex;
		UInt32 count;
	};

	struct PassCountTopEntry
	{
		UInt32 index;
		UInt32 count;
	};

	struct CameraSwayState
	{
		UInt32 calls;
		UInt32 applied;
		UInt32 skippedInactive;
		UInt32 skippedFiltered;
		UInt32 rendererRestored;
		bool inHook;
		bool firstAppliedLogged;
	};

	struct MaskPrepassCandidateState
	{
		UInt32 worldRenderCalls;
		UInt32 worldCameraCalls;
		UInt32 worldSceneGraphCalls;
		UInt32 sceneGraphCullingProcessCalls;
		UInt32 normalRenderModeCalls;
		UInt32 explicitVisibleArgCalls;
		UInt32 cullingProcessVisibleGeoCalls;
		UInt32 missingCullingProcessCalls;
		UInt32 lastRenderMode;
		void* lastCamera;
		void* lastSceneGraph;
		void* lastCullingProcess;
		void* lastSceneGraphCullingProcess;
		void* lastVisibleArg;
		void* lastCullingProcessVisibleGeo;
		bool firstExplicitVisibleLogged;
		bool firstCullingVisibleLogged;
	};

	struct CameraTransformBackup
	{
		float transform[13];
	};

	Settings s_settings =
	{
		kDefaultMoonSugarLocalFormID,
		0,
		true,
		false,
		true,
		kDefaultDurationMs,
		kDefaultMaxDurationMs,
		1.0f,
		true,
		true,
		true,
		8.0f,
		0.014f,
		0.040f,
		0.020f,
		0.34f,
		true,
		true,
		1.0f,
		true,
		1.0f
	};

	EffectState s_effect =
	{
		false,
		0,
		0,
		0,
		0,
		0.0f,
		kEffectProfile_MoonSugar75
	};

	RendererState s_rendererState = {};

	GeometryWobbleState s_geometryWobbleState =
	{
		0,
		0,
		0,
		0,
		0,
		false
	};

	ObjectVertexShaderState s_objectVertexShaderState =
	{
		nullptr,
		nullptr,
		0,
		0,
		0,
		0,
		0,
		0,
		false,
		false,
		false,
		0
	};

	ObjectVertexUnknownPass s_objectVertexUnknownPasses[kObjectVertexUnknownPassSlots] = {};
	ObjectVertexPassSample s_objectVertexPassSamples[kObjectVertexPassSampleSlots] = {};

	CameraSwayState s_cameraSwayState =
	{
		0,
		0,
		0,
		0,
		0,
		false,
		false
	};

	MaskPrepassCandidateState s_maskPrepassCandidateState = {};

	void ReleaseRendererResources();
	void ExpireMoonSugarEffect(UInt32 now);

	UInt32 ClampUInt32(UInt32 value, UInt32 minValue, UInt32 maxValue)
	{
		if (value < minValue)
			return minValue;
		if (value > maxValue)
			return maxValue;
		return value;
	}

	float ClampFloat(float value, float minValue, float maxValue)
	{
		if (value != value)
			return minValue;
		if (value < minValue)
			return minValue;
		if (value > maxValue)
			return maxValue;
		return value;
	}

	bool TickHasReached(UInt32 now, UInt32 target)
	{
		return static_cast<SInt32>(now - target) >= 0;
	}

	UInt32 GetRemainingMillisecondsAt(UInt32 now)
	{
		if (!s_effect.active || TickHasReached(now, s_effect.expireTick))
			return 0;

		return s_effect.expireTick - now;
	}

	UInt32 AddDurationCapped(UInt32 baseMs, UInt32 addMs, UInt32 capMs)
	{
		if (baseMs >= capMs)
			return capMs;

		UInt32 roomMs = capMs - baseMs;
		return addMs > roomMs ? capMs : (baseMs + addMs);
	}

	const char* GetEffectProfileName(UInt32 profile)
	{
		switch (profile)
		{
			case kEffectProfile_MoonSugar25:
				return kMoonSugar25ShaderName;
			case kEffectProfile_MoonSugar50:
				return kMoonSugar50ShaderName;
			case kEffectProfile_MoonSugar75:
				return kMoonSugar75ShaderName;
			case kEffectProfile_HeadWound25:
				return kHeadWound25ShaderName;
			case kEffectProfile_HeadWound50:
				return kHeadWound50ShaderName;
			case kEffectProfile_HeadWound75:
				return kHeadWound75ShaderName;
			case kEffectProfile_Blind25:
				return kBlind25ShaderName;
			case kEffectProfile_Blind50:
				return kBlind50ShaderName;
			case kEffectProfile_Blind75:
				return kBlind75ShaderName;
			case kEffectProfile_Blind100:
				return kBlind100ShaderName;
			case kEffectProfile_Dim50:
				return kDim50ShaderName;
			case kEffectProfile_Dim100:
				return kDim100ShaderName;
			case kEffectProfile_DimWhiteInverted:
				return kDimWhiteInvertedShaderName;
			case kEffectProfile_DimPurple:
				return kDimPurpleShaderName;
			case kEffectProfile_DimDarkRed:
				return kDimDarkRedShaderName;
			case kEffectProfile_OnFire25:
				return kOnFire25ShaderName;
			case kEffectProfile_OnFire50:
				return kOnFire50ShaderName;
			case kEffectProfile_OnFire75:
				return kOnFire75ShaderName;
			case kEffectProfile_OnFire100:
				return kOnFire100ShaderName;
			case kEffectProfile_HeatShimmer50:
				return kHeatShimmer50ShaderName;
			case kEffectProfile_HeatShimmer100:
				return kHeatShimmer100ShaderName;
			case kEffectProfile_Rain50:
				return kRain50ShaderName;
			case kEffectProfile_Rain75:
				return kRain75ShaderName;
			case kEffectProfile_Rain100:
				return kRain100ShaderName;
			case kEffectProfile_Frost50:
				return kFrost50ShaderName;
			case kEffectProfile_Frost75:
				return kFrost75ShaderName;
			case kEffectProfile_Frost100:
				return kFrost100ShaderName;
			case kEffectProfile_DepthMaskDebug:
				return kDepthMaskDebugShaderName;
			default:
				return kDefaultShaderName;
		}
	}

	const char* GetEffectProfileDisplayName(UInt32 profile)
	{
		switch (profile)
		{
			case kEffectProfile_MoonSugar25:
				return kMoonSugar25DisplayName;
			case kEffectProfile_MoonSugar50:
				return kMoonSugar50DisplayName;
			case kEffectProfile_MoonSugar75:
				return kMoonSugar75DisplayName;
			case kEffectProfile_HeadWound25:
				return kHeadWound25DisplayName;
			case kEffectProfile_HeadWound50:
				return kHeadWound50DisplayName;
			case kEffectProfile_HeadWound75:
				return kHeadWound75DisplayName;
			case kEffectProfile_Blind25:
				return kBlind25DisplayName;
			case kEffectProfile_Blind50:
				return kBlind50DisplayName;
			case kEffectProfile_Blind75:
				return kBlind75DisplayName;
			case kEffectProfile_Blind100:
				return kBlind100DisplayName;
			case kEffectProfile_Dim50:
				return kDim50DisplayName;
			case kEffectProfile_Dim100:
				return kDim100DisplayName;
			case kEffectProfile_DimWhiteInverted:
				return kDimWhiteInvertedDisplayName;
			case kEffectProfile_DimPurple:
				return kDimPurpleDisplayName;
			case kEffectProfile_DimDarkRed:
				return kDimDarkRedDisplayName;
			case kEffectProfile_OnFire25:
				return kOnFire25DisplayName;
			case kEffectProfile_OnFire50:
				return kOnFire50DisplayName;
			case kEffectProfile_OnFire75:
				return kOnFire75DisplayName;
			case kEffectProfile_OnFire100:
				return kOnFire100DisplayName;
			case kEffectProfile_HeatShimmer50:
				return kHeatShimmer50DisplayName;
			case kEffectProfile_HeatShimmer100:
				return kHeatShimmer100DisplayName;
			case kEffectProfile_Rain50:
				return kRain50DisplayName;
			case kEffectProfile_Rain75:
				return kRain75DisplayName;
			case kEffectProfile_Rain100:
				return kRain100DisplayName;
			case kEffectProfile_Frost50:
				return kFrost50DisplayName;
			case kEffectProfile_Frost75:
				return kFrost75DisplayName;
			case kEffectProfile_Frost100:
				return kFrost100DisplayName;
			case kEffectProfile_DepthMaskDebug:
				return kDepthMaskDebugDisplayName;
			default:
				return kDefaultShaderDisplayName;
		}
	}

	float GetEffectProfileSeverity(UInt32 profile)
	{
		switch (profile)
		{
			case kEffectProfile_MoonSugar25:
			case kEffectProfile_HeadWound25:
			case kEffectProfile_Blind25:
			case kEffectProfile_OnFire25:
				return 0.25f;
			case kEffectProfile_MoonSugar50:
			case kEffectProfile_HeadWound50:
			case kEffectProfile_Blind50:
			case kEffectProfile_Dim50:
			case kEffectProfile_OnFire50:
			case kEffectProfile_HeatShimmer50:
			case kEffectProfile_Rain50:
			case kEffectProfile_Frost50:
				return 0.50f;
			case kEffectProfile_MoonSugar75:
			case kEffectProfile_HeadWound75:
			case kEffectProfile_Blind75:
			case kEffectProfile_OnFire75:
			case kEffectProfile_Rain75:
			case kEffectProfile_Frost75:
				return 0.75f;
			case kEffectProfile_Blind100:
			case kEffectProfile_Dim100:
			case kEffectProfile_DimWhiteInverted:
			case kEffectProfile_DimPurple:
			case kEffectProfile_DimDarkRed:
			case kEffectProfile_OnFire100:
			case kEffectProfile_HeatShimmer100:
			case kEffectProfile_Rain100:
			case kEffectProfile_Frost100:
			case kEffectProfile_DepthMaskDebug:
				return 1.0f;
			default:
				return 0.0f;
		}
	}

	float GetEffectProfileVariant(UInt32 profile)
	{
		switch (profile)
		{
			case kEffectProfile_Dim100:
				return 1.0f;
			case kEffectProfile_DimWhiteInverted:
				return 2.0f;
			case kEffectProfile_DimPurple:
				return 3.0f;
			case kEffectProfile_DimDarkRed:
				return 4.0f;
			default:
				return 0.0f;
		}
	}

	UInt32 GetEffectProfileShaderFamily(UInt32 profile)
	{
		switch (profile)
		{
			case kEffectProfile_HeadWound25:
			case kEffectProfile_HeadWound50:
			case kEffectProfile_HeadWound75:
				return kEffectShaderFamily_HeadWound;
			case kEffectProfile_Blind25:
			case kEffectProfile_Blind50:
			case kEffectProfile_Blind75:
			case kEffectProfile_Blind100:
				return kEffectShaderFamily_Blind;
			case kEffectProfile_Dim50:
			case kEffectProfile_Dim100:
			case kEffectProfile_DimWhiteInverted:
			case kEffectProfile_DimPurple:
			case kEffectProfile_DimDarkRed:
				return kEffectShaderFamily_Dim;
			case kEffectProfile_OnFire25:
			case kEffectProfile_OnFire50:
			case kEffectProfile_OnFire75:
			case kEffectProfile_OnFire100:
				return kEffectShaderFamily_OnFire;
			case kEffectProfile_HeatShimmer50:
			case kEffectProfile_HeatShimmer100:
				return kEffectShaderFamily_HeatShimmer;
			case kEffectProfile_Rain50:
			case kEffectProfile_Rain75:
			case kEffectProfile_Rain100:
				return kEffectShaderFamily_Rain;
			case kEffectProfile_Frost50:
			case kEffectProfile_Frost75:
			case kEffectProfile_Frost100:
				return kEffectShaderFamily_Frost;
			case kEffectProfile_DepthMaskDebug:
				return kEffectShaderFamily_DepthMaskDebug;
			default:
				return kEffectShaderFamily_MoonSugar;
		}
	}

	UInt32 GetEffectProfilePixelShaderSlot(UInt32 profile)
	{
		switch (GetEffectProfileShaderFamily(profile))
		{
			case kEffectShaderFamily_HeadWound:
				return kEffectPixelShaderSlot_HeadWound;
			case kEffectShaderFamily_Blind:
				return kEffectPixelShaderSlot_Blind;
			case kEffectShaderFamily_Dim:
				return kEffectPixelShaderSlot_Dim;
			case kEffectShaderFamily_OnFire:
				return kEffectPixelShaderSlot_OnFire;
			case kEffectShaderFamily_HeatShimmer:
				return kEffectPixelShaderSlot_HeatShimmer;
			case kEffectShaderFamily_Rain:
				return kEffectPixelShaderSlot_Rain;
			case kEffectShaderFamily_Frost:
				return kEffectPixelShaderSlot_Frost;
			case kEffectShaderFamily_DepthMaskDebug:
				return kEffectPixelShaderSlot_DepthMaskDebug;
			default:
				return kEffectPixelShaderSlot_MoonSugar;
		}
	}

	bool EffectProfileUsesWorldWobble(UInt32 profile)
	{
		switch (profile)
		{
			case kEffectProfile_MoonSugar25:
			case kEffectProfile_MoonSugar50:
			case kEffectProfile_MoonSugar75:
			case kEffectProfile_HeadWound25:
			case kEffectProfile_HeadWound50:
			case kEffectProfile_HeadWound75:
				return true;
			default:
				return false;
		}
	}

	float GetEffectProfileWorldWobbleScale(UInt32 profile)
	{
		if (!EffectProfileUsesWorldWobble(profile))
			return 0.0f;

		return ClampFloat(GetEffectProfileSeverity(profile), 0.0f, 1.0f);
	}

	bool EffectProfileUsesDepth(UInt32 profile)
	{
		return profile == kEffectProfile_HeatShimmer50 ||
			profile == kEffectProfile_HeatShimmer100 ||
			profile == kEffectProfile_DepthMaskDebug;
	}

	const char* GetDepthSampleSourceName(UInt32 source)
	{
		switch (source)
		{
			case kDepthSampleSource_CapturedWorld:
				return "capturedWorld";
			case kDepthSampleSource_ActiveFallback:
				return "activeFallback";
			default:
				return "none";
		}
	}

	void ResetMoonSugarEffectState()
	{
		s_effect.active = false;
		s_effect.startTick = 0;
		s_effect.expireTick = 0;
		s_effect.doseCount = 0;
		s_effect.lastFormID = 0;
		s_effect.intensity = 0.0f;
		s_effect.profile = kEffectProfile_MoonSugar75;
	}

	void BuildShaderPaths()
	{
		_snprintf_s(s_shaderPath, sizeof(s_shaderPath), _TRUNCATE, "%s%s.fx", kShaderDirectory, s_shaderName);
		_snprintf_s(s_shaderBytecodePath, sizeof(s_shaderBytecodePath), _TRUNCATE, "%s%s.pso", kShaderDirectory, s_shaderName);
	}

	void SelectEffectShader(const char* shaderName, bool embeddedOnly, bool releaseShader)
	{
		bool changed = _stricmp(s_shaderName, shaderName) != 0;
		bool embeddedChanged = s_embeddedPixelShaderOnly != embeddedOnly;
		bool shaderSourceChanged = embeddedChanged || (!embeddedOnly && changed);
		strncpy_s(s_shaderName, sizeof(s_shaderName), shaderName, _TRUNCATE);
		s_embeddedPixelShaderOnly = embeddedOnly;

		BuildShaderPaths();
		if (releaseShader && shaderSourceChanged)
			ReleaseRendererResources();
	}

	void SelectMoonSugarShader(bool releaseShader)
	{
		SelectEffectShader(kDefaultShaderName, false, releaseShader);
	}

	void LoadSettings()
	{
		s_settings.moonSugarLocalFormID = kDefaultMoonSugarLocalFormID;
		s_settings.moonSugarFullFormID = 0;
		s_settings.matchLocalFormID = true;
		s_settings.matchFullFormID = false;
		s_settings.debugLog = true;
		s_settings.rendererDebugLog = true;
		s_settings.durationMs = kDefaultDurationMs;
		s_settings.maxDurationMs = kDefaultMaxDurationMs;
		s_settings.intensity = 1.0f;
		s_settings.fadeOutSeconds = 8.0f;
		s_settings.rendererEnabled = true;
		s_settings.preferCompiledShader = true;
		s_settings.preferShaderFile = true;
		s_settings.waveStrength = 0.014f;
		s_settings.swirlStrength = 0.040f;
		s_settings.chromaStrength = 0.020f;
		s_settings.colorShift = 0.34f;
		s_settings.cameraSwayEnabled = true;
		s_settings.cameraSwayStrength = 1.0f;
		s_settings.geometryWobbleEnabled = true;
		s_settings.geometryWobbleStrength = 1.0f;
		SelectMoonSugarShader(false);

		_MESSAGE(
			"Embedded settings: LocalFormID=%08X MatchLocal=%u FullFormID=%08X MatchFull=%u DurationMs=%u MaxDurationMs=%u Intensity=%.3f Renderer=%u ShaderName=%s CompiledShader=%u ShaderFile=%u CameraSway=%u CameraStrength=%.3f GeometryWobble=%u GeometryStrength=%.3f DebugLog=%u RendererDebug=%u",
			s_settings.moonSugarLocalFormID,
			s_settings.matchLocalFormID ? 1 : 0,
			s_settings.moonSugarFullFormID,
			s_settings.matchFullFormID ? 1 : 0,
			s_settings.durationMs,
			s_settings.maxDurationMs,
			s_settings.intensity,
			s_settings.rendererEnabled ? 1 : 0,
			s_shaderName,
			s_settings.preferCompiledShader ? 1 : 0,
			s_settings.preferShaderFile ? 1 : 0,
			s_settings.cameraSwayEnabled ? 1 : 0,
			s_settings.cameraSwayStrength,
			s_settings.geometryWobbleEnabled ? 1 : 0,
			s_settings.geometryWobbleStrength,
			s_settings.debugLog ? 1 : 0,
			s_settings.rendererDebugLog ? 1 : 0);
	}

	UInt32 GetEngineMagicType(MagicItem* item)
	{
		if (!item)
			return 0;

		void** vtbl = *reinterpret_cast<void***>(item);
		if (!vtbl)
			return 0;

		GetEngineMagicTypeFn getType = reinterpret_cast<GetEngineMagicTypeFn>(vtbl[6]);
		return getType ? getType(item) : 0;
	}

	TESForm* GetOwningMagicItemObject(MagicItem* item)
	{
		return item ? reinterpret_cast<TESForm*>(reinterpret_cast<UInt8*>(item) - kMagicItemOffsetInObject) : nullptr;
	}

	const char* GetFormName(TESForm* form)
	{
		if (!form)
			return "";

		TESFullName* fullName = form->GetFullName();
		return (fullName && fullName->name.m_data) ? fullName->name.m_data : "";
	}

	bool IsConfiguredMoonSugar(TESForm* form)
	{
		if (!form || form->typeID != kFormType_Ingredient)
			return false;

		if (s_settings.matchFullFormID && s_settings.moonSugarFullFormID && form->refID == s_settings.moonSugarFullFormID)
			return true;

		if (s_settings.matchLocalFormID && ((form->refID & 0x00FFFFFF) == (s_settings.moonSugarLocalFormID & 0x00FFFFFF)))
			return true;

		return false;
	}

	float SinF(float value)
	{
		return static_cast<float>(sin(static_cast<double>(value)));
	}

	float CosF(float value)
	{
		return static_cast<float>(cos(static_cast<double>(value)));
	}

	UInt32 GetNiObjectRTTI(void* object)
	{
		if (!object)
			return 0;

		void** vtbl = *reinterpret_cast<void***>(object);
		if (!vtbl || !vtbl[1])
			return 0;

		GetNiRTTIFn getType = reinterpret_cast<GetNiRTTIFn>(vtbl[1]);
		return getType(object);
	}

	void ApplySmallZRotation(float* transform, float angle)
	{
		float c = CosF(angle);
		float s = SinF(angle);

		float m00 = transform[0];
		float m01 = transform[1];
		float m02 = transform[2];
		float m10 = transform[3];
		float m11 = transform[4];
		float m12 = transform[5];

		transform[0] = c * m00 - s * m10;
		transform[1] = c * m01 - s * m11;
		transform[2] = c * m02 - s * m12;
		transform[3] = s * m00 + c * m10;
		transform[4] = s * m01 + c * m11;
		transform[5] = s * m02 + c * m12;
	}

	void* GetWorldSceneGraph()
	{
		return *reinterpret_cast<void**>(kWorldSceneGraphAddress);
	}

	NiDX9Renderer* GetRenderer()
	{
		return *reinterpret_cast<NiDX9Renderer**>(kRendererAddress);
	}

	void* GetWorldCamera()
	{
		void* sceneGraph = GetWorldSceneGraph();
		return sceneGraph ? *reinterpret_cast<void**>(reinterpret_cast<UInt8*>(sceneGraph) + kSceneGraphCameraOffset) : nullptr;
	}

	void* GetSceneGraphCullingProcess(void* sceneGraph)
	{
		return sceneGraph ? *reinterpret_cast<void**>(reinterpret_cast<UInt8*>(sceneGraph) + kSceneGraphCullingProcessOffset) : nullptr;
	}

	void ObserveMaskPrepassCandidateInputs(void* camera, void* sceneGraph, void* cullingProcess, void* visibleGeo)
	{
		++s_maskPrepassCandidateState.worldRenderCalls;

		void* worldSceneGraph = GetWorldSceneGraph();
		void* worldCamera = worldSceneGraph ? *reinterpret_cast<void**>(reinterpret_cast<UInt8*>(worldSceneGraph) + kSceneGraphCameraOffset) : nullptr;
		void* sceneGraphCullingProcess = GetSceneGraphCullingProcess(sceneGraph);
		void* cullingProcessVisibleGeo = nullptr;
		UInt32 renderMode = *reinterpret_cast<volatile UInt32*>(kRenderModeAddress);

		if (cullingProcess)
			cullingProcessVisibleGeo = *reinterpret_cast<void**>(reinterpret_cast<UInt8*>(cullingProcess) + kNiCullingProcessVisibleGeoOffset);
		else
			++s_maskPrepassCandidateState.missingCullingProcessCalls;

		if (camera && camera == worldCamera)
			++s_maskPrepassCandidateState.worldCameraCalls;
		if (sceneGraph && sceneGraph == worldSceneGraph)
			++s_maskPrepassCandidateState.worldSceneGraphCalls;
		if (cullingProcess && cullingProcess == sceneGraphCullingProcess)
			++s_maskPrepassCandidateState.sceneGraphCullingProcessCalls;
		if (renderMode == kRenderModeNormal)
			++s_maskPrepassCandidateState.normalRenderModeCalls;
		if (visibleGeo)
		{
			++s_maskPrepassCandidateState.explicitVisibleArgCalls;
			if (s_settings.rendererDebugLog && !s_maskPrepassCandidateState.firstExplicitVisibleLogged)
			{
				s_maskPrepassCandidateState.firstExplicitVisibleLogged = true;
				_MESSAGE(
					"VES mask prepass candidate: first explicit visible array arg camera=%08X sceneGraph=%08X culling=%08X visibleGeo=%08X mode=%u",
					reinterpret_cast<UInt32>(camera),
					reinterpret_cast<UInt32>(sceneGraph),
					reinterpret_cast<UInt32>(cullingProcess),
					reinterpret_cast<UInt32>(visibleGeo),
					renderMode);
			}
		}
		if (cullingProcessVisibleGeo)
		{
			++s_maskPrepassCandidateState.cullingProcessVisibleGeoCalls;
			if (s_settings.rendererDebugLog && !s_maskPrepassCandidateState.firstCullingVisibleLogged)
			{
				s_maskPrepassCandidateState.firstCullingVisibleLogged = true;
				_MESSAGE(
					"VES mask prepass candidate: first culling-process visible array camera=%08X sceneGraph=%08X culling=%08X cullingVisibleGeo=%08X mode=%u",
					reinterpret_cast<UInt32>(camera),
					reinterpret_cast<UInt32>(sceneGraph),
					reinterpret_cast<UInt32>(cullingProcess),
					reinterpret_cast<UInt32>(cullingProcessVisibleGeo),
					renderMode);
			}
		}

		s_maskPrepassCandidateState.lastRenderMode = renderMode;
		s_maskPrepassCandidateState.lastCamera = camera;
		s_maskPrepassCandidateState.lastSceneGraph = sceneGraph;
		s_maskPrepassCandidateState.lastCullingProcess = cullingProcess;
		s_maskPrepassCandidateState.lastSceneGraphCullingProcess = sceneGraphCullingProcess;
		s_maskPrepassCandidateState.lastVisibleArg = visibleGeo;
		s_maskPrepassCandidateState.lastCullingProcessVisibleGeo = cullingProcessVisibleGeo;
	}

	void MixVectors(const float* a, const float* b, float ca, float cb, float* out)
	{
		out[0] = a[0] * ca + b[0] * cb;
		out[1] = a[1] * ca + b[1] * cb;
		out[2] = a[2] * ca + b[2] * cb;
	}

	void StoreCameraBasis(float* transform, const float* right, const float* up, const float* forward)
	{
		transform[0] = right[0];
		transform[3] = right[1];
		transform[6] = right[2];
		transform[1] = up[0];
		transform[4] = up[1];
		transform[7] = up[2];
		transform[2] = forward[0];
		transform[5] = forward[1];
		transform[8] = forward[2];
	}

	float GetMoonSugarRenderIntensity(UInt32 now, UInt32* remainingMs)
	{
		UInt32 remaining = GetRemainingMillisecondsAt(now);
		if (remainingMs)
			*remainingMs = remaining;

		if (remaining == 0)
			return 0.0f;

		float intensity = s_effect.intensity;
		if (s_settings.fadeOutSeconds > 0.0f)
		{
			float remainingSeconds = static_cast<float>(remaining) * 0.001f;
			intensity *= ClampFloat(remainingSeconds / s_settings.fadeOutSeconds, 0.0f, 1.0f);
		}

		return ClampFloat(intensity, 0.0f, 1.0f);
	}

	bool ApplyMoonSugarCameraSway(void* camera, CameraTransformBackup* backup)
	{
		++s_cameraSwayState.calls;

		if (!s_settings.cameraSwayEnabled || !s_effect.active || !EffectProfileUsesWorldWobble(s_effect.profile) || !camera || !backup)
		{
			++s_cameraSwayState.skippedInactive;
			return false;
		}

		if (camera != GetWorldCamera() || *reinterpret_cast<volatile UInt32*>(kRenderModeAddress) != kRenderModeNormal)
		{
			++s_cameraSwayState.skippedFiltered;
			return false;
		}

		UInt32 now = GetTickCount();
		UInt32 remainingMs = 0;
		float intensity = GetMoonSugarRenderIntensity(now, &remainingMs);
		if (intensity <= 0.0f || remainingMs == 0)
		{
			ExpireMoonSugarEffect(now);
			++s_cameraSwayState.skippedInactive;
			return false;
		}

		intensity = ClampFloat(
			intensity * s_settings.cameraSwayStrength * GetEffectProfileWorldWobbleScale(s_effect.profile),
			0.0f,
			1.0f);
		if (intensity <= 0.0f)
			return false;

		float* transform = reinterpret_cast<float*>(reinterpret_cast<UInt8*>(camera) + kCameraWorldTransformOffset);
		memcpy(backup->transform, transform, sizeof(backup->transform));

		float right[3] = { backup->transform[0], backup->transform[3], backup->transform[6] };
		float up[3] = { backup->transform[1], backup->transform[4], backup->transform[7] };
		float forward[3] = { backup->transform[2], backup->transform[5], backup->transform[8] };
		float tempA[3];
		float tempB[3];

		float elapsed = static_cast<float>(now - s_effect.startTick) * 0.001f;
		float doseScale = ClampFloat(0.85f + static_cast<float>(s_effect.doseCount) * 0.08f, 0.85f, 1.18f);
		float sway = ClampFloat(intensity * doseScale, 0.0f, 1.0f);
		float yaw = (SinF(elapsed * 0.82f) + SinF(elapsed * 1.73f + 1.20f) * 0.32f) * 0.0110f * sway;
		float roll = (SinF(elapsed * 1.06f + 0.70f) + CosF(elapsed * 2.18f) * 0.24f) * 0.0175f * sway;
		float pitch = CosF(elapsed * 0.68f + 0.35f) * 0.0045f * sway;

		float c = CosF(roll);
		float s = SinF(roll);
		MixVectors(right, up, c, s, tempA);
		MixVectors(up, right, c, -s, tempB);
		memcpy(right, tempA, sizeof(right));
		memcpy(up, tempB, sizeof(up));

		c = CosF(yaw);
		s = SinF(yaw);
		MixVectors(forward, right, c, s, tempA);
		MixVectors(right, forward, c, -s, tempB);
		memcpy(forward, tempA, sizeof(forward));
		memcpy(right, tempB, sizeof(right));

		c = CosF(pitch);
		s = SinF(pitch);
		MixVectors(forward, up, c, s, tempA);
		MixVectors(up, forward, c, -s, tempB);
		memcpy(forward, tempA, sizeof(forward));
		memcpy(up, tempB, sizeof(up));

		StoreCameraBasis(transform, right, up, forward);

		float lateral = (SinF(elapsed * 1.24f) + SinF(elapsed * 2.85f + 0.55f) * 0.22f) * 2.4f * sway;
		float vertical = CosF(elapsed * 0.92f + 0.40f) * 0.55f * sway;
		float forwardDrift = SinF(elapsed * 0.58f + 1.10f) * 0.35f * sway;

		transform[9] = backup->transform[9] + right[0] * lateral + up[0] * vertical + forward[0] * forwardDrift;
		transform[10] = backup->transform[10] + right[1] * lateral + up[1] * vertical + forward[1] * forwardDrift;
		transform[11] = backup->transform[11] + right[2] * lateral + up[2] * vertical + forward[2] * forwardDrift;

		++s_cameraSwayState.applied;
		if (s_settings.rendererDebugLog && !s_cameraSwayState.firstAppliedLogged)
		{
			s_cameraSwayState.firstAppliedLogged = true;
			_MESSAGE(
				"VES camera sway first frame camera=%08X intensity=%.3f yaw=%.5f roll=%.5f pitch=%.5f",
				reinterpret_cast<UInt32>(camera),
				sway,
				yaw,
				roll,
				pitch);
		}

		return true;
	}

	void RestoreCameraTransform(void* camera, const CameraTransformBackup* backup)
	{
		if (!camera || !backup)
			return;

		float* transform = reinterpret_cast<float*>(reinterpret_cast<UInt8*>(camera) + kCameraWorldTransformOffset);
		memcpy(transform, backup->transform, sizeof(backup->transform));
	}

	void RestoreRendererCameraState(void* camera)
	{
		NiDX9Renderer* renderer = GetRenderer();
		if (!renderer || !camera)
			return;

		s_setCameraViewProj(renderer, camera);
		++s_cameraSwayState.rendererRestored;
	}

	float* __cdecl PrepareMoonSugarGeometryTransform(
		float* localTransform,
		const float* originalTransform,
		NiDX9Renderer* renderer,
		void* geometry,
		void* geomData,
		void* skinInstance,
		UInt32 boundPtr,
		void* bufferData)
	{
		(void)renderer;
		(void)boundPtr;
		++s_geometryWobbleState.calls;

		if (!s_settings.geometryWobbleEnabled || !s_effect.active || !EffectProfileUsesWorldWobble(s_effect.profile))
		{
			++s_geometryWobbleState.skippedInactive;
			return const_cast<float*>(originalTransform);
		}

		UInt32 now = GetTickCount();
		UInt32 remainingMs = GetRemainingMillisecondsAt(now);
		if (remainingMs == 0)
		{
			ExpireMoonSugarEffect(now);
			++s_geometryWobbleState.skippedInactive;
			return const_cast<float*>(originalTransform);
		}

		if (!geometry || !geomData || !originalTransform || !bufferData)
			return const_cast<float*>(originalTransform);

		if (skinInstance)
		{
			++s_geometryWobbleState.skippedSkinned;
			return const_cast<float*>(originalTransform);
		}

		if (GetNiObjectRTTI(geometry) == kNiScreenElementsRTTI)
		{
			++s_geometryWobbleState.skippedScreenElements;
			return const_cast<float*>(originalTransform);
		}

		if (*reinterpret_cast<volatile UInt32*>(kRenderModeAddress) != kRenderModeNormal)
			return const_cast<float*>(originalTransform);

		memcpy(localTransform, originalTransform, sizeof(float) * 13);

		float intensity = ClampFloat(
			s_effect.intensity * s_settings.geometryWobbleStrength * GetEffectProfileWorldWobbleScale(s_effect.profile),
			0.0f,
			1.0f);
		if (s_settings.fadeOutSeconds > 0.0f)
		{
			float remainingSeconds = static_cast<float>(remainingMs) * 0.001f;
			intensity *= ClampFloat(remainingSeconds / s_settings.fadeOutSeconds, 0.0f, 1.0f);
		}

		if (intensity <= 0.0f)
			return const_cast<float*>(originalTransform);

		UInt32 seed = reinterpret_cast<UInt32>(geometry);
		float phase = static_cast<float>((seed >> 4) & 0x3FF) * 0.006135923f;
		float elapsed = static_cast<float>(now - s_effect.startTick) * 0.001f;
		float slow = SinF(elapsed * 1.45f + phase);
		float cross = CosF(elapsed * 1.05f + phase * 1.37f);
		float tremor = SinF(elapsed * 4.90f + phase * 0.73f);
		float lift = CosF(elapsed * 2.25f + phase * 1.91f);

		float translationAmplitude = 0.85f * intensity;
		localTransform[9] += (slow * 0.62f + tremor * 0.10f) * translationAmplitude;
		localTransform[10] += (cross * 0.54f) * translationAmplitude;
		localTransform[11] += (lift * 0.18f) * translationAmplitude;

		float angle = (slow * 0.65f + tremor * 0.18f) * 0.0045f * intensity;
		ApplySmallZRotation(localTransform, angle);

		if (localTransform[12] > 0.001f)
			localTransform[12] *= 1.0f + SinF(elapsed * 1.80f + phase * 2.10f) * 0.0018f * intensity;

		++s_geometryWobbleState.applied;
		if (s_settings.rendererDebugLog && !s_geometryWobbleState.firstAppliedLogged)
		{
			s_geometryWobbleState.firstAppliedLogged = true;
			_MESSAGE(
				"VES geometry wobble first object geometry=%08X geomData=%08X buffData=%08X intensity=%.3f",
				reinterpret_cast<UInt32>(geometry),
				reinterpret_cast<UInt32>(geomData),
				reinterpret_cast<UInt32>(bufferData),
				intensity);
		}

		return localTransform;
	}

	UInt32 StartEffectProfile(
		TESForm* form,
		bool stackDuration,
		const char* reason,
		UInt32 profile,
		UInt32 durationMs,
		UInt32 maxDurationMs,
		float intensity)
	{
		UInt32 now = GetTickCount();
		UInt32 previousRemainingMs = GetRemainingMillisecondsAt(now);
		bool wasActive = s_effect.active && previousRemainingMs > 0;
		bool sameProfile = wasActive && s_effect.profile == profile;
		UInt32 baseMs = (stackDuration && sameProfile) ? previousRemainingMs : 0;
		UInt32 remainingMs = AddDurationCapped(baseMs, durationMs, maxDurationMs);

		if (!wasActive || !stackDuration || !sameProfile)
			s_effect.doseCount = 0;

		s_effect.active = true;
		s_effect.startTick = (sameProfile && stackDuration) ? s_effect.startTick : now;
		s_effect.expireTick = now + remainingMs;
		s_effect.lastFormID = form ? form->refID : 0;
		s_effect.intensity = ClampFloat(intensity, 0.0f, 1.0f);
		s_effect.profile = profile;
		++s_effect.doseCount;

		_MESSAGE(
			"VES effect started: profile=%s reason=%s form=%08X name=\"%s\" stack=%u previousRemainingMs=%u remainingMs=%u doses=%u intensity=%.3f",
			GetEffectProfileName(profile),
			reason ? reason : "unknown",
			s_effect.lastFormID,
			GetFormName(form),
			stackDuration ? 1 : 0,
			previousRemainingMs,
			remainingMs,
			s_effect.doseCount,
			s_effect.intensity);
		_MESSAGE(
			"VES effect pipeline: profile=%s imageSpace=1 depth=%u worldWobble=%u worldScale=%.3f family=%u pixelSlot=%u shaderName=%s embeddedOnly=%u",
			GetEffectProfileName(profile),
			EffectProfileUsesDepth(profile) ? 1 : 0,
			EffectProfileUsesWorldWobble(profile) ? 1 : 0,
			GetEffectProfileWorldWobbleScale(profile),
			GetEffectProfileShaderFamily(profile),
			GetEffectProfilePixelShaderSlot(profile),
			s_shaderName,
			s_embeddedPixelShaderOnly ? 1 : 0);

		return remainingMs;
	}

	UInt32 StartMoonSugarEffect(TESForm* form, bool stackDuration, const char* reason)
	{
		return StartEffectProfile(
			form,
			stackDuration,
			reason,
			kEffectProfile_MoonSugar75,
			s_settings.durationMs,
			s_settings.maxDurationMs,
			ClampFloat(s_settings.intensity * GetEffectProfileSeverity(kEffectProfile_MoonSugar75), 0.0f, 1.0f));
	}

	UInt32 StartMoonSugarProfileEffect(UInt32 profile)
	{
		SelectMoonSugarShader(true);

		return StartEffectProfile(
			nullptr,
			false,
			GetEffectProfileName(profile),
			profile,
			s_settings.durationMs,
			s_settings.durationMs,
			GetEffectProfileSeverity(profile));
	}

	UInt32 GetHeadWoundDuration(UInt32 profile)
	{
		if (profile == kEffectProfile_HeadWound25)
			return kHeadWoundSmallDurationMs;
		if (profile == kEffectProfile_HeadWound50)
			return (kHeadWoundSmallDurationMs + kHeadWoundBigDurationMs) / 2;
		return kHeadWoundBigDurationMs;
	}

	UInt32 StartHeadWoundEffect(UInt32 profile)
	{
		UInt32 durationMs = GetHeadWoundDuration(profile);
		SelectMoonSugarShader(true);

		return StartEffectProfile(
			nullptr,
			false,
			GetEffectProfileName(profile),
			profile,
			durationMs,
			durationMs,
			1.0f);
	}

	UInt32 StartBlindEffect(UInt32 profile)
	{
		const char* profileName = GetEffectProfileName(profile);
		SelectMoonSugarShader(true);

		return StartEffectProfile(
			nullptr,
			false,
			profileName,
			profile,
			kBlindDurationMs,
			kBlindDurationMs,
			1.0f);
	}

	UInt32 StartDimEffect(UInt32 profile)
	{
		SelectMoonSugarShader(true);

		return StartEffectProfile(
			nullptr,
			false,
			GetEffectProfileName(profile),
			profile,
			s_settings.durationMs,
			s_settings.durationMs,
			1.0f);
	}

	UInt32 StartOnFireEffect(UInt32 profile)
	{
		SelectMoonSugarShader(true);

		return StartEffectProfile(
			nullptr,
			false,
			GetEffectProfileName(profile),
			profile,
			s_settings.durationMs,
			s_settings.durationMs,
			1.0f);
	}

	UInt32 StartHeatShimmerEffect(UInt32 profile)
	{
		SelectMoonSugarShader(true);

		return StartEffectProfile(
			nullptr,
			false,
			GetEffectProfileName(profile),
			profile,
			s_settings.durationMs,
			s_settings.durationMs,
			1.0f);
	}

	UInt32 StartDepthMaskDebugEffect()
	{
		SelectMoonSugarShader(true);

		return StartEffectProfile(
			nullptr,
			false,
			GetEffectProfileName(kEffectProfile_DepthMaskDebug),
			kEffectProfile_DepthMaskDebug,
			s_settings.durationMs,
			s_settings.durationMs,
			1.0f);
	}

	UInt32 StartRainEffect(UInt32 profile)
	{
		SelectMoonSugarShader(true);

		return StartEffectProfile(
			nullptr,
			false,
			GetEffectProfileName(profile),
			profile,
			s_settings.durationMs,
			s_settings.durationMs,
			1.0f);
	}

	UInt32 StartFrostEffect(UInt32 profile)
	{
		SelectMoonSugarShader(true);

		return StartEffectProfile(
			nullptr,
			false,
			GetEffectProfileName(profile),
			profile,
			s_settings.durationMs,
			s_settings.durationMs,
			1.0f);
	}

	UInt32 SumCountArray(const UInt32* values, UInt32 count)
	{
		UInt32 total = 0;
		if (!values)
			return 0;

		for (UInt32 i = 0; i < count; ++i)
			total += values[i];
		return total;
	}

	UInt32 BuildAppliedMaskFromCounts(const UInt32* values, UInt32 count)
	{
		UInt32 mask = 0;
		if (!values)
			return 0;

		UInt32 maxCount = count > 32 ? 32 : count;
		for (UInt32 i = 0; i < maxCount; ++i)
			if (values[i])
				mask |= (1u << i);
		return mask;
	}

	UInt32 BuildProfilePixelShaderMask()
	{
		UInt32 mask = 0;
		for (UInt32 i = 0; i < kEffectPixelShaderSlot_Count && i < 32; ++i)
			if (s_rendererState.profilePixelShaders[i])
				mask |= (1u << i);
		return mask;
	}

	void LogMoonSugarPipelineSummary(const char* reason, UInt32 now)
	{
		if (!s_settings.rendererDebugLog || !s_effect.active)
			return;

		_MESSAGE(
			"VES pipeline summary: reason=%s profile=%s pixelSlot=%u profileShaderMask=%02X fallback=%u elapsedMs=%u remainingMs=%u imageSpace=%u frames=%u renderFailures=%u rendererShaderFailures=%u depthCapture=%u/%u/%u depthActive=%u depthFormat=%08X camera=%u/%u restored=%u geom=%u/%u skipScreen=%u skipSkin=%u object=%u/%u skin=%u/%u census=%u lighting=%u parallax=%u skinPass=%u skipInactive=%u skipPass=%u skipScreen=%u objectShaderFailures=%u legacyAppliedMask=%02X sm3AppliedMask=%02X envAppliedMask=%02X texAppliedMask=%02X decalAppliedMask=%02X depthAppliedMask=%02X supportAppliedMask=%08X",
			reason ? reason : "unknown",
			GetEffectProfileName(s_effect.profile),
			GetEffectProfilePixelShaderSlot(s_effect.profile),
			BuildProfilePixelShaderMask(),
			s_rendererState.fallbackShaderUsed ? 1 : 0,
			now - s_effect.startTick,
			GetRemainingMillisecondsAt(now),
			s_rendererState.imageSpaceCalls,
			s_rendererState.renderedFrames,
			s_rendererState.renderFailures,
			s_rendererState.shaderFailures,
			s_rendererState.depthCaptureAttempts,
			s_rendererState.depthCaptureSuccess,
			s_rendererState.depthCaptureFailures,
			s_rendererState.depthCaptureActiveLastFrame ? 1 : 0,
			s_rendererState.capturedDepthFormat,
			s_cameraSwayState.calls,
			s_cameraSwayState.applied,
			s_cameraSwayState.rendererRestored,
			s_geometryWobbleState.calls,
			s_geometryWobbleState.applied,
			s_geometryWobbleState.skippedScreenElements,
			s_geometryWobbleState.skippedSkinned,
			s_objectVertexShaderState.calls,
			s_objectVertexShaderState.applied,
			s_objectVertexShaderState.skinnedCalls,
			s_objectVertexShaderState.skinnedApplied,
			s_objectVertexShaderState.passCensusSamples,
			SumCountArray(s_objectVertexShaderState.lighting30PassCounts, kLighting30PassCount),
			SumCountArray(s_objectVertexShaderState.parallaxPassCounts, kParallaxPassCount),
			SumCountArray(s_objectVertexShaderState.skinPassCounts, kSkinPassCount),
			s_objectVertexShaderState.skippedInactive,
			s_objectVertexShaderState.skippedPass,
			s_objectVertexShaderState.skippedScreenElements,
			s_objectVertexShaderState.shaderFailures,
			BuildAppliedMaskFromCounts(s_objectVertexShaderState.legacyApplied, kLegacyObjectVertexShaderVariantCount),
			BuildAppliedMaskFromCounts(s_objectVertexShaderState.lighting30Applied, kLighting30ObjectVertexShaderVariantCount),
			BuildAppliedMaskFromCounts(s_objectVertexShaderState.lighting30EnvMapApplied, kLighting30EnvMapVertexShaderVariantCount),
			BuildAppliedMaskFromCounts(s_objectVertexShaderState.lighting30TexEffectApplied, kLighting30TexEffectVertexShaderVariantCount),
			BuildAppliedMaskFromCounts(s_objectVertexShaderState.lighting30DecalApplied, kLighting30DecalVertexShaderVariantCount),
			BuildAppliedMaskFromCounts(s_objectVertexShaderState.lighting30DepthMapApplied, kLighting30DepthMapVertexShaderVariantCount),
			BuildAppliedMaskFromCounts(s_objectVertexShaderState.lighting30SupportApplied, kLighting30SupportVertexShaderVariantCount));
	}

	void ClearMoonSugarEffect()
	{
		if (s_settings.debugLog && s_effect.active)
		{
			UInt32 now = GetTickCount();
			LogMoonSugarPipelineSummary("stop", now);
			_MESSAGE(
				"VES effect stopped: remainingMs=%u doses=%u",
				GetRemainingMillisecondsAt(now),
				s_effect.doseCount);
		}

		ResetMoonSugarEffectState();
	}

	void ExpireMoonSugarEffect(UInt32 now)
	{
		if (s_settings.debugLog && s_effect.active)
		{
			LogMoonSugarPipelineSummary("expire", now);
			_MESSAGE(
				"VES effect expired: elapsedMs=%u doses=%u",
				now - s_effect.startTick,
				s_effect.doseCount);
		}

		ResetMoonSugarEffectState();
	}

	template <typename T>
	void ReleaseCom(T*& object)
	{
		if (object)
		{
			object->Release();
			object = nullptr;
		}
	}

	void ReleaseObjectVertexShaderResources()
	{
		ReleaseCom(s_objectVertexShaderState.vertexShader);
		for (UInt32 i = 0; i < kLighting30ObjectVertexShaderVariantCount; ++i)
			ReleaseCom(s_objectVertexShaderState.lighting30VertexShaders[i]);
		for (UInt32 i = 0; i < kLighting30EnvMapVertexShaderVariantCount; ++i)
			ReleaseCom(s_objectVertexShaderState.lighting30EnvMapVertexShaders[i]);
		for (UInt32 i = 0; i < kLighting30TexEffectVertexShaderVariantCount; ++i)
			ReleaseCom(s_objectVertexShaderState.lighting30TexEffectVertexShaders[i]);
		for (UInt32 i = 0; i < kLighting30DecalVertexShaderVariantCount; ++i)
			ReleaseCom(s_objectVertexShaderState.lighting30DecalVertexShaders[i]);
		for (UInt32 i = 0; i < kLighting30DepthMapVertexShaderVariantCount; ++i)
			ReleaseCom(s_objectVertexShaderState.lighting30DepthMapVertexShaders[i]);
		for (UInt32 i = 0; i < kLighting30SupportVertexShaderVariantCount; ++i)
			ReleaseCom(s_objectVertexShaderState.lighting30SupportVertexShaders[i]);
		s_objectVertexShaderState.device = nullptr;
		s_objectVertexShaderState.compileAttempted = false;
		s_objectVertexShaderState.compileFailed = false;
		for (UInt32 i = 0; i < kLighting30ObjectVertexShaderVariantCount; ++i)
		{
			s_objectVertexShaderState.lighting30CompileAttempted[i] = false;
			s_objectVertexShaderState.lighting30CompileFailed[i] = false;
		}
		for (UInt32 i = 0; i < kLighting30EnvMapVertexShaderVariantCount; ++i)
		{
			s_objectVertexShaderState.lighting30EnvMapCompileAttempted[i] = false;
			s_objectVertexShaderState.lighting30EnvMapCompileFailed[i] = false;
		}
		for (UInt32 i = 0; i < kLighting30TexEffectVertexShaderVariantCount; ++i)
		{
			s_objectVertexShaderState.lighting30TexEffectCompileAttempted[i] = false;
			s_objectVertexShaderState.lighting30TexEffectCompileFailed[i] = false;
		}
		for (UInt32 i = 0; i < kLighting30DecalVertexShaderVariantCount; ++i)
		{
			s_objectVertexShaderState.lighting30DecalCompileAttempted[i] = false;
			s_objectVertexShaderState.lighting30DecalCompileFailed[i] = false;
		}
		for (UInt32 i = 0; i < kLighting30DepthMapVertexShaderVariantCount; ++i)
		{
			s_objectVertexShaderState.lighting30DepthMapCompileAttempted[i] = false;
			s_objectVertexShaderState.lighting30DepthMapCompileFailed[i] = false;
		}
		for (UInt32 i = 0; i < kLighting30SupportVertexShaderVariantCount; ++i)
		{
			s_objectVertexShaderState.lighting30SupportCompileAttempted[i] = false;
			s_objectVertexShaderState.lighting30SupportCompileFailed[i] = false;
		}
	}

	void ReleaseProfilePixelShaders()
	{
		for (UInt32 i = 0; i < kEffectPixelShaderSlot_Count; ++i)
			ReleaseCom(s_rendererState.profilePixelShaders[i]);
	}

	bool ProfilePixelShadersLoaded()
	{
		for (UInt32 i = 0; i < kEffectPixelShaderSlot_Count; ++i)
		{
			if (!s_rendererState.profilePixelShaders[i])
				return false;
		}
		return true;
	}

	bool ActiveProfilePixelShaderLoaded()
	{
		UInt32 slot = GetEffectProfilePixelShaderSlot(s_effect.profile);
		return slot < kEffectPixelShaderSlot_Count && s_rendererState.profilePixelShaders[slot] != nullptr;
	}

	bool EffectProfileRequiresCurrentProfileShader(UInt32 profile)
	{
		return profile == kEffectProfile_HeadWound25 ||
			profile == kEffectProfile_HeadWound50 ||
			profile == kEffectProfile_HeadWound75 ||
			profile == kEffectProfile_Blind25 ||
			profile == kEffectProfile_Blind50 ||
			profile == kEffectProfile_Blind75 ||
			profile == kEffectProfile_Blind100 ||
			profile == kEffectProfile_Dim50 ||
			profile == kEffectProfile_Dim100 ||
			profile == kEffectProfile_DimWhiteInverted ||
			profile == kEffectProfile_DimPurple ||
			profile == kEffectProfile_DimDarkRed ||
			profile == kEffectProfile_HeatShimmer50 ||
			profile == kEffectProfile_HeatShimmer100;
	}

	IDirect3DPixelShader9* GetActivePixelShader()
	{
		UInt32 slot = GetEffectProfilePixelShaderSlot(s_effect.profile);
		if (slot < kEffectPixelShaderSlot_Count && s_rendererState.profilePixelShaders[slot])
			return s_rendererState.profilePixelShaders[slot];
		if (EffectProfileRequiresCurrentProfileShader(s_effect.profile))
			return nullptr;
		return s_rendererState.pixelShader;
	}

	bool RendererHasPixelShader()
	{
		return GetActivePixelShader() != nullptr;
	}

	void ReleaseRendererResources()
	{
		ReleaseProfilePixelShaders();
		ReleaseCom(s_rendererState.pixelShader);
		ReleaseCom(s_rendererState.capturedDepthSurface);
		ReleaseCom(s_rendererState.capturedDepthTexture);
		ReleaseObjectVertexShaderResources();
		s_rendererState.shaderCompileAttempted = false;
		s_rendererState.shaderCompileFailed = false;
		s_rendererState.fallbackShaderUsed = false;
		s_rendererState.capturedDepthWidth = 0;
		s_rendererState.capturedDepthHeight = 0;
		s_rendererState.capturedDepthFormat = 0;
		s_rendererState.capturedDepthTick = 0;
		s_rendererState.depthLastSource = kDepthSampleSource_None;
		s_rendererState.depthCaptureActiveLastFrame = false;
	}

	bool EnsureD3DXCompiler()
	{
		if (s_d3dxCompileShader && s_d3dxCompileShaderFromFileA)
			return true;

		if (!s_d3dxModule)
			s_d3dxModule = LoadLibraryA("d3dx9_43.dll");

		if (!s_d3dxModule)
		{
			_MESSAGE("ERROR::EnsureD3DXCompiler: d3dx9_43.dll is unavailable; VES shader compilation disabled");
			return false;
		}

		s_d3dxCompileShader = reinterpret_cast<D3DXCompileShaderPtr>(GetProcAddress(s_d3dxModule, "D3DXCompileShader"));
		s_d3dxCompileShaderFromFileA = reinterpret_cast<D3DXCompileShaderFromFileAPtr>(GetProcAddress(s_d3dxModule, "D3DXCompileShaderFromFileA"));

		if (!s_d3dxCompileShader || !s_d3dxCompileShaderFromFileA)
		{
			_MESSAGE("ERROR::EnsureD3DXCompiler: d3dx9_43.dll does not expose required shader compiler entry points");
			s_d3dxCompileShader = nullptr;
			s_d3dxCompileShaderFromFileA = nullptr;
			return false;
		}

		return true;
	}

	bool LoadPixelShaderBytecodeFromPath(const char* path, IDirect3DDevice9* device, IDirect3DPixelShader9** outShader)
	{
		HANDLE file = CreateFileA(path, GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
		if (file == INVALID_HANDLE_VALUE)
			return false;

		DWORD byteCount = GetFileSize(file, nullptr);
		if (byteCount == INVALID_FILE_SIZE || byteCount < sizeof(DWORD) || (byteCount % sizeof(DWORD)) != 0)
		{
			_MESSAGE("ERROR::LoadPixelShaderBytecode: invalid shader bytecode size for %s", path);
			CloseHandle(file);
			return false;
		}

		void* buffer = malloc(byteCount);
		if (!buffer)
		{
			_MESSAGE("ERROR::LoadPixelShaderBytecode: allocation failed for %u byte shader", byteCount);
			CloseHandle(file);
			return false;
		}

		DWORD bytesRead = 0;
		BOOL ok = ReadFile(file, buffer, byteCount, &bytesRead, nullptr);
		CloseHandle(file);

		if (!ok || bytesRead != byteCount)
		{
			_MESSAGE("ERROR::LoadPixelShaderBytecode: ReadFile failed for %s bytesRead=%u expected=%u", path, bytesRead, byteCount);
			free(buffer);
			return false;
		}

		HRESULT result = device->CreatePixelShader(reinterpret_cast<const DWORD*>(buffer), outShader);
		free(buffer);

		if (FAILED(result) || !*outShader)
		{
			_MESSAGE("ERROR::LoadPixelShaderBytecode: CreatePixelShader failed for %s hr=%08X", path, result);
			*outShader = nullptr;
			return false;
		}

		return true;
	}

	bool LoadPixelShaderBytecode(IDirect3DDevice9* device, IDirect3DPixelShader9** outShader)
	{
		if (LoadPixelShaderBytecodeFromPath(s_shaderBytecodePath, device, outShader))
		{
			_MESSAGE("VES distortion shader loaded from %s", s_shaderBytecodePath);
			return true;
		}
		return false;
	}

	bool LoadProfilePixelShaderBytecode(IDirect3DDevice9* device)
	{
		ReleaseProfilePixelShaders();
		UInt32 loadedCount = 0;
		for (UInt32 i = 0; i < kEffectPixelShaderSlot_Count; ++i)
		{
			if (LoadPixelShaderBytecodeFromPath(kEffectPixelShaderBytecodeFiles[i], device, &s_rendererState.profilePixelShaders[i]))
				++loadedCount;
		}

		if (!loadedCount)
			return false;

		_MESSAGE(
			"VES optimized profile pixel shaders loaded from Data\\Shaders\\VES count=%u mask=%02X activeSlot=%u activeLoaded=%u",
			loadedCount,
			BuildProfilePixelShaderMask(),
			GetEffectProfilePixelShaderSlot(s_effect.profile),
			ActiveProfilePixelShaderLoaded() ? 1 : 0);
		return ActiveProfilePixelShaderLoaded();
	}

	bool LoadEmbeddedPixelShaderBytecode(IDirect3DDevice9* device, IDirect3DPixelShader9** outShader)
	{
		if (!device || !outShader)
			return false;

		if (sizeof(kEmbeddedFallbackPixelShaderBytecode) != kEmbeddedFallbackPixelShaderBytecodeBytes)
		{
			_MESSAGE(
				"ERROR::LoadEmbeddedPixelShaderBytecode: embedded bytecode size mismatch sizeof=%u expected=%u",
				static_cast<UInt32>(sizeof(kEmbeddedFallbackPixelShaderBytecode)),
				kEmbeddedFallbackPixelShaderBytecodeBytes);
			return false;
		}

		HRESULT result = device->CreatePixelShader(reinterpret_cast<const DWORD*>(kEmbeddedFallbackPixelShaderBytecode), outShader);
		if (FAILED(result) || !*outShader)
		{
			_MESSAGE("ERROR::LoadEmbeddedPixelShaderBytecode: CreatePixelShader failed hr=%08X", result);
			*outShader = nullptr;
			return false;
		}

		_MESSAGE("VES distortion shader loaded from embedded bytecode profile=%s", s_shaderName);
		return true;
	}

	bool CompilePixelShaderSource(
		const char* source,
		const char* sourceName,
		IDirect3DDevice9* device,
		IDirect3DPixelShader9** outShader)
	{
		if (!EnsureD3DXCompiler())
			return false;

		ID3DXBuffer* shaderCode = nullptr;
		ID3DXBuffer* errors = nullptr;

		HRESULT result = s_d3dxCompileShader(
			source,
			static_cast<UINT>(strlen(source)),
			nullptr,
			nullptr,
			"MoonSugarPS",
			kShaderProfile,
			D3DXSHADER_OPTIMIZATION_LEVEL3,
			&shaderCode,
			&errors,
			nullptr);

		if (FAILED(result) || !shaderCode)
		{
			const char* errorText = errors ? static_cast<const char*>(errors->GetBufferPointer()) : "";
			_MESSAGE("ERROR::CompilePixelShaderSource: %s failed hr=%08X %s", sourceName, result, errorText);
			ReleaseCom(errors);
			ReleaseCom(shaderCode);
			return false;
		}

		result = device->CreatePixelShader(reinterpret_cast<const DWORD*>(shaderCode->GetBufferPointer()), outShader);
		ReleaseCom(errors);
		ReleaseCom(shaderCode);

		if (FAILED(result) || !*outShader)
		{
			_MESSAGE("ERROR::CompilePixelShaderSource: CreatePixelShader for %s failed hr=%08X", sourceName, result);
			*outShader = nullptr;
			return false;
		}

		return true;
	}

	bool CompilePixelShaderFileEntry(
		IDirect3DDevice9* device,
		const char* entryPoint,
		IDirect3DPixelShader9** outShader)
	{
		if (!EnsureD3DXCompiler())
			return false;

		ID3DXBuffer* shaderCode = nullptr;
		ID3DXBuffer* errors = nullptr;

		HRESULT result = s_d3dxCompileShaderFromFileA(
			s_shaderPath,
			nullptr,
			nullptr,
			entryPoint,
			kShaderProfile,
			D3DXSHADER_OPTIMIZATION_LEVEL3,
			&shaderCode,
			&errors,
			nullptr);

		if (FAILED(result) || !shaderCode)
		{
			const char* errorText = errors ? static_cast<const char*>(errors->GetBufferPointer()) : "";
			_MESSAGE("ERROR::CompilePixelShaderFile: %s entry=%s failed hr=%08X %s", s_shaderPath, entryPoint, result, errorText);
			ReleaseCom(errors);
			ReleaseCom(shaderCode);
			return false;
		}

		result = device->CreatePixelShader(reinterpret_cast<const DWORD*>(shaderCode->GetBufferPointer()), outShader);
		ReleaseCom(errors);
		ReleaseCom(shaderCode);

		if (FAILED(result) || !*outShader)
		{
			_MESSAGE("ERROR::CompilePixelShaderFile: CreatePixelShader failed hr=%08X", result);
			*outShader = nullptr;
			return false;
		}

		return true;
	}

	bool CompilePixelShaderFile(IDirect3DDevice9* device, IDirect3DPixelShader9** outShader)
	{
		return CompilePixelShaderFileEntry(device, "MoonSugarPS", outShader);
	}

	bool CompileProfilePixelShaderFile(IDirect3DDevice9* device)
	{
		if (!EnsureD3DXCompiler())
			return false;

		ReleaseProfilePixelShaders();
		UInt32 compiledCount = 0;
		for (UInt32 i = 0; i < kEffectPixelShaderSlot_Count; ++i)
		{
			if (CompilePixelShaderFileEntry(device, kEffectPixelShaderEntries[i], &s_rendererState.profilePixelShaders[i]))
				++compiledCount;
		}

		if (!compiledCount)
			return false;

		_MESSAGE(
			"VES optimized profile pixel shaders compiled from %s count=%u mask=%02X activeSlot=%u activeLoaded=%u",
			s_shaderPath,
			compiledCount,
			BuildProfilePixelShaderMask(),
			GetEffectProfilePixelShaderSlot(s_effect.profile),
			ActiveProfilePixelShaderLoaded() ? 1 : 0);
		return ActiveProfilePixelShaderLoaded();
	}

	bool EnsurePixelShader(IDirect3DDevice9* device)
	{
		if (RendererHasPixelShader())
			return true;

		if (s_rendererState.shaderCompileFailed)
			return false;

		D3DCAPS9 caps = {};
		HRESULT capsResult = device->GetDeviceCaps(&caps);
		if (SUCCEEDED(capsResult) && caps.PixelShaderVersion < D3DPS_VERSION(3, 0))
		{
			_MESSAGE(
				"ERROR::EnsurePixelShader: selected shader profile %s requires pixel shader 3.0, device reports %u.%u",
				kShaderProfile,
				D3DSHADER_VERSION_MAJOR(caps.PixelShaderVersion),
				D3DSHADER_VERSION_MINOR(caps.PixelShaderVersion));
			s_rendererState.shaderCompileFailed = true;
			++s_rendererState.shaderFailures;
			return false;
		}

		s_rendererState.shaderCompileAttempted = true;
		s_rendererState.fallbackShaderUsed = false;

		if (s_embeddedPixelShaderOnly && LoadEmbeddedPixelShaderBytecode(device, &s_rendererState.pixelShader))
		{
			s_rendererState.fallbackShaderUsed = true;
			return true;
		}

		if (!s_embeddedPixelShaderOnly && s_settings.preferCompiledShader && LoadProfilePixelShaderBytecode(device))
			return true;

		if (!s_embeddedPixelShaderOnly && s_settings.preferCompiledShader && LoadPixelShaderBytecode(device, &s_rendererState.pixelShader))
			return true;

		if (!s_embeddedPixelShaderOnly && s_settings.preferShaderFile && CompileProfilePixelShaderFile(device))
			return true;

		if (!s_embeddedPixelShaderOnly && s_settings.preferShaderFile && CompilePixelShaderFile(device, &s_rendererState.pixelShader))
		{
			_MESSAGE("VES distortion shader loaded from %s", s_shaderPath);
			return true;
		}

		if (LoadEmbeddedPixelShaderBytecode(device, &s_rendererState.pixelShader))
		{
			s_rendererState.fallbackShaderUsed = true;
			return true;
		}

		if (CompilePixelShaderSource(kFallbackPixelShader, "embedded fallback shader", device, &s_rendererState.pixelShader))
		{
			s_rendererState.fallbackShaderUsed = true;
			_MESSAGE("VES distortion shader using embedded fallback profile=%s", s_shaderName);
			return true;
		}

		s_rendererState.shaderCompileFailed = true;
		++s_rendererState.shaderFailures;
		return false;
	}

	bool CreateEmbeddedVertexShaderBytecode(
		IDirect3DDevice9* device,
		const MoonSugarEmbeddedVertexShaderBytecode& bytecode,
		const char* profile,
		const char* label,
		IDirect3DVertexShader9** outShader)
	{
		if (!outShader)
			return false;

		*outShader = nullptr;
		if (!device || !bytecode.words || bytecode.wordCount == 0)
			return false;

		UInt32 versionToken = bytecode.words[0];
		UInt32 expectedVersionToken = 0;
		if (profile && strcmp(profile, kObjectVertexShaderProfile) == 0)
			expectedVersionToken = 0xFFFE0200;
		else if (profile && strcmp(profile, kLighting30ObjectVertexShaderProfile) == 0)
			expectedVersionToken = 0xFFFE0300;

		if (expectedVersionToken && versionToken != expectedVersionToken)
		{
			_MESSAGE(
				"ERROR::CreateEmbeddedVertexShaderBytecode: embedded %s token %08X did not match %s token %08X",
				label,
				versionToken,
				profile,
				expectedVersionToken);
			return false;
		}

		HRESULT result = device->CreateVertexShader(reinterpret_cast<const DWORD*>(bytecode.words), outShader);
		if (FAILED(result) || !*outShader)
		{
			_MESSAGE("ERROR::CreateEmbeddedVertexShaderBytecode: CreateVertexShader failed for %s %s hr=%08X", label, profile, result);
			*outShader = nullptr;
			return false;
		}

		_MESSAGE("VES object vertex shader loaded embedded bytecode %s %s replacement words=%u", label, profile, bytecode.wordCount);
		return true;
	}

	bool CompileVertexShaderSource(
		IDirect3DDevice9* device,
		const char* source,
		const char* profile,
		const char* label,
		const D3DXMACRO* defines,
		IDirect3DVertexShader9** outShader)
	{
		if (!EnsureD3DXCompiler())
			return false;

		ID3DXBuffer* shaderCode = nullptr;
		ID3DXBuffer* errors = nullptr;

		HRESULT result = s_d3dxCompileShader(
			source,
			static_cast<UINT>(strlen(source)),
			defines,
			nullptr,
			"MoonSugarVS",
			profile,
			D3DXSHADER_OPTIMIZATION_LEVEL3,
			&shaderCode,
			&errors,
			nullptr);

		if (FAILED(result) || !shaderCode)
		{
			const char* errorText = errors ? static_cast<const char*>(errors->GetBufferPointer()) : "";
			_MESSAGE("ERROR::CompileVertexShaderSource: embedded %s %s shader failed hr=%08X %s", label, profile, result, errorText);
			ReleaseCom(errors);
			ReleaseCom(shaderCode);
			return false;
		}

		result = device->CreateVertexShader(reinterpret_cast<const DWORD*>(shaderCode->GetBufferPointer()), outShader);
		ReleaseCom(errors);
		ReleaseCom(shaderCode);

		if (FAILED(result) || !*outShader)
		{
			_MESSAGE("ERROR::CompileVertexShaderSource: CreateVertexShader failed for %s %s hr=%08X", label, profile, result);
			*outShader = nullptr;
			return false;
		}

		_MESSAGE("VES object vertex shader compiled embedded %s %s replacement", label, profile);
		return true;
	}

	bool CompileObjectVertexShaderSource(IDirect3DDevice9* device, IDirect3DVertexShader9** outShader)
	{
		MoonSugarEmbeddedVertexShaderBytecode bytecode =
		{
			kEmbeddedMoonSugarObjectVertexShaderBytecode_PAR2016_SKIN2008,
			sizeof(kEmbeddedMoonSugarObjectVertexShaderBytecode_PAR2016_SKIN2008) /
				sizeof(kEmbeddedMoonSugarObjectVertexShaderBytecode_PAR2016_SKIN2008[0])
		};
		if (CreateEmbeddedVertexShaderBytecode(device, bytecode, kObjectVertexShaderProfile, "PAR2016/SKIN2008", outShader))
			return true;

		return CompileVertexShaderSource(device, kObjectVertexShader, kObjectVertexShaderProfile, "PAR2016/SKIN2008", nullptr, outShader);
	}

	const char* GetLegacyObjectVertexShaderVariantName(UInt32 variant)
	{
		switch (variant)
		{
			case kLegacyObjectVertexShader_Par2016:
				return "PAR2016/PAR2012";
			case kLegacyObjectVertexShader_Skin2008:
				return "SKIN2008/SKIN2004";
			default:
				return "unknown";
		}
	}

	const char* GetLighting30ObjectVertexShaderVariantName(UInt32 variant)
	{
		switch (variant)
		{
			case kLighting30ObjectVertexShader_Sm3000:
				return "SM3000";
			case kLighting30ObjectVertexShader_Sm3002Vc:
				return "SM3002 VC";
			case kLighting30ObjectVertexShader_Sm3004Proj:
				return "SM3004 PROJSHADOW";
			case kLighting30ObjectVertexShader_Sm3006VcProj:
				return "SM3006 VC PROJSHADOW";
			case kLighting30ObjectVertexShader_Sm3001Skin:
				return "SM3001 SKIN";
			case kLighting30ObjectVertexShader_Sm3003SkinVc:
				return "SM3003 SKIN VC";
			case kLighting30ObjectVertexShader_Sm3005SkinProj:
				return "SM3005 SKIN PROJSHADOW";
			case kLighting30ObjectVertexShader_Sm3007SkinVcProj:
				return "SM3007 SKIN VC PROJSHADOW";
			default:
				return "unknown";
		}
	}

	bool CompileLighting30ObjectVertexShaderSource(IDirect3DDevice9* device, UInt32 variant, IDirect3DVertexShader9** outShader)
	{
		if (variant >= kLighting30ObjectVertexShaderVariantCount)
			return false;

		D3DXMACRO defines[3] = {};
		UInt32 defineCount = 0;
		if (variant == kLighting30ObjectVertexShader_Sm3002Vc ||
			variant == kLighting30ObjectVertexShader_Sm3006VcProj ||
			variant == kLighting30ObjectVertexShader_Sm3003SkinVc ||
			variant == kLighting30ObjectVertexShader_Sm3007SkinVcProj)
		{
			defines[defineCount].Name = "USE_VERTEX_COLOR";
			defines[defineCount].Definition = "1";
			++defineCount;
		}
		if (variant == kLighting30ObjectVertexShader_Sm3004Proj ||
			variant == kLighting30ObjectVertexShader_Sm3006VcProj ||
			variant == kLighting30ObjectVertexShader_Sm3005SkinProj ||
			variant == kLighting30ObjectVertexShader_Sm3007SkinVcProj)
		{
			defines[defineCount].Name = "USE_PROJ_SHADOW";
			defines[defineCount].Definition = "1";
			++defineCount;
		}
		defines[defineCount].Name = nullptr;
		defines[defineCount].Definition = nullptr;

		char label[64] = {};
		_snprintf_s(label, sizeof(label), _TRUNCATE, "Lighting30 %s", GetLighting30ObjectVertexShaderVariantName(variant));
		if (CreateEmbeddedVertexShaderBytecode(device, kEmbeddedMoonSugarLighting30ObjectVertexShaders[variant], kLighting30ObjectVertexShaderProfile, label, outShader))
			return true;

		const char* source = variant >= kLighting30ObjectVertexShader_Sm3001Skin ?
			kLighting30SkinnedObjectVertexShader :
			kLighting30ObjectVertexShader;
		return CompileVertexShaderSource(device, source, kLighting30ObjectVertexShaderProfile, label, defines, outShader);
	}

	bool EnsureObjectVertexShader(IDirect3DDevice9* device)
	{
		if (!device)
			return false;

		if (s_objectVertexShaderState.vertexShader && s_objectVertexShaderState.device == device)
			return true;

		if (s_objectVertexShaderState.device && s_objectVertexShaderState.device != device)
			ReleaseObjectVertexShaderResources();

		if (s_objectVertexShaderState.compileFailed)
			return false;

		D3DCAPS9 caps = {};
		HRESULT capsResult = device->GetDeviceCaps(&caps);
		if (SUCCEEDED(capsResult) && caps.VertexShaderVersion < D3DVS_VERSION(2, 0))
		{
			_MESSAGE(
				"ERROR::EnsureObjectVertexShader: selected shader profile %s requires vertex shader 2.0, device reports %u.%u",
				kObjectVertexShaderProfile,
				D3DSHADER_VERSION_MAJOR(caps.VertexShaderVersion),
				D3DSHADER_VERSION_MINOR(caps.VertexShaderVersion));
			s_objectVertexShaderState.compileFailed = true;
			++s_objectVertexShaderState.shaderFailures;
			return false;
		}

		s_objectVertexShaderState.compileAttempted = true;
		if (!CompileObjectVertexShaderSource(device, &s_objectVertexShaderState.vertexShader))
		{
			s_objectVertexShaderState.compileFailed = true;
			++s_objectVertexShaderState.shaderFailures;
			return false;
		}

		s_objectVertexShaderState.device = device;
		return true;
	}

	bool EnsureLighting30ObjectVertexShader(IDirect3DDevice9* device, UInt32 variant)
	{
		if (!device)
			return false;
		if (variant >= kLighting30ObjectVertexShaderVariantCount)
			return false;

		if (s_objectVertexShaderState.lighting30VertexShaders[variant] && s_objectVertexShaderState.device == device)
			return true;

		if (s_objectVertexShaderState.device && s_objectVertexShaderState.device != device)
			ReleaseObjectVertexShaderResources();

		if (s_objectVertexShaderState.lighting30CompileFailed[variant])
			return false;

		D3DCAPS9 caps = {};
		HRESULT capsResult = device->GetDeviceCaps(&caps);
		if (SUCCEEDED(capsResult) && caps.VertexShaderVersion < D3DVS_VERSION(3, 0))
		{
			_MESSAGE(
				"ERROR::EnsureLighting30ObjectVertexShader: selected shader profile %s requires vertex shader 3.0, device reports %u.%u",
				kLighting30ObjectVertexShaderProfile,
				D3DSHADER_VERSION_MAJOR(caps.VertexShaderVersion),
				D3DSHADER_VERSION_MINOR(caps.VertexShaderVersion));
			s_objectVertexShaderState.lighting30CompileFailed[variant] = true;
			++s_objectVertexShaderState.shaderFailures;
			return false;
		}

		s_objectVertexShaderState.lighting30CompileAttempted[variant] = true;
		if (!CompileLighting30ObjectVertexShaderSource(device, variant, &s_objectVertexShaderState.lighting30VertexShaders[variant]))
		{
			s_objectVertexShaderState.lighting30CompileFailed[variant] = true;
			++s_objectVertexShaderState.shaderFailures;
			return false;
		}

		s_objectVertexShaderState.device = device;
		return true;
	}

	const char* GetLighting30EnvMapVertexShaderVariantName(UInt32 variant)
	{
		switch (variant)
		{
			case kLighting30EnvMapVertexShader_Sm3008:
				return "SM3008 EnvMap";
			case kLighting30EnvMapVertexShader_Sm3009Vc:
				return "SM3009 EnvMap VC";
			case kLighting30EnvMapVertexShader_Sm3010Skin:
				return "SM3010 EnvMap SKIN";
			case kLighting30EnvMapVertexShader_Sm3011SkinVc:
				return "SM3011 EnvMap SKIN VC";
			case kLighting30EnvMapVertexShader_Sm3012Special:
				return "SM3012 EnvMap SPECIAL";
			default:
				return "unknown";
		}
	}

	bool CompileLighting30EnvMapVertexShaderSource(IDirect3DDevice9* device, UInt32 variant, IDirect3DVertexShader9** outShader)
	{
		if (variant >= kLighting30EnvMapVertexShaderVariantCount)
			return false;

		D3DXMACRO defines[2] = {};
		UInt32 defineCount = 0;
		if (variant == kLighting30EnvMapVertexShader_Sm3009Vc ||
			variant == kLighting30EnvMapVertexShader_Sm3011SkinVc)
		{
			defines[defineCount].Name = "USE_VERTEX_COLOR";
			defines[defineCount].Definition = "1";
			++defineCount;
		}
		defines[defineCount].Name = nullptr;
		defines[defineCount].Definition = nullptr;

		const char* source = kLighting30EnvMapObjectVertexShader;
		if (variant == kLighting30EnvMapVertexShader_Sm3010Skin ||
			variant == kLighting30EnvMapVertexShader_Sm3011SkinVc)
		{
			source = kLighting30EnvMapSkinnedObjectVertexShader;
		}
		else if (variant == kLighting30EnvMapVertexShader_Sm3012Special)
		{
			source = kLighting30EnvMapSpecialObjectVertexShader;
		}

		char label[64] = {};
		_snprintf_s(label, sizeof(label), _TRUNCATE, "Lighting30 %s", GetLighting30EnvMapVertexShaderVariantName(variant));
		if (CreateEmbeddedVertexShaderBytecode(device, kEmbeddedMoonSugarLighting30EnvMapVertexShaders[variant], kLighting30ObjectVertexShaderProfile, label, outShader))
			return true;

		return CompileVertexShaderSource(device, source, kLighting30ObjectVertexShaderProfile, label, defines, outShader);
	}

	bool EnsureLighting30EnvMapVertexShader(IDirect3DDevice9* device, UInt32 variant)
	{
		if (!device)
			return false;
		if (variant >= kLighting30EnvMapVertexShaderVariantCount)
			return false;

		if (s_objectVertexShaderState.lighting30EnvMapVertexShaders[variant] && s_objectVertexShaderState.device == device)
			return true;

		if (s_objectVertexShaderState.device && s_objectVertexShaderState.device != device)
			ReleaseObjectVertexShaderResources();

		if (s_objectVertexShaderState.lighting30EnvMapCompileFailed[variant])
			return false;

		D3DCAPS9 caps = {};
		HRESULT capsResult = device->GetDeviceCaps(&caps);
		if (SUCCEEDED(capsResult) && caps.VertexShaderVersion < D3DVS_VERSION(3, 0))
		{
			_MESSAGE(
				"ERROR::EnsureLighting30EnvMapVertexShader: selected shader profile %s requires vertex shader 3.0, device reports %u.%u",
				kLighting30ObjectVertexShaderProfile,
				D3DSHADER_VERSION_MAJOR(caps.VertexShaderVersion),
				D3DSHADER_VERSION_MINOR(caps.VertexShaderVersion));
			s_objectVertexShaderState.lighting30EnvMapCompileFailed[variant] = true;
			++s_objectVertexShaderState.shaderFailures;
			return false;
		}

		s_objectVertexShaderState.lighting30EnvMapCompileAttempted[variant] = true;
		if (!CompileLighting30EnvMapVertexShaderSource(device, variant, &s_objectVertexShaderState.lighting30EnvMapVertexShaders[variant]))
		{
			s_objectVertexShaderState.lighting30EnvMapCompileFailed[variant] = true;
			++s_objectVertexShaderState.shaderFailures;
			return false;
		}

		s_objectVertexShaderState.device = device;
		return true;
	}

	const char* GetLighting30TexEffectVertexShaderVariantName(UInt32 variant)
	{
		switch (variant)
		{
			case kLighting30TexEffectVertexShader_Sm3028:
				return "SM3028 TexEffect";
			case kLighting30TexEffectVertexShader_Sm3029Skin:
				return "SM3029 TexEffect SKIN";
			default:
				return "unknown";
		}
	}

	bool CompileLighting30TexEffectVertexShaderSource(IDirect3DDevice9* device, UInt32 variant, IDirect3DVertexShader9** outShader)
	{
		if (variant >= kLighting30TexEffectVertexShaderVariantCount)
			return false;

		const char* source = kLighting30TexEffectObjectVertexShader;
		if (variant == kLighting30TexEffectVertexShader_Sm3029Skin)
			source = kLighting30TexEffectSkinnedObjectVertexShader;

		char label[64] = {};
		_snprintf_s(label, sizeof(label), _TRUNCATE, "Lighting30 %s", GetLighting30TexEffectVertexShaderVariantName(variant));
		if (CreateEmbeddedVertexShaderBytecode(device, kEmbeddedMoonSugarLighting30TexEffectVertexShaders[variant], kLighting30ObjectVertexShaderProfile, label, outShader))
			return true;

		return CompileVertexShaderSource(device, source, kLighting30ObjectVertexShaderProfile, label, nullptr, outShader);
	}

	bool EnsureLighting30TexEffectVertexShader(IDirect3DDevice9* device, UInt32 variant)
	{
		if (!device)
			return false;
		if (variant >= kLighting30TexEffectVertexShaderVariantCount)
			return false;

		if (s_objectVertexShaderState.lighting30TexEffectVertexShaders[variant] && s_objectVertexShaderState.device == device)
			return true;

		if (s_objectVertexShaderState.device && s_objectVertexShaderState.device != device)
			ReleaseObjectVertexShaderResources();

		if (s_objectVertexShaderState.lighting30TexEffectCompileFailed[variant])
			return false;

		D3DCAPS9 caps = {};
		HRESULT capsResult = device->GetDeviceCaps(&caps);
		if (SUCCEEDED(capsResult) && caps.VertexShaderVersion < D3DVS_VERSION(3, 0))
		{
			_MESSAGE(
				"ERROR::EnsureLighting30TexEffectVertexShader: selected shader profile %s requires vertex shader 3.0, device reports %u.%u",
				kLighting30ObjectVertexShaderProfile,
				D3DSHADER_VERSION_MAJOR(caps.VertexShaderVersion),
				D3DSHADER_VERSION_MINOR(caps.VertexShaderVersion));
			s_objectVertexShaderState.lighting30TexEffectCompileFailed[variant] = true;
			++s_objectVertexShaderState.shaderFailures;
			return false;
		}

		s_objectVertexShaderState.lighting30TexEffectCompileAttempted[variant] = true;
		if (!CompileLighting30TexEffectVertexShaderSource(device, variant, &s_objectVertexShaderState.lighting30TexEffectVertexShaders[variant]))
		{
			s_objectVertexShaderState.lighting30TexEffectCompileFailed[variant] = true;
			++s_objectVertexShaderState.shaderFailures;
			return false;
		}

		s_objectVertexShaderState.device = device;
		return true;
	}

	const char* GetLighting30DecalVertexShaderVariantName(UInt32 variant)
	{
		switch (variant)
		{
			case kLighting30DecalVertexShader_Sm3017:
				return "SM3017 Decal MAXDECALS8";
			default:
				return "unknown";
		}
	}

	bool CompileLighting30DecalVertexShaderSource(IDirect3DDevice9* device, UInt32 variant, IDirect3DVertexShader9** outShader)
	{
		if (variant != kLighting30DecalVertexShader_Sm3017)
			return false;

		char label[64] = {};
		_snprintf_s(label, sizeof(label), _TRUNCATE, "Lighting30 %s", GetLighting30DecalVertexShaderVariantName(variant));
		MoonSugarEmbeddedVertexShaderBytecode bytecode =
		{
			kEmbeddedMoonSugarLighting30DecalVertexShaderBytecode_SM3017,
			sizeof(kEmbeddedMoonSugarLighting30DecalVertexShaderBytecode_SM3017) /
				sizeof(kEmbeddedMoonSugarLighting30DecalVertexShaderBytecode_SM3017[0])
		};
		if (CreateEmbeddedVertexShaderBytecode(device, bytecode, kLighting30ObjectVertexShaderProfile, label, outShader))
			return true;

		return CompileVertexShaderSource(device, kLighting30DecalObjectVertexShader, kLighting30ObjectVertexShaderProfile, label, nullptr, outShader);
	}

	bool EnsureLighting30DecalVertexShader(IDirect3DDevice9* device, UInt32 variant)
	{
		if (!device)
			return false;
		if (variant >= kLighting30DecalVertexShaderVariantCount)
			return false;

		if (s_objectVertexShaderState.lighting30DecalVertexShaders[variant] && s_objectVertexShaderState.device == device)
			return true;

		if (s_objectVertexShaderState.device && s_objectVertexShaderState.device != device)
			ReleaseObjectVertexShaderResources();

		if (s_objectVertexShaderState.lighting30DecalCompileFailed[variant])
			return false;

		D3DCAPS9 caps = {};
		HRESULT capsResult = device->GetDeviceCaps(&caps);
		if (SUCCEEDED(capsResult) && caps.VertexShaderVersion < D3DVS_VERSION(3, 0))
		{
			_MESSAGE(
				"ERROR::EnsureLighting30DecalVertexShader: selected shader profile %s requires vertex shader 3.0, device reports %u.%u",
				kLighting30ObjectVertexShaderProfile,
				D3DSHADER_VERSION_MAJOR(caps.VertexShaderVersion),
				D3DSHADER_VERSION_MINOR(caps.VertexShaderVersion));
			s_objectVertexShaderState.lighting30DecalCompileFailed[variant] = true;
			++s_objectVertexShaderState.shaderFailures;
			return false;
		}

		s_objectVertexShaderState.lighting30DecalCompileAttempted[variant] = true;
		if (!CompileLighting30DecalVertexShaderSource(device, variant, &s_objectVertexShaderState.lighting30DecalVertexShaders[variant]))
		{
			s_objectVertexShaderState.lighting30DecalCompileFailed[variant] = true;
			++s_objectVertexShaderState.shaderFailures;
			return false;
		}

		s_objectVertexShaderState.device = device;
		return true;
	}

	const char* GetLighting30DepthMapVertexShaderVariantName(UInt32 variant)
	{
		switch (variant)
		{
			case kLighting30DepthMapVertexShader_Sm3018:
				return "SM3018 DepthMap";
			case kLighting30DepthMapVertexShader_Sm3019Skin:
				return "SM3019 DepthMap SKIN";
			default:
				return "unknown";
		}
	}

	bool CompileLighting30DepthMapVertexShaderSource(IDirect3DDevice9* device, UInt32 variant, IDirect3DVertexShader9** outShader)
	{
		if (variant >= kLighting30DepthMapVertexShaderVariantCount)
			return false;

		const char* source = kLighting30DepthMapObjectVertexShader;
		if (variant == kLighting30DepthMapVertexShader_Sm3019Skin)
			source = kLighting30DepthMapSkinnedObjectVertexShader;
		else if (variant != kLighting30DepthMapVertexShader_Sm3018)
			return false;

		char label[64] = {};
		_snprintf_s(label, sizeof(label), _TRUNCATE, "Lighting30 %s", GetLighting30DepthMapVertexShaderVariantName(variant));
		if (CreateEmbeddedVertexShaderBytecode(device, kEmbeddedMoonSugarLighting30DepthMapVertexShaders[variant], kLighting30ObjectVertexShaderProfile, label, outShader))
			return true;

		return CompileVertexShaderSource(device, source, kLighting30ObjectVertexShaderProfile, label, nullptr, outShader);
	}

	bool EnsureLighting30DepthMapVertexShader(IDirect3DDevice9* device, UInt32 variant)
	{
		if (!device)
			return false;
		if (variant >= kLighting30DepthMapVertexShaderVariantCount)
			return false;

		if (s_objectVertexShaderState.lighting30DepthMapVertexShaders[variant] && s_objectVertexShaderState.device == device)
			return true;

		if (s_objectVertexShaderState.device && s_objectVertexShaderState.device != device)
			ReleaseObjectVertexShaderResources();

		if (s_objectVertexShaderState.lighting30DepthMapCompileFailed[variant])
			return false;

		D3DCAPS9 caps = {};
		HRESULT capsResult = device->GetDeviceCaps(&caps);
		if (SUCCEEDED(capsResult) && caps.VertexShaderVersion < D3DVS_VERSION(3, 0))
		{
			_MESSAGE(
				"ERROR::EnsureLighting30DepthMapVertexShader: selected shader profile %s requires vertex shader 3.0, device reports %u.%u",
				kLighting30ObjectVertexShaderProfile,
				D3DSHADER_VERSION_MAJOR(caps.VertexShaderVersion),
				D3DSHADER_VERSION_MINOR(caps.VertexShaderVersion));
			s_objectVertexShaderState.lighting30DepthMapCompileFailed[variant] = true;
			++s_objectVertexShaderState.shaderFailures;
			return false;
		}

		s_objectVertexShaderState.lighting30DepthMapCompileAttempted[variant] = true;
		if (!CompileLighting30DepthMapVertexShaderSource(device, variant, &s_objectVertexShaderState.lighting30DepthMapVertexShaders[variant]))
		{
			s_objectVertexShaderState.lighting30DepthMapCompileFailed[variant] = true;
			++s_objectVertexShaderState.shaderFailures;
			return false;
		}

		s_objectVertexShaderState.device = device;
		return true;
	}

	const char* GetLighting30SupportVertexShaderVariantName(UInt32 variant)
	{
		switch (variant)
		{
			case kLighting30SupportVertexShader_Sm3030ZOnly:
				return "SM3030 ZOnly";
			case kLighting30SupportVertexShader_Sm3031ZOnlySkin:
				return "SM3031 ZOnly SKIN";
			case kLighting30SupportVertexShader_Sm3013SimpleShadow:
				return "SM3013 SimpleShadow";
			case kLighting30SupportVertexShader_Sm3014SimpleShadowVc:
				return "SM3014 SimpleShadow VC";
			case kLighting30SupportVertexShader_Sm3015SimpleShadowSkin:
				return "SM3015 SimpleShadow SKIN";
			case kLighting30SupportVertexShader_Sm3016SimpleShadowSkinVc:
				return "SM3016 SimpleShadow SKIN VC";
			case kLighting30SupportVertexShader_Sm3020RenderNormals:
				return "SM3020 RenderNormals";
			case kLighting30SupportVertexShader_Sm3021RenderNormalsSkin:
				return "SM3021 RenderNormals SKIN";
			case kLighting30SupportVertexShader_Sm3022RenderNormalsFire:
				return "SM3022 RenderNormals FIRE";
			case kLighting30SupportVertexShader_Sm3025LocalMap:
				return "SM3025 LocalMap";
			case kLighting30SupportVertexShader_Sm3026LocalMapSkin:
				return "SM3026 LocalMap SKIN";
			default:
				return "unknown";
		}
	}

	bool IsLighting30SupportVariantSkinned(UInt32 variant)
	{
		return variant == kLighting30SupportVertexShader_Sm3031ZOnlySkin ||
			variant == kLighting30SupportVertexShader_Sm3015SimpleShadowSkin ||
			variant == kLighting30SupportVertexShader_Sm3016SimpleShadowSkinVc ||
			variant == kLighting30SupportVertexShader_Sm3021RenderNormalsSkin ||
			variant == kLighting30SupportVertexShader_Sm3026LocalMapSkin;
	}

	bool CompileLighting30SupportVertexShaderSource(IDirect3DDevice9* device, UInt32 variant, IDirect3DVertexShader9** outShader)
	{
		if (variant >= kLighting30SupportVertexShaderVariantCount)
			return false;

		D3DXMACRO defines[6] = {};
		UInt32 defineCount = 0;
		if (IsLighting30SupportVariantSkinned(variant))
		{
			defines[defineCount].Name = "SKIN";
			defines[defineCount].Definition = "1";
			++defineCount;
		}

		switch (variant)
		{
			case kLighting30SupportVertexShader_Sm3030ZOnly:
			case kLighting30SupportVertexShader_Sm3031ZOnlySkin:
				defines[defineCount].Name = "HAS_UV";
				defines[defineCount].Definition = "1";
				++defineCount;
				defines[defineCount].Name = "MODE_ZONLY";
				defines[defineCount].Definition = "1";
				++defineCount;
				break;
			case kLighting30SupportVertexShader_Sm3013SimpleShadow:
			case kLighting30SupportVertexShader_Sm3014SimpleShadowVc:
			case kLighting30SupportVertexShader_Sm3015SimpleShadowSkin:
			case kLighting30SupportVertexShader_Sm3016SimpleShadowSkinVc:
				defines[defineCount].Name = "HAS_UV";
				defines[defineCount].Definition = "1";
				++defineCount;
				defines[defineCount].Name = "MODE_SIMPLE_SHADOW";
				defines[defineCount].Definition = "1";
				++defineCount;
				break;
			case kLighting30SupportVertexShader_Sm3020RenderNormals:
			case kLighting30SupportVertexShader_Sm3021RenderNormalsSkin:
				defines[defineCount].Name = "HAS_UV";
				defines[defineCount].Definition = "1";
				++defineCount;
				defines[defineCount].Name = "HAS_NORMAL";
				defines[defineCount].Definition = "1";
				++defineCount;
				defines[defineCount].Name = "MODE_RENDER_NORMALS";
				defines[defineCount].Definition = "1";
				++defineCount;
				break;
			case kLighting30SupportVertexShader_Sm3022RenderNormalsFire:
				defines[defineCount].Name = "HAS_NORMAL";
				defines[defineCount].Definition = "1";
				++defineCount;
				defines[defineCount].Name = "MODE_RENDER_NORMALS_FIRE";
				defines[defineCount].Definition = "1";
				++defineCount;
				break;
			case kLighting30SupportVertexShader_Sm3025LocalMap:
			case kLighting30SupportVertexShader_Sm3026LocalMapSkin:
				defines[defineCount].Name = "HAS_NORMAL";
				defines[defineCount].Definition = "1";
				++defineCount;
				defines[defineCount].Name = "MODE_LOCALMAP";
				defines[defineCount].Definition = "1";
				++defineCount;
				break;
			default:
				return false;
		}

		defines[defineCount].Name = nullptr;
		defines[defineCount].Definition = nullptr;

		char label[64] = {};
		_snprintf_s(label, sizeof(label), _TRUNCATE, "Lighting30 %s", GetLighting30SupportVertexShaderVariantName(variant));
		if (CreateEmbeddedVertexShaderBytecode(device, kEmbeddedMoonSugarLighting30SupportVertexShaders[variant], kLighting30ObjectVertexShaderProfile, label, outShader))
			return true;

		return CompileVertexShaderSource(device, kLighting30SupportObjectVertexShader, kLighting30ObjectVertexShaderProfile, label, defines, outShader);
	}

	bool EnsureLighting30SupportVertexShader(IDirect3DDevice9* device, UInt32 variant)
	{
		if (!device)
			return false;
		if (variant >= kLighting30SupportVertexShaderVariantCount)
			return false;

		if (s_objectVertexShaderState.lighting30SupportVertexShaders[variant] && s_objectVertexShaderState.device == device)
			return true;

		if (s_objectVertexShaderState.device && s_objectVertexShaderState.device != device)
			ReleaseObjectVertexShaderResources();

		if (s_objectVertexShaderState.lighting30SupportCompileFailed[variant])
			return false;

		D3DCAPS9 caps = {};
		HRESULT capsResult = device->GetDeviceCaps(&caps);
		if (SUCCEEDED(capsResult) && caps.VertexShaderVersion < D3DVS_VERSION(3, 0))
		{
			_MESSAGE(
				"ERROR::EnsureLighting30SupportVertexShader: selected shader profile %s requires vertex shader 3.0, device reports %u.%u",
				kLighting30ObjectVertexShaderProfile,
				D3DSHADER_VERSION_MAJOR(caps.VertexShaderVersion),
				D3DSHADER_VERSION_MINOR(caps.VertexShaderVersion));
			s_objectVertexShaderState.lighting30SupportCompileFailed[variant] = true;
			++s_objectVertexShaderState.shaderFailures;
			return false;
		}

		s_objectVertexShaderState.lighting30SupportCompileAttempted[variant] = true;
		if (!CompileLighting30SupportVertexShaderSource(device, variant, &s_objectVertexShaderState.lighting30SupportVertexShaders[variant]))
		{
			s_objectVertexShaderState.lighting30SupportCompileFailed[variant] = true;
			++s_objectVertexShaderState.shaderFailures;
			return false;
		}

		s_objectVertexShaderState.device = device;
		return true;
	}

	enum RendererSkipReason
	{
		kRendererSkip_None = 0,
		kRendererSkip_Disabled,
		kRendererSkip_NoRenderer,
		kRendererSkip_LostDevice,
		kRendererSkip_RenderMode,
		kRendererSkip_RenderTargetStack,
		kRendererSkip_NonDefaultTarget,
		kRendererSkip_Inactive,
		kRendererSkip_ZeroIntensity
	};

	enum RendererContext
	{
		kRendererContext_Unknown = 0,
		kRendererContext_StrictTarget,
		kRendererContext_ImageSpace
	};

	void LogRendererSkip(UInt32 now, RendererSkipReason reason, UInt32 detailA, UInt32 detailB)
	{
		if (!s_settings.rendererDebugLog || !s_effect.active)
			return;

		if (s_rendererState.lastSkipReason == reason && (now - s_rendererState.lastSkipTick) < 3000)
			return;

		s_rendererState.lastSkipReason = reason;
		s_rendererState.lastSkipTick = now;

		_MESSAGE(
			"VES renderer skip: reason=%u detailA=%u detailB=%u remainingMs=%u renderedFrames=%u renderFailures=%u shaderFailures=%u",
			reason,
			detailA,
			detailB,
			GetRemainingMillisecondsAt(now),
			s_rendererState.renderedFrames,
			s_rendererState.renderFailures,
			s_rendererState.shaderFailures);
	}

	bool ShouldRenderDistortion(NiDX9Renderer* renderer, UInt32 now, UInt32* remainingMs, float* effectiveIntensity)
	{
		if (!s_settings.rendererEnabled)
		{
			LogRendererSkip(now, kRendererSkip_Disabled, 0, 0);
			return false;
		}

		if (!renderer || !renderer->device)
		{
			LogRendererSkip(now, kRendererSkip_NoRenderer, reinterpret_cast<UInt32>(renderer), 0);
			return false;
		}

		if (renderer->lostDevice)
		{
			ReleaseRendererResources();
			LogRendererSkip(now, kRendererSkip_LostDevice, 0, 0);
			return false;
		}

		if (!s_allowOffscreenDistortion)
		{
			UInt32 renderMode = *reinterpret_cast<volatile UInt32*>(kRenderModeAddress);
			if (renderMode != kRenderModeNormal)
			{
				LogRendererSkip(now, kRendererSkip_RenderMode, renderMode, 0);
				return false;
			}

			UInt32 renderTargetStackDepth = *reinterpret_cast<volatile UInt32*>(kRenderTargetStackDepthAddress);
			if (renderTargetStackDepth != 0)
			{
				LogRendererSkip(now, kRendererSkip_RenderTargetStack, renderTargetStackDepth, 0);
				return false;
			}

			if (renderer->currentRTGroup != renderer->defaultRTGroup)
			{
				LogRendererSkip(now, kRendererSkip_NonDefaultTarget, reinterpret_cast<UInt32>(renderer->currentRTGroup), reinterpret_cast<UInt32>(renderer->defaultRTGroup));
				return false;
			}
		}

		*remainingMs = GetRemainingMillisecondsAt(now);
		if (*remainingMs == 0)
		{
			if (s_effect.active)
				ExpireMoonSugarEffect(now);
			LogRendererSkip(now, kRendererSkip_Inactive, 0, 0);
			return false;
		}

		float intensity = s_effect.intensity;
		if (s_settings.fadeOutSeconds > 0.0f)
		{
			float remainingSeconds = static_cast<float>(*remainingMs) * 0.001f;
			float fade = ClampFloat(remainingSeconds / s_settings.fadeOutSeconds, 0.0f, 1.0f);
			intensity *= fade;
		}

		*effectiveIntensity = ClampFloat(intensity, 0.0f, 1.0f);
		if (*effectiveIntensity <= 0.0f)
		{
			LogRendererSkip(now, kRendererSkip_ZeroIntensity, 0, 0);
			return false;
		}

		return true;
	}

	bool CopyRenderTargetToTexture(
		IDirect3DDevice9* device,
		IDirect3DSurface9* renderTarget,
		const D3DSURFACE_DESC& desc,
		IDirect3DTexture9** outTexture)
	{
		IDirect3DTexture9* texture = nullptr;
		IDirect3DSurface9* textureSurface = nullptr;

		HRESULT result = device->CreateTexture(
			desc.Width,
			desc.Height,
			1,
			D3DUSAGE_RENDERTARGET,
			desc.Format,
			D3DPOOL_DEFAULT,
			&texture,
			nullptr);

		if (FAILED(result) || !texture)
		{
			_MESSAGE("ERROR::CopyRenderTargetToTexture: CreateTexture failed hr=%08X", result);
			return false;
		}

		result = texture->GetSurfaceLevel(0, &textureSurface);
		if (FAILED(result) || !textureSurface)
		{
			_MESSAGE("ERROR::CopyRenderTargetToTexture: GetSurfaceLevel failed hr=%08X", result);
			ReleaseCom(texture);
			return false;
		}

		result = device->StretchRect(renderTarget, nullptr, textureSurface, nullptr, D3DTEXF_NONE);
		ReleaseCom(textureSurface);

		if (FAILED(result))
		{
			_MESSAGE("ERROR::CopyRenderTargetToTexture: StretchRect failed hr=%08X", result);
			ReleaseCom(texture);
			return false;
		}

		*outTexture = texture;
		return true;
	}

	void ReleaseCapturedDepthTexture()
	{
		ReleaseCom(s_rendererState.capturedDepthSurface);
		ReleaseCom(s_rendererState.capturedDepthTexture);
		s_rendererState.capturedDepthWidth = 0;
		s_rendererState.capturedDepthHeight = 0;
		s_rendererState.capturedDepthFormat = 0;
		s_rendererState.capturedDepthTick = 0;
		if (s_rendererState.depthLastSource == kDepthSampleSource_CapturedWorld)
			s_rendererState.depthLastSource = kDepthSampleSource_None;
		s_rendererState.depthCaptureActiveLastFrame = false;
	}

	bool IsTextureBackedDepthFormatSupported(
		IDirect3DDevice9* device,
		const D3DSURFACE_DESC& renderTargetDesc,
		D3DFORMAT depthFormat,
		UInt32* outHr)
	{
		if (outHr)
			*outHr = S_OK;
		if (!device)
			return false;

		IDirect3D9* d3d = nullptr;
		HRESULT result = device->GetDirect3D(&d3d);
		if (FAILED(result) || !d3d)
		{
			if (outHr)
				*outHr = static_cast<UInt32>(result);
			return true;
		}

		D3DDEVICE_CREATION_PARAMETERS params = {};
		result = device->GetCreationParameters(&params);
		if (FAILED(result))
		{
			ReleaseCom(d3d);
			if (outHr)
				*outHr = static_cast<UInt32>(result);
			return true;
		}

		D3DDISPLAYMODE mode = {};
		result = d3d->GetAdapterDisplayMode(params.AdapterOrdinal, &mode);
		if (FAILED(result))
		{
			ReleaseCom(d3d);
			if (outHr)
				*outHr = static_cast<UInt32>(result);
			return true;
		}

		result = d3d->CheckDeviceFormat(
			params.AdapterOrdinal,
			params.DeviceType,
			mode.Format,
			D3DUSAGE_DEPTHSTENCIL,
			D3DRTYPE_TEXTURE,
			depthFormat);
		if (SUCCEEDED(result))
		{
			result = d3d->CheckDepthStencilMatch(
				params.AdapterOrdinal,
				params.DeviceType,
				mode.Format,
				renderTargetDesc.Format,
				depthFormat);
		}

		ReleaseCom(d3d);
		if (outHr)
			*outHr = static_cast<UInt32>(result);
		return SUCCEEDED(result);
	}

	bool CreateTextureBackedDepthSurface(
		IDirect3DDevice9* device,
		const D3DSURFACE_DESC& renderTargetDesc,
		IDirect3DTexture9** outTexture,
		IDirect3DSurface9** outSurface,
		UInt32* outFormat,
		UInt32* outHr)
	{
		if (!device || !outTexture || !outSurface || !outFormat || !outHr)
			return false;

		*outTexture = nullptr;
		*outSurface = nullptr;
		*outFormat = 0;
		*outHr = 0;

		if (renderTargetDesc.MultiSampleType != D3DMULTISAMPLE_NONE)
		{
			*outHr = D3DERR_INVALIDCALL;
			return false;
		}

		s_rendererState.depthCaptureAttemptedFormatMask = 0;
		s_rendererState.depthCapturePreflightPassFormatMask = 0;
		s_rendererState.depthCapturePreflightRejectFormatMask = 0;

		for (UInt32 i = 0; i < kTextureBackedDepthFormatCount; ++i)
		{
			IDirect3DTexture9* texture = nullptr;
			IDirect3DSurface9* surface = nullptr;
			D3DFORMAT format = kTextureBackedDepthFormats[i];
			UInt32 formatBit = 1u << i;
			UInt32 supportHr = S_OK;
			s_rendererState.depthCaptureAttemptedFormatMask |= formatBit;
			*outFormat = static_cast<UInt32>(format);
			if (!IsTextureBackedDepthFormatSupported(device, renderTargetDesc, format, &supportHr))
			{
				s_rendererState.depthCapturePreflightRejectFormatMask |= formatBit;
				*outHr = supportHr;
				continue;
			}

			s_rendererState.depthCapturePreflightPassFormatMask |= formatBit;
			HRESULT result = device->CreateTexture(
				renderTargetDesc.Width,
				renderTargetDesc.Height,
				1,
				D3DUSAGE_DEPTHSTENCIL,
				format,
				D3DPOOL_DEFAULT,
				&texture,
				nullptr);

			*outHr = static_cast<UInt32>(result);
			if (FAILED(result) || !texture)
			{
				ReleaseCom(texture);
				continue;
			}

			result = texture->GetSurfaceLevel(0, &surface);
			*outHr = static_cast<UInt32>(result);
			if (FAILED(result) || !surface)
			{
				ReleaseCom(surface);
				ReleaseCom(texture);
				continue;
			}

			*outTexture = texture;
			*outSurface = surface;
			return true;
		}

		return false;
	}

	bool EnsureTextureBackedDepthCapture(IDirect3DDevice9* device, const D3DSURFACE_DESC& renderTargetDesc)
	{
		if (!device || renderTargetDesc.Width == 0 || renderTargetDesc.Height == 0)
			return false;

		if (s_rendererState.capturedDepthTexture &&
			s_rendererState.capturedDepthSurface &&
			s_rendererState.capturedDepthWidth == renderTargetDesc.Width &&
			s_rendererState.capturedDepthHeight == renderTargetDesc.Height)
		{
			return true;
		}

		ReleaseCapturedDepthTexture();

		IDirect3DTexture9* texture = nullptr;
		IDirect3DSurface9* surface = nullptr;
		UInt32 format = 0;
		UInt32 hr = 0;
		if (!CreateTextureBackedDepthSurface(device, renderTargetDesc, &texture, &surface, &format, &hr))
		{
			++s_rendererState.depthCaptureFailures;
			s_rendererState.depthCaptureLastHr = hr;
			s_rendererState.capturedDepthFormat = format;
			if (s_settings.rendererDebugLog && !s_rendererState.depthCaptureUnsupportedLogged)
			{
				_MESSAGE(
					"VES texture-backed depth capture unsupported: size=%ux%u rtFormat=%08X msaa=%u triedLastFormat=%08X attemptedMask=%02X preflightPassMask=%02X preflightRejectMask=%02X hr=%08X",
					renderTargetDesc.Width,
					renderTargetDesc.Height,
					static_cast<UInt32>(renderTargetDesc.Format),
					static_cast<UInt32>(renderTargetDesc.MultiSampleType),
					format,
					s_rendererState.depthCaptureAttemptedFormatMask,
					s_rendererState.depthCapturePreflightPassFormatMask,
					s_rendererState.depthCapturePreflightRejectFormatMask,
					hr);
				s_rendererState.depthCaptureUnsupportedLogged = true;
			}
			return false;
		}

		s_rendererState.capturedDepthTexture = texture;
		s_rendererState.capturedDepthSurface = surface;
		s_rendererState.capturedDepthWidth = renderTargetDesc.Width;
		s_rendererState.capturedDepthHeight = renderTargetDesc.Height;
		s_rendererState.capturedDepthFormat = format;
		s_rendererState.depthCaptureLastHr = S_OK;
		return true;
	}

	bool BeginTextureBackedDepthCapture(IDirect3DDevice9* device, IDirect3DSurface9** outPreviousDepth)
	{
		if (!device || !outPreviousDepth)
			return false;

		*outPreviousDepth = nullptr;
		s_rendererState.depthCaptureActiveLastFrame = false;
		++s_rendererState.depthCaptureAttempts;

		IDirect3DSurface9* renderTarget = nullptr;
		D3DSURFACE_DESC renderTargetDesc = {};
		HRESULT result = device->GetRenderTarget(0, &renderTarget);
		if (FAILED(result) || !renderTarget)
		{
			++s_rendererState.depthCaptureFailures;
			s_rendererState.depthCaptureLastHr = static_cast<UInt32>(result);
			return false;
		}

		result = renderTarget->GetDesc(&renderTargetDesc);
		ReleaseCom(renderTarget);
		if (FAILED(result))
		{
			++s_rendererState.depthCaptureFailures;
			s_rendererState.depthCaptureLastHr = static_cast<UInt32>(result);
			return false;
		}

		if (!EnsureTextureBackedDepthCapture(device, renderTargetDesc))
			return false;

		result = device->GetDepthStencilSurface(outPreviousDepth);
		if (FAILED(result) || !*outPreviousDepth)
		{
			++s_rendererState.depthCaptureFailures;
			s_rendererState.depthCaptureLastHr = static_cast<UInt32>(result);
			*outPreviousDepth = nullptr;
			return false;
		}

		result = device->SetDepthStencilSurface(s_rendererState.capturedDepthSurface);
		if (FAILED(result))
		{
			++s_rendererState.depthCaptureFailures;
			s_rendererState.depthCaptureLastHr = static_cast<UInt32>(result);
			ReleaseCom(*outPreviousDepth);
			return false;
		}

		device->Clear(0, nullptr, D3DCLEAR_ZBUFFER, 0, 1.0f, 0);
		s_rendererState.capturedDepthTick = GetTickCount();
		s_rendererState.depthCaptureActiveLastFrame = true;
		++s_rendererState.depthCaptureSuccess;
		if (s_settings.rendererDebugLog && !s_rendererState.depthCaptureFirstLogged)
		{
			_MESSAGE(
				"VES texture-backed depth capture active: size=%ux%u format=%08X",
				s_rendererState.capturedDepthWidth,
				s_rendererState.capturedDepthHeight,
				s_rendererState.capturedDepthFormat);
			s_rendererState.depthCaptureFirstLogged = true;
		}
		return true;
	}

	void EndTextureBackedDepthCapture(IDirect3DDevice9* device, IDirect3DSurface9* previousDepth)
	{
		if (!device || !previousDepth)
			return;

		HRESULT result = device->SetDepthStencilSurface(previousDepth);
		if (FAILED(result))
		{
			++s_rendererState.depthCaptureFailures;
			s_rendererState.depthCaptureLastHr = static_cast<UInt32>(result);
			if (s_settings.rendererDebugLog)
				_MESSAGE("ERROR::EndTextureBackedDepthCapture: restore depth surface failed hr=%08X", result);
		}
	}

	bool AcquireActiveDepthTexture(
		IDirect3DDevice9* device,
		IDirect3DTexture9** outDepthTexture,
		IDirect3DSurface9** outDepthSurface)
	{
		if (!device || !outDepthTexture || !outDepthSurface)
			return false;

		*outDepthTexture = nullptr;
		*outDepthSurface = nullptr;
		++s_rendererState.depthBindAttempts;

		IDirect3DSurface9* depthSurface = nullptr;
		HRESULT result = device->GetDepthStencilSurface(&depthSurface);
		s_rendererState.depthLastHr = static_cast<UInt32>(result);
		if (FAILED(result) || !depthSurface)
		{
			++s_rendererState.depthBindFailures;
			return false;
		}

		D3DSURFACE_DESC depthDesc = {};
		result = depthSurface->GetDesc(&depthDesc);
		if (SUCCEEDED(result))
			s_rendererState.depthLastFormat = static_cast<UInt32>(depthDesc.Format);

		IDirect3DTexture9* depthTexture = nullptr;
		result = depthSurface->GetContainer(__uuidof(IDirect3DTexture9), reinterpret_cast<void**>(&depthTexture));
		s_rendererState.depthLastHr = static_cast<UInt32>(result);
		if (FAILED(result) || !depthTexture)
		{
			++s_rendererState.depthBindFailures;
			if (s_settings.rendererDebugLog && !s_rendererState.depthUnavailableLogged)
			{
				_MESSAGE(
					"VES depth texture unavailable: active depth surface is not texture-backed format=%08X hr=%08X",
					s_rendererState.depthLastFormat,
					s_rendererState.depthLastHr);
				s_rendererState.depthUnavailableLogged = true;
			}

			ReleaseCom(depthSurface);
			return false;
		}

		*outDepthTexture = depthTexture;
		*outDepthSurface = depthSurface;
		++s_rendererState.depthBindSuccess;
		return true;
	}

	struct ScreenVertex
	{
		float x;
		float y;
		float z;
		float rhw;
		float u;
		float v;
	};

	bool DrawDistortionQuad(
		IDirect3DDevice9* device,
		IDirect3DTexture9* sceneTexture,
		IDirect3DTexture9* depthTexture,
		IDirect3DSurface9* activeDepthSurface,
		UInt32 depthSource,
		const D3DSURFACE_DESC& desc,
		UInt32 now,
		UInt32 remainingMs,
		float effectiveIntensity)
	{
		IDirect3DPixelShader9* activePixelShader = GetActivePixelShader();
		if (!activePixelShader)
			return false;

		const DWORD kScreenVertexFVF = D3DFVF_XYZRHW | D3DFVF_TEX1;
		D3DVIEWPORT9 viewport = { 0 };
		HRESULT viewportResult = device->GetViewport(&viewport);
		if (FAILED(viewportResult) || viewport.Width == 0 || viewport.Height == 0)
		{
			viewport.X = 0;
			viewport.Y = 0;
			viewport.Width = desc.Width;
			viewport.Height = desc.Height;
			viewport.MinZ = 0.0f;
			viewport.MaxZ = 1.0f;
		}

		const float renderTargetWidth = static_cast<float>(desc.Width);
		const float renderTargetHeight = static_cast<float>(desc.Height);
		const float viewportLeft = ClampFloat(static_cast<float>(viewport.X), 0.0f, renderTargetWidth);
		const float viewportTop = ClampFloat(static_cast<float>(viewport.Y), 0.0f, renderTargetHeight);
		const float viewportRight = ClampFloat(static_cast<float>(viewport.X) + static_cast<float>(viewport.Width), viewportLeft, renderTargetWidth);
		const float viewportBottom = ClampFloat(static_cast<float>(viewport.Y) + static_cast<float>(viewport.Height), viewportTop, renderTargetHeight);
		const float viewportWidth = ((viewportRight - viewportLeft) > 1.0f) ? (viewportRight - viewportLeft) : 1.0f;
		const float viewportHeight = ((viewportBottom - viewportTop) > 1.0f) ? (viewportBottom - viewportTop) : 1.0f;
		const float viewportU0 = viewportLeft / renderTargetWidth;
		const float viewportV0 = viewportTop / renderTargetHeight;
		const float viewportU1 = viewportRight / renderTargetWidth;
		const float viewportV1 = viewportBottom / renderTargetHeight;

		ScreenVertex vertices[4] =
		{
			{ viewportLeft - 0.5f, viewportTop - 0.5f, 0.0f, 1.0f, viewportU0, viewportV0 },
			{ viewportRight - 0.5f, viewportTop - 0.5f, 0.0f, 1.0f, viewportU1, viewportV0 },
			{ viewportLeft - 0.5f, viewportBottom - 0.5f, 0.0f, 1.0f, viewportU0, viewportV1 },
			{ viewportRight - 0.5f, viewportBottom - 0.5f, 0.0f, 1.0f, viewportU1, viewportV1 }
		};
		bool depthSampleEnabled = depthTexture != nullptr;
		bool detachDepthSurface = depthSampleEnabled && activeDepthSurface != nullptr;
		if (detachDepthSurface)
		{
			HRESULT depthResult = device->SetDepthStencilSurface(nullptr);
			if (FAILED(depthResult))
			{
				depthSampleEnabled = false;
				s_rendererState.depthAvailableLastFrame = false;
				s_rendererState.depthLastHr = static_cast<UInt32>(depthResult);
				if (s_settings.rendererDebugLog && !s_rendererState.depthUnavailableLogged)
				{
					_MESSAGE("VES depth texture unavailable: SetDepthStencilSurface(NULL) failed hr=%08X", s_rendererState.depthLastHr);
					s_rendererState.depthUnavailableLogged = true;
				}
			}
		}

		float capturedDepthAgeSeconds =
			(depthSource == kDepthSampleSource_CapturedWorld && now >= s_rendererState.capturedDepthTick) ?
			(static_cast<float>(now - s_rendererState.capturedDepthTick) * 0.001f) :
			0.0f;
		float constants[24] =
		{
			static_cast<float>(now) * 0.001f,
			effectiveIntensity,
			static_cast<float>(remainingMs) * 0.001f,
			static_cast<float>(s_effect.doseCount),
			1.0f / renderTargetWidth,
			1.0f / renderTargetHeight,
			viewportWidth,
			viewportHeight,
			s_settings.waveStrength,
			s_settings.swirlStrength,
			s_settings.chromaStrength,
			s_settings.colorShift,
			static_cast<float>(GetEffectProfileShaderFamily(s_effect.profile)),
			GetEffectProfileSeverity(s_effect.profile),
			depthSampleEnabled ? 1.0f : 0.0f,
			GetEffectProfileVariant(s_effect.profile),
			viewportU0,
			viewportV0,
			viewportU1 - viewportU0,
			viewportV1 - viewportV0,
			depthSampleEnabled ? 1.0f : 0.0f,
			(depthSource == kDepthSampleSource_CapturedWorld && depthSampleEnabled) ? 1.0f : 0.0f,
			(depthSource == kDepthSampleSource_ActiveFallback && depthSampleEnabled) ? 1.0f : 0.0f,
			capturedDepthAgeSeconds
		};

		device->SetRenderState(D3DRS_ZENABLE, FALSE);
		device->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);
		device->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
		device->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
		device->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
		device->SetRenderState(D3DRS_FOGENABLE, FALSE);
		device->SetRenderState(D3DRS_LIGHTING, FALSE);
		device->SetRenderState(D3DRS_STENCILENABLE, FALSE);
		device->SetRenderState(D3DRS_SCISSORTESTENABLE, FALSE);

		device->SetSamplerState(0, D3DSAMP_ADDRESSU, D3DTADDRESS_CLAMP);
		device->SetSamplerState(0, D3DSAMP_ADDRESSV, D3DTADDRESS_CLAMP);
		device->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
		device->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
		device->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_NONE);
		device->SetSamplerState(1, D3DSAMP_ADDRESSU, D3DTADDRESS_CLAMP);
		device->SetSamplerState(1, D3DSAMP_ADDRESSV, D3DTADDRESS_CLAMP);
		device->SetSamplerState(1, D3DSAMP_MAGFILTER, D3DTEXF_POINT);
		device->SetSamplerState(1, D3DSAMP_MINFILTER, D3DTEXF_POINT);
		device->SetSamplerState(1, D3DSAMP_MIPFILTER, D3DTEXF_NONE);

		device->SetTexture(0, sceneTexture);
		device->SetTexture(1, depthSampleEnabled ? depthTexture : sceneTexture);
		device->SetVertexShader(nullptr);
		device->SetPixelShader(activePixelShader);
		device->SetPixelShaderConstantF(0, constants, 6);
		device->SetFVF(kScreenVertexFVF);

		HRESULT result = device->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, vertices, sizeof(ScreenVertex));

		device->SetTexture(0, nullptr);
		device->SetTexture(1, nullptr);
		device->SetPixelShader(nullptr);
		if (detachDepthSurface && activeDepthSurface)
			device->SetDepthStencilSurface(activeDepthSurface);
		return SUCCEEDED(result);
	}

	enum ObjectVertexPassFamily
	{
		kObjectVertexPass_Unknown = 0,
		kObjectVertexPass_Lighting30,
		kObjectVertexPass_Parallax,
		kObjectVertexPass_Skin
	};

	const char* GetObjectVertexPassFamilyName(ObjectVertexPassFamily family)
	{
		switch (family)
		{
			case kObjectVertexPass_Lighting30:
				return "Lighting30";
			case kObjectVertexPass_Parallax:
				return "Parallax";
			case kObjectVertexPass_Skin:
				return "Skin";
			default:
				return "Unknown";
		}
	}

	void* GetPassTableEntry(UInt32 tableAddress, UInt32 index)
	{
		return *reinterpret_cast<void**>(tableAddress + (index * sizeof(void*)));
	}

	bool IsPointerInTable(void* pointer, UInt32 tableAddress, UInt32 count, UInt32* outIndex)
	{
		if (!pointer)
			return false;

		for (UInt32 i = 0; i < count; ++i)
		{
			if (pointer == GetPassTableEntry(tableAddress, i))
			{
				if (outIndex)
					*outIndex = i;
				return true;
			}
		}

		return false;
	}

	bool IsPassInTable(void* pass, UInt32 tableAddress, UInt32 count, UInt32 currentPassIndex, UInt32* outIndex)
	{
		if (!pass)
			return false;

		if (currentPassIndex < count && pass == GetPassTableEntry(tableAddress, currentPassIndex))
		{
			if (outIndex)
				*outIndex = currentPassIndex;
			return true;
		}

		for (UInt32 i = 0; i < count; ++i)
		{
			if (pass == GetPassTableEntry(tableAddress, i))
			{
				if (outIndex)
					*outIndex = i;
				return true;
			}
		}

		return false;
	}

	ObjectVertexPassFamily ClassifyObjectVertexPass(void* pass, UInt32 currentPassIndex, UInt32* outIndex)
	{
		UInt32 index = 0;
		if (IsPassInTable(pass, kLighting30PassTableAddress, kLighting30PassCount, currentPassIndex, &index))
		{
			if (outIndex)
				*outIndex = index;
			return kObjectVertexPass_Lighting30;
		}

		if (IsPassInTable(pass, kParallaxPassTableAddress, kParallaxPassCount, currentPassIndex, &index))
		{
			if (outIndex)
				*outIndex = index;
			return kObjectVertexPass_Parallax;
		}

		if (IsPassInTable(pass, kSkinPassTableAddress, kSkinPassCount, currentPassIndex, &index))
		{
			if (outIndex)
				*outIndex = index;
			return kObjectVertexPass_Skin;
		}

		if (outIndex)
			*outIndex = currentPassIndex;
		return kObjectVertexPass_Unknown;
	}

	const char* GetObjectVertexProgramFamilyName(ObjectVertexProgramFamily family)
	{
		switch (family)
		{
			case kObjectVertexProgram_Lighting30VS:
				return "Lighting30VS";
			case kObjectVertexProgram_Lighting30PS:
				return "Lighting30PS";
			case kObjectVertexProgram_Lighting30LowPS:
				return "Lighting30LowPS";
			default:
				return "Unknown";
		}
	}

	const char* GetObjectVertexProgramLabel(ObjectVertexProgramFamily family, UInt32 index)
	{
		switch (family)
		{
			case kObjectVertexProgram_Lighting30VS:
				if (index < kLighting30VertexProgramCount)
					return kLighting30VertexProgramLabels[index];
				break;

			case kObjectVertexProgram_Lighting30PS:
				if (index < kLighting30PixelProgramCount)
					return kLighting30PixelProgramLabels[index];
				break;

			case kObjectVertexProgram_Lighting30LowPS:
				if (index < kLighting30LowPixelProgramCount)
					return kLighting30LowPixelProgramLabels[index];
				break;

			default:
				break;
		}

		return "Unknown";
	}

	ObjectVertexProgramFamily ClassifyObjectVertexProgram(void* program, bool vertexProgram, UInt32* outIndex)
	{
		UInt32 index = 0;
		if (vertexProgram)
		{
			if (IsPointerInTable(program, kLighting30VertexProgramTableAddress, kLighting30VertexProgramCount, &index))
			{
				if (outIndex)
					*outIndex = index;
				return kObjectVertexProgram_Lighting30VS;
			}
		}
		else
		{
			if (IsPointerInTable(program, kLighting30PixelProgramTableAddress, kLighting30PixelProgramCount, &index))
			{
				if (outIndex)
					*outIndex = index;
				return kObjectVertexProgram_Lighting30PS;
			}

			if (IsPointerInTable(program, kLighting30LowPixelProgramTableAddress, kLighting30LowPixelProgramCount, &index))
			{
				if (outIndex)
					*outIndex = index;
				return kObjectVertexProgram_Lighting30LowPS;
			}
		}

		if (outIndex)
			*outIndex = 0xFFFFFFFF;
		return kObjectVertexProgram_Unknown;
	}

	void RecordObjectVertexPassSample(
		void* shader,
		void* pass,
		void* vertexShader,
		void* pixelShader,
		UInt32 currentPassIndex,
		UInt32 passCount,
		ObjectVertexPassFamily family,
		UInt32 passIndex)
	{
		UInt32 vertexProgramIndex = 0xFFFFFFFF;
		UInt32 pixelProgramIndex = 0xFFFFFFFF;
		ObjectVertexProgramFamily vertexProgramFamily = ClassifyObjectVertexProgram(vertexShader, true, &vertexProgramIndex);
		ObjectVertexProgramFamily pixelProgramFamily = ClassifyObjectVertexProgram(pixelShader, false, &pixelProgramIndex);

		for (UInt32 i = 0; i < kObjectVertexPassSampleSlots; ++i)
		{
			ObjectVertexPassSample& entry = s_objectVertexPassSamples[i];
			if (entry.pass == pass && entry.vertexShader == vertexShader && entry.pixelShader == pixelShader)
			{
				++entry.count;
				entry.shader = shader;
				entry.currentPassIndex = currentPassIndex;
				entry.passCount = passCount;
				entry.passFamily = family;
				entry.passIndex = passIndex;
				entry.vertexProgramFamily = vertexProgramFamily;
				entry.vertexProgramIndex = vertexProgramIndex;
				entry.pixelProgramFamily = pixelProgramFamily;
				entry.pixelProgramIndex = pixelProgramIndex;
				return;
			}
		}

		for (UInt32 i = 0; i < kObjectVertexPassSampleSlots; ++i)
		{
			ObjectVertexPassSample& entry = s_objectVertexPassSamples[i];
			if (!entry.pass)
			{
				entry.pass = pass;
				entry.shader = shader;
				entry.vertexShader = vertexShader;
				entry.pixelShader = pixelShader;
				entry.currentPassIndex = currentPassIndex;
				entry.passCount = passCount;
				entry.passFamily = family;
				entry.passIndex = passIndex;
				entry.vertexProgramFamily = vertexProgramFamily;
				entry.vertexProgramIndex = vertexProgramIndex;
				entry.pixelProgramFamily = pixelProgramFamily;
				entry.pixelProgramIndex = pixelProgramIndex;
				entry.count = 1;
				return;
			}
		}
	}

	void RecordObjectVertexPassCensus(
		void* shader,
		void* pass,
		void* vertexShader,
		void* pixelShader,
		UInt32 currentPassIndex,
		UInt32 passCount,
		ObjectVertexPassFamily family,
		UInt32 passIndex)
	{
		++s_objectVertexShaderState.passCensusSamples;
		RecordObjectVertexPassSample(shader, pass, vertexShader, pixelShader, currentPassIndex, passCount, family, passIndex);

		switch (family)
		{
			case kObjectVertexPass_Lighting30:
			{
				UInt32 vertexProgramIndex = 0xFFFFFFFF;
				UInt32 pixelProgramIndex = 0xFFFFFFFF;
				ObjectVertexProgramFamily vertexProgramFamily = ClassifyObjectVertexProgram(vertexShader, true, &vertexProgramIndex);
				ObjectVertexProgramFamily pixelProgramFamily = ClassifyObjectVertexProgram(pixelShader, false, &pixelProgramIndex);

				if (passIndex < kLighting30PassCount)
					++s_objectVertexShaderState.lighting30PassCounts[passIndex];
				if (vertexProgramFamily == kObjectVertexProgram_Lighting30VS && vertexProgramIndex < kLighting30VertexProgramCount)
					++s_objectVertexShaderState.lighting30VertexProgramCounts[vertexProgramIndex];
				if (pixelProgramFamily == kObjectVertexProgram_Lighting30PS && pixelProgramIndex < kLighting30PixelProgramCount)
					++s_objectVertexShaderState.lighting30PixelProgramCounts[pixelProgramIndex];
				if (pixelProgramFamily == kObjectVertexProgram_Lighting30LowPS && pixelProgramIndex < kLighting30LowPixelProgramCount)
					++s_objectVertexShaderState.lighting30LowPixelProgramCounts[pixelProgramIndex];
				return;
			}

			case kObjectVertexPass_Parallax:
				if (passIndex < kParallaxPassCount)
					++s_objectVertexShaderState.parallaxPassCounts[passIndex];
				return;

			case kObjectVertexPass_Skin:
				if (passIndex < kSkinPassCount)
					++s_objectVertexShaderState.skinPassCounts[passIndex];
				return;

			default:
				break;
		}

		for (UInt32 i = 0; i < kObjectVertexUnknownPassSlots; ++i)
		{
			ObjectVertexUnknownPass& entry = s_objectVertexUnknownPasses[i];
			if (entry.pass == pass)
			{
				++entry.count;
				entry.shader = shader;
				entry.vertexShader = vertexShader;
				entry.pixelShader = pixelShader;
				entry.currentPassIndex = currentPassIndex;
				return;
			}
		}

		for (UInt32 i = 0; i < kObjectVertexUnknownPassSlots; ++i)
		{
			ObjectVertexUnknownPass& entry = s_objectVertexUnknownPasses[i];
			if (!entry.pass)
			{
				entry.pass = pass;
				entry.shader = shader;
				entry.vertexShader = vertexShader;
				entry.pixelShader = pixelShader;
				entry.currentPassIndex = currentPassIndex;
				entry.count = 1;
				return;
			}
		}

		++s_objectVertexShaderState.unknownPassOverflow;
	}

	bool GetObjectVertexCurrentPassInfo(
		void* shader,
		void** outPass,
		void** outOriginalVertexShader,
		void** outOriginalPixelShader,
		UInt32* outCurrentPassIndex,
		UInt32* outPassCount,
		ObjectVertexPassFamily* outFamily,
		UInt32* outPassIndex)
	{
		if (!shader)
			return false;

		UInt8* shaderBytes = reinterpret_cast<UInt8*>(shader);
		UInt32 passCount = *reinterpret_cast<UInt32*>(shaderBytes + kNiD3DShaderPassCountOffset);
		UInt32 currentPassIndex = *reinterpret_cast<UInt32*>(shaderBytes + kNiD3DShaderCurrentPassIndexOffset);
		void* currentPass = *reinterpret_cast<void**>(shaderBytes + kNiD3DShaderCurrentPassOffset);

		if (!currentPass || passCount == 0)
			return false;

		void* originalVertexShader = *reinterpret_cast<void**>(reinterpret_cast<UInt8*>(currentPass) + kNiD3DPassVertexShaderOffset);
		if (!originalVertexShader)
			return false;
		void* originalPixelShader = *reinterpret_cast<void**>(reinterpret_cast<UInt8*>(currentPass) + kNiD3DPassPixelShaderOffset);

		UInt32 passIndex = 0;
		ObjectVertexPassFamily family = ClassifyObjectVertexPass(currentPass, currentPassIndex, &passIndex);

		if (outPass)
			*outPass = currentPass;
		if (outOriginalVertexShader)
			*outOriginalVertexShader = originalVertexShader;
		if (outOriginalPixelShader)
			*outOriginalPixelShader = originalPixelShader;
		if (outCurrentPassIndex)
			*outCurrentPassIndex = currentPassIndex;
		if (outPassCount)
			*outPassCount = passCount;
		if (outFamily)
			*outFamily = family;
		if (outPassIndex)
			*outPassIndex = passIndex;
		return true;
	}

	bool TryGetLighting30Sm3Variant(
		ObjectVertexPassFamily family,
		UInt32 passIndex,
		void* originalVertexShader,
		void* originalPixelShader,
		UInt32* outVariant,
		UInt32* outVertexProgramIndex,
		UInt32* outPixelProgramIndex,
		bool* outUsesLowLightPixel)
	{
		if (family != kObjectVertexPass_Lighting30 || passIndex >= kLighting30PassCount)
			return false;

		UInt32 vertexProgramIndex = kLighting30PassVertexProgramIndices[passIndex];
		UInt32 pixelProgramIndex = kLighting30PassPixelProgramIndices[passIndex];
		UInt32 variant = 0xFFFFFFFF;
		switch (vertexProgramIndex)
		{
			case 0:
				variant = kLighting30ObjectVertexShader_Sm3000;
				break;
			case 2:
				variant = kLighting30ObjectVertexShader_Sm3002Vc;
				break;
			case 4:
				variant = kLighting30ObjectVertexShader_Sm3004Proj;
				break;
			case 6:
				variant = kLighting30ObjectVertexShader_Sm3006VcProj;
				break;
			case 1:
				variant = kLighting30ObjectVertexShader_Sm3001Skin;
				break;
			case 3:
				variant = kLighting30ObjectVertexShader_Sm3003SkinVc;
				break;
			case 5:
				variant = kLighting30ObjectVertexShader_Sm3005SkinProj;
				break;
			case 7:
				variant = kLighting30ObjectVertexShader_Sm3007SkinVcProj;
				break;
			default:
				return false;
		}

		if (pixelProgramIndex >= kLighting30PixelProgramCount)
			return false;

		const Lighting30PixelProgramContract& pixelContract = kLighting30PixelProgramContracts[pixelProgramIndex];
		if (strcmp(pixelContract.family, "SM3Lighting") != 0)
			return false;

		void* expectedVertexShader = *reinterpret_cast<void**>(
			kLighting30VertexProgramTableAddress + vertexProgramIndex * sizeof(void*));
		void* expectedPixelShader = *reinterpret_cast<void**>(
			kLighting30PixelProgramTableAddress + pixelProgramIndex * sizeof(void*));

		if (!originalVertexShader ||
			!originalPixelShader ||
			originalVertexShader != expectedVertexShader)
		{
			return false;
		}

		bool usesLowLightPixel = false;
		bool pixelShaderMatches = originalPixelShader == expectedPixelShader;
		if (!pixelShaderMatches && pixelProgramIndex < kLighting30LowPixelProgramCount)
		{
			const Lighting30PixelProgramContract& lowPixelContract = kLighting30LowPixelProgramContracts[pixelProgramIndex];
			if (strcmp(lowPixelContract.family, "SM3LLLighting") == 0)
			{
				void* expectedLowPixelShader = *reinterpret_cast<void**>(
					kLighting30LowPixelProgramTableAddress + pixelProgramIndex * sizeof(void*));
				pixelShaderMatches = originalPixelShader == expectedLowPixelShader;
				usesLowLightPixel = pixelShaderMatches;
			}
		}

		if (!pixelShaderMatches)
			return false;

		if (outVariant)
			*outVariant = variant;
		if (outVertexProgramIndex)
			*outVertexProgramIndex = vertexProgramIndex;
		if (outPixelProgramIndex)
			*outPixelProgramIndex = pixelProgramIndex;
		if (outUsesLowLightPixel)
			*outUsesLowLightPixel = usesLowLightPixel;
		return true;
	}

	bool TryGetLighting30EnvMapVariant(
		ObjectVertexPassFamily family,
		UInt32 passIndex,
		void* originalVertexShader,
		void* originalPixelShader,
		UInt32* outVariant,
		UInt32* outVertexProgramIndex,
		UInt32* outPixelProgramIndex)
	{
		if (family != kObjectVertexPass_Lighting30 || passIndex >= kLighting30PassCount)
			return false;

		UInt32 vertexProgramIndex = kLighting30PassVertexProgramIndices[passIndex];
		UInt32 pixelProgramIndex = kLighting30PassPixelProgramIndices[passIndex];
		UInt32 variant = 0xFFFFFFFF;
		switch (vertexProgramIndex)
		{
			case 8:
				variant = kLighting30EnvMapVertexShader_Sm3008;
				break;
			case 9:
				variant = kLighting30EnvMapVertexShader_Sm3009Vc;
				break;
			case 10:
				variant = kLighting30EnvMapVertexShader_Sm3010Skin;
				break;
			case 11:
				variant = kLighting30EnvMapVertexShader_Sm3011SkinVc;
				break;
			case 12:
				variant = kLighting30EnvMapVertexShader_Sm3012Special;
				break;
			default:
				return false;
		}

		if (pixelProgramIndex >= kLighting30PixelProgramCount)
			return false;

		const Lighting30PixelProgramContract& pixelContract = kLighting30PixelProgramContracts[pixelProgramIndex];
		if (strcmp(pixelContract.family, "EnvMap") != 0)
			return false;

		void* expectedVertexShader = *reinterpret_cast<void**>(
			kLighting30VertexProgramTableAddress + vertexProgramIndex * sizeof(void*));
		void* expectedPixelShader = *reinterpret_cast<void**>(
			kLighting30PixelProgramTableAddress + pixelProgramIndex * sizeof(void*));

		if (!originalVertexShader ||
			!originalPixelShader ||
			originalVertexShader != expectedVertexShader ||
			originalPixelShader != expectedPixelShader)
		{
			return false;
		}

		if (outVariant)
			*outVariant = variant;
		if (outVertexProgramIndex)
			*outVertexProgramIndex = vertexProgramIndex;
		if (outPixelProgramIndex)
			*outPixelProgramIndex = pixelProgramIndex;
		return true;
	}

	bool TryGetLighting30TexEffectVariant(
		ObjectVertexPassFamily family,
		UInt32 passIndex,
		void* originalVertexShader,
		void* originalPixelShader,
		UInt32* outVariant,
		UInt32* outVertexProgramIndex,
		UInt32* outPixelProgramIndex)
	{
		if (family != kObjectVertexPass_Lighting30 || passIndex >= kLighting30PassCount)
			return false;
		if (passIndex != 52 && passIndex != 53)
			return false;

		UInt32 vertexProgramIndex = kLighting30PassVertexProgramIndices[passIndex];
		UInt32 pixelProgramIndex = kLighting30PassPixelProgramIndices[passIndex];
		UInt32 variant = 0xFFFFFFFF;
		switch (vertexProgramIndex)
		{
			case 28:
				variant = kLighting30TexEffectVertexShader_Sm3028;
				break;
			case 29:
				variant = kLighting30TexEffectVertexShader_Sm3029Skin;
				break;
			default:
				return false;
		}

		if (pixelProgramIndex >= kLighting30PixelProgramCount)
			return false;

		const Lighting30PixelProgramContract& pixelContract = kLighting30PixelProgramContracts[pixelProgramIndex];
		if (strcmp(pixelContract.family, "TexEffect") != 0)
			return false;

		void* expectedVertexShader = *reinterpret_cast<void**>(
			kLighting30VertexProgramTableAddress + vertexProgramIndex * sizeof(void*));
		void* expectedPixelShader = *reinterpret_cast<void**>(
			kLighting30PixelProgramTableAddress + pixelProgramIndex * sizeof(void*));

		if (!originalVertexShader ||
			!originalPixelShader ||
			originalVertexShader != expectedVertexShader ||
			originalPixelShader != expectedPixelShader)
		{
			return false;
		}

		if (outVariant)
			*outVariant = variant;
		if (outVertexProgramIndex)
			*outVertexProgramIndex = vertexProgramIndex;
		if (outPixelProgramIndex)
			*outPixelProgramIndex = pixelProgramIndex;
		return true;
	}

	bool TryGetLighting30DecalVariant(
		ObjectVertexPassFamily family,
		UInt32 passIndex,
		void* originalVertexShader,
		void* originalPixelShader,
		UInt32* outVariant,
		UInt32* outVertexProgramIndex,
		UInt32* outPixelProgramIndex)
	{
		if (family != kObjectVertexPass_Lighting30 || passIndex >= kLighting30PassCount)
			return false;
		if (passIndex != 40 && passIndex != 41)
			return false;

		UInt32 vertexProgramIndex = kLighting30PassVertexProgramIndices[passIndex];
		UInt32 pixelProgramIndex = kLighting30PassPixelProgramIndices[passIndex];
		if (vertexProgramIndex != 17)
			return false;
		if (pixelProgramIndex != 24 && pixelProgramIndex != 25)
			return false;
		if (pixelProgramIndex >= kLighting30PixelProgramCount)
			return false;

		const Lighting30PixelProgramContract& pixelContract = kLighting30PixelProgramContracts[pixelProgramIndex];
		if (strcmp(pixelContract.family, "Decal") != 0)
			return false;

		void* expectedVertexShader = *reinterpret_cast<void**>(
			kLighting30VertexProgramTableAddress + vertexProgramIndex * sizeof(void*));
		void* expectedPixelShader = *reinterpret_cast<void**>(
			kLighting30PixelProgramTableAddress + pixelProgramIndex * sizeof(void*));

		if (!originalVertexShader ||
			!originalPixelShader ||
			originalVertexShader != expectedVertexShader ||
			originalPixelShader != expectedPixelShader)
		{
			return false;
		}

		if (outVariant)
			*outVariant = kLighting30DecalVertexShader_Sm3017;
		if (outVertexProgramIndex)
			*outVertexProgramIndex = vertexProgramIndex;
		if (outPixelProgramIndex)
			*outPixelProgramIndex = pixelProgramIndex;
		return true;
	}

	bool TryGetLighting30DepthMapVariant(
		ObjectVertexPassFamily family,
		UInt32 passIndex,
		void* originalVertexShader,
		void* originalPixelShader,
		UInt32* outVariant,
		UInt32* outVertexProgramIndex,
		UInt32* outPixelProgramIndex)
	{
		if (family != kObjectVertexPass_Lighting30 || passIndex >= kLighting30PassCount)
			return false;
		if (passIndex != kLighting30DepthMapObjectPassIndex && passIndex != kLighting30DepthMapSkinPassIndex)
			return false;

		UInt32 vertexProgramIndex = kLighting30PassVertexProgramIndices[passIndex];
		UInt32 pixelProgramIndex = kLighting30PassPixelProgramIndices[passIndex];
		UInt32 variant = 0xFFFFFFFF;
		switch (vertexProgramIndex)
		{
			case kLighting30DepthMapObjectVertexProgramIndex:
				variant = kLighting30DepthMapVertexShader_Sm3018;
				break;
			case kLighting30DepthMapSkinVertexProgramIndex:
				variant = kLighting30DepthMapVertexShader_Sm3019Skin;
				break;
			default:
				return false;
		}

		UInt32 expectedVertexConstantMask =
			variant == kLighting30DepthMapVertexShader_Sm3019Skin ?
			kLighting30DepthMapSkinVertexConstantMask :
			kLighting30DepthMapObjectVertexConstantMask;
		if (kLighting30PassVertexConstantMasks[passIndex] != expectedVertexConstantMask ||
			kLighting30PassPixelConstantMasks[passIndex] != kLighting30DepthMapPixelConstantMask)
		{
			return false;
		}

		if (pixelProgramIndex != kLighting30DepthMapPixelProgramIndex ||
			pixelProgramIndex >= kLighting30PixelProgramCount)
			return false;

		const Lighting30PixelProgramContract& pixelContract = kLighting30PixelProgramContracts[pixelProgramIndex];
		if (strcmp(pixelContract.family, "DepthMap") != 0)
			return false;

		void* expectedVertexShader = *reinterpret_cast<void**>(
			kLighting30VertexProgramTableAddress + vertexProgramIndex * sizeof(void*));
		void* expectedPixelShader = *reinterpret_cast<void**>(
			kLighting30PixelProgramTableAddress + pixelProgramIndex * sizeof(void*));

		if (!originalVertexShader ||
			!originalPixelShader ||
			originalVertexShader != expectedVertexShader ||
			originalPixelShader != expectedPixelShader)
		{
			return false;
		}

		if (outVariant)
			*outVariant = variant;
		if (outVertexProgramIndex)
			*outVertexProgramIndex = vertexProgramIndex;
		if (outPixelProgramIndex)
			*outPixelProgramIndex = pixelProgramIndex;
		return true;
	}

	bool TryGetLighting30SupportVariant(
		ObjectVertexPassFamily family,
		UInt32 passIndex,
		void* originalVertexShader,
		void* originalPixelShader,
		UInt32* outVariant,
		UInt32* outVertexProgramIndex,
		UInt32* outPixelProgramIndex)
	{
		if (family != kObjectVertexPass_Lighting30 || passIndex >= kLighting30PassCount)
			return false;

		UInt32 expectedVertexProgramIndex = 0xFFFFFFFF;
		UInt32 expectedPixelProgramIndex = 0xFFFFFFFF;
		UInt32 expectedVertexConstantMask = 0;
		UInt32 expectedPixelConstantMask = 0;
		UInt32 variant = 0xFFFFFFFF;
		const char* expectedPixelFamily = nullptr;

		switch (passIndex)
		{
			case 0:
				variant = kLighting30SupportVertexShader_Sm3030ZOnly;
				expectedVertexProgramIndex = 30;
				expectedPixelProgramIndex = 37;
				expectedVertexConstantMask = 0x00000812;
				expectedPixelConstantMask = kLighting30ZOnlyPixelConstantMask;
				expectedPixelFamily = "ZOnly";
				break;
			case 1:
				variant = kLighting30SupportVertexShader_Sm3030ZOnly;
				expectedVertexProgramIndex = 30;
				expectedPixelProgramIndex = 37;
				expectedVertexConstantMask = 0x00000002;
				expectedPixelConstantMask = kLighting30ZOnlyPixelConstantMask;
				expectedPixelFamily = "ZOnly";
				break;
			case 2:
				variant = kLighting30SupportVertexShader_Sm3031ZOnlySkin;
				expectedVertexProgramIndex = 31;
				expectedPixelProgramIndex = 38;
				expectedVertexConstantMask = 0x0000000C;
				expectedPixelConstantMask = kLighting30ZOnlyPixelConstantMask;
				expectedPixelFamily = "ZOnly";
				break;
			case 36:
				variant = kLighting30SupportVertexShader_Sm3013SimpleShadow;
				expectedVertexProgramIndex = 13;
				expectedPixelProgramIndex = 23;
				expectedVertexConstantMask = 0x00030802;
				expectedPixelConstantMask = kLighting30SimpleShadowPixelConstantMask;
				expectedPixelFamily = "SimpleShadow";
				break;
			case 37:
				variant = kLighting30SupportVertexShader_Sm3014SimpleShadowVc;
				expectedVertexProgramIndex = 14;
				expectedPixelProgramIndex = 23;
				expectedVertexConstantMask = 0x00030802;
				expectedPixelConstantMask = kLighting30SimpleShadowPixelConstantMask;
				expectedPixelFamily = "SimpleShadow";
				break;
			case 38:
				variant = kLighting30SupportVertexShader_Sm3015SimpleShadowSkin;
				expectedVertexProgramIndex = 15;
				expectedPixelProgramIndex = 23;
				expectedVertexConstantMask = 0x0003080C;
				expectedPixelConstantMask = kLighting30SimpleShadowPixelConstantMask;
				expectedPixelFamily = "SimpleShadow";
				break;
			case 39:
				variant = kLighting30SupportVertexShader_Sm3016SimpleShadowSkinVc;
				expectedVertexProgramIndex = 16;
				expectedPixelProgramIndex = 23;
				expectedVertexConstantMask = 0x0003080C;
				expectedPixelConstantMask = kLighting30SimpleShadowPixelConstantMask;
				expectedPixelFamily = "SimpleShadow";
				break;
			case 44:
				variant = kLighting30SupportVertexShader_Sm3020RenderNormals;
				expectedVertexProgramIndex = 20;
				expectedPixelProgramIndex = 28;
				expectedVertexConstantMask = 0x00000012;
				expectedPixelConstantMask = kLighting30RenderNormalsPixelConstantMask;
				expectedPixelFamily = "RenderNormals";
				break;
			case 45:
				variant = kLighting30SupportVertexShader_Sm3021RenderNormalsSkin;
				expectedVertexProgramIndex = 21;
				expectedPixelProgramIndex = 29;
				expectedVertexConstantMask = 0x0000002C;
				expectedPixelConstantMask = kLighting30RenderNormalsPixelConstantMask;
				expectedPixelFamily = "RenderNormals";
				break;
			case 46:
				variant = kLighting30SupportVertexShader_Sm3022RenderNormalsFire;
				expectedVertexProgramIndex = 22;
				expectedPixelProgramIndex = 30;
				expectedVertexConstantMask = 0x00108012;
				expectedPixelConstantMask = kLighting30RenderNormalsPixelConstantMask;
				expectedPixelFamily = "RenderNormals";
				break;
			case 47:
			case 48:
				// CLEAR support passes write constant buffer values; replacing coverage can leave stale support data.
				return false;
			case 49:
				variant = kLighting30SupportVertexShader_Sm3025LocalMap;
				expectedVertexProgramIndex = 25;
				expectedPixelProgramIndex = 33;
				expectedVertexConstantMask = 0x00000012;
				expectedPixelConstantMask = kLighting30LocalMapPixelConstantMask;
				expectedPixelFamily = "LocalMap";
				break;
			case 50:
				variant = kLighting30SupportVertexShader_Sm3026LocalMapSkin;
				expectedVertexProgramIndex = 26;
				expectedPixelProgramIndex = 33;
				expectedVertexConstantMask = 0x0000002C;
				expectedPixelConstantMask = kLighting30LocalMapPixelConstantMask;
				expectedPixelFamily = "LocalMap";
				break;
			case 51:
				return false;
			default:
				return false;
		}

		UInt32 vertexProgramIndex = kLighting30PassVertexProgramIndices[passIndex];
		UInt32 pixelProgramIndex = kLighting30PassPixelProgramIndices[passIndex];
		if (vertexProgramIndex != expectedVertexProgramIndex ||
			pixelProgramIndex != expectedPixelProgramIndex ||
			kLighting30PassVertexConstantMasks[passIndex] != expectedVertexConstantMask ||
			kLighting30PassPixelConstantMasks[passIndex] != expectedPixelConstantMask ||
			pixelProgramIndex >= kLighting30PixelProgramCount)
		{
			return false;
		}

		const Lighting30PixelProgramContract& pixelContract = kLighting30PixelProgramContracts[pixelProgramIndex];
		if (!expectedPixelFamily || strcmp(pixelContract.family, expectedPixelFamily) != 0)
			return false;

		void* expectedVertexShader = *reinterpret_cast<void**>(
			kLighting30VertexProgramTableAddress + vertexProgramIndex * sizeof(void*));
		void* expectedPixelShader = *reinterpret_cast<void**>(
			kLighting30PixelProgramTableAddress + pixelProgramIndex * sizeof(void*));

		if (!originalVertexShader ||
			!originalPixelShader ||
			originalVertexShader != expectedVertexShader ||
			originalPixelShader != expectedPixelShader)
		{
			return false;
		}

		if (outVariant)
			*outVariant = variant;
		if (outVertexProgramIndex)
			*outVertexProgramIndex = vertexProgramIndex;
		if (outPixelProgramIndex)
			*outPixelProgramIndex = pixelProgramIndex;
		return true;
	}

	bool TryGetLegacyObjectVertexShaderVariant(
		ObjectVertexPassFamily family,
		UInt32 passIndex,
		void* pass,
		void* shader,
		void* originalVertexShader,
		void* originalPixelShader,
		UInt32* outVariant)
	{
		if (!pass || !shader || !originalVertexShader || !originalPixelShader)
			return false;

		void* expectedPass = nullptr;
		void* expectedVertexShader = nullptr;
		void* expectedPixelShader = nullptr;
		UInt32 variant = 0xFFFFFFFF;

		if (family == kObjectVertexPass_Parallax && passIndex == 0)
		{
			expectedPass = GetPassTableEntry(kParallaxPassTableAddress, 0);
			expectedVertexShader = *reinterpret_cast<void**>(
				reinterpret_cast<UInt8*>(shader) + kParallaxPass0VertexShaderObjectOffset);
			expectedPixelShader = *reinterpret_cast<void**>(
				reinterpret_cast<UInt8*>(shader) + kParallaxPass0PixelShaderObjectOffset);
			variant = kLegacyObjectVertexShader_Par2016;
		}
		else if (family == kObjectVertexPass_Skin && passIndex == 0)
		{
			expectedPass = GetPassTableEntry(kSkinPassTableAddress, 0);
			expectedVertexShader = *reinterpret_cast<void**>(
				reinterpret_cast<UInt8*>(shader) + kSkinPass0VertexShaderObjectOffset);
			expectedPixelShader = *reinterpret_cast<void**>(
				reinterpret_cast<UInt8*>(shader) + kSkinPass0PixelShaderObjectOffset);
			variant = kLegacyObjectVertexShader_Skin2008;
		}
		else
		{
			return false;
		}

		if (!expectedPass ||
			!expectedVertexShader ||
			!expectedPixelShader ||
			pass != expectedPass ||
			originalVertexShader != expectedVertexShader ||
			originalPixelShader != expectedPixelShader)
		{
			return false;
		}

		if (outVariant)
			*outVariant = variant;
		return true;
	}

	ObjectVertexReplacementKind GetObjectVertexReplacementKind(
		ObjectVertexPassFamily family,
		UInt32 passIndex,
		void* pass,
		void* shader,
		void* originalVertexShader,
		void* originalPixelShader)
	{
		if (TryGetLegacyObjectVertexShaderVariant(family, passIndex, pass, shader, originalVertexShader, originalPixelShader, nullptr))
			return kObjectVertexReplacement_ParallaxSkinVs20;

		if (TryGetLighting30Sm3Variant(family, passIndex, originalVertexShader, originalPixelShader, nullptr, nullptr, nullptr, nullptr))
			return kObjectVertexReplacement_Lighting30Sm3Vs30;

		if (TryGetLighting30EnvMapVariant(family, passIndex, originalVertexShader, originalPixelShader, nullptr, nullptr, nullptr))
			return kObjectVertexReplacement_Lighting30EnvMapVs30;

		if (TryGetLighting30TexEffectVariant(family, passIndex, originalVertexShader, originalPixelShader, nullptr, nullptr, nullptr))
			return kObjectVertexReplacement_Lighting30TexEffectVs30;

		if (TryGetLighting30DecalVariant(family, passIndex, originalVertexShader, originalPixelShader, nullptr, nullptr, nullptr))
			return kObjectVertexReplacement_Lighting30DecalVs30;

		// Keep native support/depth/normal buffers owned by Oblivion. Runtime testing showed that
		// wobbling these auxiliary passes can surface as white texture flashes or unstable normals.

		return kObjectVertexReplacement_None;
	}

	const char* GetObjectVertexReplacementName(ObjectVertexReplacementKind kind)
	{
		switch (kind)
		{
			case kObjectVertexReplacement_ParallaxSkinVs20:
				return "PAR2016/SKIN2008";
			case kObjectVertexReplacement_Lighting30Sm3Vs30:
				return "Lighting30 SM3";
			case kObjectVertexReplacement_Lighting30EnvMapVs30:
				return "Lighting30 EnvMap";
			case kObjectVertexReplacement_Lighting30TexEffectVs30:
				return "Lighting30 TexEffect";
			case kObjectVertexReplacement_Lighting30DecalVs30:
				return "Lighting30 Decal";
			case kObjectVertexReplacement_Lighting30DepthMapVs30:
				return "Lighting30 DepthMap";
			case kObjectVertexReplacement_Lighting30SupportVs30:
				return "Lighting30 Support";
			default:
				return "none";
		}
	}

	UInt32 GetLighting30ObjectVertexShaderMask()
	{
		UInt32 mask = 0;
		for (UInt32 i = 0; i < kLighting30ObjectVertexShaderVariantCount; ++i)
			if (s_objectVertexShaderState.lighting30VertexShaders[i])
				mask |= (1u << i);
		return mask;
	}

	UInt32 GetLighting30ObjectVertexAppliedMask()
	{
		UInt32 mask = 0;
		for (UInt32 i = 0; i < kLighting30ObjectVertexShaderVariantCount; ++i)
			if (s_objectVertexShaderState.lighting30Applied[i])
				mask |= (1u << i);
		return mask;
	}

	UInt32 GetLighting30EnvMapVertexShaderMask()
	{
		UInt32 mask = 0;
		for (UInt32 i = 0; i < kLighting30EnvMapVertexShaderVariantCount; ++i)
			if (s_objectVertexShaderState.lighting30EnvMapVertexShaders[i])
				mask |= (1u << i);
		return mask;
	}

	UInt32 GetLighting30EnvMapVertexAppliedMask()
	{
		UInt32 mask = 0;
		for (UInt32 i = 0; i < kLighting30EnvMapVertexShaderVariantCount; ++i)
			if (s_objectVertexShaderState.lighting30EnvMapApplied[i])
				mask |= (1u << i);
		return mask;
	}

	UInt32 GetLighting30TexEffectVertexShaderMask()
	{
		UInt32 mask = 0;
		for (UInt32 i = 0; i < kLighting30TexEffectVertexShaderVariantCount; ++i)
			if (s_objectVertexShaderState.lighting30TexEffectVertexShaders[i])
				mask |= (1u << i);
		return mask;
	}

	UInt32 GetLighting30TexEffectVertexAppliedMask()
	{
		UInt32 mask = 0;
		for (UInt32 i = 0; i < kLighting30TexEffectVertexShaderVariantCount; ++i)
			if (s_objectVertexShaderState.lighting30TexEffectApplied[i])
				mask |= (1u << i);
		return mask;
	}

	UInt32 GetLighting30DecalVertexShaderMask()
	{
		UInt32 mask = 0;
		for (UInt32 i = 0; i < kLighting30DecalVertexShaderVariantCount; ++i)
			if (s_objectVertexShaderState.lighting30DecalVertexShaders[i])
				mask |= (1u << i);
		return mask;
	}

	UInt32 GetLighting30DecalVertexAppliedMask()
	{
		UInt32 mask = 0;
		for (UInt32 i = 0; i < kLighting30DecalVertexShaderVariantCount; ++i)
			if (s_objectVertexShaderState.lighting30DecalApplied[i])
				mask |= (1u << i);
		return mask;
	}

	UInt32 GetLighting30DepthMapVertexShaderMask()
	{
		UInt32 mask = 0;
		for (UInt32 i = 0; i < kLighting30DepthMapVertexShaderVariantCount; ++i)
			if (s_objectVertexShaderState.lighting30DepthMapVertexShaders[i])
				mask |= (1u << i);
		return mask;
	}

	UInt32 GetLighting30DepthMapVertexAppliedMask()
	{
		UInt32 mask = 0;
		for (UInt32 i = 0; i < kLighting30DepthMapVertexShaderVariantCount; ++i)
			if (s_objectVertexShaderState.lighting30DepthMapApplied[i])
				mask |= (1u << i);
		return mask;
	}

	UInt32 GetLighting30SupportVertexShaderMask()
	{
		UInt32 mask = 0;
		for (UInt32 i = 0; i < kLighting30SupportVertexShaderVariantCount; ++i)
			if (s_objectVertexShaderState.lighting30SupportVertexShaders[i])
				mask |= (1u << i);
		return mask;
	}

	UInt32 GetLighting30SupportVertexAppliedMask()
	{
		UInt32 mask = 0;
		for (UInt32 i = 0; i < kLighting30SupportVertexShaderVariantCount; ++i)
			if (s_objectVertexShaderState.lighting30SupportApplied[i])
				mask |= (1u << i);
		return mask;
	}

	UInt32 GetLegacyObjectVertexAppliedMask()
	{
		UInt32 mask = 0;
		for (UInt32 i = 0; i < kLegacyObjectVertexShaderVariantCount; ++i)
			if (s_objectVertexShaderState.legacyApplied[i])
				mask |= (1u << i);
		return mask;
	}

	UInt32 GetLighting30ObjectVertexCompileAttemptMask()
	{
		UInt32 mask = 0;
		for (UInt32 i = 0; i < kLighting30ObjectVertexShaderVariantCount; ++i)
			if (s_objectVertexShaderState.lighting30CompileAttempted[i])
				mask |= (1u << i);
		return mask;
	}

	UInt32 GetLighting30EnvMapVertexCompileAttemptMask()
	{
		UInt32 mask = 0;
		for (UInt32 i = 0; i < kLighting30EnvMapVertexShaderVariantCount; ++i)
			if (s_objectVertexShaderState.lighting30EnvMapCompileAttempted[i])
				mask |= (1u << i);
		return mask;
	}

	UInt32 GetLighting30TexEffectVertexCompileAttemptMask()
	{
		UInt32 mask = 0;
		for (UInt32 i = 0; i < kLighting30TexEffectVertexShaderVariantCount; ++i)
			if (s_objectVertexShaderState.lighting30TexEffectCompileAttempted[i])
				mask |= (1u << i);
		return mask;
	}

	UInt32 GetLighting30DecalVertexCompileAttemptMask()
	{
		UInt32 mask = 0;
		for (UInt32 i = 0; i < kLighting30DecalVertexShaderVariantCount; ++i)
			if (s_objectVertexShaderState.lighting30DecalCompileAttempted[i])
				mask |= (1u << i);
		return mask;
	}

	UInt32 GetLighting30DepthMapVertexCompileAttemptMask()
	{
		UInt32 mask = 0;
		for (UInt32 i = 0; i < kLighting30DepthMapVertexShaderVariantCount; ++i)
			if (s_objectVertexShaderState.lighting30DepthMapCompileAttempted[i])
				mask |= (1u << i);
		return mask;
	}

	UInt32 GetLighting30SupportVertexCompileAttemptMask()
	{
		UInt32 mask = 0;
		for (UInt32 i = 0; i < kLighting30SupportVertexShaderVariantCount; ++i)
			if (s_objectVertexShaderState.lighting30SupportCompileAttempted[i])
				mask |= (1u << i);
		return mask;
	}

	UInt32 GetLighting30ObjectVertexCompileFailedMask()
	{
		UInt32 mask = 0;
		for (UInt32 i = 0; i < kLighting30ObjectVertexShaderVariantCount; ++i)
			if (s_objectVertexShaderState.lighting30CompileFailed[i])
				mask |= (1u << i);
		return mask;
	}

	UInt32 GetLighting30EnvMapVertexCompileFailedMask()
	{
		UInt32 mask = 0;
		for (UInt32 i = 0; i < kLighting30EnvMapVertexShaderVariantCount; ++i)
			if (s_objectVertexShaderState.lighting30EnvMapCompileFailed[i])
				mask |= (1u << i);
		return mask;
	}

	UInt32 GetLighting30TexEffectVertexCompileFailedMask()
	{
		UInt32 mask = 0;
		for (UInt32 i = 0; i < kLighting30TexEffectVertexShaderVariantCount; ++i)
			if (s_objectVertexShaderState.lighting30TexEffectCompileFailed[i])
				mask |= (1u << i);
		return mask;
	}

	UInt32 GetLighting30DecalVertexCompileFailedMask()
	{
		UInt32 mask = 0;
		for (UInt32 i = 0; i < kLighting30DecalVertexShaderVariantCount; ++i)
			if (s_objectVertexShaderState.lighting30DecalCompileFailed[i])
				mask |= (1u << i);
		return mask;
	}

	UInt32 GetLighting30DepthMapVertexCompileFailedMask()
	{
		UInt32 mask = 0;
		for (UInt32 i = 0; i < kLighting30DepthMapVertexShaderVariantCount; ++i)
			if (s_objectVertexShaderState.lighting30DepthMapCompileFailed[i])
				mask |= (1u << i);
		return mask;
	}

	UInt32 GetLighting30SupportVertexCompileFailedMask()
	{
		UInt32 mask = 0;
		for (UInt32 i = 0; i < kLighting30SupportVertexShaderVariantCount; ++i)
			if (s_objectVertexShaderState.lighting30SupportCompileFailed[i])
				mask |= (1u << i);
		return mask;
	}

	UInt32 SumPassCounts(const UInt32* counts, UInt32 count)
	{
		UInt32 total = 0;
		for (UInt32 i = 0; i < count; ++i)
			total += counts[i];
		return total;
	}

	void CollectTopPassCounts(const UInt32* counts, UInt32 count, PassCountTopEntry* out, UInt32 outCount)
	{
		if (!out || !outCount)
			return;

		for (UInt32 i = 0; i < outCount; ++i)
		{
			out[i].index = 0xFFFFFFFF;
			out[i].count = 0;
		}

		for (UInt32 i = 0; i < count; ++i)
		{
			UInt32 value = counts[i];
			if (!value)
				continue;

			for (UInt32 slot = 0; slot < outCount; ++slot)
			{
				if (value > out[slot].count)
				{
					for (UInt32 move = outCount - 1; move > slot; --move)
						out[move] = out[move - 1];

					out[slot].index = i;
					out[slot].count = value;
					break;
				}
			}
		}
	}

	void FormatTopPassCounts(const PassCountTopEntry* topEntries, UInt32 topCount, char* out, UInt32 outLen)
	{
		if (!out || !outLen)
			return;

		out[0] = '\0';

		for (UInt32 slot = 0; slot < topCount; ++slot)
		{
			if (!topEntries[slot].count)
				continue;

			char piece[48] = {};
			_snprintf_s(piece, sizeof(piece), _TRUNCATE, "%s%u:%u", out[0] ? "," : "", topEntries[slot].index, topEntries[slot].count);
			strncat_s(out, outLen, piece, _TRUNCATE);
		}

		if (!out[0])
			strncpy_s(out, outLen, "none", _TRUNCATE);
	}

	bool TextStartsWith(const char* text, const char* prefix)
	{
		if (!text || !prefix)
			return false;

		size_t prefixLen = strlen(prefix);
		return strncmp(text, prefix, prefixLen) == 0;
	}

	UInt32 GetLighting30PrimarySelectorId(UInt32 passIndex)
	{
		return passIndex < kLighting30PassCount ? kLighting30SelectorIdBase + passIndex : kLighting30SelectorAliasNone;
	}

	UInt32 GetLighting30AliasSelectorId(UInt32 passIndex)
	{
		if (passIndex == 1)
			return 4;
		if (passIndex == 2)
			return 5;
		return kLighting30SelectorAliasNone;
	}

	UInt32 GetLighting30PrimarySelectorA8(UInt32 passIndex)
	{
		if (passIndex >= 1 && passIndex <= 0x2B)
			return 7;
		if (passIndex >= 0x2C && passIndex <= 0x33)
			return 0xF;
		return 0;
	}

	const char* GetLighting30SelectorRoute(UInt32 passIndex)
	{
		if (passIndex == 0)
			return "direct";
		if (passIndex == 1 || passIndex == 2)
			return "alpha7+directAlias";
		if (passIndex <= 0x2B)
			return "alpha7";
		if (passIndex <= 0x33)
			return "alpha15";
		if (passIndex <= 0x35)
			return "altShaderSlots";
		return "unknown";
	}

	bool IsLighting30SupportBufferFamily(const char* family)
	{
		return family &&
			(strcmp(family, "SimpleShadow") == 0 ||
				strcmp(family, "DepthMap") == 0 ||
				strcmp(family, "RenderNormals") == 0 ||
				strcmp(family, "LocalMap") == 0 ||
				strcmp(family, "ZOnly") == 0);
	}

	const char* GetLighting30PipelineCoverageStatus(UInt32 passIndex)
	{
		if (passIndex >= kLighting30PassCount)
			return "unknown:passIndex";

		UInt32 vertexProgramIndex = kLighting30PassVertexProgramIndices[passIndex];
		UInt32 pixelProgramIndex = kLighting30PassPixelProgramIndices[passIndex];
		if (vertexProgramIndex >= kLighting30VertexProgramCount ||
			pixelProgramIndex >= kLighting30PixelProgramCount)
		{
			return "unknown:programIndex";
		}

		const Lighting30VertexProgramContract& vertexContract = kLighting30VertexProgramContracts[vertexProgramIndex];
		const Lighting30PixelProgramContract& pixelContract = kLighting30PixelProgramContracts[pixelProgramIndex];
		if ((vertexContract.flags & kLighting30VertexContract_Clear) ||
			(pixelContract.flags & kLighting30PixelContract_Clear))
		{
			return "blocked:clearSupportPass";
		}

		if (strcmp(vertexContract.family, "SM3Lighting") == 0 &&
			strcmp(pixelContract.family, "SM3Lighting") == 0)
		{
			return "implemented:visibleLighting30";
		}
		if (strcmp(vertexContract.family, "EnvMap") == 0 &&
			strcmp(pixelContract.family, "EnvMap") == 0)
		{
			return "implemented:visibleEnvMap";
		}
		if (strcmp(vertexContract.family, "TexEffect") == 0 &&
			strcmp(pixelContract.family, "TexEffect") == 0)
		{
			return "implemented:visibleTexEffect";
		}
		if (strcmp(vertexContract.family, "Decal") == 0 &&
			strcmp(pixelContract.family, "Decal") == 0)
		{
			return "implemented:visibleDecal";
		}
		if (IsLighting30SupportBufferFamily(vertexContract.family) &&
			strcmp(vertexContract.family, pixelContract.family) == 0)
		{
			return "blocked:preserveNativeSupportBuffers";
		}

		return "unknown:familyMismatch";
	}

	struct ObjectVertexPipelineCoverage
	{
		UInt32 lighting30Observed;
		UInt32 visibleImplemented;
		UInt32 supportPreserved;
		UInt32 blockedClear;
		UInt32 unknown;
		UInt32 parallaxObserved;
		UInt32 skinObserved;
		UInt32 largestGapPass;
		UInt32 largestGapCount;
		const char* largestGapStatus;
	};

	void BuildObjectVertexPipelineCoverage(ObjectVertexPipelineCoverage* out)
	{
		if (!out)
			return;

		out->lighting30Observed = SumPassCounts(s_objectVertexShaderState.lighting30PassCounts, kLighting30PassCount);
		out->visibleImplemented = 0;
		out->supportPreserved = 0;
		out->blockedClear = 0;
		out->unknown = s_objectVertexShaderState.unknownPassOverflow;
		out->parallaxObserved = SumPassCounts(s_objectVertexShaderState.parallaxPassCounts, kParallaxPassCount);
		out->skinObserved = SumPassCounts(s_objectVertexShaderState.skinPassCounts, kSkinPassCount);
		out->largestGapPass = 0xFFFFFFFF;
		out->largestGapCount = 0;
		out->largestGapStatus = "none";

		for (UInt32 passIndex = 0; passIndex < kLighting30PassCount; ++passIndex)
		{
			UInt32 count = s_objectVertexShaderState.lighting30PassCounts[passIndex];
			if (!count)
				continue;

			const char* status = GetLighting30PipelineCoverageStatus(passIndex);
			if (TextStartsWith(status, "implemented:visible"))
			{
				out->visibleImplemented += count;
				continue;
			}
			if (TextStartsWith(status, "blocked:preserveNativeSupportBuffers"))
				out->supportPreserved += count;
			else if (TextStartsWith(status, "blocked:clear"))
				out->blockedClear += count;
			else
				out->unknown += count;

			if (count > out->largestGapCount)
			{
				out->largestGapPass = passIndex;
				out->largestGapCount = count;
				out->largestGapStatus = status;
			}
		}
	}

	void LogObjectVertexPipelineCoverage()
	{
		ObjectVertexPipelineCoverage coverage = {};
		BuildObjectVertexPipelineCoverage(&coverage);

		Console_Print(
			"VES pipeline coverage: lighting30Observed=%u visibleImplemented=%u supportPreserved=%u blockedClear=%u unknown=%u parallaxObserved=%u skinObserved=%u applied=%u",
			coverage.lighting30Observed,
			coverage.visibleImplemented,
			coverage.supportPreserved,
			coverage.blockedClear,
			coverage.unknown,
			coverage.parallaxObserved,
			coverage.skinObserved,
			s_objectVertexShaderState.applied);
		Console_Print(
			"VES pipeline largest gap: pass=%s count=%u status=%s",
			coverage.largestGapPass == 0xFFFFFFFF ? "none" : "Lighting30",
			coverage.largestGapCount,
			coverage.largestGapStatus);
		if (coverage.largestGapPass != 0xFFFFFFFF)
		{
			Console_Print(
				"VES pipeline largest gap detail: pass=%u selector=%04X route=%s vs=\"%s\" ps=\"%s\"",
				coverage.largestGapPass,
				GetLighting30PrimarySelectorId(coverage.largestGapPass),
				GetLighting30SelectorRoute(coverage.largestGapPass),
				GetObjectVertexProgramLabel(kObjectVertexProgram_Lighting30VS, kLighting30PassVertexProgramIndices[coverage.largestGapPass]),
				GetObjectVertexProgramLabel(kObjectVertexProgram_Lighting30PS, kLighting30PassPixelProgramIndices[coverage.largestGapPass]));
		}

		_MESSAGE(
			"Pipeline coverage: lighting30Observed=%u visibleImplemented=%u supportPreserved=%u blockedClear=%u unknown=%u parallaxObserved=%u skinObserved=%u applied=%u largestGapPass=%u largestGapCount=%u largestGapStatus=%s",
			coverage.lighting30Observed,
			coverage.visibleImplemented,
			coverage.supportPreserved,
			coverage.blockedClear,
			coverage.unknown,
			coverage.parallaxObserved,
			coverage.skinObserved,
			s_objectVertexShaderState.applied,
			coverage.largestGapPass,
			coverage.largestGapCount,
			coverage.largestGapStatus);
	}

	void FormatSelectorId(UInt32 selectorId, char* out, UInt32 outLen)
	{
		if (!out || !outLen)
			return;

		if (selectorId == kLighting30SelectorAliasNone)
			strncpy_s(out, outLen, "none", _TRUNCATE);
		else
			_snprintf_s(out, outLen, _TRUNCATE, "%04X", selectorId);
	}

	void FormatLighting30VertexContract(UInt32 vertexProgramIndex, char* out, UInt32 outLen)
	{
		if (!out || !outLen)
			return;

		if (vertexProgramIndex >= kLighting30VertexProgramCount)
		{
			strncpy_s(out, outLen, "unknown", _TRUNCATE);
			return;
		}

		const Lighting30VertexProgramContract& contract = kLighting30VertexProgramContracts[vertexProgramIndex];
		strncpy_s(out, outLen, contract.family, _TRUNCATE);

		if (contract.flags & kLighting30VertexContract_Skin)
			strncat_s(out, outLen, "|SKIN", _TRUNCATE);
		if (contract.flags & kLighting30VertexContract_VertexColor)
			strncat_s(out, outLen, "|VC", _TRUNCATE);
		if (contract.flags & kLighting30VertexContract_ProjectShadow)
			strncat_s(out, outLen, "|PROJSHADOW", _TRUNCATE);
		if (contract.flags & kLighting30VertexContract_Special)
			strncat_s(out, outLen, "|SPECIAL", _TRUNCATE);
		if (contract.flags & kLighting30VertexContract_Clear)
			strncat_s(out, outLen, "|CLEAR", _TRUNCATE);
		if (contract.flags & kLighting30VertexContract_Fire)
			strncat_s(out, outLen, "|FIRE", _TRUNCATE);
	}

	const char* GetLighting30VertexReadiness(UInt32 vertexProgramIndex)
	{
		if (vertexProgramIndex >= kLighting30VertexProgramCount)
			return "unknown";

		const Lighting30VertexProgramContract& contract = kLighting30VertexProgramContracts[vertexProgramIndex];
		if (strcmp(contract.family, "SM3Lighting") == 0)
		{
			UInt32 supportedFlags =
				kLighting30VertexContract_Skin |
				kLighting30VertexContract_VertexColor |
				kLighting30VertexContract_ProjectShadow;
			if ((contract.flags & ~supportedFlags) == 0)
				return "candidate:SM3LightingVS30Clone";
			return "blocked:SM3LightingVariantNeedsClone";
		}
		if (strcmp(contract.family, "EnvMap") == 0)
		{
			UInt32 supportedFlags =
				kLighting30VertexContract_Skin |
				kLighting30VertexContract_VertexColor |
				kLighting30VertexContract_Special;
			if ((contract.flags & ~supportedFlags) == 0)
				return "candidate:EnvMapVS30Clone";
			return "blocked:EnvMapVariantNeedsClone";
		}
		if (strcmp(contract.family, "TexEffect") == 0)
		{
			UInt32 supportedFlags = kLighting30VertexContract_Skin;
			if ((contract.flags & ~supportedFlags) == 0)
				return "candidate:TexEffectVS30Clone";
			return "blocked:TexEffectVariantNeedsClone";
		}
		if (strcmp(contract.family, "Decal") == 0)
			return "candidate:DecalVS30Clone";
		if (IsLighting30SupportBufferFamily(contract.family))
		{
			if (contract.flags & kLighting30VertexContract_Clear)
				return "blocked:clearSupportPass";
			return "blocked:preserveNativeSupportBuffers";
		}
		return "blocked:nonLightingAux";
	}

	void AppendLighting30PixelFlagText(UInt32 flags, char* out, UInt32 outLen)
	{
		if (flags & kLighting30PixelContract_Specular)
			strncat_s(out, outLen, "|SPECULAR", _TRUNCATE);
		if (flags & kLighting30PixelContract_Hair)
			strncat_s(out, outLen, "|HAIR", _TRUNCATE);
		if (flags & kLighting30PixelContract_Parallax)
			strncat_s(out, outLen, "|PARALLAX", _TRUNCATE);
		if (flags & kLighting30PixelContract_FaceGenBlend)
			strncat_s(out, outLen, "|FACEGENBLEND", _TRUNCATE);
		if (flags & kLighting30PixelContract_Glow)
			strncat_s(out, outLen, "|GLOW", _TRUNCATE);
		if (flags & kLighting30PixelContract_ProjectShadow)
			strncat_s(out, outLen, "|PROJSHADOW", _TRUNCATE);
		if (flags & kLighting30PixelContract_Window)
			strncat_s(out, outLen, "|WINDOW", _TRUNCATE);
		if (flags & kLighting30PixelContract_Special)
			strncat_s(out, outLen, "|SPECIAL", _TRUNCATE);
		if (flags & kLighting30PixelContract_SoftShadow)
			strncat_s(out, outLen, "|SOFTSHADOW", _TRUNCATE);
		if (flags & kLighting30PixelContract_DepthBias)
			strncat_s(out, outLen, "|DEPTHBIAS", _TRUNCATE);
		if (flags & kLighting30PixelContract_Alpha)
			strncat_s(out, outLen, "|ALPHA", _TRUNCATE);
		if (flags & kLighting30PixelContract_Fire)
			strncat_s(out, outLen, "|FIRE", _TRUNCATE);
		if (flags & kLighting30PixelContract_Clear)
			strncat_s(out, outLen, "|CLEAR", _TRUNCATE);
		if (flags & kLighting30PixelContract_HQ)
			strncat_s(out, outLen, "|HQ", _TRUNCATE);
	}

	void FormatLighting30PixelContract(
		ObjectVertexProgramFamily programFamily,
		UInt32 pixelProgramIndex,
		char* out,
		UInt32 outLen)
	{
		if (!out || !outLen)
			return;

		const Lighting30PixelProgramContract* contract = nullptr;
		if (programFamily == kObjectVertexProgram_Lighting30PS && pixelProgramIndex < kLighting30PixelProgramCount)
			contract = &kLighting30PixelProgramContracts[pixelProgramIndex];
		else if (programFamily == kObjectVertexProgram_Lighting30LowPS && pixelProgramIndex < kLighting30LowPixelProgramCount)
			contract = &kLighting30LowPixelProgramContracts[pixelProgramIndex];

		if (!contract)
		{
			strncpy_s(out, outLen, "unknown", _TRUNCATE);
			return;
		}

		strncpy_s(out, outLen, contract->family, _TRUNCATE);
		if (contract->maxLights)
		{
			char maxLightsText[16] = {};
			_snprintf_s(maxLightsText, sizeof(maxLightsText), _TRUNCATE, "|MAX%u", contract->maxLights);
			strncat_s(out, outLen, maxLightsText, _TRUNCATE);
		}
		AppendLighting30PixelFlagText(contract->flags, out, outLen);
	}

	const Lighting30PixelProgramContract* GetLighting30PixelContract(
		ObjectVertexProgramFamily programFamily,
		UInt32 pixelProgramIndex)
	{
		if (programFamily == kObjectVertexProgram_Lighting30PS && pixelProgramIndex < kLighting30PixelProgramCount)
			return &kLighting30PixelProgramContracts[pixelProgramIndex];
		if (programFamily == kObjectVertexProgram_Lighting30LowPS && pixelProgramIndex < kLighting30LowPixelProgramCount)
			return &kLighting30LowPixelProgramContracts[pixelProgramIndex];
		return nullptr;
	}

	const char* GetLighting30PixelReadiness(ObjectVertexProgramFamily programFamily, UInt32 pixelProgramIndex)
	{
		const Lighting30PixelProgramContract* contract = GetLighting30PixelContract(programFamily, pixelProgramIndex);
		if (!contract)
			return "unknown";
		if (strcmp(contract->family, "SM3Lighting") == 0)
			return "candidate:nativeSM3LightingPS";
		if (programFamily == kObjectVertexProgram_Lighting30LowPS && strcmp(contract->family, "SM3LLLighting") == 0)
			return "candidate:nativeSM3LLLightingPS";
		if (strcmp(contract->family, "EnvMap") == 0)
			return "candidate:nativeEnvMapPS";
		if (strcmp(contract->family, "TexEffect") == 0)
			return "candidate:nativeTexEffectPS";
		if (strcmp(contract->family, "Decal") == 0)
			return "candidate:nativeDecalPS";
		if (IsLighting30SupportBufferFamily(contract->family))
		{
			if (contract->flags & kLighting30PixelContract_Clear)
				return "blocked:clearSupportPass";
			return "blocked:preserveNativeSupportBuffers";
		}
		return "blocked:nonLightingPixel";
	}

	const char* GetLighting30PassReadiness(UInt32 vertexProgramIndex, ObjectVertexProgramFamily pixelProgramFamily, UInt32 pixelProgramIndex)
	{
		const Lighting30VertexProgramContract* vertexContract =
			vertexProgramIndex < kLighting30VertexProgramCount ? &kLighting30VertexProgramContracts[vertexProgramIndex] : nullptr;
		const Lighting30PixelProgramContract* pixelContract = GetLighting30PixelContract(pixelProgramFamily, pixelProgramIndex);

		if (!vertexContract || !pixelContract)
			return "unknown";
		if (IsLighting30SupportBufferFamily(vertexContract->family) ||
			IsLighting30SupportBufferFamily(pixelContract->family))
		{
			if ((vertexContract->flags & kLighting30VertexContract_Clear) ||
				(pixelContract->flags & kLighting30PixelContract_Clear))
			{
				return "blocked:clearSupportPass";
			}
			return "blocked:preserveNativeSupportBuffers";
		}
		if (strcmp(vertexContract->family, "SM3Lighting") != 0)
		{
			if (strcmp(vertexContract->family, "EnvMap") == 0 &&
				pixelProgramFamily == kObjectVertexProgram_Lighting30PS &&
				strcmp(pixelContract->family, "EnvMap") == 0)
			{
				UInt32 supportedFlags =
					kLighting30VertexContract_Skin |
					kLighting30VertexContract_VertexColor |
					kLighting30VertexContract_Special;
				if ((vertexContract->flags & ~supportedFlags) == 0)
					return "candidate:EnvMapVS30Pass";
				return "blocked:EnvMapVariantNeedsClone";
			}
			if (strcmp(vertexContract->family, "TexEffect") == 0 &&
				pixelProgramFamily == kObjectVertexProgram_Lighting30PS &&
				strcmp(pixelContract->family, "TexEffect") == 0)
			{
				UInt32 supportedFlags = kLighting30VertexContract_Skin;
				if ((vertexContract->flags & ~supportedFlags) == 0)
					return "candidate:TexEffectVS30Pass";
				return "blocked:TexEffectVariantNeedsClone";
			}
			if (strcmp(vertexContract->family, "Decal") == 0 &&
				pixelProgramFamily == kObjectVertexProgram_Lighting30PS &&
				strcmp(pixelContract->family, "Decal") == 0)
			{
				if (vertexContract->flags == kLighting30VertexContract_None)
				return "candidate:DecalVS30Pass";
				return "blocked:DecalVariantNeedsClone";
			}
			return "blocked:nonLightingVS";
		}
		UInt32 supportedVertexFlags =
			kLighting30VertexContract_Skin |
			kLighting30VertexContract_VertexColor |
			kLighting30VertexContract_ProjectShadow;
		if (vertexContract->flags & ~supportedVertexFlags)
			return "blocked:SM3LightingVSVariantNeedsClone";
		if (pixelProgramFamily == kObjectVertexProgram_Lighting30LowPS)
		{
			if (strcmp(pixelContract->family, "SM3LLLighting") == 0)
				return "candidate:SM3LLLightingVS30Pass";
			return "blocked:nonLightingLowPS";
		}
		if (strcmp(pixelContract->family, "SM3Lighting") != 0)
			return "blocked:nonLightingPS";
		return "candidate:SM3LightingVS30Pass";
	}

	const char* GetLighting30ReplacementPlan(
		UInt32 passIndex,
		UInt32 vertexProgramIndex,
		ObjectVertexProgramFamily pixelProgramFamily,
		UInt32 pixelProgramIndex)
	{
		const Lighting30PixelProgramContract* pixelContract = GetLighting30PixelContract(pixelProgramFamily, pixelProgramIndex);
		const Lighting30VertexProgramContract* vertexContract =
			vertexProgramIndex < kLighting30VertexProgramCount ? &kLighting30VertexProgramContracts[vertexProgramIndex] : nullptr;
		if ((vertexContract && IsLighting30SupportBufferFamily(vertexContract->family)) ||
			(pixelContract && IsLighting30SupportBufferFamily(pixelContract->family)))
		{
			return GetLighting30PassReadiness(vertexProgramIndex, pixelProgramFamily, pixelProgramIndex);
		}

		if (pixelContract &&
			((pixelProgramFamily == kObjectVertexProgram_Lighting30PS && strcmp(pixelContract->family, "SM3Lighting") == 0) ||
				(pixelProgramFamily == kObjectVertexProgram_Lighting30LowPS && strcmp(pixelContract->family, "SM3LLLighting") == 0)))
		{
			if (vertexProgramIndex == 0)
				return "candidate:SM3000_vs3_clone_c26c27";
			if (vertexProgramIndex == 2)
				return "candidate:SM3002_VC_vs3_clone_c26c27";
			if (vertexProgramIndex == 4)
				return "candidate:SM3004_PROJ_vs3_clone_c27c28";
			if (vertexProgramIndex == 6)
				return "candidate:SM3006_VC_PROJ_vs3_clone_c27c28";
			if (vertexProgramIndex == 1)
				return "candidate:SM3001_SKIN_vs3_clone_c27c28";
			if (vertexProgramIndex == 3)
				return "candidate:SM3003_SKIN_VC_vs3_clone_c27c28";
			if (vertexProgramIndex == 5)
				return "candidate:SM3005_SKIN_PROJ_vs3_clone_c27c28";
			if (vertexProgramIndex == 7)
				return "candidate:SM3007_SKIN_VC_PROJ_vs3_clone_c27c28";
		}

		if (pixelProgramFamily == kObjectVertexProgram_Lighting30PS &&
			pixelContract &&
			strcmp(pixelContract->family, "EnvMap") == 0)
		{
			if (vertexProgramIndex == 8)
				return "candidate:SM3008_ENVMAP_vs3_clone_c26c27";
			if (vertexProgramIndex == 9)
				return "candidate:SM3009_ENVMAP_VC_vs3_clone_c26c27";
			if (vertexProgramIndex == 10)
				return "candidate:SM3010_ENVMAP_SKIN_vs3_clone_c24c25";
			if (vertexProgramIndex == 11)
				return "candidate:SM3011_ENVMAP_SKIN_VC_vs3_clone_c24c25";
			if (vertexProgramIndex == 12)
				return "candidate:SM3012_ENVMAP_SPECIAL_vs3_clone_c26c27";
		}

		if (pixelProgramFamily == kObjectVertexProgram_Lighting30PS &&
			pixelContract &&
			strcmp(pixelContract->family, "TexEffect") == 0)
		{
			if (vertexProgramIndex == 28)
				return "candidate:SM3028_TEXEFFECT_vs3_clone_c26c27";
			if (vertexProgramIndex == 29)
				return "candidate:SM3029_TEXEFFECT_SKIN_vs3_clone_c68c69";
		}

		if (pixelProgramFamily == kObjectVertexProgram_Lighting30PS &&
			pixelContract &&
			strcmp(pixelContract->family, "Decal") == 0)
		{
			if (vertexProgramIndex == 17)
				return "candidate:SM3017_DECAL_vs3_clone_c26c27";
		}

		if (pixelProgramFamily == kObjectVertexProgram_Lighting30PS &&
			pixelContract &&
			(strcmp(pixelContract->family, "SimpleShadow") == 0 ||
				strcmp(pixelContract->family, "DepthMap") == 0 ||
				strcmp(pixelContract->family, "RenderNormals") == 0 ||
				strcmp(pixelContract->family, "LocalMap") == 0 ||
				strcmp(pixelContract->family, "ZOnly") == 0))
		{
			return GetLighting30PassReadiness(vertexProgramIndex, pixelProgramFamily, pixelProgramIndex);
		}

		const char* readiness = GetLighting30PassReadiness(vertexProgramIndex, pixelProgramFamily, pixelProgramIndex);
		return readiness;
	}

	void AppendDelimited(char* out, UInt32 outLen, const char* text)
	{
		if (!out || !outLen || !text || !text[0])
			return;

		if (out[0])
			strncat_s(out, outLen, ",", _TRUNCATE);

		strncat_s(out, outLen, text, _TRUNCATE);
	}

	bool IsMaskBitSet(UInt32 mask, UInt32 bitIndex)
	{
		return bitIndex < 32 && (mask & (1u << bitIndex)) != 0;
	}

	void FormatLighting30VertexMaskSummary(UInt32 mask, char* out, UInt32 outLen)
	{
		if (!out || !outLen)
			return;

		out[0] = '\0';

		char named[96] = {};
		if (IsMaskBitSet(mask, 1))
			AppendDelimited(named, sizeof(named), "WVP(c0)");
		if (IsMaskBitSet(mask, 2))
			AppendDelimited(named, sizeof(named), "SkinWVP(c1)");
		if (IsMaskBitSet(mask, 3))
			AppendDelimited(named, sizeof(named), "Bone3(c31)");
		if (IsMaskBitSet(mask, 4))
			AppendDelimited(named, sizeof(named), "WV(c5)");
		if (IsMaskBitSet(mask, 5))
			AppendDelimited(named, sizeof(named), "SkinWV(c6)");

		char stateBytes[128] = {};
		for (UInt32 bitIndex = 6; bitIndex < 32; ++bitIndex)
		{
			if (!IsMaskBitSet(mask, bitIndex))
				continue;

			char piece[24] = {};
			UInt32 byteOffset = bitIndex - 1;
			if (bitIndex == 11)
				_snprintf_s(piece, sizeof(piece), _TRUNCATE, "b%u:ViewProjCG", byteOffset);
			else if (bitIndex == 22)
				_snprintf_s(piece, sizeof(piece), _TRUNCATE, "b%u:ObjectCG", byteOffset);
			else if (bitIndex == 28)
				_snprintf_s(piece, sizeof(piece), _TRUNCATE, "b%u:SkinCG", byteOffset);
			else
				_snprintf_s(piece, sizeof(piece), _TRUNCATE, "b%u", byteOffset);

			AppendDelimited(stateBytes, sizeof(stateBytes), piece);
		}

		if (named[0])
			_snprintf_s(out, outLen, _TRUNCATE, "named[%s]", named);
		if (stateBytes[0])
		{
			if (out[0])
				strncat_s(out, outLen, "|", _TRUNCATE);
			strncat_s(out, outLen, "state[", _TRUNCATE);
			strncat_s(out, outLen, stateBytes, _TRUNCATE);
			strncat_s(out, outLen, "]", _TRUNCATE);
		}

		if (out[0])
			strncat_s(out, outLen, "|", _TRUNCATE);
		strncat_s(out, outLen, "forcedBytes[16-18]", _TRUNCATE);
	}

	void FormatLighting30PixelMaskSummary(UInt32 mask, char* out, UInt32 outLen)
	{
		if (!out || !outLen)
			return;

		out[0] = '\0';

		char rows[160] = {};
		for (UInt32 bitIndex = 1; bitIndex < 32; ++bitIndex)
		{
			if (!IsMaskBitSet(mask, bitIndex))
				continue;

			char piece[16] = {};
			_snprintf_s(piece, sizeof(piece), _TRUNCATE, "pc%u", bitIndex - 1);
			AppendDelimited(rows, sizeof(rows), piece);
		}

		if (rows[0])
			_snprintf_s(out, outLen, _TRUNCATE, "rows[%s]|forcedRows[5-7]", rows);
		else
			strncpy_s(out, outLen, "rows[none]|forcedRows[5-7]", _TRUNCATE);
	}

	void LogTopLighting30PassDetails(const PassCountTopEntry* topEntries, UInt32 topCount)
	{
		if (!topEntries)
			return;

		for (UInt32 i = 0; i < topCount; ++i)
		{
			if (!topEntries[i].count || topEntries[i].index >= kLighting30PassCount)
				continue;

			UInt32 vertexProgramIndex = kLighting30PassVertexProgramIndices[topEntries[i].index];
			UInt32 pixelProgramIndex = kLighting30PassPixelProgramIndices[topEntries[i].index];
			UInt32 vertexConstantMask = kLighting30PassVertexConstantMasks[topEntries[i].index];
			UInt32 pixelConstantMask = kLighting30PassPixelConstantMasks[topEntries[i].index];
			UInt32 primarySelectorId = GetLighting30PrimarySelectorId(topEntries[i].index);
			UInt32 aliasSelectorId = GetLighting30AliasSelectorId(topEntries[i].index);
			UInt32 primarySelectorA8 = GetLighting30PrimarySelectorA8(topEntries[i].index);
			char primarySelectorText[16] = {};
			char aliasSelectorText[16] = {};
			FormatSelectorId(primarySelectorId, primarySelectorText, sizeof(primarySelectorText));
			FormatSelectorId(aliasSelectorId, aliasSelectorText, sizeof(aliasSelectorText));
			const char* vertexProgramLabel = GetObjectVertexProgramLabel(kObjectVertexProgram_Lighting30VS, vertexProgramIndex);
			const char* pixelProgramLabel = GetObjectVertexProgramLabel(kObjectVertexProgram_Lighting30PS, pixelProgramIndex);
			const char* selectorRoute = GetLighting30SelectorRoute(topEntries[i].index);
			char vertexMaskSummary[192] = {};
			char pixelMaskSummary[192] = {};
			char vertexContract[96] = {};
			char pixelContract[128] = {};
			FormatLighting30VertexMaskSummary(vertexConstantMask, vertexMaskSummary, sizeof(vertexMaskSummary));
			FormatLighting30PixelMaskSummary(pixelConstantMask, pixelMaskSummary, sizeof(pixelMaskSummary));
			FormatLighting30VertexContract(vertexProgramIndex, vertexContract, sizeof(vertexContract));
			FormatLighting30PixelContract(kObjectVertexProgram_Lighting30PS, pixelProgramIndex, pixelContract, sizeof(pixelContract));

			Console_Print(
				"VES Lighting30 top[%u]: pass=%u count=%u selector=%s alias=%s route=%s a8=%u vs=%08X \"%s\" ps=%08X \"%s\" vMask=%08X pMask=%08X",
				i,
				topEntries[i].index,
				topEntries[i].count,
				primarySelectorText,
				aliasSelectorText,
				selectorRoute,
				primarySelectorA8,
				vertexProgramIndex,
				vertexProgramLabel,
				pixelProgramIndex,
				pixelProgramLabel,
				vertexConstantMask,
				pixelConstantMask);
			Console_Print(
				"VES Lighting30 mask[%u]: pass=%u v=%s p=%s",
				i,
				topEntries[i].index,
				vertexMaskSummary,
				pixelMaskSummary);
			Console_Print(
				"VES Lighting30 contract[%u]: pass=%u vs=%s vReady=%s ps=%s pReady=%s passReady=%s replacement=%s",
				i,
				topEntries[i].index,
				vertexContract,
				GetLighting30VertexReadiness(vertexProgramIndex),
				pixelContract,
				GetLighting30PixelReadiness(kObjectVertexProgram_Lighting30PS, pixelProgramIndex),
				GetLighting30PassReadiness(vertexProgramIndex, kObjectVertexProgram_Lighting30PS, pixelProgramIndex),
				GetLighting30ReplacementPlan(topEntries[i].index, vertexProgramIndex, kObjectVertexProgram_Lighting30PS, pixelProgramIndex));
			_MESSAGE(
				"Lighting30 top pass[%u]: pass=%u count=%u selector=%s alias=%s route=%s a8=%u vs=%08X \"%s\" ps=%08X \"%s\" vMask=%08X pMask=%08X",
				i,
				topEntries[i].index,
				topEntries[i].count,
				primarySelectorText,
				aliasSelectorText,
				selectorRoute,
				primarySelectorA8,
				vertexProgramIndex,
				vertexProgramLabel,
				pixelProgramIndex,
				pixelProgramLabel,
				vertexConstantMask,
				pixelConstantMask);
			_MESSAGE(
				"Lighting30 mask[%u]: pass=%u v=%s p=%s",
				i,
				topEntries[i].index,
				vertexMaskSummary,
				pixelMaskSummary);
			_MESSAGE(
				"Lighting30 contract[%u]: pass=%u vs=%s vReady=%s ps=%s pReady=%s passReady=%s replacement=%s",
				i,
				topEntries[i].index,
				vertexContract,
				GetLighting30VertexReadiness(vertexProgramIndex),
				pixelContract,
				GetLighting30PixelReadiness(kObjectVertexProgram_Lighting30PS, pixelProgramIndex),
				GetLighting30PassReadiness(vertexProgramIndex, kObjectVertexProgram_Lighting30PS, pixelProgramIndex),
				GetLighting30ReplacementPlan(topEntries[i].index, vertexProgramIndex, kObjectVertexProgram_Lighting30PS, pixelProgramIndex));
		}
	}

	void LogLighting30SampleMapCheck(const ObjectVertexPassSample& entry, UInt32 sampleIndex)
	{
		if (entry.passFamily != kObjectVertexPass_Lighting30 || entry.passIndex >= kLighting30PassCount)
			return;

		UInt32 expectedVertexProgramIndex = kLighting30PassVertexProgramIndices[entry.passIndex];
		UInt32 expectedPixelProgramIndex = kLighting30PassPixelProgramIndices[entry.passIndex];
		UInt32 vertexConstantMask = kLighting30PassVertexConstantMasks[entry.passIndex];
		UInt32 pixelConstantMask = kLighting30PassPixelConstantMasks[entry.passIndex];
		UInt32 primarySelectorId = GetLighting30PrimarySelectorId(entry.passIndex);
		UInt32 aliasSelectorId = GetLighting30AliasSelectorId(entry.passIndex);
		UInt32 primarySelectorA8 = GetLighting30PrimarySelectorA8(entry.passIndex);
		char primarySelectorText[16] = {};
		char aliasSelectorText[16] = {};
		FormatSelectorId(primarySelectorId, primarySelectorText, sizeof(primarySelectorText));
		FormatSelectorId(aliasSelectorId, aliasSelectorText, sizeof(aliasSelectorText));
		bool vertexMatches = entry.vertexProgramFamily == kObjectVertexProgram_Lighting30VS &&
			entry.vertexProgramIndex == expectedVertexProgramIndex;
		bool pixelMatches = entry.pixelProgramFamily == kObjectVertexProgram_Lighting30PS &&
			entry.pixelProgramIndex == expectedPixelProgramIndex;
		const char* mapStatus = (vertexMatches && pixelMatches) ? "match" : "mismatch";
		const char* expectedVertexProgramLabel = GetObjectVertexProgramLabel(kObjectVertexProgram_Lighting30VS, expectedVertexProgramIndex);
		const char* expectedPixelProgramLabel = GetObjectVertexProgramLabel(kObjectVertexProgram_Lighting30PS, expectedPixelProgramIndex);
		const char* selectorRoute = GetLighting30SelectorRoute(entry.passIndex);
		char vertexMaskSummary[192] = {};
		char pixelMaskSummary[192] = {};
		char vertexContract[96] = {};
		char pixelContract[128] = {};
		FormatLighting30VertexMaskSummary(vertexConstantMask, vertexMaskSummary, sizeof(vertexMaskSummary));
		FormatLighting30PixelMaskSummary(pixelConstantMask, pixelMaskSummary, sizeof(pixelMaskSummary));
		FormatLighting30VertexContract(expectedVertexProgramIndex, vertexContract, sizeof(vertexContract));
		FormatLighting30PixelContract(static_cast<ObjectVertexProgramFamily>(entry.pixelProgramFamily), entry.pixelProgramIndex, pixelContract, sizeof(pixelContract));

		Console_Print(
			"VES Lighting30 sample[%u] map=%s selector=%s alias=%s route=%s a8=%u expectedVS=%08X \"%s\" expectedPS=%08X \"%s\" vMask=%08X pMask=%08X",
			sampleIndex,
			mapStatus,
			primarySelectorText,
			aliasSelectorText,
			selectorRoute,
			primarySelectorA8,
			expectedVertexProgramIndex,
			expectedVertexProgramLabel,
			expectedPixelProgramIndex,
			expectedPixelProgramLabel,
			vertexConstantMask,
			pixelConstantMask);
		Console_Print(
			"VES Lighting30 sampleMask[%u]: pass=%u v=%s p=%s",
			sampleIndex,
			entry.passIndex,
			vertexMaskSummary,
			pixelMaskSummary);
		Console_Print(
			"VES Lighting30 sampleContract[%u]: pass=%u vs=%s vReady=%s ps=%s pReady=%s passReady=%s replacement=%s",
			sampleIndex,
			entry.passIndex,
			vertexContract,
			GetLighting30VertexReadiness(expectedVertexProgramIndex),
			pixelContract,
			GetLighting30PixelReadiness(static_cast<ObjectVertexProgramFamily>(entry.pixelProgramFamily), entry.pixelProgramIndex),
			GetLighting30PassReadiness(expectedVertexProgramIndex, static_cast<ObjectVertexProgramFamily>(entry.pixelProgramFamily), entry.pixelProgramIndex),
			GetLighting30ReplacementPlan(entry.passIndex, expectedVertexProgramIndex, static_cast<ObjectVertexProgramFamily>(entry.pixelProgramFamily), entry.pixelProgramIndex));
		_MESSAGE(
			"Lighting30 sample[%u] map=%s selector=%s alias=%s route=%s a8=%u expectedVS=%08X \"%s\" expectedPS=%08X \"%s\" vMask=%08X pMask=%08X",
			sampleIndex,
			mapStatus,
			primarySelectorText,
			aliasSelectorText,
			selectorRoute,
			primarySelectorA8,
			expectedVertexProgramIndex,
			expectedVertexProgramLabel,
			expectedPixelProgramIndex,
			expectedPixelProgramLabel,
			vertexConstantMask,
			pixelConstantMask);
		_MESSAGE(
			"Lighting30 sampleMask[%u]: pass=%u v=%s p=%s",
			sampleIndex,
			entry.passIndex,
			vertexMaskSummary,
			pixelMaskSummary);
		_MESSAGE(
			"Lighting30 sampleContract[%u]: pass=%u vs=%s vReady=%s ps=%s pReady=%s passReady=%s replacement=%s",
			sampleIndex,
			entry.passIndex,
			vertexContract,
			GetLighting30VertexReadiness(expectedVertexProgramIndex),
			pixelContract,
			GetLighting30PixelReadiness(static_cast<ObjectVertexProgramFamily>(entry.pixelProgramFamily), entry.pixelProgramIndex),
			GetLighting30PassReadiness(expectedVertexProgramIndex, static_cast<ObjectVertexProgramFamily>(entry.pixelProgramFamily), entry.pixelProgramIndex),
			GetLighting30ReplacementPlan(entry.passIndex, expectedVertexProgramIndex, static_cast<ObjectVertexProgramFamily>(entry.pixelProgramFamily), entry.pixelProgramIndex));
	}

	void LogObjectVertexPassCensus()
	{
		char lightingTop[96] = {};
		char parallaxTop[96] = {};
		char skinTop[96] = {};
		char lightingVsTop[96] = {};
		char lightingPsTop[96] = {};
		char lightingLowPsTop[96] = {};
		PassCountTopEntry lightingTopEntries[3] = {};
		PassCountTopEntry parallaxTopEntries[3] = {};
		PassCountTopEntry skinTopEntries[3] = {};
		PassCountTopEntry lightingVsTopEntries[3] = {};
		PassCountTopEntry lightingPsTopEntries[3] = {};
		PassCountTopEntry lightingLowPsTopEntries[3] = {};
		CollectTopPassCounts(s_objectVertexShaderState.lighting30PassCounts, kLighting30PassCount, lightingTopEntries, 3);
		CollectTopPassCounts(s_objectVertexShaderState.parallaxPassCounts, kParallaxPassCount, parallaxTopEntries, 3);
		CollectTopPassCounts(s_objectVertexShaderState.skinPassCounts, kSkinPassCount, skinTopEntries, 3);
		CollectTopPassCounts(s_objectVertexShaderState.lighting30VertexProgramCounts, kLighting30VertexProgramCount, lightingVsTopEntries, 3);
		CollectTopPassCounts(s_objectVertexShaderState.lighting30PixelProgramCounts, kLighting30PixelProgramCount, lightingPsTopEntries, 3);
		CollectTopPassCounts(s_objectVertexShaderState.lighting30LowPixelProgramCounts, kLighting30LowPixelProgramCount, lightingLowPsTopEntries, 3);
		FormatTopPassCounts(lightingTopEntries, 3, lightingTop, sizeof(lightingTop));
		FormatTopPassCounts(parallaxTopEntries, 3, parallaxTop, sizeof(parallaxTop));
		FormatTopPassCounts(skinTopEntries, 3, skinTop, sizeof(skinTop));
		FormatTopPassCounts(lightingVsTopEntries, 3, lightingVsTop, sizeof(lightingVsTop));
		FormatTopPassCounts(lightingPsTopEntries, 3, lightingPsTop, sizeof(lightingPsTop));
		FormatTopPassCounts(lightingLowPsTopEntries, 3, lightingLowPsTop, sizeof(lightingLowPsTop));

		UInt32 lightingTotal = SumPassCounts(s_objectVertexShaderState.lighting30PassCounts, kLighting30PassCount);
		UInt32 lightingVsTotal = SumPassCounts(s_objectVertexShaderState.lighting30VertexProgramCounts, kLighting30VertexProgramCount);
		UInt32 lightingPsTotal = SumPassCounts(s_objectVertexShaderState.lighting30PixelProgramCounts, kLighting30PixelProgramCount);
		UInt32 lightingLowPsTotal = SumPassCounts(s_objectVertexShaderState.lighting30LowPixelProgramCounts, kLighting30LowPixelProgramCount);
		UInt32 parallaxTotal = SumPassCounts(s_objectVertexShaderState.parallaxPassCounts, kParallaxPassCount);
		UInt32 skinTotal = SumPassCounts(s_objectVertexShaderState.skinPassCounts, kSkinPassCount);

		Console_Print(
			"VES objectVS pass census: Lighting30=%u top[%s] Parallax=%u top[%s] Skin=%u top[%s] unknownOverflow=%u",
			lightingTotal,
			lightingTop,
			parallaxTotal,
			parallaxTop,
			skinTotal,
			skinTop,
			s_objectVertexShaderState.unknownPassOverflow);
		_MESSAGE(
			"Object vertex pass census: Lighting30=%u top[%s] Parallax=%u top[%s] Skin=%u top[%s] unknownOverflow=%u",
			lightingTotal,
			lightingTop,
			parallaxTotal,
			parallaxTop,
			skinTotal,
			skinTop,
			s_objectVertexShaderState.unknownPassOverflow);

		Console_Print(
			"VES Lighting30 program census: VS=%u top[%s] PS=%u top[%s] lowPS=%u top[%s]",
			lightingVsTotal,
			lightingVsTop,
			lightingPsTotal,
			lightingPsTop,
			lightingLowPsTotal,
			lightingLowPsTop);
		_MESSAGE(
			"Lighting30 program census: VS=%u top[%s] PS=%u top[%s] lowPS=%u top[%s]",
			lightingVsTotal,
			lightingVsTop,
			lightingPsTotal,
			lightingPsTop,
			lightingLowPsTotal,
			lightingLowPsTop);

		for (UInt32 i = 0; i < 3; ++i)
		{
			if (!lightingVsTopEntries[i].count || lightingVsTopEntries[i].index >= kLighting30VertexProgramCount)
				continue;

			char vertexContract[96] = {};
			FormatLighting30VertexContract(lightingVsTopEntries[i].index, vertexContract, sizeof(vertexContract));
			Console_Print(
				"VES Lighting30 VS top[%u]: program=%u count=%u label=\"%s\" contract=%s readiness=%s",
				i,
				lightingVsTopEntries[i].index,
				lightingVsTopEntries[i].count,
				GetObjectVertexProgramLabel(kObjectVertexProgram_Lighting30VS, lightingVsTopEntries[i].index),
				vertexContract,
				GetLighting30VertexReadiness(lightingVsTopEntries[i].index));
			_MESSAGE(
				"Lighting30 VS top[%u]: program=%u count=%u label=\"%s\" contract=%s readiness=%s",
				i,
				lightingVsTopEntries[i].index,
				lightingVsTopEntries[i].count,
				GetObjectVertexProgramLabel(kObjectVertexProgram_Lighting30VS, lightingVsTopEntries[i].index),
				vertexContract,
				GetLighting30VertexReadiness(lightingVsTopEntries[i].index));
		}

		for (UInt32 i = 0; i < 3; ++i)
		{
			if (!lightingPsTopEntries[i].count || lightingPsTopEntries[i].index >= kLighting30PixelProgramCount)
				continue;

			char pixelContract[128] = {};
			FormatLighting30PixelContract(kObjectVertexProgram_Lighting30PS, lightingPsTopEntries[i].index, pixelContract, sizeof(pixelContract));
			Console_Print(
				"VES Lighting30 PS top[%u]: program=%u count=%u label=\"%s\" contract=%s readiness=%s",
				i,
				lightingPsTopEntries[i].index,
				lightingPsTopEntries[i].count,
				GetObjectVertexProgramLabel(kObjectVertexProgram_Lighting30PS, lightingPsTopEntries[i].index),
				pixelContract,
				GetLighting30PixelReadiness(kObjectVertexProgram_Lighting30PS, lightingPsTopEntries[i].index));
			_MESSAGE(
				"Lighting30 PS top[%u]: program=%u count=%u label=\"%s\" contract=%s readiness=%s",
				i,
				lightingPsTopEntries[i].index,
				lightingPsTopEntries[i].count,
				GetObjectVertexProgramLabel(kObjectVertexProgram_Lighting30PS, lightingPsTopEntries[i].index),
				pixelContract,
				GetLighting30PixelReadiness(kObjectVertexProgram_Lighting30PS, lightingPsTopEntries[i].index));
		}

		for (UInt32 i = 0; i < 3; ++i)
		{
			if (!lightingLowPsTopEntries[i].count || lightingLowPsTopEntries[i].index >= kLighting30LowPixelProgramCount)
				continue;

			char pixelContract[128] = {};
			FormatLighting30PixelContract(kObjectVertexProgram_Lighting30LowPS, lightingLowPsTopEntries[i].index, pixelContract, sizeof(pixelContract));
			Console_Print(
				"VES Lighting30 lowPS top[%u]: program=%u count=%u label=\"%s\" contract=%s readiness=%s",
				i,
				lightingLowPsTopEntries[i].index,
				lightingLowPsTopEntries[i].count,
				GetObjectVertexProgramLabel(kObjectVertexProgram_Lighting30LowPS, lightingLowPsTopEntries[i].index),
				pixelContract,
				GetLighting30PixelReadiness(kObjectVertexProgram_Lighting30LowPS, lightingLowPsTopEntries[i].index));
			_MESSAGE(
				"Lighting30 lowPS top[%u]: program=%u count=%u label=\"%s\" contract=%s readiness=%s",
				i,
				lightingLowPsTopEntries[i].index,
				lightingLowPsTopEntries[i].count,
				GetObjectVertexProgramLabel(kObjectVertexProgram_Lighting30LowPS, lightingLowPsTopEntries[i].index),
				pixelContract,
				GetLighting30PixelReadiness(kObjectVertexProgram_Lighting30LowPS, lightingLowPsTopEntries[i].index));
		}

		LogTopLighting30PassDetails(lightingTopEntries, 3);

		for (UInt32 i = 0; i < kObjectVertexUnknownPassSlots; ++i)
		{
			const ObjectVertexUnknownPass& entry = s_objectVertexUnknownPasses[i];
			if (!entry.pass)
				continue;

			Console_Print(
				"VES objectVS unknown[%u]: pass=%08X shader=%08X vs=%08X ps=%08X curIndex=%u count=%u",
				i,
				reinterpret_cast<UInt32>(entry.pass),
				reinterpret_cast<UInt32>(entry.shader),
				reinterpret_cast<UInt32>(entry.vertexShader),
				reinterpret_cast<UInt32>(entry.pixelShader),
				entry.currentPassIndex,
				entry.count);
			_MESSAGE(
				"Object vertex unknown pass[%u]: pass=%08X shader=%08X vs=%08X ps=%08X curIndex=%u count=%u",
				i,
				reinterpret_cast<UInt32>(entry.pass),
				reinterpret_cast<UInt32>(entry.shader),
				reinterpret_cast<UInt32>(entry.vertexShader),
				reinterpret_cast<UInt32>(entry.pixelShader),
				entry.currentPassIndex,
				entry.count);
		}

		for (UInt32 i = 0; i < kObjectVertexPassSampleSlots; ++i)
		{
			const ObjectVertexPassSample& entry = s_objectVertexPassSamples[i];
			if (!entry.pass)
				continue;

			ObjectVertexProgramFamily vertexProgramFamily = static_cast<ObjectVertexProgramFamily>(entry.vertexProgramFamily);
			ObjectVertexProgramFamily pixelProgramFamily = static_cast<ObjectVertexProgramFamily>(entry.pixelProgramFamily);
			const char* vertexProgramFamilyName = GetObjectVertexProgramFamilyName(vertexProgramFamily);
			const char* pixelProgramFamilyName = GetObjectVertexProgramFamilyName(pixelProgramFamily);
			const char* vertexProgramLabel = GetObjectVertexProgramLabel(vertexProgramFamily, entry.vertexProgramIndex);
			const char* pixelProgramLabel = GetObjectVertexProgramLabel(pixelProgramFamily, entry.pixelProgramIndex);

			Console_Print(
				"VES objectVS sample[%u]: family=%s passIndex=%u curIndex=%u passCount=%u vs=%s:%08X \"%s\" ps=%s:%08X \"%s\" count=%u",
				i,
				GetObjectVertexPassFamilyName(static_cast<ObjectVertexPassFamily>(entry.passFamily)),
				entry.passIndex,
				entry.currentPassIndex,
				entry.passCount,
				vertexProgramFamilyName,
				entry.vertexProgramIndex,
				vertexProgramLabel,
				pixelProgramFamilyName,
				entry.pixelProgramIndex,
				pixelProgramLabel,
				entry.count);
			_MESSAGE(
				"Object vertex pass sample[%u]: family=%s passIndex=%u curIndex=%u passCount=%u pass=%08X shader=%08X vs=%08X vsProgram=%s:%08X \"%s\" ps=%08X psProgram=%s:%08X \"%s\" count=%u",
				i,
				GetObjectVertexPassFamilyName(static_cast<ObjectVertexPassFamily>(entry.passFamily)),
				entry.passIndex,
				entry.currentPassIndex,
				entry.passCount,
				reinterpret_cast<UInt32>(entry.pass),
				reinterpret_cast<UInt32>(entry.shader),
				reinterpret_cast<UInt32>(entry.vertexShader),
				vertexProgramFamilyName,
				entry.vertexProgramIndex,
				vertexProgramLabel,
				reinterpret_cast<UInt32>(entry.pixelShader),
				pixelProgramFamilyName,
				entry.pixelProgramIndex,
				pixelProgramLabel,
				entry.count);

			LogLighting30SampleMapCheck(entry, i);
		}
	}

	void BuildMoonSugarObjectVertexConstants(void* geometry, UInt32 now, float intensity, float* constants)
	{
		float elapsed = static_cast<float>(now - s_effect.startTick) * 0.001f;
		float doseScale = ClampFloat(0.92f + static_cast<float>(s_effect.doseCount) * 0.05f, 0.92f, 1.18f);
		UInt32 seed = reinterpret_cast<UInt32>(geometry);
		float phase = static_cast<float>((seed >> 4) & 0xFFFF) * (1.0f / 65536.0f);

		constants[0] = elapsed;
		constants[1] = intensity;
		constants[2] = 1.15f * doseScale;
		constants[3] = 0.72f;
		constants[4] = 0.74f;
		constants[5] = 0.46f;
		constants[6] = 1.0f;
		constants[7] = phase;
	}

	bool ApplyMoonSugarObjectVertexShaderInternal(
		NiDX9Renderer* renderer,
		void* shader,
		void* geometry,
		void* bufferData,
		bool geometryIsNiObject,
		bool skinnedDraw)
	{
		++s_objectVertexShaderState.calls;

		if (!renderer || !shader || !bufferData || (geometryIsNiObject && !geometry))
		{
			++s_objectVertexShaderState.skippedInactive;
			return false;
		}

		if (renderer->lostDevice || !renderer->device)
		{
			ReleaseRendererResources();
			++s_objectVertexShaderState.skippedInactive;
			return false;
		}

		if (*reinterpret_cast<volatile UInt32*>(kRenderModeAddress) != kRenderModeNormal)
		{
			++s_objectVertexShaderState.skippedInactive;
			return false;
		}

		if (geometryIsNiObject && GetNiObjectRTTI(geometry) == kNiScreenElementsRTTI)
		{
			++s_objectVertexShaderState.skippedScreenElements;
			return false;
		}

		if (!s_effect.active && !s_settings.rendererDebugLog)
		{
			++s_objectVertexShaderState.skippedInactive;
			return false;
		}

		void* pass = nullptr;
		void* originalVertexShader = nullptr;
		void* originalPixelShader = nullptr;
		UInt32 currentPassIndex = 0;
		UInt32 passCount = 0;
		UInt32 knownPassIndex = 0;
		ObjectVertexPassFamily passFamily = kObjectVertexPass_Unknown;
		if (!GetObjectVertexCurrentPassInfo(
			shader,
			&pass,
			&originalVertexShader,
			&originalPixelShader,
			&currentPassIndex,
			&passCount,
			&passFamily,
			&knownPassIndex))
		{
			++s_objectVertexShaderState.skippedPass;
			return false;
		}

		RecordObjectVertexPassCensus(shader, pass, originalVertexShader, originalPixelShader, currentPassIndex, passCount, passFamily, knownPassIndex);
		if (!s_settings.geometryWobbleEnabled || !s_effect.active || !EffectProfileUsesWorldWobble(s_effect.profile))
		{
			++s_objectVertexShaderState.skippedInactive;
			return false;
		}

		ObjectVertexReplacementKind replacementKind =
			GetObjectVertexReplacementKind(passFamily, knownPassIndex, pass, shader, originalVertexShader, originalPixelShader);
		if (replacementKind == kObjectVertexReplacement_None)
		{
			++s_objectVertexShaderState.skippedPass;
			return false;
		}

		UInt32 now = GetTickCount();
		UInt32 remainingMs = 0;
		float intensity = GetMoonSugarRenderIntensity(now, &remainingMs);
		if (remainingMs == 0 || intensity <= 0.0f)
		{
			ExpireMoonSugarEffect(now);
			++s_objectVertexShaderState.skippedInactive;
			return false;
		}

		intensity = ClampFloat(
			intensity * s_settings.geometryWobbleStrength * GetEffectProfileWorldWobbleScale(s_effect.profile),
			0.0f,
			1.0f);
		if (intensity <= 0.0f)
		{
			++s_objectVertexShaderState.skippedInactive;
			return false;
		}

		IDirect3DVertexShader9* replacementShader = nullptr;
		UInt32 vertexConstantBase = 26;
		UInt32 lighting30Variant = 0xFFFFFFFF;
		UInt32 lighting30VertexProgramIndex = 0xFFFFFFFF;
		UInt32 lighting30PixelProgramIndex = 0xFFFFFFFF;
		bool lighting30UsesLowLightPixel = false;
		UInt32 lighting30EnvMapVariant = 0xFFFFFFFF;
		UInt32 lighting30EnvMapVertexProgramIndex = 0xFFFFFFFF;
		UInt32 lighting30EnvMapPixelProgramIndex = 0xFFFFFFFF;
		UInt32 lighting30TexEffectVariant = 0xFFFFFFFF;
		UInt32 lighting30TexEffectVertexProgramIndex = 0xFFFFFFFF;
		UInt32 lighting30TexEffectPixelProgramIndex = 0xFFFFFFFF;
		UInt32 lighting30DecalVariant = 0xFFFFFFFF;
		UInt32 lighting30DecalVertexProgramIndex = 0xFFFFFFFF;
		UInt32 lighting30DecalPixelProgramIndex = 0xFFFFFFFF;
		UInt32 lighting30DepthMapVariant = 0xFFFFFFFF;
		UInt32 lighting30DepthMapVertexProgramIndex = 0xFFFFFFFF;
		UInt32 lighting30DepthMapPixelProgramIndex = 0xFFFFFFFF;
		UInt32 lighting30SupportVariant = 0xFFFFFFFF;
		UInt32 lighting30SupportVertexProgramIndex = 0xFFFFFFFF;
		UInt32 lighting30SupportPixelProgramIndex = 0xFFFFFFFF;
		UInt32 legacyObjectVertexVariant = 0xFFFFFFFF;
		if (replacementKind == kObjectVertexReplacement_Lighting30Sm3Vs30)
		{
			if (!TryGetLighting30Sm3Variant(
				passFamily,
				knownPassIndex,
				originalVertexShader,
				originalPixelShader,
				&lighting30Variant,
				&lighting30VertexProgramIndex,
				&lighting30PixelProgramIndex,
				&lighting30UsesLowLightPixel))
			{
				++s_objectVertexShaderState.skippedPass;
				return false;
			}

			if (skinnedDraw && lighting30Variant < kLighting30ObjectVertexShader_Sm3001Skin)
			{
				++s_objectVertexShaderState.skippedPass;
				return false;
			}

			if (!EnsureLighting30ObjectVertexShader(renderer->device, lighting30Variant))
				return false;
			replacementShader = s_objectVertexShaderState.lighting30VertexShaders[lighting30Variant];
			if (lighting30Variant >= kLighting30ObjectVertexShader_Sm3001Skin ||
				lighting30Variant == kLighting30ObjectVertexShader_Sm3004Proj ||
				lighting30Variant == kLighting30ObjectVertexShader_Sm3006VcProj)
			{
				vertexConstantBase = 27;
			}
		}
		else if (replacementKind == kObjectVertexReplacement_Lighting30EnvMapVs30)
		{
			if (!TryGetLighting30EnvMapVariant(
				passFamily,
				knownPassIndex,
				originalVertexShader,
				originalPixelShader,
				&lighting30EnvMapVariant,
				&lighting30EnvMapVertexProgramIndex,
				&lighting30EnvMapPixelProgramIndex))
			{
				++s_objectVertexShaderState.skippedPass;
				return false;
			}

			if (skinnedDraw &&
				lighting30EnvMapVariant != kLighting30EnvMapVertexShader_Sm3010Skin &&
				lighting30EnvMapVariant != kLighting30EnvMapVertexShader_Sm3011SkinVc)
			{
				++s_objectVertexShaderState.skippedPass;
				return false;
			}

			if (!EnsureLighting30EnvMapVertexShader(renderer->device, lighting30EnvMapVariant))
				return false;
			replacementShader = s_objectVertexShaderState.lighting30EnvMapVertexShaders[lighting30EnvMapVariant];
			if (lighting30EnvMapVariant == kLighting30EnvMapVertexShader_Sm3010Skin ||
				lighting30EnvMapVariant == kLighting30EnvMapVertexShader_Sm3011SkinVc)
			{
				vertexConstantBase = 24;
			}
		}
		else if (replacementKind == kObjectVertexReplacement_Lighting30TexEffectVs30)
		{
			if (!TryGetLighting30TexEffectVariant(
				passFamily,
				knownPassIndex,
				originalVertexShader,
				originalPixelShader,
				&lighting30TexEffectVariant,
				&lighting30TexEffectVertexProgramIndex,
				&lighting30TexEffectPixelProgramIndex))
			{
				++s_objectVertexShaderState.skippedPass;
				return false;
			}

			if (skinnedDraw && lighting30TexEffectVariant != kLighting30TexEffectVertexShader_Sm3029Skin)
			{
				++s_objectVertexShaderState.skippedPass;
				return false;
			}

			if (!EnsureLighting30TexEffectVertexShader(renderer->device, lighting30TexEffectVariant))
				return false;
			replacementShader = s_objectVertexShaderState.lighting30TexEffectVertexShaders[lighting30TexEffectVariant];
			if (lighting30TexEffectVariant == kLighting30TexEffectVertexShader_Sm3029Skin)
				vertexConstantBase = 68;
		}
		else if (replacementKind == kObjectVertexReplacement_Lighting30DecalVs30)
		{
			if (skinnedDraw)
			{
				++s_objectVertexShaderState.skippedPass;
				return false;
			}

			if (!TryGetLighting30DecalVariant(
				passFamily,
				knownPassIndex,
				originalVertexShader,
				originalPixelShader,
				&lighting30DecalVariant,
				&lighting30DecalVertexProgramIndex,
				&lighting30DecalPixelProgramIndex))
			{
				++s_objectVertexShaderState.skippedPass;
				return false;
			}

			if (!EnsureLighting30DecalVertexShader(renderer->device, lighting30DecalVariant))
				return false;
			replacementShader = s_objectVertexShaderState.lighting30DecalVertexShaders[lighting30DecalVariant];
		}
		else if (replacementKind == kObjectVertexReplacement_Lighting30DepthMapVs30)
		{
			if (!TryGetLighting30DepthMapVariant(
				passFamily,
				knownPassIndex,
				originalVertexShader,
				originalPixelShader,
				&lighting30DepthMapVariant,
				&lighting30DepthMapVertexProgramIndex,
				&lighting30DepthMapPixelProgramIndex))
			{
				++s_objectVertexShaderState.skippedPass;
				return false;
			}

			bool depthVariantIsSkinned = lighting30DepthMapVariant == kLighting30DepthMapVertexShader_Sm3019Skin;
			if (depthVariantIsSkinned != skinnedDraw)
			{
				++s_objectVertexShaderState.skippedPass;
				return false;
			}

			if (!EnsureLighting30DepthMapVertexShader(renderer->device, lighting30DepthMapVariant))
				return false;
			replacementShader = s_objectVertexShaderState.lighting30DepthMapVertexShaders[lighting30DepthMapVariant];
			if (lighting30DepthMapVariant == kLighting30DepthMapVertexShader_Sm3019Skin)
				vertexConstantBase = 27;
		}
		else if (replacementKind == kObjectVertexReplacement_Lighting30SupportVs30)
		{
			if (!TryGetLighting30SupportVariant(
				passFamily,
				knownPassIndex,
				originalVertexShader,
				originalPixelShader,
				&lighting30SupportVariant,
				&lighting30SupportVertexProgramIndex,
				&lighting30SupportPixelProgramIndex))
			{
				++s_objectVertexShaderState.skippedPass;
				return false;
			}

			if (IsLighting30SupportVariantSkinned(lighting30SupportVariant) != skinnedDraw)
			{
				++s_objectVertexShaderState.skippedPass;
				return false;
			}

			if (!EnsureLighting30SupportVertexShader(renderer->device, lighting30SupportVariant))
				return false;
			replacementShader = s_objectVertexShaderState.lighting30SupportVertexShaders[lighting30SupportVariant];
			if (IsLighting30SupportVariantSkinned(lighting30SupportVariant))
				vertexConstantBase = 27;
		}
		else
		{
			if (!TryGetLegacyObjectVertexShaderVariant(
				passFamily,
				knownPassIndex,
				pass,
				shader,
				originalVertexShader,
				originalPixelShader,
				&legacyObjectVertexVariant))
			{
				++s_objectVertexShaderState.skippedPass;
				return false;
			}

			if (skinnedDraw)
			{
				++s_objectVertexShaderState.skippedPass;
				return false;
			}

			if (!EnsureObjectVertexShader(renderer->device))
				return false;
			replacementShader = s_objectVertexShaderState.vertexShader;
		}

		if (!replacementShader)
		{
			++s_objectVertexShaderState.shaderFailures;
			return false;
		}

		float constants[8];
		BuildMoonSugarObjectVertexConstants(geometry, now, intensity, constants);

		HRESULT constantResult = renderer->device->SetVertexShaderConstantF(vertexConstantBase, constants, 2);
		HRESULT shaderResult = SUCCEEDED(constantResult) ? renderer->device->SetVertexShader(replacementShader) : constantResult;
		if (FAILED(shaderResult) || FAILED(constantResult))
		{
			++s_objectVertexShaderState.shaderFailures;
			if (s_settings.rendererDebugLog)
				_MESSAGE(
					"ERROR::ApplyMoonSugarObjectVertexShader: D3D update failed shaderHr=%08X constantHr=%08X failures=%u",
					shaderResult,
					constantResult,
					s_objectVertexShaderState.shaderFailures);
			return false;
		}

		++s_objectVertexShaderState.applied;
		if (replacementKind == kObjectVertexReplacement_ParallaxSkinVs20 &&
			legacyObjectVertexVariant < kLegacyObjectVertexShaderVariantCount)
		{
			++s_objectVertexShaderState.legacyApplied[legacyObjectVertexVariant];
			if (s_settings.rendererDebugLog &&
				!s_objectVertexShaderState.legacyFirstAppliedLogged[legacyObjectVertexVariant])
			{
				s_objectVertexShaderState.legacyFirstAppliedLogged[legacyObjectVertexVariant] = true;
				_MESSAGE(
					"VES object vertex shader Legacy first %s draw pass=%u currentPassIndex=%u passCount=%u originalVS=%08X originalPS=%08X cBase=%u appliedMask=%02X",
					GetLegacyObjectVertexShaderVariantName(legacyObjectVertexVariant),
					knownPassIndex,
					currentPassIndex,
					passCount,
					reinterpret_cast<UInt32>(originalVertexShader),
					reinterpret_cast<UInt32>(originalPixelShader),
					vertexConstantBase,
					GetLegacyObjectVertexAppliedMask());
			}
		}
		if (replacementKind == kObjectVertexReplacement_Lighting30Sm3Vs30 &&
			lighting30Variant < kLighting30ObjectVertexShaderVariantCount)
		{
			++s_objectVertexShaderState.lighting30Applied[lighting30Variant];
			if (s_settings.rendererDebugLog &&
				!s_objectVertexShaderState.lighting30FirstAppliedLogged[lighting30Variant])
			{
				s_objectVertexShaderState.lighting30FirstAppliedLogged[lighting30Variant] = true;
				_MESSAGE(
					"VES object vertex shader Lighting30 first %s draw pass=%u currentPassIndex=%u passCount=%u originalVS=%08X originalPS=%08X sm3VS=%u sm3PS=%u sm3LowPS=%u cBase=%u appliedMask=%02X",
					GetLighting30ObjectVertexShaderVariantName(lighting30Variant),
					knownPassIndex,
					currentPassIndex,
					passCount,
					reinterpret_cast<UInt32>(originalVertexShader),
					reinterpret_cast<UInt32>(originalPixelShader),
					lighting30VertexProgramIndex,
					lighting30PixelProgramIndex,
					lighting30UsesLowLightPixel ? 1 : 0,
					vertexConstantBase,
					GetLighting30ObjectVertexAppliedMask());
			}
		}
		if (replacementKind == kObjectVertexReplacement_Lighting30EnvMapVs30 &&
			lighting30EnvMapVariant < kLighting30EnvMapVertexShaderVariantCount)
		{
			++s_objectVertexShaderState.lighting30EnvMapApplied[lighting30EnvMapVariant];
			if (s_settings.rendererDebugLog &&
				!s_objectVertexShaderState.lighting30EnvMapFirstAppliedLogged[lighting30EnvMapVariant])
			{
				s_objectVertexShaderState.lighting30EnvMapFirstAppliedLogged[lighting30EnvMapVariant] = true;
				_MESSAGE(
					"VES object vertex shader EnvMap first %s draw pass=%u currentPassIndex=%u passCount=%u originalVS=%08X originalPS=%08X sm3VS=%u sm3PS=%u cBase=%u appliedMask=%02X",
					GetLighting30EnvMapVertexShaderVariantName(lighting30EnvMapVariant),
					knownPassIndex,
					currentPassIndex,
					passCount,
					reinterpret_cast<UInt32>(originalVertexShader),
					reinterpret_cast<UInt32>(originalPixelShader),
					lighting30EnvMapVertexProgramIndex,
					lighting30EnvMapPixelProgramIndex,
					vertexConstantBase,
					GetLighting30EnvMapVertexAppliedMask());
			}
		}
		if (replacementKind == kObjectVertexReplacement_Lighting30TexEffectVs30 &&
			lighting30TexEffectVariant < kLighting30TexEffectVertexShaderVariantCount)
		{
			++s_objectVertexShaderState.lighting30TexEffectApplied[lighting30TexEffectVariant];
			if (s_settings.rendererDebugLog &&
				!s_objectVertexShaderState.lighting30TexEffectFirstAppliedLogged[lighting30TexEffectVariant])
			{
				s_objectVertexShaderState.lighting30TexEffectFirstAppliedLogged[lighting30TexEffectVariant] = true;
				_MESSAGE(
					"VES object vertex shader TexEffect first %s draw pass=%u currentPassIndex=%u passCount=%u originalVS=%08X originalPS=%08X sm3VS=%u sm3PS=%u cBase=%u appliedMask=%02X",
					GetLighting30TexEffectVertexShaderVariantName(lighting30TexEffectVariant),
					knownPassIndex,
					currentPassIndex,
					passCount,
					reinterpret_cast<UInt32>(originalVertexShader),
					reinterpret_cast<UInt32>(originalPixelShader),
					lighting30TexEffectVertexProgramIndex,
					lighting30TexEffectPixelProgramIndex,
					vertexConstantBase,
					GetLighting30TexEffectVertexAppliedMask());
			}
		}
		if (replacementKind == kObjectVertexReplacement_Lighting30DecalVs30 &&
			lighting30DecalVariant < kLighting30DecalVertexShaderVariantCount)
		{
			++s_objectVertexShaderState.lighting30DecalApplied[lighting30DecalVariant];
			if (s_settings.rendererDebugLog &&
				!s_objectVertexShaderState.lighting30DecalFirstAppliedLogged[lighting30DecalVariant])
			{
				s_objectVertexShaderState.lighting30DecalFirstAppliedLogged[lighting30DecalVariant] = true;
				_MESSAGE(
					"VES object vertex shader Decal first %s draw pass=%u currentPassIndex=%u passCount=%u originalVS=%08X originalPS=%08X sm3VS=%u sm3PS=%u cBase=%u appliedMask=%02X",
					GetLighting30DecalVertexShaderVariantName(lighting30DecalVariant),
					knownPassIndex,
					currentPassIndex,
					passCount,
					reinterpret_cast<UInt32>(originalVertexShader),
					reinterpret_cast<UInt32>(originalPixelShader),
					lighting30DecalVertexProgramIndex,
					lighting30DecalPixelProgramIndex,
					vertexConstantBase,
					GetLighting30DecalVertexAppliedMask());
			}
		}
		if (replacementKind == kObjectVertexReplacement_Lighting30DepthMapVs30 &&
			lighting30DepthMapVariant < kLighting30DepthMapVertexShaderVariantCount)
		{
			++s_objectVertexShaderState.lighting30DepthMapApplied[lighting30DepthMapVariant];
			if (s_settings.rendererDebugLog &&
				!s_objectVertexShaderState.lighting30DepthMapFirstAppliedLogged[lighting30DepthMapVariant])
			{
				s_objectVertexShaderState.lighting30DepthMapFirstAppliedLogged[lighting30DepthMapVariant] = true;
				_MESSAGE(
					"VES object vertex shader DepthMap first %s draw pass=%u currentPassIndex=%u passCount=%u originalVS=%08X originalPS=%08X sm3VS=%u sm3PS=%u cBase=%u appliedMask=%02X",
					GetLighting30DepthMapVertexShaderVariantName(lighting30DepthMapVariant),
					knownPassIndex,
					currentPassIndex,
					passCount,
					reinterpret_cast<UInt32>(originalVertexShader),
					reinterpret_cast<UInt32>(originalPixelShader),
					lighting30DepthMapVertexProgramIndex,
					lighting30DepthMapPixelProgramIndex,
					vertexConstantBase,
					GetLighting30DepthMapVertexAppliedMask());
			}
		}
		if (replacementKind == kObjectVertexReplacement_Lighting30SupportVs30 &&
			lighting30SupportVariant < kLighting30SupportVertexShaderVariantCount)
		{
			++s_objectVertexShaderState.lighting30SupportApplied[lighting30SupportVariant];
			if (s_settings.rendererDebugLog &&
				!s_objectVertexShaderState.lighting30SupportFirstAppliedLogged[lighting30SupportVariant])
			{
				s_objectVertexShaderState.lighting30SupportFirstAppliedLogged[lighting30SupportVariant] = true;
				_MESSAGE(
					"VES object vertex shader Support first %s draw pass=%u currentPassIndex=%u passCount=%u originalVS=%08X originalPS=%08X sm3VS=%u sm3PS=%u cBase=%u appliedMask=%08X",
					GetLighting30SupportVertexShaderVariantName(lighting30SupportVariant),
					knownPassIndex,
					currentPassIndex,
					passCount,
					reinterpret_cast<UInt32>(originalVertexShader),
					reinterpret_cast<UInt32>(originalPixelShader),
					lighting30SupportVertexProgramIndex,
					lighting30SupportPixelProgramIndex,
					vertexConstantBase,
					GetLighting30SupportVertexAppliedMask());
			}
		}

		if (s_settings.rendererDebugLog && !s_objectVertexShaderState.firstAppliedLogged)
		{
			s_objectVertexShaderState.firstAppliedLogged = true;
			_MESSAGE(
				"VES object vertex shader first draw skinned=%u geometryOrSeed=%08X shader=%08X pass=%08X originalVS=%08X buffData=%08X intensity=%.3f",
				skinnedDraw ? 1 : 0,
				reinterpret_cast<UInt32>(geometry),
				reinterpret_cast<UInt32>(shader),
				reinterpret_cast<UInt32>(pass),
				reinterpret_cast<UInt32>(originalVertexShader),
				reinterpret_cast<UInt32>(bufferData),
				intensity);
			_MESSAGE(
				"VES object vertex shader pass family=%s index=%u currentPassIndex=%u passCount=%u replacement=%s sm3Variant=%s sm3VS=%u sm3PS=%u sm3LowPS=%u cBase=%u",
				GetObjectVertexPassFamilyName(passFamily),
				knownPassIndex,
				currentPassIndex,
				passCount,
				GetObjectVertexReplacementName(replacementKind),
				lighting30Variant < kLighting30ObjectVertexShaderVariantCount ? GetLighting30ObjectVertexShaderVariantName(lighting30Variant) : "n/a",
				lighting30VertexProgramIndex,
				lighting30PixelProgramIndex,
				lighting30UsesLowLightPixel ? 1 : 0,
				vertexConstantBase);
			if (replacementKind == kObjectVertexReplacement_ParallaxSkinVs20)
				_MESSAGE(
					"VES object vertex shader Legacy variant=%s cBase=%u appliedMask=%02X",
					legacyObjectVertexVariant < kLegacyObjectVertexShaderVariantCount ? GetLegacyObjectVertexShaderVariantName(legacyObjectVertexVariant) : "n/a",
					vertexConstantBase,
					GetLegacyObjectVertexAppliedMask());
			if (replacementKind == kObjectVertexReplacement_Lighting30EnvMapVs30)
				_MESSAGE(
					"VES object vertex shader EnvMap variant=%s sm3VS=%u sm3PS=%u cBase=%u",
					lighting30EnvMapVariant < kLighting30EnvMapVertexShaderVariantCount ? GetLighting30EnvMapVertexShaderVariantName(lighting30EnvMapVariant) : "n/a",
					lighting30EnvMapVertexProgramIndex,
					lighting30EnvMapPixelProgramIndex,
					vertexConstantBase);
			if (replacementKind == kObjectVertexReplacement_Lighting30TexEffectVs30)
				_MESSAGE(
					"VES object vertex shader TexEffect variant=%s sm3VS=%u sm3PS=%u cBase=%u",
					lighting30TexEffectVariant < kLighting30TexEffectVertexShaderVariantCount ? GetLighting30TexEffectVertexShaderVariantName(lighting30TexEffectVariant) : "n/a",
					lighting30TexEffectVertexProgramIndex,
					lighting30TexEffectPixelProgramIndex,
					vertexConstantBase);
			if (replacementKind == kObjectVertexReplacement_Lighting30DecalVs30)
				_MESSAGE(
					"VES object vertex shader Decal variant=%s sm3VS=%u sm3PS=%u cBase=%u",
					lighting30DecalVariant < kLighting30DecalVertexShaderVariantCount ? GetLighting30DecalVertexShaderVariantName(lighting30DecalVariant) : "n/a",
					lighting30DecalVertexProgramIndex,
					lighting30DecalPixelProgramIndex,
					vertexConstantBase);
			if (replacementKind == kObjectVertexReplacement_Lighting30DepthMapVs30)
				_MESSAGE(
					"VES object vertex shader DepthMap variant=%s sm3VS=%u sm3PS=%u cBase=%u",
					lighting30DepthMapVariant < kLighting30DepthMapVertexShaderVariantCount ? GetLighting30DepthMapVertexShaderVariantName(lighting30DepthMapVariant) : "n/a",
					lighting30DepthMapVertexProgramIndex,
					lighting30DepthMapPixelProgramIndex,
					vertexConstantBase);
			if (replacementKind == kObjectVertexReplacement_Lighting30SupportVs30)
				_MESSAGE(
					"VES object vertex shader Support variant=%s sm3VS=%u sm3PS=%u cBase=%u",
					lighting30SupportVariant < kLighting30SupportVertexShaderVariantCount ? GetLighting30SupportVertexShaderVariantName(lighting30SupportVariant) : "n/a",
					lighting30SupportVertexProgramIndex,
					lighting30SupportPixelProgramIndex,
					vertexConstantBase);
		}

		return true;
	}

	void __cdecl ApplyMoonSugarObjectVertexShader(NiDX9Renderer* renderer, void* shader, void* geometry, void* bufferData)
	{
		ApplyMoonSugarObjectVertexShaderInternal(renderer, shader, geometry, bufferData, true, false);
	}

	void __cdecl ApplyMoonSugarSkinnedObjectVertexShader(NiDX9Renderer* renderer, void* shader, void* geometry, void* skinPartition, void* bufferData)
	{
		++s_objectVertexShaderState.skinnedCalls;
		void* seed = geometry ? geometry : (skinPartition ? skinPartition : bufferData);
		if (ApplyMoonSugarObjectVertexShaderInternal(renderer, shader, seed, bufferData, geometry != nullptr, true))
			++s_objectVertexShaderState.skinnedApplied;
	}

	void MaybeStartMoonSugarEffect(MagicItem* item)
	{
		if (GetEngineMagicType(item) != kEngineMagicTypeIngredient)
			return;

		TESForm* form = GetOwningMagicItemObject(item);
		if (!IsConfiguredMoonSugar(form))
		{
			if (s_settings.debugLog && form && form->typeID == kFormType_Ingredient)
				_MESSAGE("Ingredient consumed but not matched: form=%08X name=\"%s\"", form->refID, GetFormName(form));
			return;
		}

		SelectMoonSugarShader(true);
		StartMoonSugarEffect(form, true, "consume");
	}

	void __fastcall ProcessEffectsFromItemHook(void* magicTarget, UInt32, MagicItem* item)
	{
		s_processEffectsFromItem(magicTarget, item);
		MaybeStartMoonSugarEffect(item);
	}

	bool ValidatePatchSite()
	{
		const UInt8* actual = reinterpret_cast<const UInt8*>(kPlayerConsumeProcessEffectsCall);
		if (memcmp(actual, kExpectedPlayerConsumeCallBytes, sizeof(kExpectedPlayerConsumeCallBytes)) == 0)
			return true;

		_MESSAGE(
			"ERROR::ValidatePatchSite: unexpected bytes at %08X: %02X %02X %02X %02X %02X",
			kPlayerConsumeProcessEffectsCall,
			actual[0],
			actual[1],
			actual[2],
			actual[3],
			actual[4]);
		return false;
	}

	bool ValidateRendererPatchSite()
	{
		const UInt8* actual = reinterpret_cast<const UInt8*>(kNiRendererRenderProcessImageSpaceShaderCall);
		if (memcmp(actual, kExpectedProcessImageSpaceShaderCallBytes, sizeof(kExpectedProcessImageSpaceShaderCallBytes)) == 0)
			return true;

		_MESSAGE(
			"ERROR::ValidateRendererPatchSite: unexpected bytes at %08X: %02X %02X %02X %02X %02X",
			kNiRendererRenderProcessImageSpaceShaderCall,
			actual[0],
			actual[1],
			actual[2],
			actual[3],
			actual[4]);
		return false;
	}

	bool ValidateGeometryPatchSite()
	{
		const UInt8* actual = reinterpret_cast<const UInt8*>(kRenderTriGeometriesNonSkinnedCall);
		if (memcmp(actual, kExpectedRenderTriGeometrySetupCallBytes, sizeof(kExpectedRenderTriGeometrySetupCallBytes)) == 0)
			return true;

		_MESSAGE(
			"ERROR::ValidateGeometryPatchSite: unexpected bytes at %08X: %02X %02X %02X %02X %02X",
			kRenderTriGeometriesNonSkinnedCall,
			actual[0],
			actual[1],
			actual[2],
			actual[3],
			actual[4]);
		return false;
	}

	bool ValidateObjectVertexPatchSite()
	{
		const UInt8* actual = reinterpret_cast<const UInt8*>(kRenderTriGeometryPostSetupPatch);
		if (memcmp(actual, kExpectedRenderTriGeometryPostSetupBytes, sizeof(kExpectedRenderTriGeometryPostSetupBytes)) == 0)
			return true;

		_MESSAGE(
			"ERROR::ValidateObjectVertexPatchSite: unexpected bytes at %08X: %02X %02X %02X %02X %02X",
			kRenderTriGeometryPostSetupPatch,
			actual[0],
			actual[1],
			actual[2],
			actual[3],
			actual[4]);
		return false;
	}

	bool ValidateObjectVertexSkinnedPatchSite()
	{
		const UInt8* actual = reinterpret_cast<const UInt8*>(kRenderTriGeometrySkinnedPostSetupPatch);
		if (memcmp(actual, kExpectedRenderTriGeometrySkinnedPostSetupBytes, sizeof(kExpectedRenderTriGeometrySkinnedPostSetupBytes)) == 0)
			return true;

		_MESSAGE(
			"ERROR::ValidateObjectVertexSkinnedPatchSite: unexpected bytes at %08X: %02X %02X %02X %02X %02X",
			kRenderTriGeometrySkinnedPostSetupPatch,
			actual[0],
			actual[1],
			actual[2],
			actual[3],
			actual[4]);
		return false;
	}

	bool ValidateCameraPatchSite()
	{
		const UInt8* actualA = reinterpret_cast<const UInt8*>(kNiRendererRenderWorldCallA);
		const UInt8* actualB = reinterpret_cast<const UInt8*>(kNiRendererRenderWorldCallB);
		bool okA = memcmp(actualA, kExpectedRenderWorldCallABytes, sizeof(kExpectedRenderWorldCallABytes)) == 0;
		bool okB = memcmp(actualB, kExpectedRenderWorldCallBBytes, sizeof(kExpectedRenderWorldCallBBytes)) == 0;

		if (okA && okB)
			return true;

		if (!okA)
		{
			_MESSAGE(
				"ERROR::ValidateCameraPatchSite: unexpected bytes at %08X: %02X %02X %02X %02X %02X %02X %02X %02X",
				kNiRendererRenderWorldCallA,
				actualA[0],
				actualA[1],
				actualA[2],
				actualA[3],
				actualA[4],
				actualA[5],
				actualA[6],
				actualA[7]);
		}

		if (!okB)
		{
			_MESSAGE(
				"ERROR::ValidateCameraPatchSite: unexpected bytes at %08X: %02X %02X %02X %02X %02X %02X %02X %02X",
				kNiRendererRenderWorldCallB,
				actualB[0],
				actualB[1],
				actualB[2],
				actualB[3],
				actualB[4],
				actualB[5],
				actualB[6],
				actualB[7]);
		}

		return false;
	}

	bool InstallHooks()
	{
		if (s_hookInstalled)
			return true;

		if (!ValidatePatchSite())
		{
			_FATALERROR("ERROR::InstallHooks: Oblivion ingredient consume hook site did not match decoded 1.2.0.416 bytes");
			return false;
		}

		if (!ValidateRendererPatchSite())
		{
			_FATALERROR("ERROR::InstallHooks: Oblivion image-space shader hook site did not match decoded 1.2.0.416 bytes");
			return false;
		}

		if (!ValidateGeometryPatchSite())
		{
			_FATALERROR("ERROR::InstallHooks: Oblivion geometry setup hook site did not match decoded 1.2.0.416 bytes");
			return false;
		}

		if (!ValidateObjectVertexPatchSite())
		{
			_FATALERROR("ERROR::InstallHooks: Oblivion object vertex shader hook site did not match decoded 1.2.0.416 bytes");
			return false;
		}

		if (!ValidateObjectVertexSkinnedPatchSite())
		{
			_FATALERROR("ERROR::InstallHooks: Oblivion skinned object vertex shader hook site did not match decoded 1.2.0.416 bytes");
			return false;
		}

		if (!ValidateCameraPatchSite())
		{
			_FATALERROR("ERROR::InstallHooks: Oblivion camera sway hook sites did not match decoded 1.2.0.416 bytes");
			return false;
		}

		WriteRelCall(kPlayerConsumeProcessEffectsCall, reinterpret_cast<UInt32>(&ProcessEffectsFromItemHook));
		s_hookInstalled = true;
		_MESSAGE("Installed player consume hook at %08X -> %08X", kPlayerConsumeProcessEffectsCall, reinterpret_cast<UInt32>(&ProcessEffectsFromItemHook));

		WriteRelCall(kNiRendererRenderProcessImageSpaceShaderCall, reinterpret_cast<UInt32>(&ProcessImageSpaceShaderHook));
		s_rendererHookInstalled = true;
		_MESSAGE("Installed renderer image-space hook at %08X -> %08X", kNiRendererRenderProcessImageSpaceShaderCall, reinterpret_cast<UInt32>(&ProcessImageSpaceShaderHook));

		WriteRelCall(kRenderTriGeometriesNonSkinnedCall, reinterpret_cast<UInt32>(&RenderTriGeometrySetupHook));
		s_geometryHookInstalled = true;
		_MESSAGE("Installed renderer geometry wobble hook at %08X -> %08X", kRenderTriGeometriesNonSkinnedCall, reinterpret_cast<UInt32>(&RenderTriGeometrySetupHook));

		WriteRelJump(kRenderTriGeometryPostSetupPatch, reinterpret_cast<UInt32>(&RenderTriGeometryPostSetupHook));
		s_objectVertexHookInstalled = true;
		_MESSAGE("Installed object vertex shader hook at %08X -> %08X", kRenderTriGeometryPostSetupPatch, reinterpret_cast<UInt32>(&RenderTriGeometryPostSetupHook));

		WriteRelJump(kRenderTriGeometrySkinnedPostSetupPatch, reinterpret_cast<UInt32>(&RenderTriGeometrySkinnedPostSetupHook));
		s_objectVertexSkinnedHookInstalled = true;
		_MESSAGE("Installed skinned object vertex shader hook at %08X -> %08X", kRenderTriGeometrySkinnedPostSetupPatch, reinterpret_cast<UInt32>(&RenderTriGeometrySkinnedPostSetupHook));

		WriteRelCall(kNiRendererRenderWorldCallA, reinterpret_cast<UInt32>(&RenderWorldCameraSwayHook));
		WriteRelCall(kNiRendererRenderWorldCallB, reinterpret_cast<UInt32>(&RenderWorldCameraSwayHook));
		s_cameraHookInstalled = true;
		_MESSAGE(
			"Installed renderer camera sway hooks at %08X/%08X -> %08X",
			kNiRendererRenderWorldCallA,
			kNiRendererRenderWorldCallB,
			reinterpret_cast<UInt32>(&RenderWorldCameraSwayHook));
		return true;
	}

	bool RegisterCommandChecked(const OBSEInterface* obse, CommandInfo* commandInfo)
	{
		if (obse->RegisterCommand(commandInfo))
			return true;

		_MESSAGE("ERROR::RegisterCommandChecked: failed to register %s", commandInfo->longName);
		return false;
	}

	void RegisterCommands(const OBSEInterface* obse)
	{
		obse->SetOpcodeBase(kOpcodeBase);

		bool ok = true;
		ok = RegisterCommandChecked(obse, &kCommandInfo_VESDistortion) && ok;
		ok = RegisterCommandChecked(obse, &kCommandInfo_VESStop) && ok;
		ok = RegisterCommandChecked(obse, &kCommandInfo_VESGetRemaining) && ok;
		ok = RegisterCommandChecked(obse, &kCommandInfo_VESGetIntensity) && ok;
		ok = RegisterCommandChecked(obse, &kCommandInfo_VESReloadSettings) && ok;
		ok = RegisterCommandChecked(obse, &kCommandInfo_VESDumpShaderRenderer) && ok;
		ok = RegisterCommandChecked(obse, &kCommandInfo_VESMoonSugar25) && ok;
		ok = RegisterCommandChecked(obse, &kCommandInfo_VESMoonSugar50) && ok;
		ok = RegisterCommandChecked(obse, &kCommandInfo_VESMoonSugar75) && ok;
		ok = RegisterCommandChecked(obse, &kCommandInfo_VESHeadWound25) && ok;
		ok = RegisterCommandChecked(obse, &kCommandInfo_VESHeadWound50) && ok;
		ok = RegisterCommandChecked(obse, &kCommandInfo_VESHeadWound75) && ok;
		ok = RegisterCommandChecked(obse, &kCommandInfo_VESBlind25) && ok;
		ok = RegisterCommandChecked(obse, &kCommandInfo_VESBlind50) && ok;
		ok = RegisterCommandChecked(obse, &kCommandInfo_VESBlind75) && ok;
		ok = RegisterCommandChecked(obse, &kCommandInfo_VESBlind100) && ok;
		ok = RegisterCommandChecked(obse, &kCommandInfo_VESDim50) && ok;
		ok = RegisterCommandChecked(obse, &kCommandInfo_VESDim100) && ok;
		ok = RegisterCommandChecked(obse, &kCommandInfo_VESDimWhiteInverted) && ok;
		ok = RegisterCommandChecked(obse, &kCommandInfo_VESDimPurple) && ok;
		ok = RegisterCommandChecked(obse, &kCommandInfo_VESDimDarkRed) && ok;
		ok = RegisterCommandChecked(obse, &kCommandInfo_VESOnFire25) && ok;
		ok = RegisterCommandChecked(obse, &kCommandInfo_VESOnFire50) && ok;
		ok = RegisterCommandChecked(obse, &kCommandInfo_VESOnFire75) && ok;
		ok = RegisterCommandChecked(obse, &kCommandInfo_VESOnFire100) && ok;
		ok = RegisterCommandChecked(obse, &kCommandInfo_VESHeatShimmer50) && ok;
		ok = RegisterCommandChecked(obse, &kCommandInfo_VESHeatShimmer100) && ok;
		ok = RegisterCommandChecked(obse, &kCommandInfo_VESDepthMaskDebug) && ok;
		ok = RegisterCommandChecked(obse, &kCommandInfo_VESRain50) && ok;
		ok = RegisterCommandChecked(obse, &kCommandInfo_VESRain75) && ok;
		ok = RegisterCommandChecked(obse, &kCommandInfo_VESRain100) && ok;
		ok = RegisterCommandChecked(obse, &kCommandInfo_VESFrost50) && ok;
		ok = RegisterCommandChecked(obse, &kCommandInfo_VESFrost75) && ok;
		ok = RegisterCommandChecked(obse, &kCommandInfo_VESFrost100) && ok;

		if (ok)
			_MESSAGE("Plugin_Load: Commands registered");
	}
}

extern "C"
{
	__declspec(dllexport) bool VES_IsActive();
	__declspec(dllexport) float VES_GetIntensity();
	__declspec(dllexport) UInt32 VES_GetRemainingMilliseconds();
}

void __stdcall RenderVESDistortionFrame(NiDX9Renderer* renderer)
{
	UInt32 now = GetTickCount();
	UInt32 remainingMs = 0;
	float effectiveIntensity = 0.0f;

	s_rendererState.lastRenderContext = s_allowOffscreenDistortion ? kRendererContext_ImageSpace : kRendererContext_StrictTarget;

	if (!ShouldRenderDistortion(renderer, now, &remainingMs, &effectiveIntensity))
		return;

	IDirect3DDevice9* device = renderer->device;
	if (!EnsurePixelShader(device))
		return;

	IDirect3DSurface9* renderTarget = nullptr;
	IDirect3DTexture9* sceneTexture = nullptr;
	IDirect3DTexture9* depthTexture = nullptr;
	IDirect3DSurface9* activeDepthSurface = nullptr;
	IDirect3DStateBlock9* stateBlock = nullptr;
	D3DSURFACE_DESC desc = {};

	HRESULT result = device->GetRenderTarget(0, &renderTarget);
	if (FAILED(result) || !renderTarget)
	{
		++s_rendererState.renderFailures;
		if (s_settings.rendererDebugLog)
			_MESSAGE("ERROR::RenderVESDistortionFrame: GetRenderTarget failed hr=%08X failures=%u", result, s_rendererState.renderFailures);
		return;
	}

	result = renderTarget->GetDesc(&desc);
	if (FAILED(result) || desc.Width == 0 || desc.Height == 0)
	{
		++s_rendererState.renderFailures;
		if (s_settings.rendererDebugLog)
			_MESSAGE("ERROR::RenderVESDistortionFrame: GetDesc failed hr=%08X failures=%u", result, s_rendererState.renderFailures);
		ReleaseCom(renderTarget);
		return;
	}

	result = device->CreateStateBlock(D3DSBT_ALL, &stateBlock);
	if (FAILED(result) || !stateBlock)
	{
		++s_rendererState.renderFailures;
		if (s_settings.rendererDebugLog)
			_MESSAGE("ERROR::RenderVESDistortionFrame: CreateStateBlock failed hr=%08X failures=%u", result, s_rendererState.renderFailures);
		ReleaseCom(renderTarget);
		return;
	}

	result = stateBlock->Capture();
	if (FAILED(result))
	{
		++s_rendererState.renderFailures;
		if (s_settings.rendererDebugLog)
			_MESSAGE("ERROR::RenderVESDistortionFrame: state Capture failed hr=%08X failures=%u", result, s_rendererState.renderFailures);
		ReleaseCom(stateBlock);
		ReleaseCom(renderTarget);
		return;
	}

	if (!CopyRenderTargetToTexture(device, renderTarget, desc, &sceneTexture))
	{
		++s_rendererState.renderFailures;
		stateBlock->Apply();
		ReleaseCom(stateBlock);
		ReleaseCom(renderTarget);
		return;
	}

	bool acquiredActiveDepthTexture = false;
	bool depthAvailable = false;
	UInt32 depthSource = kDepthSampleSource_None;
	bool wantsDepth = EffectProfileUsesDepth(s_effect.profile);
	if (wantsDepth &&
		s_rendererState.capturedDepthTexture &&
		s_rendererState.depthCaptureActiveLastFrame &&
		(now - s_rendererState.capturedDepthTick) <= kDepthCaptureMaxAgeMs)
	{
		depthTexture = s_rendererState.capturedDepthTexture;
		depthAvailable = true;
		depthSource = kDepthSampleSource_CapturedWorld;
		s_rendererState.depthLastFormat = s_rendererState.capturedDepthFormat;
		s_rendererState.depthLastHr = S_OK;
	}
	else if (wantsDepth)
	{
		depthAvailable = AcquireActiveDepthTexture(device, &depthTexture, &activeDepthSurface);
		acquiredActiveDepthTexture = depthAvailable;
		if (depthAvailable)
			depthSource = kDepthSampleSource_ActiveFallback;
	}
	if (wantsDepth)
	{
		if (depthSource == kDepthSampleSource_CapturedWorld)
		{
			++s_rendererState.depthCapturedSourceFrames;
			++s_rendererState.depthMaskTrustedFrames;
		}
		else if (depthSource == kDepthSampleSource_ActiveFallback)
		{
			++s_rendererState.depthActiveFallbackFrames;
			++s_rendererState.depthMaskUntrustedFrames;
		}
		else
		{
			++s_rendererState.depthUnavailableFrames;
			++s_rendererState.depthMaskUntrustedFrames;
		}
	}
	s_rendererState.depthLastSource = depthSource;
	s_rendererState.depthAvailableLastFrame = depthAvailable;

	bool hadActivePixelShader = RendererHasPixelShader();
	if (!DrawDistortionQuad(device, sceneTexture, depthTexture, activeDepthSurface, depthSource, desc, now, remainingMs, effectiveIntensity))
	{
		++s_rendererState.renderFailures;
		if (s_settings.rendererDebugLog)
		{
			if (!hadActivePixelShader)
			{
				_MESSAGE(
					"ERROR::RenderVESDistortionFrame: active pixel shader unavailable profile=%s slot=%u profileShader=%u fallback=%u failures=%u",
					GetEffectProfileDisplayName(s_effect.profile),
					GetEffectProfilePixelShaderSlot(s_effect.profile),
					ActiveProfilePixelShaderLoaded() ? 1 : 0,
					s_rendererState.pixelShader ? 1 : 0,
					s_rendererState.renderFailures);
			}
			else
			{
				_MESSAGE("ERROR::RenderVESDistortionFrame: DrawPrimitiveUP failed failures=%u", s_rendererState.renderFailures);
			}
		}
	}
	else
	{
		++s_rendererState.renderedFrames;
		if (s_settings.rendererDebugLog && s_rendererState.renderedFrames == 1)
			_MESSAGE(
				"VES distortion rendered first frame %ux%u fallbackShader=%u context=%u depth=%u depthSource=%s depthFormat=%08X",
				desc.Width,
				desc.Height,
				s_rendererState.fallbackShaderUsed ? 1 : 0,
				s_rendererState.lastRenderContext,
				depthAvailable ? 1 : 0,
				GetDepthSampleSourceName(depthSource),
				s_rendererState.depthLastFormat);
	}

	stateBlock->Apply();
	if (acquiredActiveDepthTexture)
		ReleaseCom(depthTexture);
	ReleaseCom(activeDepthSurface);
	ReleaseCom(sceneTexture);
	ReleaseCom(stateBlock);
	ReleaseCom(renderTarget);
}

void __cdecl BeforeProcessImageSpaceShaderHook(NiDX9Renderer* renderer, void* sourceTexture, void* destinationTexture)
{
	++s_rendererState.imageSpaceCalls;
	if (s_settings.rendererDebugLog && s_rendererState.imageSpaceCalls == 1)
		_MESSAGE(
			"VES renderer image-space hook first call renderer=%08X source=%08X destination=%08X",
			reinterpret_cast<UInt32>(renderer),
			reinterpret_cast<UInt32>(sourceTexture),
			reinterpret_cast<UInt32>(destinationTexture));
}

void __cdecl AfterProcessImageSpaceShaderHook(NiDX9Renderer* renderer, void*, void*)
{
	if (!s_effect.active)
		return;

	bool previousAllowOffscreen = s_allowOffscreenDistortion;
	s_allowOffscreenDistortion = true;
	RenderVESDistortionFrame(renderer);
	s_allowOffscreenDistortion = previousAllowOffscreen;
}

void __cdecl RenderWorldCameraSwayHook(void* camera, void* sceneGraph, void* cullingProcess, void* visibleGeo)
{
	if (s_cameraSwayState.inHook)
	{
		s_renderWorldSceneGraph(camera, sceneGraph, cullingProcess, visibleGeo);
		return;
	}

	s_cameraSwayState.inHook = true;
	ObserveMaskPrepassCandidateInputs(camera, sceneGraph, cullingProcess, visibleGeo);

	IDirect3DSurface9* previousDepthSurface = nullptr;
	NiDX9Renderer* renderer = GetRenderer();
	bool depthCaptureActive = false;
	if (!renderer || !renderer->device)
	{
		++s_rendererState.depthCaptureGuardNoRenderer;
	}
	else if (!s_effect.active)
	{
		++s_rendererState.depthCaptureGuardNoEffect;
	}
	else if (!EffectProfileUsesDepth(s_effect.profile))
	{
		++s_rendererState.depthCaptureGuardProfileNoDepth;
	}
	else if (camera != GetWorldCamera())
	{
		++s_rendererState.depthCaptureGuardCameraMismatch;
	}
	else if (*reinterpret_cast<volatile UInt32*>(kRenderModeAddress) != kRenderModeNormal)
	{
		++s_rendererState.depthCaptureGuardRenderMode;
	}
	else
	{
		depthCaptureActive = BeginTextureBackedDepthCapture(renderer->device, &previousDepthSurface);
		if (!depthCaptureActive)
			++s_rendererState.depthCaptureGuardBeginFailed;
	}

	CameraTransformBackup backup = {};
	bool applied = ApplyMoonSugarCameraSway(camera, &backup);
	s_renderWorldSceneGraph(camera, sceneGraph, cullingProcess, visibleGeo);
	if (depthCaptureActive)
	{
		EndTextureBackedDepthCapture(renderer->device, previousDepthSurface);
		ReleaseCom(previousDepthSurface);
	}
	if (applied)
	{
		RestoreCameraTransform(camera, &backup);
		RestoreRendererCameraState(camera);
	}

	s_cameraSwayState.inHook = false;
}

void __declspec(naked) ProcessImageSpaceShaderHook()
{
	__asm
	{
		push	ebp
		mov		ebp, esp

		pushfd
		pushad
		push	dword ptr [ebp + 0x10]
		push	dword ptr [ebp + 0x0C]
		push	dword ptr [ebp + 0x08]
		call	BeforeProcessImageSpaceShaderHook
		add		esp, 0x0C
		popad
		popfd

		push	dword ptr [ebp + 0x10]
		push	dword ptr [ebp + 0x0C]
		push	dword ptr [ebp + 0x08]
		mov		eax, 0x007B48E0
		call	eax
		add		esp, 0x0C

		pushfd
		pushad
		push	dword ptr [ebp + 0x10]
		push	dword ptr [ebp + 0x0C]
		push	dword ptr [ebp + 0x08]
		call	AfterProcessImageSpaceShaderHook
		add		esp, 0x0C
		popad
		popfd

		pop		ebp
		retn
	}
}

void __declspec(naked) RenderTriGeometrySetupHook()
{
	__asm
	{
		push	ebp
		mov		ebp, esp
		sub		esp, 0x40
		mov		dword ptr [ebp - 0x04], ecx

		push	dword ptr [ebp + 0x1C]
		push	dword ptr [ebp + 0x18]
		push	dword ptr [ebp + 0x10]
		push	dword ptr [ebp + 0x0C]
		push	dword ptr [ebp + 0x08]
		push	ecx
		push	dword ptr [ebp + 0x14]
		lea		eax, [ebp - 0x40]
		push	eax
		call	PrepareMoonSugarGeometryTransform
		add		esp, 0x20

		mov		edx, eax
		push	dword ptr [ebp + 0x1C]
		push	dword ptr [ebp + 0x18]
		push	edx
		push	dword ptr [ebp + 0x10]
		push	dword ptr [ebp + 0x0C]
		push	dword ptr [ebp + 0x08]
		mov		ecx, dword ptr [ebp - 0x04]
		mov		eax, 0x007672F0
		call	eax

		mov		esp, ebp
		pop		ebp
		retn	0x18
	}
}

void __declspec(naked) RenderTriGeometryPostSetupHook()
{
	__asm
	{
		pushfd
		pushad
		push	esi
		push	ebp
		push	ebx
		push	edi
		call	ApplyMoonSugarObjectVertexShader
		add		esp, 0x10
		popad
		popfd

		xor		eax, eax
		cmp		dword ptr [esi + 0x30], eax
		push	0x00767415
		ret
	}
}

void __declspec(naked) RenderTriGeometrySkinnedPostSetupHook()
{
	__asm
	{
		pushfd
		pushad
		mov		eax, dword ptr [esp + 0x54]
		push	edi
		push	ebp
		push	eax
		push	ebx
		push	esi
		call	ApplyMoonSugarSkinnedObjectVertexShader
		add		esp, 0x14
		popad
		popfd

		xor		eax, eax
		cmp		dword ptr [edi + 0x44], eax
		push	0x007676FE
		ret
	}
}

bool Cmd_VESDistortion_Execute(COMMAND_ARGS)
{
	SelectMoonSugarShader(true);
	UInt32 remainingMs = StartMoonSugarEffect(nullptr, false, kDefaultShaderName);

	if (result)
		*result = static_cast<double>(remainingMs) / 1000.0;

	Console_Print("VES: started %s %.2f intensity for %.2f seconds",
		kDefaultShaderDisplayName,
		s_effect.intensity,
		static_cast<double>(remainingMs) / 1000.0);
	return true;
}

bool Cmd_VESMoonSugar25_Execute(COMMAND_ARGS)
{
	UInt32 remainingMs = StartMoonSugarProfileEffect(kEffectProfile_MoonSugar25);

	if (result)
		*result = static_cast<double>(remainingMs) / 1000.0;

	Console_Print("VES: started %s %.2f intensity for %.2f seconds",
		GetEffectProfileDisplayName(kEffectProfile_MoonSugar25),
		s_effect.intensity,
		static_cast<double>(remainingMs) / 1000.0);
	return true;
}

bool Cmd_VESMoonSugar50_Execute(COMMAND_ARGS)
{
	UInt32 remainingMs = StartMoonSugarProfileEffect(kEffectProfile_MoonSugar50);

	if (result)
		*result = static_cast<double>(remainingMs) / 1000.0;

	Console_Print("VES: started %s %.2f intensity for %.2f seconds",
		GetEffectProfileDisplayName(kEffectProfile_MoonSugar50),
		s_effect.intensity,
		static_cast<double>(remainingMs) / 1000.0);
	return true;
}

bool Cmd_VESMoonSugar75_Execute(COMMAND_ARGS)
{
	UInt32 remainingMs = StartMoonSugarProfileEffect(kEffectProfile_MoonSugar75);

	if (result)
		*result = static_cast<double>(remainingMs) / 1000.0;

	Console_Print("VES: started %s %.2f intensity for %.2f seconds",
		GetEffectProfileDisplayName(kEffectProfile_MoonSugar75),
		s_effect.intensity,
		static_cast<double>(remainingMs) / 1000.0);
	return true;
}

bool Cmd_VESHeadWound25_Execute(COMMAND_ARGS)
{
	UInt32 remainingMs = StartHeadWoundEffect(kEffectProfile_HeadWound25);

	if (result)
		*result = static_cast<double>(remainingMs) / 1000.0;

	Console_Print("VES: started %s %.2f intensity for %.2f seconds",
		GetEffectProfileDisplayName(kEffectProfile_HeadWound25),
		s_effect.intensity,
		static_cast<double>(remainingMs) / 1000.0);
	return true;
}

bool Cmd_VESHeadWound50_Execute(COMMAND_ARGS)
{
	UInt32 remainingMs = StartHeadWoundEffect(kEffectProfile_HeadWound50);

	if (result)
		*result = static_cast<double>(remainingMs) / 1000.0;

	Console_Print("VES: started %s %.2f intensity for %.2f seconds",
		GetEffectProfileDisplayName(kEffectProfile_HeadWound50),
		s_effect.intensity,
		static_cast<double>(remainingMs) / 1000.0);
	return true;
}

bool Cmd_VESHeadWound75_Execute(COMMAND_ARGS)
{
	UInt32 remainingMs = StartHeadWoundEffect(kEffectProfile_HeadWound75);

	if (result)
		*result = static_cast<double>(remainingMs) / 1000.0;

	Console_Print("VES: started %s %.2f intensity for %.2f seconds",
		GetEffectProfileDisplayName(kEffectProfile_HeadWound75),
		s_effect.intensity,
		static_cast<double>(remainingMs) / 1000.0);
	return true;
}

bool Cmd_VESBlind25_Execute(COMMAND_ARGS)
{
	UInt32 remainingMs = StartBlindEffect(kEffectProfile_Blind25);

	if (result)
		*result = static_cast<double>(remainingMs) / 1000.0;

	Console_Print("VES: started %s %.2f intensity for %.2f seconds",
		GetEffectProfileDisplayName(kEffectProfile_Blind25),
		s_effect.intensity,
		static_cast<double>(remainingMs) / 1000.0);
	return true;
}

bool Cmd_VESBlind50_Execute(COMMAND_ARGS)
{
	UInt32 remainingMs = StartBlindEffect(kEffectProfile_Blind50);

	if (result)
		*result = static_cast<double>(remainingMs) / 1000.0;

	Console_Print("VES: started %s %.2f intensity for %.2f seconds",
		GetEffectProfileDisplayName(kEffectProfile_Blind50),
		s_effect.intensity,
		static_cast<double>(remainingMs) / 1000.0);
	return true;
}

bool Cmd_VESBlind75_Execute(COMMAND_ARGS)
{
	UInt32 remainingMs = StartBlindEffect(kEffectProfile_Blind75);

	if (result)
		*result = static_cast<double>(remainingMs) / 1000.0;

	Console_Print("VES: started %s %.2f intensity for %.2f seconds",
		GetEffectProfileDisplayName(kEffectProfile_Blind75),
		s_effect.intensity,
		static_cast<double>(remainingMs) / 1000.0);
	return true;
}

bool Cmd_VESBlind100_Execute(COMMAND_ARGS)
{
	UInt32 remainingMs = StartBlindEffect(kEffectProfile_Blind100);

	if (result)
		*result = static_cast<double>(remainingMs) / 1000.0;

	Console_Print("VES: started %s %.2f intensity for %.2f seconds",
		GetEffectProfileDisplayName(kEffectProfile_Blind100),
		s_effect.intensity,
		static_cast<double>(remainingMs) / 1000.0);
	return true;
}

bool Cmd_VESDim50_Execute(COMMAND_ARGS)
{
	UInt32 remainingMs = StartDimEffect(kEffectProfile_Dim50);

	if (result)
		*result = static_cast<double>(remainingMs) / 1000.0;

	Console_Print("VES: started %s %.2f intensity for %.2f seconds",
		GetEffectProfileDisplayName(kEffectProfile_Dim50),
		s_effect.intensity,
		static_cast<double>(remainingMs) / 1000.0);
	return true;
}

bool Cmd_VESDim100_Execute(COMMAND_ARGS)
{
	UInt32 remainingMs = StartDimEffect(kEffectProfile_Dim100);

	if (result)
		*result = static_cast<double>(remainingMs) / 1000.0;

	Console_Print("VES: started %s %.2f intensity for %.2f seconds",
		GetEffectProfileDisplayName(kEffectProfile_Dim100),
		s_effect.intensity,
		static_cast<double>(remainingMs) / 1000.0);
	return true;
}

bool Cmd_VESDimWhiteInverted_Execute(COMMAND_ARGS)
{
	UInt32 remainingMs = StartDimEffect(kEffectProfile_DimWhiteInverted);

	if (result)
		*result = static_cast<double>(remainingMs) / 1000.0;

	Console_Print("VES: started %s %.2f intensity for %.2f seconds",
		GetEffectProfileDisplayName(kEffectProfile_DimWhiteInverted),
		s_effect.intensity,
		static_cast<double>(remainingMs) / 1000.0);
	return true;
}

bool Cmd_VESDimPurple_Execute(COMMAND_ARGS)
{
	UInt32 remainingMs = StartDimEffect(kEffectProfile_DimPurple);

	if (result)
		*result = static_cast<double>(remainingMs) / 1000.0;

	Console_Print("VES: started %s %.2f intensity for %.2f seconds",
		GetEffectProfileDisplayName(kEffectProfile_DimPurple),
		s_effect.intensity,
		static_cast<double>(remainingMs) / 1000.0);
	return true;
}

bool Cmd_VESDimDarkRed_Execute(COMMAND_ARGS)
{
	UInt32 remainingMs = StartDimEffect(kEffectProfile_DimDarkRed);

	if (result)
		*result = static_cast<double>(remainingMs) / 1000.0;

	Console_Print("VES: started %s %.2f intensity for %.2f seconds",
		GetEffectProfileDisplayName(kEffectProfile_DimDarkRed),
		s_effect.intensity,
		static_cast<double>(remainingMs) / 1000.0);
	return true;
}

bool Cmd_VESOnFire25_Execute(COMMAND_ARGS)
{
	UInt32 remainingMs = StartOnFireEffect(kEffectProfile_OnFire25);

	if (result)
		*result = static_cast<double>(remainingMs) / 1000.0;

	Console_Print("VES: started %s %.2f intensity for %.2f seconds",
		GetEffectProfileDisplayName(kEffectProfile_OnFire25),
		s_effect.intensity,
		static_cast<double>(remainingMs) / 1000.0);
	return true;
}

bool Cmd_VESOnFire50_Execute(COMMAND_ARGS)
{
	UInt32 remainingMs = StartOnFireEffect(kEffectProfile_OnFire50);

	if (result)
		*result = static_cast<double>(remainingMs) / 1000.0;

	Console_Print("VES: started %s %.2f intensity for %.2f seconds",
		GetEffectProfileDisplayName(kEffectProfile_OnFire50),
		s_effect.intensity,
		static_cast<double>(remainingMs) / 1000.0);
	return true;
}

bool Cmd_VESOnFire75_Execute(COMMAND_ARGS)
{
	UInt32 remainingMs = StartOnFireEffect(kEffectProfile_OnFire75);

	if (result)
		*result = static_cast<double>(remainingMs) / 1000.0;

	Console_Print("VES: started %s %.2f intensity for %.2f seconds",
		GetEffectProfileDisplayName(kEffectProfile_OnFire75),
		s_effect.intensity,
		static_cast<double>(remainingMs) / 1000.0);
	return true;
}

bool Cmd_VESOnFire100_Execute(COMMAND_ARGS)
{
	UInt32 remainingMs = StartOnFireEffect(kEffectProfile_OnFire100);

	if (result)
		*result = static_cast<double>(remainingMs) / 1000.0;

	Console_Print("VES: started %s %.2f intensity for %.2f seconds",
		GetEffectProfileDisplayName(kEffectProfile_OnFire100),
		s_effect.intensity,
		static_cast<double>(remainingMs) / 1000.0);
	return true;
}

bool Cmd_VESHeatShimmer50_Execute(COMMAND_ARGS)
{
	UInt32 remainingMs = StartHeatShimmerEffect(kEffectProfile_HeatShimmer50);

	if (result)
		*result = static_cast<double>(remainingMs) / 1000.0;

	Console_Print("VES: started %s %.2f intensity for %.2f seconds",
		GetEffectProfileDisplayName(kEffectProfile_HeatShimmer50),
		s_effect.intensity,
		static_cast<double>(remainingMs) / 1000.0);
	return true;
}

bool Cmd_VESHeatShimmer100_Execute(COMMAND_ARGS)
{
	UInt32 remainingMs = StartHeatShimmerEffect(kEffectProfile_HeatShimmer100);

	if (result)
		*result = static_cast<double>(remainingMs) / 1000.0;

	Console_Print("VES: started %s %.2f intensity for %.2f seconds",
		GetEffectProfileDisplayName(kEffectProfile_HeatShimmer100),
		s_effect.intensity,
		static_cast<double>(remainingMs) / 1000.0);
	return true;
}

bool Cmd_VESDepthMaskDebug_Execute(COMMAND_ARGS)
{
	UInt32 remainingMs = StartDepthMaskDebugEffect();

	if (result)
		*result = static_cast<double>(remainingMs) / 1000.0;

	Console_Print("VES: started %s %.2f intensity for %.2f seconds",
		GetEffectProfileDisplayName(kEffectProfile_DepthMaskDebug),
		s_effect.intensity,
		static_cast<double>(remainingMs) / 1000.0);
	return true;
}

bool Cmd_VESRain50_Execute(COMMAND_ARGS)
{
	UInt32 remainingMs = StartRainEffect(kEffectProfile_Rain50);

	if (result)
		*result = static_cast<double>(remainingMs) / 1000.0;

	Console_Print("VES: started %s %.2f intensity for %.2f seconds",
		GetEffectProfileDisplayName(kEffectProfile_Rain50),
		s_effect.intensity,
		static_cast<double>(remainingMs) / 1000.0);
	return true;
}

bool Cmd_VESRain75_Execute(COMMAND_ARGS)
{
	UInt32 remainingMs = StartRainEffect(kEffectProfile_Rain75);

	if (result)
		*result = static_cast<double>(remainingMs) / 1000.0;

	Console_Print("VES: started %s %.2f intensity for %.2f seconds",
		GetEffectProfileDisplayName(kEffectProfile_Rain75),
		s_effect.intensity,
		static_cast<double>(remainingMs) / 1000.0);
	return true;
}

bool Cmd_VESRain100_Execute(COMMAND_ARGS)
{
	UInt32 remainingMs = StartRainEffect(kEffectProfile_Rain100);

	if (result)
		*result = static_cast<double>(remainingMs) / 1000.0;

	Console_Print("VES: started %s %.2f intensity for %.2f seconds",
		GetEffectProfileDisplayName(kEffectProfile_Rain100),
		s_effect.intensity,
		static_cast<double>(remainingMs) / 1000.0);
	return true;
}

bool Cmd_VESFrost50_Execute(COMMAND_ARGS)
{
	UInt32 remainingMs = StartFrostEffect(kEffectProfile_Frost50);

	if (result)
		*result = static_cast<double>(remainingMs) / 1000.0;

	Console_Print("VES: started %s %.2f intensity for %.2f seconds",
		GetEffectProfileDisplayName(kEffectProfile_Frost50),
		s_effect.intensity,
		static_cast<double>(remainingMs) / 1000.0);
	return true;
}

bool Cmd_VESFrost75_Execute(COMMAND_ARGS)
{
	UInt32 remainingMs = StartFrostEffect(kEffectProfile_Frost75);

	if (result)
		*result = static_cast<double>(remainingMs) / 1000.0;

	Console_Print("VES: started %s %.2f intensity for %.2f seconds",
		GetEffectProfileDisplayName(kEffectProfile_Frost75),
		s_effect.intensity,
		static_cast<double>(remainingMs) / 1000.0);
	return true;
}

bool Cmd_VESFrost100_Execute(COMMAND_ARGS)
{
	UInt32 remainingMs = StartFrostEffect(kEffectProfile_Frost100);

	if (result)
		*result = static_cast<double>(remainingMs) / 1000.0;

	Console_Print("VES: started %s %.2f intensity for %.2f seconds",
		GetEffectProfileDisplayName(kEffectProfile_Frost100),
		s_effect.intensity,
		static_cast<double>(remainingMs) / 1000.0);
	return true;
}

bool Cmd_VESStop_Execute(COMMAND_ARGS)
{
	ClearMoonSugarEffect();

	if (result)
		*result = 1.0;

	Console_Print("VES: stopped");
	return true;
}

bool Cmd_VESGetRemaining_Execute(COMMAND_ARGS)
{
	UInt32 remainingMs = VES_GetRemainingMilliseconds();
	if (result)
		*result = static_cast<double>(remainingMs) / 1000.0;

	Console_Print("VES: remaining %.2f seconds", static_cast<double>(remainingMs) / 1000.0);
	return true;
}

bool Cmd_VESGetIntensity_Execute(COMMAND_ARGS)
{
	float intensity = VES_GetIntensity();
	if (result)
		*result = intensity;

	Console_Print("VES: intensity %.3f", intensity);
	return true;
}

bool Cmd_VESReloadSettings_Execute(COMMAND_ARGS)
{
	LoadSettings();
	ReleaseRendererResources();

	if (result)
		*result = 1.0;

	Console_Print("VES: embedded settings reset");
	return true;
}

bool Cmd_VESDumpShaderRenderer_Execute(COMMAND_ARGS)
{
	UInt32 remainingMs = VES_GetRemainingMilliseconds();
	UInt32 renderMode = *reinterpret_cast<volatile UInt32*>(kRenderModeAddress);
	UInt32 renderTargetStackDepth = *reinterpret_cast<volatile UInt32*>(kRenderTargetStackDepthAddress);

	if (result)
		*result = static_cast<double>(s_rendererState.renderedFrames);

	Console_Print(
		"VES renderer: active=%u profile=%s shader=%s remaining=%.2fs doses=%u frames=%u failures=%u shaderFailures=%u lastSkip=%u imageSpace=%u",
		VES_IsActive() ? 1 : 0,
		GetEffectProfileName(s_effect.profile),
		s_shaderName,
		static_cast<double>(remainingMs) / 1000.0,
		s_effect.doseCount,
		s_rendererState.renderedFrames,
		s_rendererState.renderFailures,
		s_rendererState.shaderFailures,
		s_rendererState.lastSkipReason,
		s_rendererState.imageSpaceCalls);
	Console_Print(
		"VES renderer: mode=%u rtStack=%u shader=%u fallback=%u context=%u",
		renderMode,
		renderTargetStackDepth,
		RendererHasPixelShader() ? 1 : 0,
		s_rendererState.fallbackShaderUsed ? 1 : 0,
		s_rendererState.lastRenderContext);
	Console_Print(
		"VES pixel pipeline: activeSlot=%u profileMask=%02X fallbackShader=%u activeProfileShader=%u",
		GetEffectProfilePixelShaderSlot(s_effect.profile),
		BuildProfilePixelShaderMask(),
		s_rendererState.pixelShader ? 1 : 0,
		ActiveProfilePixelShaderLoaded() ? 1 : 0);
	Console_Print(
		"VES depth: available=%u attempts=%u success=%u failures=%u format=%08X hr=%08X",
		s_rendererState.depthAvailableLastFrame ? 1 : 0,
		s_rendererState.depthBindAttempts,
		s_rendererState.depthBindSuccess,
		s_rendererState.depthBindFailures,
		s_rendererState.depthLastFormat,
		s_rendererState.depthLastHr);
	Console_Print(
		"VES depth source: last=%s capturedFrames=%u activeFallbackFrames=%u unavailableFrames=%u maskTrusted=%u",
		GetDepthSampleSourceName(s_rendererState.depthLastSource),
		s_rendererState.depthCapturedSourceFrames,
		s_rendererState.depthActiveFallbackFrames,
		s_rendererState.depthUnavailableFrames,
		s_rendererState.depthLastSource == kDepthSampleSource_CapturedWorld ? 1 : 0);
	Console_Print(
		"VES depth mask: trustedFrames=%u untrustedFrames=%u guardNoRenderer=%u guardNoEffect=%u guardNoDepthProfile=%u guardCamera=%u guardMode=%u guardBeginFail=%u",
		s_rendererState.depthMaskTrustedFrames,
		s_rendererState.depthMaskUntrustedFrames,
		s_rendererState.depthCaptureGuardNoRenderer,
		s_rendererState.depthCaptureGuardNoEffect,
		s_rendererState.depthCaptureGuardProfileNoDepth,
		s_rendererState.depthCaptureGuardCameraMismatch,
		s_rendererState.depthCaptureGuardRenderMode,
		s_rendererState.depthCaptureGuardBeginFailed);
	Console_Print(
		"VES depth capture: attempts=%u success=%u failures=%u size=%ux%u format=%08X attemptedMask=%02X preflightPassMask=%02X preflightRejectMask=%02X hr=%08X",
		s_rendererState.depthCaptureAttempts,
		s_rendererState.depthCaptureSuccess,
		s_rendererState.depthCaptureFailures,
		s_rendererState.capturedDepthWidth,
		s_rendererState.capturedDepthHeight,
		s_rendererState.capturedDepthFormat,
		s_rendererState.depthCaptureAttemptedFormatMask,
		s_rendererState.depthCapturePreflightPassFormatMask,
		s_rendererState.depthCapturePreflightRejectFormatMask,
		s_rendererState.depthCaptureLastHr);
	Console_Print(
		"VES geometry: hook=%u calls=%u applied=%u skipScreen=%u skipSkin=%u",
		s_geometryHookInstalled ? 1 : 0,
		s_geometryWobbleState.calls,
		s_geometryWobbleState.applied,
		s_geometryWobbleState.skippedScreenElements,
		s_geometryWobbleState.skippedSkinned);
	Console_Print(
		"VES objectVS: hook=%u skinHook=%u calls=%u applied=%u skinCalls=%u skinApplied=%u census=%u skipPass=%u shaderFailures=%u legacyAppliedMask=%02X sm3ShaderMask=%02X sm3AppliedMask=%02X envShaderMask=%02X envAppliedMask=%02X texShaderMask=%02X texAppliedMask=%02X decalShaderMask=%02X decalAppliedMask=%02X depthShaderMask=%02X depthAppliedMask=%02X supportShaderMask=%08X supportAppliedMask=%08X",
		s_objectVertexHookInstalled ? 1 : 0,
		s_objectVertexSkinnedHookInstalled ? 1 : 0,
		s_objectVertexShaderState.calls,
		s_objectVertexShaderState.applied,
		s_objectVertexShaderState.skinnedCalls,
		s_objectVertexShaderState.skinnedApplied,
		s_objectVertexShaderState.passCensusSamples,
		s_objectVertexShaderState.skippedPass,
		s_objectVertexShaderState.shaderFailures,
		GetLegacyObjectVertexAppliedMask(),
		GetLighting30ObjectVertexShaderMask(),
		GetLighting30ObjectVertexAppliedMask(),
		GetLighting30EnvMapVertexShaderMask(),
		GetLighting30EnvMapVertexAppliedMask(),
		GetLighting30TexEffectVertexShaderMask(),
		GetLighting30TexEffectVertexAppliedMask(),
		GetLighting30DecalVertexShaderMask(),
		GetLighting30DecalVertexAppliedMask(),
		GetLighting30DepthMapVertexShaderMask(),
		GetLighting30DepthMapVertexAppliedMask(),
		GetLighting30SupportVertexShaderMask(),
		GetLighting30SupportVertexAppliedMask());
	LogObjectVertexPipelineCoverage();
	Console_Print(
		"VES camera: hook=%u calls=%u applied=%u restored=%u skipInactive=%u skipFiltered=%u",
		s_cameraHookInstalled ? 1 : 0,
		s_cameraSwayState.calls,
		s_cameraSwayState.applied,
		s_cameraSwayState.rendererRestored,
		s_cameraSwayState.skippedInactive,
		s_cameraSwayState.skippedFiltered);
	Console_Print(
		"VES mask prepass candidate: worldCalls=%u worldCamera=%u worldScene=%u sceneCull=%u normalMode=%u explicitVisibleArg=%u cullingVisibleGeo=%u missingCull=%u lastMode=%u",
		s_maskPrepassCandidateState.worldRenderCalls,
		s_maskPrepassCandidateState.worldCameraCalls,
		s_maskPrepassCandidateState.worldSceneGraphCalls,
		s_maskPrepassCandidateState.sceneGraphCullingProcessCalls,
		s_maskPrepassCandidateState.normalRenderModeCalls,
		s_maskPrepassCandidateState.explicitVisibleArgCalls,
		s_maskPrepassCandidateState.cullingProcessVisibleGeoCalls,
		s_maskPrepassCandidateState.missingCullingProcessCalls,
		s_maskPrepassCandidateState.lastRenderMode);
	Console_Print(
		"VES mask prepass candidate ptrs: camera=%08X scene=%08X culling=%08X sceneCull=%08X visibleArg=%08X cullingVisible=%08X",
		reinterpret_cast<UInt32>(s_maskPrepassCandidateState.lastCamera),
		reinterpret_cast<UInt32>(s_maskPrepassCandidateState.lastSceneGraph),
		reinterpret_cast<UInt32>(s_maskPrepassCandidateState.lastCullingProcess),
		reinterpret_cast<UInt32>(s_maskPrepassCandidateState.lastSceneGraphCullingProcess),
		reinterpret_cast<UInt32>(s_maskPrepassCandidateState.lastVisibleArg),
		reinterpret_cast<UInt32>(s_maskPrepassCandidateState.lastCullingProcessVisibleGeo));
	_MESSAGE(
		"Renderer dump: active=%u profile=%s shaderName=%s embeddedOnly=%u activePixelSlot=%u profileShaderMask=%02X activeProfileShader=%u remainingMs=%u doses=%u frames=%u failures=%u shaderFailures=%u lastSkip=%u imageSpace=%u mode=%u rtStack=%u shader=%u fallback=%u context=%u geometryHook=%u geometryCalls=%u geometryApplied=%u geometrySkipScreen=%u geometrySkipSkin=%u cameraHook=%u cameraCalls=%u cameraApplied=%u cameraRestored=%u cameraSkipInactive=%u cameraSkipFiltered=%u",
		VES_IsActive() ? 1 : 0,
		GetEffectProfileName(s_effect.profile),
		s_shaderName,
		s_embeddedPixelShaderOnly ? 1 : 0,
		GetEffectProfilePixelShaderSlot(s_effect.profile),
		BuildProfilePixelShaderMask(),
		ActiveProfilePixelShaderLoaded() ? 1 : 0,
		remainingMs,
		s_effect.doseCount,
		s_rendererState.renderedFrames,
		s_rendererState.renderFailures,
		s_rendererState.shaderFailures,
		s_rendererState.lastSkipReason,
		s_rendererState.imageSpaceCalls,
		renderMode,
		renderTargetStackDepth,
		RendererHasPixelShader() ? 1 : 0,
		s_rendererState.fallbackShaderUsed ? 1 : 0,
		s_rendererState.lastRenderContext,
		s_geometryHookInstalled ? 1 : 0,
		s_geometryWobbleState.calls,
		s_geometryWobbleState.applied,
		s_geometryWobbleState.skippedScreenElements,
		s_geometryWobbleState.skippedSkinned,
		s_cameraHookInstalled ? 1 : 0,
		s_cameraSwayState.calls,
		s_cameraSwayState.applied,
		s_cameraSwayState.rendererRestored,
		s_cameraSwayState.skippedInactive,
		s_cameraSwayState.skippedFiltered);
	_MESSAGE(
		"Renderer depth dump: available=%u attempts=%u success=%u failures=%u format=%08X hr=%08X",
		s_rendererState.depthAvailableLastFrame ? 1 : 0,
		s_rendererState.depthBindAttempts,
		s_rendererState.depthBindSuccess,
		s_rendererState.depthBindFailures,
		s_rendererState.depthLastFormat,
		s_rendererState.depthLastHr);
	_MESSAGE(
		"Renderer depth source dump: last=%s capturedFrames=%u activeFallbackFrames=%u unavailableFrames=%u maskTrusted=%u",
		GetDepthSampleSourceName(s_rendererState.depthLastSource),
		s_rendererState.depthCapturedSourceFrames,
		s_rendererState.depthActiveFallbackFrames,
		s_rendererState.depthUnavailableFrames,
		s_rendererState.depthLastSource == kDepthSampleSource_CapturedWorld ? 1 : 0);
	_MESSAGE(
		"Renderer depth mask dump: trustedFrames=%u untrustedFrames=%u guardNoRenderer=%u guardNoEffect=%u guardNoDepthProfile=%u guardCamera=%u guardMode=%u guardBeginFail=%u",
		s_rendererState.depthMaskTrustedFrames,
		s_rendererState.depthMaskUntrustedFrames,
		s_rendererState.depthCaptureGuardNoRenderer,
		s_rendererState.depthCaptureGuardNoEffect,
		s_rendererState.depthCaptureGuardProfileNoDepth,
		s_rendererState.depthCaptureGuardCameraMismatch,
		s_rendererState.depthCaptureGuardRenderMode,
		s_rendererState.depthCaptureGuardBeginFailed);
	_MESSAGE(
		"Renderer depth capture dump: attempts=%u success=%u failures=%u size=%ux%u format=%08X attemptedMask=%02X preflightPassMask=%02X preflightRejectMask=%02X hr=%08X active=%u",
		s_rendererState.depthCaptureAttempts,
		s_rendererState.depthCaptureSuccess,
		s_rendererState.depthCaptureFailures,
		s_rendererState.capturedDepthWidth,
		s_rendererState.capturedDepthHeight,
		s_rendererState.capturedDepthFormat,
		s_rendererState.depthCaptureAttemptedFormatMask,
		s_rendererState.depthCapturePreflightPassFormatMask,
		s_rendererState.depthCapturePreflightRejectFormatMask,
		s_rendererState.depthCaptureLastHr,
		s_rendererState.depthCaptureActiveLastFrame ? 1 : 0);
	_MESSAGE(
		"Mask prepass candidate dump: worldCalls=%u worldCamera=%u worldScene=%u sceneCull=%u normalMode=%u explicitVisibleArg=%u cullingVisibleGeo=%u missingCull=%u lastMode=%u lastCamera=%08X lastScene=%08X lastCulling=%08X lastSceneCull=%08X lastVisibleArg=%08X lastCullingVisible=%08X",
		s_maskPrepassCandidateState.worldRenderCalls,
		s_maskPrepassCandidateState.worldCameraCalls,
		s_maskPrepassCandidateState.worldSceneGraphCalls,
		s_maskPrepassCandidateState.sceneGraphCullingProcessCalls,
		s_maskPrepassCandidateState.normalRenderModeCalls,
		s_maskPrepassCandidateState.explicitVisibleArgCalls,
		s_maskPrepassCandidateState.cullingProcessVisibleGeoCalls,
		s_maskPrepassCandidateState.missingCullingProcessCalls,
		s_maskPrepassCandidateState.lastRenderMode,
		reinterpret_cast<UInt32>(s_maskPrepassCandidateState.lastCamera),
		reinterpret_cast<UInt32>(s_maskPrepassCandidateState.lastSceneGraph),
		reinterpret_cast<UInt32>(s_maskPrepassCandidateState.lastCullingProcess),
		reinterpret_cast<UInt32>(s_maskPrepassCandidateState.lastSceneGraphCullingProcess),
		reinterpret_cast<UInt32>(s_maskPrepassCandidateState.lastVisibleArg),
		reinterpret_cast<UInt32>(s_maskPrepassCandidateState.lastCullingProcessVisibleGeo));
	_MESSAGE(
		"Object vertex dump: hook=%u skinHook=%u calls=%u applied=%u skinCalls=%u skinApplied=%u census=%u skipInactive=%u skipPass=%u skipScreen=%u shaderFailures=%u compileAttempted=%u compileFailed=%u legacyAppliedMask=%02X sm3CompileAttemptMask=%02X sm3CompileFailedMask=%02X sm3ShaderMask=%02X sm3AppliedMask=%02X envCompileAttemptMask=%02X envCompileFailedMask=%02X envShaderMask=%02X envAppliedMask=%02X texCompileAttemptMask=%02X texCompileFailedMask=%02X texShaderMask=%02X texAppliedMask=%02X decalCompileAttemptMask=%02X decalCompileFailedMask=%02X decalShaderMask=%02X decalAppliedMask=%02X depthCompileAttemptMask=%02X depthCompileFailedMask=%02X depthShaderMask=%02X depthAppliedMask=%02X supportCompileAttemptMask=%08X supportCompileFailedMask=%08X supportShaderMask=%08X supportAppliedMask=%08X",
		s_objectVertexHookInstalled ? 1 : 0,
		s_objectVertexSkinnedHookInstalled ? 1 : 0,
		s_objectVertexShaderState.calls,
		s_objectVertexShaderState.applied,
		s_objectVertexShaderState.skinnedCalls,
		s_objectVertexShaderState.skinnedApplied,
		s_objectVertexShaderState.passCensusSamples,
		s_objectVertexShaderState.skippedInactive,
		s_objectVertexShaderState.skippedPass,
		s_objectVertexShaderState.skippedScreenElements,
		s_objectVertexShaderState.shaderFailures,
		s_objectVertexShaderState.compileAttempted ? 1 : 0,
		s_objectVertexShaderState.compileFailed ? 1 : 0,
		GetLegacyObjectVertexAppliedMask(),
		GetLighting30ObjectVertexCompileAttemptMask(),
		GetLighting30ObjectVertexCompileFailedMask(),
		GetLighting30ObjectVertexShaderMask(),
		GetLighting30ObjectVertexAppliedMask(),
		GetLighting30EnvMapVertexCompileAttemptMask(),
		GetLighting30EnvMapVertexCompileFailedMask(),
		GetLighting30EnvMapVertexShaderMask(),
		GetLighting30EnvMapVertexAppliedMask(),
		GetLighting30TexEffectVertexCompileAttemptMask(),
		GetLighting30TexEffectVertexCompileFailedMask(),
		GetLighting30TexEffectVertexShaderMask(),
		GetLighting30TexEffectVertexAppliedMask(),
		GetLighting30DecalVertexCompileAttemptMask(),
		GetLighting30DecalVertexCompileFailedMask(),
		GetLighting30DecalVertexShaderMask(),
		GetLighting30DecalVertexAppliedMask(),
		GetLighting30DepthMapVertexCompileAttemptMask(),
		GetLighting30DepthMapVertexCompileFailedMask(),
		GetLighting30DepthMapVertexShaderMask(),
		GetLighting30DepthMapVertexAppliedMask(),
		GetLighting30SupportVertexCompileAttemptMask(),
		GetLighting30SupportVertexCompileFailedMask(),
		GetLighting30SupportVertexShaderMask(),
		GetLighting30SupportVertexAppliedMask());
	LogObjectVertexPassCensus();
	return true;
}

DEFINE_COMMAND_PLUGIN(VESDistortion, "starts the configured VES distortion visual effect", 0, 0, NULL)
DEFINE_COMMAND_PLUGIN(VESStop, "stops the active VES visual effect", 0, 0, NULL)
DEFINE_COMMAND_PLUGIN(VESGetRemaining, "returns remaining VES effect seconds", 0, 0, NULL)
DEFINE_COMMAND_PLUGIN(VESGetIntensity, "returns current VES effect intensity", 0, 0, NULL)
DEFINE_COMMAND_PLUGIN(VESReloadSettings, "resets embedded VES effect settings", 0, 0, NULL)
DEFINE_COMMAND_PLUGIN(VESDumpShaderRenderer, "prints VES shader renderer diagnostics", 0, 0, NULL)
DEFINE_COMMAND_PLUGIN(VESMoonSugar25, "starts the MoonSugar 25 VES effect", 0, 0, NULL)
DEFINE_COMMAND_PLUGIN(VESMoonSugar50, "starts the MoonSugar 50 VES effect", 0, 0, NULL)
DEFINE_COMMAND_PLUGIN(VESMoonSugar75, "starts the MoonSugar 75 VES effect", 0, 0, NULL)
DEFINE_COMMAND_PLUGIN(VESHeadWound25, "starts the HeadWound 25 VES effect", 0, 0, NULL)
DEFINE_COMMAND_PLUGIN(VESHeadWound50, "starts the HeadWound 50 VES effect", 0, 0, NULL)
DEFINE_COMMAND_PLUGIN(VESHeadWound75, "starts the HeadWound 75 VES effect", 0, 0, NULL)
DEFINE_COMMAND_PLUGIN(VESBlind25, "starts the Blind 25 VES effect", 0, 0, NULL)
DEFINE_COMMAND_PLUGIN(VESBlind50, "starts the Blind 50 VES effect", 0, 0, NULL)
DEFINE_COMMAND_PLUGIN(VESBlind75, "starts the Blind 75 VES effect", 0, 0, NULL)
DEFINE_COMMAND_PLUGIN(VESBlind100, "starts the Blind 100 VES effect", 0, 0, NULL)
DEFINE_COMMAND_PLUGIN(VESDim50, "starts the Dim 50 VES effect", 0, 0, NULL)
DEFINE_COMMAND_PLUGIN(VESDim100, "starts the Dim 100 VES effect", 0, 0, NULL)
DEFINE_COMMAND_PLUGIN(VESDimWhiteInverted, "starts the Dim White/Inverted VES effect", 0, 0, NULL)
DEFINE_COMMAND_PLUGIN(VESDimPurple, "starts the Dim Purple VES effect", 0, 0, NULL)
DEFINE_COMMAND_PLUGIN(VESDimDarkRed, "starts the Dim Dark Red VES effect", 0, 0, NULL)
DEFINE_COMMAND_PLUGIN(VESOnFire25, "starts the On Fire 25 VES effect", 0, 0, NULL)
DEFINE_COMMAND_PLUGIN(VESOnFire50, "starts the On Fire 50 VES effect", 0, 0, NULL)
DEFINE_COMMAND_PLUGIN(VESOnFire75, "starts the On Fire 75 VES effect", 0, 0, NULL)
DEFINE_COMMAND_PLUGIN(VESOnFire100, "starts the On Fire 100 VES effect", 0, 0, NULL)
DEFINE_COMMAND_PLUGIN(VESHeatShimmer50, "starts the Heat Shimmer 50 VES effect", 0, 0, NULL)
DEFINE_COMMAND_PLUGIN(VESHeatShimmer100, "starts the Heat Shimmer 100 VES effect", 0, 0, NULL)
DEFINE_COMMAND_PLUGIN(VESDepthMaskDebug, "starts the Depth Mask Debug VES diagnostic effect", 0, 0, NULL)
DEFINE_COMMAND_PLUGIN(VESRain50, "starts the Rain 50 VES effect", 0, 0, NULL)
DEFINE_COMMAND_PLUGIN(VESRain75, "starts the Rain 75 VES effect", 0, 0, NULL)
DEFINE_COMMAND_PLUGIN(VESRain100, "starts the Rain 100 VES effect", 0, 0, NULL)
DEFINE_COMMAND_PLUGIN(VESFrost50, "starts the Frost 50 VES effect", 0, 0, NULL)
DEFINE_COMMAND_PLUGIN(VESFrost75, "starts the Frost 75 VES effect", 0, 0, NULL)
DEFINE_COMMAND_PLUGIN(VESFrost100, "starts the Frost 100 VES effect", 0, 0, NULL)

extern "C"
{
	__declspec(dllexport) bool VES_IsActive()
	{
		if (!s_effect.active)
			return false;

		UInt32 now = GetTickCount();
		if (TickHasReached(now, s_effect.expireTick))
		{
			ExpireMoonSugarEffect(now);
			return false;
		}

		return true;
	}

	__declspec(dllexport) float VES_GetIntensity()
	{
		if (!VES_IsActive())
			return 0.0f;

		return s_effect.intensity;
	}

	__declspec(dllexport) UInt32 VES_GetRemainingMilliseconds()
	{
		if (!VES_IsActive())
			return 0;

		return GetRemainingMillisecondsAt(GetTickCount());
	}
}

// ================================
// Plugin Compatibility Check
// ================================

const bool IsCompatible(const OBSEInterface* obse)
{
	if (obse->isEditor)
	{
		_MESSAGE("ERROR::IsCompatible: VES is runtime-only");
		_FATALERROR("ERROR::IsCompatible: VES is runtime-only");
		return false;
	}

	if (!IVersionCheck::IsCompatibleVersion(obse->oblivionVersion, MINIMUM_RUNTIME_VERSION, SUPPORTED_RUNTIME_VERSION, SUPPORTED_RUNTIME_VERSION_STRICT))
	{
		_MESSAGE("ERROR::IsCompatible: expected Oblivion runtime %08X, got %08X", SUPPORTED_RUNTIME_VERSION, obse->oblivionVersion);
		_FATALERROR("ERROR::IsCompatible: incompatible Oblivion runtime");
		return false;
	}

	return true;
}

extern "C"
{
	bool OBSEPlugin_Query(const OBSEInterface* obse, PluginInfo* info)
	{
		gLog.OpenRelative(CSIDL_MYDOCUMENTS, PLUGIN_LOG_FILE);

		_MESSAGE(PLUGIN_VERSION_INFO);
		_MESSAGE("Plugin_Query: Querying");

		info->infoVersion = PluginInfo::kInfoVersion;
		info->name = PLUGIN_NAME_LONG;
		info->version = PLUGIN_VERSION_DLL;

		if (!IsCompatible(obse))
		{
			_MESSAGE("ERROR::Plugin_Query: Incompatible | Disabling Plugin");
			return false;
		}

		_MESSAGE("Plugin_Query: Queried Successfully");
		return true;
	}

	bool OBSEPlugin_Load(const OBSEInterface* obse)
	{
		gLog.OpenRelative(CSIDL_MYDOCUMENTS, PLUGIN_LOG_FILE);

		_MESSAGE(PLUGIN_VERSION_INFO);
		_MESSAGE("Plugin_Load: Loading");

		if (!IsCompatible(obse))
		{
			_MESSAGE("ERROR::Plugin_Load: Incompatible | Disabling Plugin");
			return false;
		}

		g_pluginHandle = obse->GetPluginHandle();

		LoadSettings();
		if (!InstallHooks())
		{
			_MESSAGE("ERROR::Plugin_Load: hook installation failed | Disabling Plugin");
			return false;
		}

		RegisterCommands(obse);

		_MESSAGE("Plugin_Load: Loaded Successfully");
		return true;
	}
}














