# 依賴注入(Dependency Injection)


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
