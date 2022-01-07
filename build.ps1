param(
    [string]$OutDir = ".\bin\.build\",
    [string]$ProductName = "C_Prgms"
)

$ErrorActionPreference = "Stop"

Import-Module .\build-tools.psm1 -Force

$config = [PSCustomObject]@{
    archs = @("x64")
    buildConfig = "Release"
}

# output environment variables
Get-ChildItem env:* | Where { $_.Name -ne "SFTP_PASSWORD" } | Sort-Object Name

$msbuild = Get-MsbuildPath
Write-Host "[*] MSBuild: '$msbuild'"

Write-Host "[*] Configuration"
Write-Host "[*] - MSBuild target: $($config.buildTarget)"
Write-Host "[*] - MSBuild config: $($config.buildConfig)"
Write-Host "[*] - Archs: $($config.archs)"

# get version
$version = Get-BuildVersion .\version.props
Write-Host "[*] Build version -> $version"
$env:BUILD_VERSION = $version

foreach($arch in $config.archs) {
    Write-Host "[*] Building $arch..."
    & $msbuild /p:Configuration=$($config.buildConfig) /p:Platform=$arch collection.sln
    if (!$?) {
        Write-Error "[!] MSBuild failed w/code $LASTEXITCODE!"
        Exit $LASTEXITCODE
    }
}

Write-Host "[*] Collecting and packing build output..."

# set default output directories
$outBinDir = "${OutDir}bin\"
$tmpDir = "${OutDir}.temp"
$exePath = "${tmpDir}\exe"
$drvApplePath = "${tmpDir}\drv-apple"

# clean up directories if needed
@($OutDir, $outBinDir, $tmpDir, $exePath) | foreach {
    if (Test-Path $_) {
        Remove-Item $_ -Recurse -Force
    }
    New-Item $_ -Type Directory | Out-Null
}

# gather build results

$buildOutDir = ".\x64\Release"

Get-ChildItem -Path "$buildOutDir\collection.exe" | Copy-Item -Destination $exePath -Recurse -Force

foreach($arch in $config.archs) {
    Compress-Archive -CompressionLevel Optimal -Path "$exePath\*" -DestinationPath "${outBinDir}${ProductName}_ver_${version}.zip"
}

# remove directories
Remove-Item $tmpDir -Force -Recurse

# save version
$version | Out-File -FilePath "${OutDir}version.txt" -Encoding ascii -NoNewline

Write-Output "[*] Build done! Package Location ${outBinDir}${ProductName}_ver_${version}.zip"
