param(
    [string]$Configuration = "Release",
    [string]$Platform = "x86"
)

$ErrorActionPreference = "Stop"

$BuildDir = Split-Path -Parent $MyInvocation.MyCommand.Path
$ProjectDir = Split-Path -Parent $BuildDir
$SolutionPath = Join-Path $ProjectDir "ez_obse_plugin_example.sln"
$SupportProps = Join-Path $BuildDir "MoonSugar.ObseSupportPaths.props"
$MSBuild = "C:\Program Files\Microsoft Visual Studio\2022\Community\MSBuild\Current\Bin\MSBuild.exe"

& $MSBuild $SolutionPath `
    /p:Configuration=$Configuration `
    /p:Platform=$Platform `
    /p:ForceImportBeforeCppProps=$SupportProps `
    /m

exit $LASTEXITCODE
