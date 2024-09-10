# 使用TensorRt加载onnx模型的步骤其实是很固定的,根据官方例呈给出的示范,加载一个onnx的模型分为以下几步
- 创建builder(构建器)
- 创建网络定义：builder —> network
- 配置参数：builder —> config
- 生成engine：builder —> engine (network, config)
- 序列化保存：engine —> serialize
- 释放资源：delete

# 