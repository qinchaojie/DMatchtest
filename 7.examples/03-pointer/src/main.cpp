#include <stdio.h>

#define PI 3.1415926
int main(){
    int a = 555; // 定义
    int& b = a; // 引用
    int* ptra = &a; //指针创建
    int c = a;

    // &a 取变量 a 的地址
    printf("Value of a: %d\n", a);
    printf("Address of a: %p\n", &a); 
    printf("\n");

    // &b 引用，b 相当于是 a 的别名，是同一块内存的数据
    printf("Value of b: %d\n", b);    
    printf("Address of b: %p\n", &b);
    printf("\n");

    // c 是另外声明的变量，只是把 a 的值赋给 c
    printf("Value of c: %d\n", c);
    printf("Address of c: %p\n", &c);
    printf("\n");

    printf("Value of ptr: %p\n", ptra); //指针的值是a的地址
    printf("Address of ptr: %p\n", &ptra); // & 取 ptra 的内存地址，
    printf("Value pointed by ptr: %d\n", *ptra); // 取 ptra 指向的值

    // 宏常量 define
    const int d = 10; //不能修改
    
    printf("d = %f\n", d * PI);

    // auto
    
    return 0;
}