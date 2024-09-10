&emsp;
# 如何正确的到处onnx
> https://www.bilibili.com/video/BV1Xw411f7FW?p=3&spm_id_from=pageDriver&vd_source=f00c0e55d0379144855afd14bd8d641c
<div align='center'>
    <image src='imgs/1.png' width=600>
</div>
&emsp;

# onnx转换代码
```python

import torch
class Model(nn.Module):
    def __init__(self):
        super().__init__()
        self.conv = nn.Conv2d(1,1,3,stride=1,padding=1,bias=True)
        self.conv.weight.data.fill_(0.3)
        self.conv.bias.data.fill_(0.2)
    def forward(self,x):
        x = self.conv(x)
        return x.view(x.shape[0], -1)
        # return x.view(int(x.size(0)),-1)
        # return x.view(-1, int(x.numel()/x.size(0)))

model = Model().eval()
x = torch.full((1,1,3,3),1.0)
y = model(x)

torch.onnx.export(model, (x,), 
    "test_1.onnx", 
    verbose=False)
```