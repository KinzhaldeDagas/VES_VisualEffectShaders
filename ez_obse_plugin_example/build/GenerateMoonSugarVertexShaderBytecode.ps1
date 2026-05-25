param(
    [string]$ProjectDir = (Resolve-Path (Join-Path $PSScriptRoot '..')).Path,
    [string]$FxcPath = 'C:\Program Files (x86)\Microsoft DirectX SDK (June 2010)\Utilities\bin\x86\fxc.exe'
)

$ErrorActionPreference = 'Stop'

$mainPath = Join-Path $ProjectDir 'main.cpp'
$headerPath = Join-Path $ProjectDir 'MoonSugarVertexShaderBytecode.h'
$tempDir = Join-Path $env:TEMP 'MoonSugarVertexShaderBytecode'

if (-not (Test-Path -LiteralPath $FxcPath)) {
    throw "fxc.exe not found at $FxcPath"
}

New-Item -ItemType Directory -Force -Path $tempDir | Out-Null
$main = Get-Content -Raw -LiteralPath $mainPath

function Get-HlslSource {
    param([string]$Name)

    $pattern = 'const char\* ' + [regex]::Escape($Name) + '\s*=\s*((?:"(?:[^"\\]|\\.)*"\s*)+);'
    $match = [regex]::Match($main, $pattern, 'Singleline')
    if (-not $match.Success) {
        throw "HLSL string $Name not found"
    }

    $source = ''
    foreach ($literal in [regex]::Matches($match.Groups[1].Value, '"((?:[^"\\]|\\.)*)"', 'Singleline')) {
        $source += [System.Text.RegularExpressions.Regex]::Unescape($literal.Groups[1].Value)
    }
    return $source
}

function Convert-BytesToWords {
    param([byte[]]$Bytes)

    if (($Bytes.Length % 4) -ne 0) {
        throw "Shader bytecode length $($Bytes.Length) is not DWORD-aligned"
    }

    $words = New-Object System.Collections.Generic.List[string]
    for ($i = 0; $i -lt $Bytes.Length; $i += 4) {
        $words.Add(('0x{0:X8}' -f [System.BitConverter]::ToUInt32($Bytes, $i)))
    }
    return $words
}

function Add-Array {
    param(
        [System.Text.StringBuilder]$Builder,
        [string]$Name,
        [System.Collections.Generic.List[string]]$Words
    )

    [void]$Builder.AppendLine("static const unsigned int $Name[] =")
    [void]$Builder.AppendLine('{')
    for ($i = 0; $i -lt $Words.Count; $i += 8) {
        $take = [Math]::Min(8, $Words.Count - $i)
        $line = '    ' + (($Words.GetRange($i, $take)) -join ', ')
        if (($i + $take) -lt $Words.Count) {
            $line += ','
        }
        [void]$Builder.AppendLine($line)
    }
    [void]$Builder.AppendLine('};')
    [void]$Builder.AppendLine()
}

function Compile-Shader {
    param(
        [string]$ArrayName,
        [string]$SourceName,
        [string]$Profile,
        [string[]]$Defines
    )

    $sourcePath = Join-Path $tempDir "$ArrayName.hlsl"
    $outputPath = Join-Path $tempDir "$ArrayName.vso"
    Set-Content -LiteralPath $sourcePath -Value (Get-HlslSource $SourceName) -Encoding ASCII

    $args = @('/nologo', '/T', $Profile, '/E', 'MoonSugarVS', '/O3', '/Fo', $outputPath)
    foreach ($define in $Defines) {
        $args += "/D$define=1"
    }
    $args += $sourcePath

    $oldErrorActionPreference = $ErrorActionPreference
    $ErrorActionPreference = 'Continue'
    $fxcOutput = & $FxcPath @args 2>&1
    $exitCode = $LASTEXITCODE
    $ErrorActionPreference = $oldErrorActionPreference

    if ($exitCode -ne 0) {
        if ($fxcOutput) {
            $fxcOutput | ForEach-Object {
                $text = $_.ToString()
                if ($text -and $text -ne 'System.Management.Automation.RemoteException') { Write-Host $text }
            }
        }
        throw "fxc failed for $ArrayName"
    }
    if ($fxcOutput) {
        $fxcOutput | ForEach-Object {
            $text = $_.ToString()
            if ($text -and $text -ne 'System.Management.Automation.RemoteException') { Write-Host $text }
        }
    }

    return Convert-BytesToWords ([System.IO.File]::ReadAllBytes($outputPath))
}

