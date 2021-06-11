## Bin to Hex  
  
     static void Main(string[] args)
     {
                //string[] files = Directory.GetFiles("./pkg.zip");
                string file = "./ubuntu1804-pytorch.tar";
                string EncryptFileName = "./ubuntu1804-pytorch";
                int j = 1;
                // foreach (string file in files)
                // {
                // Method 1. Binary To Hex
                FileStream fs = new FileStream(file, FileMode.Open);
                int hexIn;
                StringBuilder hex = new StringBuilder();
                using(var writer = File.CreateText(EncryptFileName)){
                    for (int i = 0; (hexIn = fs.ReadByte()) != -1; i++){
                        writer.Write(string.Format("{0:X2}", hexIn));
                    }
                }
                // Method 2. Binary To Hex
                // for (int i = 0; (hexIn = fs.ReadByte()) != -1; i++)
                // {
                //     hex.Append(string.Format("{0:X2}", hexIn));
                // }
                // File.AppendAllText("./" + EncryptFileName , hex.ToString());
            
                // Method 1. Hex To Binary
            
      }
       
    
  
  
## Hex to Bin  
  Method 1.  StreamReader & Buffer  
  
     try
     {
            string[] all_path_2 = Directory.GetFiles(@"\\10.92.129.40\217_backup\\20210412_ascii\data2");
            for (int path_i = 0; path_i < all_path_2.Length; path_i++)
                {
                    FileStream fs = new FileStream(all_path_2[path_i].Replace("data2", "data2_output").Replace(".txt", ""), FileMode.Create, FileAccess.ReadWrite);

                    
                    StreamReader reader = new StreamReader(all_path_2[path_i]);                    
                    WriteHexStringToFile(reader, fs);


                    reader.Close();
                    fs.Close();
                }
            }
     catch (Exception ex)
     {
             Console.WriteLine(ex.Message);
     }
       
       
     public static void WriteHexStringToFile(StreamReader reader, FileStream fs)
     {

            var twoCharacterBuffer = new StringBuilder();
            var oneByte = new byte[1];
            long Tchar = 0;
            while (reader.Peek() > 0)
            {
                char c = (char)reader.Read();
                if (c != ' ')
                {
                    twoCharacterBuffer.Append(c);

                    if (twoCharacterBuffer.Length == 2)
                    {
                        oneByte[0] = (byte)Convert.ToByte(twoCharacterBuffer.ToString(), 16);
                        fs.Write(oneByte, 0, 1);
                        twoCharacterBuffer.Clear();
                    }
                }
                Tchar++;
            }

      }
