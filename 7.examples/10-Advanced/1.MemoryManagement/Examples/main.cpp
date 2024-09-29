#include <stdio.h>
#include <iostream>
using namespace std;

#include <stdlib.h>

#define OVERFLOW -2
typedef int cudaError_t;

struct Camera{
    double focal;
    double fx;
    double fy;
    double cx;
    double cy;
};

void printArray(int n, int* ptr){
    for(int i=0; i<n; i++)
        printf("%d ", ptr[i]);
    printf("\n");
}
cudaError_t normMalloc(void* pdev, size_t size){
    // void * pdev = ptr
    pdev = (int*)malloc(size);
    printf("valueof of pdev : %p\n", pdev);
    printf("address of pdev : %p\n", &pdev);
    return 0;
}

cudaError_t cudaMalloc(void** ppdev, size_t size){
    // void** ppdev = (void *)&ptr
    *ppdev = malloc(size);

    if (!(*ppdev)){
        exit(OVERFLOW);
    } 
    
    return 0;
}

int main(int argv, char**argc){
    
    cout << "########malloc processing#########" << endl;
    // 分配内存
    int * ptr1 = (int*)malloc(sizeof(int)*5);
    if (ptr1 == NULL)
        cout << "malloc failed" << endl;
    else cout << "malloc success" << endl;
    free(ptr1);
    ptr1 = NULL;
    cout << "#########cuda malloc processed#########" << endl;
    int* ptr = NULL;
    cudaMalloc((void **) &ptr, sizeof(int));
    if(ptr) printf("malloc succeed!\n");
    else printf("malloc faled!\n");
    printf("adress of ptr : %p\n", &ptr);
    free(ptr);
    ptr = NULL;
    cout << "#########理解性测试#########" << endl;
    char * pchar;
    printf("address of pchar : %p\n", &pchar);
    printf("value of pchar : %p\n", pchar);
    pchar = (char*)malloc(sizeof(char)*5); // 分配了一个内2存地址给它指向的位置
    printf("address of pchar : %p\n", &pchar);
    printf("value of pchar : %p\n", pchar);
    free(pchar);
    pchar = NULL;
    cout << "#########struct 指针 分配内存#########" << endl;
    Camera * pCamera;
    pCamera = (Camera*)malloc(sizeof(Camera));
    if (pCamera) printf("malloc succeed!\n");
    else printf("malloc faled!\n");
    pCamera->focal = 1.0;
    printf("focal : %f\n", pCamera->focal);
    free(pCamera);
    pCamera = NULL;
    
    cout << "#########realloc 改变内存长度#########" << endl;
    char * pchar2;
    pchar2 = (char*)malloc(sizeof(char)*5);
    if (pchar2) printf("Malloc succeed!\n");
    else printf("Malloc faled!\n");
    pchar2 = (char*)realloc(pchar2, sizeof(char)*10);
    if (pchar2) printf("reMalloc succeed!\n");
    else printf("reMalloc faled!\n");
    
    cout << "#########memcpy#########" << endl;
    // 复制地址
    int pSrc[] = {1, 2, 3, 4, 5};

    int* pDst1 = (int*)malloc(5*sizeof(int));
    memcpy(pDst1, pSrc, 3*sizeof(int));
    printArray(3, pDst1);


    int* pDst2 = (int*)memcpy(pDst1, pSrc, 3*sizeof(int));
    printArray(3, pDst2);
    printf("value of pDst1: %p\n", pDst1);
    printf("value of pDst2: %p\n", pDst2);

    free(pDst1);
    pDst1 = NULL;

    cout << "#########c++ new delect 牛逼#########" << endl;

    float* pfloat = new float;
    if (pfloat) printf("new succeed!\n");
    else printf("new faled!\n");
    delete pfloat;

    float* pfloat2 = new float[5];
    if (pfloat2) printf("new succeed!\n");
    else printf("new faled!\n");
    delete[] pfloat2;
    return 0;

}