$objectVariants = @(
    @{ Array = 'kEmbeddedMoonSugarLighting30ObjectVertexShaderBytecode_SM3000'; Source = 'kLighting30ObjectVertexShader'; Defines = @() },
    @{ Array = 'kEmbeddedMoonSugarLighting30ObjectVertexShaderBytecode_SM3002Vc'; Source = 'kLighting30ObjectVertexShader'; Defines = @('USE_VERTEX_COLOR') },
    @{ Array = 'kEmbeddedMoonSugarLighting30ObjectVertexShaderBytecode_SM3004Proj'; Source = 'kLighting30ObjectVertexShader'; Defines = @('USE_PROJ_SHADOW') },
    @{ Array = 'kEmbeddedMoonSugarLighting30ObjectVertexShaderBytecode_SM3006VcProj'; Source = 'kLighting30ObjectVertexShader'; Defines = @('USE_VERTEX_COLOR', 'USE_PROJ_SHADOW') },
    @{ Array = 'kEmbeddedMoonSugarLighting30ObjectVertexShaderBytecode_SM3001Skin'; Source = 'kLighting30SkinnedObjectVertexShader'; Defines = @() },
    @{ Array = 'kEmbeddedMoonSugarLighting30ObjectVertexShaderBytecode_SM3003SkinVc'; Source = 'kLighting30SkinnedObjectVertexShader'; Defines = @('USE_VERTEX_COLOR') },
    @{ Array = 'kEmbeddedMoonSugarLighting30ObjectVertexShaderBytecode_SM3005SkinProj'; Source = 'kLighting30SkinnedObjectVertexShader'; Defines = @('USE_PROJ_SHADOW') },
    @{ Array = 'kEmbeddedMoonSugarLighting30ObjectVertexShaderBytecode_SM3007SkinVcProj'; Source = 'kLighting30SkinnedObjectVertexShader'; Defines = @('USE_VERTEX_COLOR', 'USE_PROJ_SHADOW') }
)

$envMapVariants = @(
    @{ Array = 'kEmbeddedMoonSugarLighting30EnvMapVertexShaderBytecode_SM3008'; Source = 'kLighting30EnvMapObjectVertexShader'; Defines = @() },
    @{ Array = 'kEmbeddedMoonSugarLighting30EnvMapVertexShaderBytecode_SM3009Vc'; Source = 'kLighting30EnvMapObjectVertexShader'; Defines = @('USE_VERTEX_COLOR') },
    @{ Array = 'kEmbeddedMoonSugarLighting30EnvMapVertexShaderBytecode_SM3010Skin'; Source = 'kLighting30EnvMapSkinnedObjectVertexShader'; Defines = @() },
    @{ Array = 'kEmbeddedMoonSugarLighting30EnvMapVertexShaderBytecode_SM3011SkinVc'; Source = 'kLighting30EnvMapSkinnedObjectVertexShader'; Defines = @('USE_VERTEX_COLOR') },
    @{ Array = 'kEmbeddedMoonSugarLighting30EnvMapVertexShaderBytecode_SM3012Special'; Source = 'kLighting30EnvMapSpecialObjectVertexShader'; Defines = @() }
)

