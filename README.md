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
13,14,20,21,35

# Nuget paks

dotnet add package Microsoft.AspNetCore.Mvc.NewtonsoftJson --version 3.1.17
dotnet add package Microsoft.AspNetCore.Mvc.NewtonsoftJson --version 5.0.0
dotnet add package SMBLibrary --version 1.4.6.1


# setting

        public void ConfigureServices(IServiceCollection services)
        {
            //services.AddMvc().SetCompatibilityVersion(CompatibilityVersion.Version_2_1);
            //services.AddControllersWithViews();

            //NeedleMachineSetting and Service
            services.Configure<PCsNeedleMachineMongoSettings>(options =>
                Configuration.GetSection("PCsNeedleMachineOnlineMongoSettings").Bind(options));
            services.AddSingleton<IMongoSettings>(sp =>
                    sp.GetRequiredService<IOptions<PCsNeedleMachineMongoSettings>>().Value);
            services.AddSingleton<NeedleMachineService>();

            services.AddControllers()
                .AddNewtonsoftJson(options => options.UseMemberCasing());

            //services.AddRazorPages();
        }

        // This method gets called by the runtime. Use this method to configure the HTTP request pipeline.
        public void Configure(IApplicationBuilder app, IWebHostEnvironment env)
        {
            if (env.IsDevelopment())
            {
                app.UseDeveloperExceptionPage();
            }
            else
            {
                app.UseHsts();
            }

            app.Use(async (context, next) =>
            {
                await next();

                // 判斷是否是要存取網頁，而不是發送 API 需求
                if (context.Response.StatusCode == 404 &&                       // 該資源不存在
                    !System.IO.Path.HasExtension(context.Request.Path.Value) && // 網址最後沒有帶副檔名
                    !context.Request.Path.Value.StartsWith("/api"))             // 網址不是 /api 開頭
                {
                    context.Request.Path = "/index.html";                       // 將網址改成 /index.html
                    context.Response.StatusCode = 200;                          // 並將 HTTP 狀態碼修改為 200 成功
                    await next();
                }
            });
            app.UseDefaultFiles();
            app.UseStaticFiles();

            app.UseRouting();
            app.UseEndpoints(endpoints =>
            {
                //endpoints.MapRazorPages();
                endpoints.MapControllers();
            });
        }
