# Keras
## ResNet50 + KMeans



## 擷取特定層

    base_model = keras.models.load_model('./ml-data/ResNet50_Weights/weights0607-57-1.69.hdf5')
    model = Model(inputs=base_model.input,outputs=base_model.get_layer('activation_48').output)

## EWGWEGWEG

