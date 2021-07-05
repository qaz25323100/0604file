# 一般主機

Main.cs  
    static void Main(string[] args)
    {
            var host = CreateHostBuilder(args).Build();
            
            var FileWrite = host.Services.GetService<IFileWrite>();
            var sql = host.Services.GetService<ISQLService>();
            var NeedleMachine = host.Services.GetRequiredService<PCsNeedleMachineService>();
            
            host.Run();
    }

    public static IHostBuilder CreateHostBuilder(string[] args) =>
            Host.CreateDefaultBuilder(args).ConfigureAppConfiguration((context, config) =>
            {
                IHostEnvironment env = context.HostingEnvironment;
                config.AddEnvironmentVariables()
                    // copy configuration files to output directory
                    .AddJsonFile("appsettings.json");
                
            }).ConfigureServices((context, service) =>
            {
                service.Configure<PCsNeedleMachineMongoSettings>(
                   context.Configuration.GetSection("PCsNeedleMachineMongoSettings"))
                    .AddSingleton<IMongoSettings>(sp =>
                        sp.GetRequiredService<IOptions<PCsNeedleMachineMongoSettings>>().Value)

                    .AddSingleton<PCsNeedleMachineService>()
                    .AddSingleton<IDBHelper, MYSQLHelper>()
                    .AddScoped<ISQLService, SQLService>()
                    .AddSingleton<IFileWrite, FileWriter>();
            });
