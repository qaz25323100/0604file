# 依賴注入(Dependency Injection)

https://blog.darkthread.net/blog/aspnet-core-di-notes/  

https://blog.darkthread.net/blog/aspnetcore-use-scoped-in-singleton/

## Mongodb建議client使用單例  

  https://github.com/nbarbettini/little-aspnetcore-book/issues/37
  http://mongodb.github.io/mongo-csharp-driver/2.5/reference/driver/connecting/#re-use
  

## 生命週期

  注入主要有三種生命週期：AddTransient()、 AddScoped()、 AddSingleton()，根據使用的方法而有所不同，
  其底下為三種生命週期上的差異：
  
    var services = new ServiceCollection()
                 .AddTransient<IFoo, Foo>()
                 .AddScoped<IBar, Bar>()
                 .AddSingleton<IBaz, Baz>()
                 .BuildServiceProvider();
            
    var provider1 = services.CreateScope().ServiceProvider;
    var provider2 = services.CreateScope().ServiceProvider;
    
    GetService<IFoo>(provider1);
    GetService<IBar>(provider1);
    GetService<IBaz>(provider1);
    Console.WriteLine();
    GetService<IFoo>(provider2);
    GetService<IBar>(provider2);
    GetService<IBaz>(provider2);
            
    static void GetService<T>(IServiceProvider provider){
        provider.GetService<T>(); //Use two GetService cause AddTransient
        provider.GetService<T>();
    }
  
  輸出結果如下
  
    An Instance of Foo is created.
    An Instance of Foo is created.
    An Instance of Bar is created.
    An Instance of Baz is created.
  
    An Instance of Foo is created.
    An Instance of Foo is created.
    An Instance of Bar is created.

# 使用時機限制  

### Singleton服務中有Scope服務  
  
當有Scope服務存在在Singleton服務中,Scope服務將變成一個Singleton服務實例  
如底下例子:  

### 當註冊服務時，建構式為private 
  
Foobar服務與IFoobar介面
    
    public interface IFoobar{}

    public class Foobar:IFoobar{
        public static readonly Foobar Instance = new Foobar();
        private Foobar(){}
    }  
 主程式
   
    static void Main(string[] args)
        {
            // var services = new ServiceCollection()
            //     .AddSingleton<MySqlConnection>()
            //     .BuildServiceProvider();

            BuildServiceProvider(false);
            BuildServiceProvider(true);

            static void BuildServiceProvider(bool validateOnBuild)
            {
                try
                {
                    var options = new ServiceProviderOptions
                    {
                        ValidateOnBuild = validateOnBuild
                    };
                    new ServiceCollection()
                    .AddSingleton<IFoobar, Foobar>()
                    .BuildServiceProvider(options);

                    Console.WriteLine($"Status: Success, ValidationOnBuild: {validateOnBuild}");
                }
                catch (Exception ex)
                {
                    Console.WriteLine($"Status: Fail, ValidationOnBuild: {validateOnBuild}");
                    Console.WriteLine($"Eror: {ex.Message}");
                }

            }
        }  
  
  看  
  
    Status: Fail, ValidationOnBuild: True
    Eror: Some services are not able to be constructed (Error while validating the service descriptor 'ServiceType: IFoobar Lifetime: Singleton ImplementationType: Foobar': A       suitable constructor for type 'Foobar' could not be located. Ensure the type is concrete and services are registered for all parameters of a public constructor.)
