## Mysql交易功能Transaction  
  
MySQL 常用的兩個資料表引擎：MyISAM、InnoDB，(MyISAM 不支援交易功能)  
  
### 交易功能4個特性 (ACID)  

1.  Atomicity (原子性、不可分割)：交易內的 SQL 指令，不管在任何情況，都只能是全部執行完成，或全部不執行。若是發生無法全部執行完成的狀況，則會回滾(rollback)到完全沒執行時的狀態。
2.  Consistency (一致性)：交易完成後，必須維持資料的完整性。所有資料必須符合預設的驗證規則、外鍵限制...等。
3.  Isolation (隔離性)：多個交易可以獨立、同時執行，不會互相干擾。這一點跟後面會提到的「隔離層級」有關。
4.  Durability (持久性)：交易完成後，異動結果須完整的保留。  
  
開始進入交易模式  
SQL 指令：START TRANSACTION 或 BEGIN  

## Awesome Mysql  
https://github.com/shlomi-noach/awesome-mysql#gui

## Anemometer(php)  
https://github.com/box/Anemometer
