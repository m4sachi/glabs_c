<#
.SYNOPSIS
    Extract version number from .props file

.PARAMETER File
    Specifies a path to .props file
#>
function Get-BuildVersion
{
    param
    (
        [Parameter(Mandatory=1)][string]$File
    )

    [xml]$doc = Get-Content -LiteralPath $File

    $namespace = @{ns="http://schemas.microsoft.com/developer/msbuild/2003"}
    $verMajor = Select-Xml -Xml $doc -XPath "//ns:VersionMajor" -Namespace $namespace |
                    Select-Object -ExpandProperty Node | 
                    Select-Object -ExpandProperty InnerXml

    $verMinor = Select-Xml -Xml $doc -XPath "//ns:VersionMinor" -Namespace $namespace |
                    Select-Object -ExpandProperty Node | 
                    Select-Object -ExpandProperty InnerXml

    $verBuild = Select-Xml -Xml $doc -XPath "//ns:VersionBuild" -Namespace $namespace |
                    Select-Object -ExpandProperty Node | 
                    Select-Object -ExpandProperty InnerXml

    $verRevision = Select-Xml -Xml $doc -XPath "//ns:VersionRevision" -Namespace $namespace |
                    Select-Object -ExpandProperty Node | 
                    Select-Object -ExpandProperty InnerXml

    if ($verMajor -eq $null -or $verMinor -eq $null -or $verBuild -eq $null -or $verRevision -eq $null) {
        Write-Error "Couldn't query version from file: $File"
        throw "Couldn't query version from file: $File"
    }

    $version = [string]::Format("{0}.{1}.{2}.{3}", $verMajor, $verMinor, [int]$verBuild, $verRevision)
    return $version
}

<#
.SYNOPSIS
    Gets path to latest installed MSBuild using vswhere utility.
#>
function Get-MsbuildPath
{
    $vswhere = if ($env:PROCESSOR_ARCHITECTURE -eq "AMD64") {
        "${env:ProgramFiles(x86)}\Microsoft Visual Studio\Installer\vswhere.exe"
    } else {
        "${env:ProgramFiles}\Microsoft Visual Studio\Installer\vswhere.exe"
    }

    if (-not (Test-Path $vswhere)) {
        throw "Oooops! Couldn't find vswhere!"
    }

    $path = & $vswhere -latest -products * -requires Microsoft.Component.MSBuild -property installationPath
    if ($path) {
        $msbuild = join-path $path 'MSBuild\Current\Bin\MSBuild.exe'
        if (-not (test-path $msbuild)) {
            $msbuild = join-path $path 'MSBuild\15.0\Bin\MSBuild.exe'
            if (-not (Test-Path $msbuild)) {
                throw "Oooops! Couldn't find MSBuild!"
            }
        }

        return $msbuild
    }
    
    throw "Oooops! Couldn't find MSBuild!"  
}
