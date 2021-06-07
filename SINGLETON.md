# 單例模式(Singleton)
from https://espressocoder.com/2019/01/03/implementing-the-singleton-pattern-in-asp-net-core/

## 經典做法

使用private staic readonly宣告 instance
建構式宣告成private,避免外部類別宣告
public static存取instance

    public class MSSQLHelper
    {

        private static readonly MSSQLHelper instance = new MSSQLHelper();
        private string _ConnectStr;

        private MSSQLHelper()
        {
            _ConnectStr = ConfigurationManager.AppSettings.Get("MSSQL_CONNECTSTR");
        }

        public static MSSQLHelper Instance
        {
            get
            {
                return instance;
            }
        }
    }

## Asp.net Core作法
    public interface IDBHelper
    {
        private static IDBHelper Instance { get; }
       
    }

    public class MSSQLHelper : IDBHelper
    {

        private static readonly MSSQLHelper instance = new MSSQLHelper();
        private string _ConnectStr;

        private MSSQLHelper()
        {            
            _ConnectStr = ConfigurationManager.AppSettings.Get("MSSQL_CONNECTSTR");
        }

        public static MSSQLHelper Instance
        {
            get
            {
                return instance;
            }
        }       
    }
    
    class Program
    {
        static async Task Main(string[] args)
        {
                    
            var serviceProvider = new ServiceCollection()
            .AddSingleton(FileWriter.Instance)
            .AddSingleton(MSSQLHelper.Instance)
            .BuildServiceProvider();            

            var FileWrite = serviceProvider.GetService<FileWriter>();
            var MSSQL = serviceProvider.GetService<MSSQLHelper>();
            
             Task.Run(async () =>
            {
                await FileWrite.WriteAsync(CombineTipData, probc.ProbcName, DateTime.Today.ToString(), MSSQL);               

            }).Wait();
        }
    }
