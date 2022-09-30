# Anritsu讀檔機制
**寫到anritsu Setting檔的comport，是否會寫到QCA9377_Control_Settings.xml裡面(待確認)**

    
# GoldenBin
> 需將VT420_goldenBoardData_20210324.bin放置 **程式目錄** 及 **程式目錄\{Fixture}\CP\SRW\QCA9377\\**  
> 如: **D:\TE\Setting** and **D:\TE\Setting\Fixture_1\CP\SRW\QCA9377**

## GoldenBin需要設定MD5
> 如VT420_goldenBoardData_20210324.bin (WIFI golden bin) 的特徵值是 : f005a84ccc6a2af20b3d5ff54ee543b8  
> 更換新的GoldenBin，請務必更換Setting.ini的特徵值

## QCA9377_Control_Settings

> Anritsu目前是使用 **程式目錄\{Fixture}\CP\SRW\QCA9377\QCA9377_Control_Settings.xml**  
> 根據使用場景把底下的Files複製成QCA9377_Control_Settings.xml

- [x] QCA9377_Control_Settings_XTAL_CAL 第一次XTAL calibration
- [x] QCA9377_Control_Settings_Test Golden  第一次測試用WIFI golden bin file
- [x] QCA9377_Control_Settings_XTAL_OLPC_CLPC_CAL  如果第一次測試fail，就做第二次XTAL/OLPC/CLPC calibration
- [x] QCA9377_Control_Settings_Test  第二次測試用重cal 的bin file

> Note : 上面四份control setting 裡面的setup差異如下  
> **a.	Calibration setting**  
> **RUN_XTAL_CAL,TRUE**  
> **RUN_OPEN_LOOP_CAL,FALSE**  
> **RUN_CLOSE_LOOP_CAL,FALSE**  
> **b.	Calibration setting**  
> **BROAD_DATA_FILE_NAME,VT420_goldenBoardData_20210324.bin**  


