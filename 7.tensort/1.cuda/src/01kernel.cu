#include <iostream>
#include <cuda_runtime.h>
#include <device_launch_parameters.h>

__global__ void compute(float* a, float* b, float* c)
{
    int position = threadIdx.x;
    c[position] = a[position] * b[position];
}

int main()
{
    // 定义3个数组
    const int num = 3;
    float a[num] = {1, 2, 3};
    float b[num] = {5 ,7 ,9};
    float c[num] = {0};

    // 定义三个设备指针，device指针
    size_t size_array = sizeof(c);
    float* device_a = nullptr;
    float* device_b = nullptr;
    float* device_c = nullptr;

    // 分配设备空间，大小是size_array, 单位是byte
    cudaMalloc(&device_a, size_array);
    cudaMalloc(&device_b, size_array);
    cudaMalloc(&device_c, size_array);

    // 把数据冲host复制到device,其实就是主机复制到显卡
    // 复制的是a, b
    cudaMemcpy(device_a, a, size_array, cudaMemcpyHostToDevice);
    cudaMemcpy(device_b, b, size_array, cudaMemcpyHostToDevice);

    // 执行核函数，把结果放在c上
    compute<<<1, 3>>>(device_a, device_b, device_c);

    // 把计算后的结果c复制回主机上
    cudaMemcpy(c, device_c, size_array, cudaMemcpyDeviceToHost);

    // 查看主机上的c内容是多少
    for (int i = 0; i < num; ++i)
        printf("c[%d] = %f\n", i, c[i]);
    return 0;
}