$texEffectVariants = @(
    @{ Array = 'kEmbeddedMoonSugarLighting30TexEffectVertexShaderBytecode_SM3028'; Source = 'kLighting30TexEffectObjectVertexShader'; Defines = @() },
    @{ Array = 'kEmbeddedMoonSugarLighting30TexEffectVertexShaderBytecode_SM3029Skin'; Source = 'kLighting30TexEffectSkinnedObjectVertexShader'; Defines = @() }
)

$depthMapVariants = @(
    @{ Array = 'kEmbeddedMoonSugarLighting30DepthMapVertexShaderBytecode_SM3018'; Source = 'kLighting30DepthMapObjectVertexShader'; Defines = @() },
    @{ Array = 'kEmbeddedMoonSugarLighting30DepthMapVertexShaderBytecode_SM3019Skin'; Source = 'kLighting30DepthMapSkinnedObjectVertexShader'; Defines = @() }
)

$supportVariants = @(
    @{ Array = 'kEmbeddedMoonSugarLighting30SupportVertexShaderBytecode_SM3030ZOnly'; Source = 'kLighting30SupportObjectVertexShader'; Defines = @('HAS_UV', 'MODE_ZONLY') },
    @{ Array = 'kEmbeddedMoonSugarLighting30SupportVertexShaderBytecode_SM3031ZOnlySkin'; Source = 'kLighting30SupportObjectVertexShader'; Defines = @('SKIN', 'HAS_UV', 'MODE_ZONLY') },
    @{ Array = 'kEmbeddedMoonSugarLighting30SupportVertexShaderBytecode_SM3020RenderNormals'; Source = 'kLighting30SupportObjectVertexShader'; Defines = @('HAS_UV', 'HAS_NORMAL', 'MODE_RENDER_NORMALS') },
    @{ Array = 'kEmbeddedMoonSugarLighting30SupportVertexShaderBytecode_SM3021RenderNormalsSkin'; Source = 'kLighting30SupportObjectVertexShader'; Defines = @('SKIN', 'HAS_UV', 'HAS_NORMAL', 'MODE_RENDER_NORMALS') },
    @{ Array = 'kEmbeddedMoonSugarLighting30SupportVertexShaderBytecode_SM3022RenderNormalsFire'; Source = 'kLighting30SupportObjectVertexShader'; Defines = @('HAS_NORMAL', 'MODE_RENDER_NORMALS_FIRE') },
    @{ Array = 'kEmbeddedMoonSugarLighting30SupportVertexShaderBytecode_SM3025LocalMap'; Source = 'kLighting30SupportObjectVertexShader'; Defines = @('HAS_NORMAL', 'MODE_LOCALMAP') },
    @{ Array = 'kEmbeddedMoonSugarLighting30SupportVertexShaderBytecode_SM3026LocalMapSkin'; Source = 'kLighting30SupportObjectVertexShader'; Defines = @('SKIN', 'HAS_NORMAL', 'MODE_LOCALMAP') },
    @{ Array = 'kEmbeddedMoonSugarLighting30SupportVertexShaderBytecode_SM3013SimpleShadow'; Source = 'kLighting30SupportObjectVertexShader'; Defines = @('HAS_UV', 'MODE_SIMPLE_SHADOW') },
    @{ Array = 'kEmbeddedMoonSugarLighting30SupportVertexShaderBytecode_SM3014SimpleShadowVc'; Source = 'kLighting30SupportObjectVertexShader'; Defines = @('HAS_UV', 'MODE_SIMPLE_SHADOW') },
    @{ Array = 'kEmbeddedMoonSugarLighting30SupportVertexShaderBytecode_SM3015SimpleShadowSkin'; Source = 'kLighting30SupportObjectVertexShader'; Defines = @('SKIN', 'HAS_UV', 'MODE_SIMPLE_SHADOW') },
    @{ Array = 'kEmbeddedMoonSugarLighting30SupportVertexShaderBytecode_SM3016SimpleShadowSkinVc'; Source = 'kLighting30SupportObjectVertexShader'; Defines = @('SKIN', 'HAS_UV', 'MODE_SIMPLE_SHADOW') }
)

