# 單例模式(Singleton)
from https://espressocoder.com/2019/01/03/implementing-the-singleton-pattern-in-asp-net-core/
from https://dotnetcoretutorials.com/2019/06/11/singleton-pattern-in-net-core/

## Asp.net Core作法

   public class MSSQLHelper 
    {

        private static readonly MSSQLHelper instance=new MSSQLHelper();
        private string _ConnectStr;

        public MSSQLHelper()
        {            
            _ConnectStr = ConfigurationManager.AppSettings.Get("MSSQL_CONNECTSTR");
        }

        public static MSSQLHelper GetInstance() => instance;
        
    }
    
    class Program
    {
        static void Main(string[] args)
        {
            var serviceProvider = new ServiceCollection()            
            .AddSingleton<MSSQLHelper>()
            .AddSingleton<FileWriter>()
            .BuildServiceProvider();            

            var FileWrite = serviceProvider.GetService<FileWriter>();
            var MSSQL = serviceProvider.GetService<MSSQLHelper>();
            
             Task.Run(async () =>
            {
                await FileWrite.WriteAsync(CombineTipData, probc.ProbcName, DateTime.Today.ToString(), MSSQL);               

            }).Wait();
        }
    }
