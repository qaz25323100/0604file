## pytorch Dataset and DataLoader
  
https://www.cnblogs.com/dogecheng/p/11930535.html
  
## 增加pytorch效能
  
https://hackmd.io/@-CDCNK_qTUicXsissQsHMA/SJ6Gjpxv8#%E5%A6%82%E6%9E%9C%E7%94%A8%E5%88%B0-DataLoader-%E8%A8%98%E5%BE%97%E8%A8%AD-pin_memoryTrue  
  
## CustomDataset.py
  
     import os
     import pandas as pd
     from torch.utils.data import Dataset
     import glob
     
     class CustomImageDataset(Dataset):
        def __init__(self, data_root):
            image_paths = glob.glob(os.path.join(data_root, '*.png'))
            self.images = [Image.open(path).copy() for path in image_paths]
    
        def __len__(self):
            return len(self.images)
    
        def __getitem__(self, index):
            return self.images[index]
   
 ## 測試
