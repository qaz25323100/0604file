# Vue-Cli + .Net Core

> https://blog.poychang.net/vue-cli-with-dotnet-core-api/

# .Net Core新增Web api專案

    dotnet new webapi -o "TestAPI"
    
    
# 透過Vue-Cli新建專案至.Net Core專案

npm安裝vue-cli

    npm install -g @vue/cli

到剛建的net core 專案中

    cd TestAPI
    vue create ClientApp
    
新建vue.config.js，並加入底下內容，讓build輸出位置在TestAPI/wwwroot

    module.exports = {
      outputDir: '../wwwroot'
    };

執行底下指令
    
    npm run build
    
# 