$singleShaders = @(
    @{ Array = 'kEmbeddedMoonSugarObjectVertexShaderBytecode_PAR2016_SKIN2008'; Source = 'kObjectVertexShader'; Profile = 'vs_2_0'; Defines = @() },
    @{ Array = 'kEmbeddedMoonSugarLighting30DecalVertexShaderBytecode_SM3017'; Source = 'kLighting30DecalObjectVertexShader'; Profile = 'vs_3_0'; Defines = @() }
)

$builder = New-Object System.Text.StringBuilder
[void]$builder.AppendLine('#pragma once')
[void]$builder.AppendLine()
[void]$builder.AppendLine('// Generated by build/GenerateMoonSugarVertexShaderBytecode.ps1 from main.cpp replacement HLSL strings.')
[void]$builder.AppendLine('// These blobs do not define shader eligibility; runtime gates still come from decoded Oblivion pass and program contracts.')
[void]$builder.AppendLine('struct MoonSugarEmbeddedVertexShaderBytecode')
[void]$builder.AppendLine('{')
[void]$builder.AppendLine('    const unsigned int* words;')
[void]$builder.AppendLine('    unsigned int wordCount;')
[void]$builder.AppendLine('};')
[void]$builder.AppendLine()

foreach ($shader in $singleShaders) {
    Add-Array $builder $shader.Array (Compile-Shader $shader.Array $shader.Source $shader.Profile $shader.Defines)
}
foreach ($shader in $objectVariants) {
    Add-Array $builder $shader.Array (Compile-Shader $shader.Array $shader.Source 'vs_3_0' $shader.Defines)
}
foreach ($shader in $envMapVariants) {
    Add-Array $builder $shader.Array (Compile-Shader $shader.Array $shader.Source 'vs_3_0' $shader.Defines)
}
foreach ($shader in $texEffectVariants) {
    Add-Array $builder $shader.Array (Compile-Shader $shader.Array $shader.Source 'vs_3_0' $shader.Defines)
}
foreach ($shader in $depthMapVariants) {
    Add-Array $builder $shader.Array (Compile-Shader $shader.Array $shader.Source 'vs_3_0' $shader.Defines)
}
foreach ($shader in $supportVariants) {
    Add-Array $builder $shader.Array (Compile-Shader $shader.Array $shader.Source 'vs_3_0' $shader.Defines)
}

function Add-DescriptorArray {
    param(
        [System.Text.StringBuilder]$Builder,
        [string]$Name,
        [array]$Shaders
    )

    [void]$Builder.AppendLine("static const MoonSugarEmbeddedVertexShaderBytecode $Name[] =")
    [void]$Builder.AppendLine('{')
    for ($i = 0; $i -lt $Shaders.Count; ++$i) {
        $array = $Shaders[$i].Array
        $suffix = if ($i + 1 -lt $Shaders.Count) { ',' } else { '' }
        [void]$Builder.AppendLine("    { $array, sizeof($array) / sizeof($array[0]) }$suffix")
    }
    [void]$Builder.AppendLine('};')
    [void]$Builder.AppendLine()
}

Add-DescriptorArray $builder 'kEmbeddedMoonSugarLighting30ObjectVertexShaders' $objectVariants
Add-DescriptorArray $builder 'kEmbeddedMoonSugarLighting30EnvMapVertexShaders' $envMapVariants
Add-DescriptorArray $builder 'kEmbeddedMoonSugarLighting30TexEffectVertexShaders' $texEffectVariants
Add-DescriptorArray $builder 'kEmbeddedMoonSugarLighting30DepthMapVertexShaders' $depthMapVariants
Add-DescriptorArray $builder 'kEmbeddedMoonSugarLighting30SupportVertexShaders' $supportVariants

Set-Content -LiteralPath $headerPath -Value $builder.ToString() -Encoding ASCII
Write-Output "Generated $headerPath"
