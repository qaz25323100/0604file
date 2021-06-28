
<Project Sdk="Microsoft.NET.Sdk">

  <PropertyGroup>
    <OutputType>Exe</OutputType>
    <OutDir Condition="'$(Configuration)' == 'release'">/DATA_POOL/LOG/CP/Scheduling/plugin/followingLastLot</OutDir>
    <TargetFramework>netcoreapp3.1</TargetFramework>
    <GenerateTargetFrameworkAttribute>false</GenerateTargetFrameworkAttribute>
    <GenerateAssemblyInfo>false</GenerateAssemblyInfo>
  </PropertyGroup>

  <PropertyGroup>
    <OutputType>Exe</OutputType>
    <OutDir Condition="'$(Configuration)' == 'dev'">/home/cpeng/HankLin/CS_PGM/Scheduling/plugin/followingLastLot</OutDir>
    <TargetFramework>netcoreapp3.1</TargetFramework>
    <GenerateTargetFrameworkAttribute>false</GenerateTargetFrameworkAttribute>
    <GenerateAssemblyInfo>false</GenerateAssemblyInfo>
  </PropertyGroup>


  <ItemGroup>
    <PackageReference Include="NewtonSoft.Json" Version="12.0.3" />
    <PackageReference Include="ssh.net" Version="2016.1.0" />
    <PackageReference Include="Microsoft.Extensions.Configuration" Version="3.1.9" />
    <PackageReference Include="Microsoft.Extensions.Configuration.Json" Version="3.1.9" />
    <PackageReference Include="System.Data.SqlClient" Version="4.8.2" />
  </ItemGroup>

  <ItemGroup Condition="'$(Configuration)' != 'release'">
    <None Include="getExtendSchedulingInfo*.sql" CopyToOutputDirectory="Always" />
    <None Include="config/pgm.ini" CopyToOutputDirectory="Always" />
  </ItemGroup>

  <ItemGroup Condition="'$(Configuration)' == 'release'">
    <None Include="getExtendSchedulingInfo*.sql" CopyToOutputDirectory="Always" />
    <None Include="config/pgm.release.ini" CopyToOutputDirectory="Always">
      <Link>config/pgm.ini</Link>
    </None>
  </ItemGroup>

  <ItemGroup>
    <ProjectReference Include="..\..\lib\QuickQueryDB\QuickQueryDB.csproj" />
    <ProjectReference Include="..\..\lib\logWriter\logWriter.csproj" />
    <ProjectReference Include="..\..\lib\ConfigurationLibrary\ConfigurationLibrary.csproj" />
    <ProjectReference Include="..\..\lib\SelectableList\SelectableList.csproj" />
    <ProjectReference Include="..\..\lib\BashHelper\BashHelper.csproj" />
  </ItemGroup>

</Project>
