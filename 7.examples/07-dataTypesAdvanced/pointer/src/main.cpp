#include <iostream>
using namespace std;
#include <cmath>
#include <math.h>

int main()
{   
    // cout << "######### 初始化 #############" << endl;
    // int array[5];
    // int * pInt = array; // 指针指向数组
    // int (*pInt2)[5] = &array;  // 指针指向数组
    // printf("%p\n", pInt);
    // printf("%p\n", pInt2);
    
    // cout << "######### 指针的运算 #############" << endl;
    // int a = 10;
    // int * pa = &a;
    // printf("%-17s: %p\n", "value of pInt", pa);
    // printf("%-17s: %p\n", "value of pInt+=1", pa+=1); //
    // printf("%-17s: %p\n", "value of ++pInt", ++pa);
    // printf("%-17s: %p\n", "value of pInt+1", pa+1); // 未改变pa值

    // cout << "######### 二级指针 #############" << endl; 
    
    // int b = 10;
    // int * pb = &b;
    // int** ppb = &pb;

    // printf("value of pb :%p\n", pb);
    // printf("address of pb :%p\n", &pb);
    // printf("value of ppb :%p\n", ppb);

    // printf("value of pointer by ppb :%p\n", *ppb);

    // cout << "######### 指针常量和常量指针 #############" << endl; 
    // int c = 10;
    // int const d = 10;

    // int const * pc1 = &c;
    // int * const pc2 = &c;
    // int const * const pc3 = &c; //所有的都不能改变

    // // *pc1 = 20; // 错误，不能改变指向的值
    // // pc2 = &d; // 错误，不能改变指指针的值

    // cout << "######### 一维数组指针 #############" << endl; 
    // int arr[5];
    // int (&refarr)[5] = arr; // 数组引用
    // for(int i=0; i<10; i++){
    //     array[i] = 33+i;
    // }

    // int * parr = arr;
    // printf("value of ptr  : %p\n", arr);
    // printf("value of array: %p\n\n", arr);
    // printf("value of array[0]  : %d\n", arr[0]);
    // printf("address of array[0]: %p\n", &arr[0]);

    // *parr = 100;
    // ++parr;
    // *parr = 200;
    // parr = &arr[2];
    // *parr = 300;
    // arr[3] = 400;
    // *(arr + 4) = 500;

    // for (int i=0; i<5; i++){
    //     printf("value of array[%d]  : %d\n", i, arr[i]);
    // }
    // cout << "######### ----- #############" << endl; 

    // int i = 0;
    // for (int * p = arr; 1>0; p++){
    //     if (i<5)
    //         printf("value of array[%d]  : %d\n", i, *p);
    //     i++;
        
    // }

    cout << "######### 多维数组指针 #############" << endl; 
    int arr2[3][2][2] = {0,1,2,3,4,5,6,7,8,9,10,11};

    // address of block 0; int*[2][2] const
    printf("value of arr2  : %p\n", arr2);
    printf("value of arr2+1: %p\n", arr2+1);
    // interval = 4*4Bytes = 16Bytes
    printf("interval = %d\n\n", 4*4);

    // address of block 1, row 0; int*[2] const
    printf("value of arr2[1]  : %p\n", arr2[1]);
    printf("value of arr2[1]+1: %p\n", arr2[1]+1);
    // interval = 2*4Bytes = 8Bytes
    printf("interval = %d\n\n", 2*4);


    // address of block 2, row 1, col 0; int* const
    printf("value of arr2[2][1]  : %p\n", arr2[2][1]);
    printf("value of arr2[2][1]+1: %p\n", arr2[2][1]+1);
    // interval = 1*4Bytes = 4Bytes
    printf("interval = %d\n\n", 1*4);


    // Syntatic Sugar 语法糖
    printf("value of arr2[2][0][0]  : %d\n", arr2[2][0][1]);
    printf("Syntatic Sugar: equivalent to:\n");
    printf("value of *(arr2[2][0]+1): %d\n", *(arr2[2][0]+1));
    return 0;
}