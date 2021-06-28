## mysql語法順序與執行順序  

語法順序:

1.  SELECT[DISTINCT]
2.  FROM
3.  WHERE
4.  GROUP BY
5.  HAVING
6.  UNION
7.  ORDER BY

執行順序  

1.  FROM
2.  WHERE
3.  GROUP BY
4.  HAVING
5.  SELECT
6.  DISTINCT
7.  UNION
8.  ORDER BY


原文網址：https://kknews.cc/news/zmvrbbp.html



## Mysql Lock
  
目的：協調多個程式存取資料的機制。

1.  表鎖：開銷小，加鎖快；不會出現死鎖；鎖定粒度大，發生鎖衝突的概率最高,併發度最低。  
2.  列鎖：開銷大，加鎖慢；會出現死鎖；鎖定粒度最小，發生鎖衝突的概率最低,併發度也最高。

### 資料表鎖
  https://xyz.cinc.biz/2013/04/mysql-lock-tables.html

## Mysql交易功能Transaction  
  
MySQL 常用的兩個資料表引擎：MyISAM、InnoDB，(MyISAM 不支援交易功能)  
  
  
### 交易功能4個特性 (ACID)  

1.  Atomicity (原子性、不可分割)：交易內的 SQL 指令，不管在任何情況，都只能是全部執行完成，或全部不執行。若是發生無法全部執行完成的狀況，則會回滾(rollback)到完全沒執行時的狀態。
2.  Consistency (一致性)：交易完成後，必須維持資料的完整性。所有資料必須符合預設的驗證規則、外鍵限制...等。
3.  Isolation (隔離性)：多個交易可以獨立、同時執行，不會互相干擾。這一點跟後面會提到的「隔離層級」有關。
4.  Durability (持久性)：交易完成後，異動結果須完整的保留。  
  
### 開始進入交易模式  
SQL 指令：START TRANSACTION 或 BEGIN  
  
### 結束交易模式
交易完成：使用 COMMIT 儲存所有變動，並結束交易。  
交易過程異常：使用 ROLLBACK 回滾，取消交易，還原到未進行交易的狀態。(若交易過程連線中斷，沒 COMMIT 提交的變更，亦會如同執行 ROLLBACK 取消交易)  


## Awesome Mysql  
https://github.com/shlomi-noach/awesome-mysql#gui

## Anemometer(php)  
https://github.com/box/Anemometer
