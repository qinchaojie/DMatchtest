#include <stdio.h>


__global__ void printHello_from_gpu(){

    printf("hello\n");
}


int main(){

    printHello_from_gpu<<<4,4>>>();
    cudaDeviceSynchronize(); // 同步
    
    return 0;
}
