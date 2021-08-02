# Vue-Cli + .Net Core

> https://blog.poychang.net/vue-cli-with-dotnet-core-api/

# 透過Vue-Cli新建專案至.Net Core專案

### .Net Core新增Web api專案

    dotnet new webapi -o "TestAPI"

### Vue-cli build

到剛建的net core 專案中

    cd TestAPI
    vue create ClientApp
    
新建vue.config.js，並加入底下內容，讓build輸出位置在TestAPI/wwwroot

    module.exports = {
      outputDir: '../wwwroot'
    };

執行底下指令
    
    npm run build
    
# .Net Core編譯問題

.Net Core編譯時會掃描整個專案目錄，如果當中有node_modules,bower_components這種資料夾，會導致編譯時間過久  
因此需在xxxxx.csproj檔案中設定排除的資料夾  

    <Project Sdk="Microsoft.NET.Sdk.Web">

        <PropertyGroup>
            <TargetFramework>netcoreapp3.1</TargetFramework>
            <RootNamespace>xxxxxx</RootNamespace>
            <DefaultItemExcludes>ClientApp\**;$(DefaultItemExcludes)</DefaultItemExcludes>
        </PropertyGroup>
     </Project>



# LeetCode EASY
13,14,20
