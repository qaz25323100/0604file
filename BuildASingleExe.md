## .Net Core Project File  
  
     <PropertyGroup>
        <OutputType>Exe</OutputType>
        <!--<OutputType>WinExe</OutputType>--><!--Use this for WPF or Windows Forms apps-->
        <TargetFramework>net5.0</TargetFramework>
        <!--<TargetFramework>net5.0-windows</TargetFramework>--><!--Use this for WPF or Windows Forms apps-->
        <PublishSingleFile>true</PublishSingleFile>
        <SelfContained>true</SelfContained>
        <IncludeAllContentForSelfExtract>true</IncludeAllContentForSelfExtract>
        <RuntimeIdentifier>win-x64</RuntimeIdentifier><!--Specify the appropriate runtime here-->
    </PropertyGroup>
  
## Build Command  
    dotnet publish -r win-x64 --self-contained true -p:PublishSingleFile=true -p:IncludeAllContentForSelfExtract=true
