> https://github.com/sangyc10/CUDA-code
# examples
```c++
#include <stdio.h>

// gpu执行
__global__ void printHello_from_gpu(){

    printf("hello\n");
}


int main(){

    printHello_from_gpu<<<4,4>>>(); // 16 线程, 4块， 4个线程
    cudaDeviceSynchronize(); // 同步
    
    return 0;
}
```
# 核函数
*核函数在gpu上并行执行
注意事项：
1. 核函数只能访问GPU内存
2. 核函数不能使用变长参数
3. 核函数不能使用静态变量
4. 核函数不能使用函数指针
5. 核函数具有异步性
```c++
__global__ void kernel_function(arg){

    // .....
}
```

