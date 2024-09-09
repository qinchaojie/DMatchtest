#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
    printf("10的进制转换");
    printf("十进制:%d\n", 10); //十进制
    printf("十六进制:%x\n", 10); //十六进制
    printf("八进制:%o\n", 10); //八进制
    
    printf("%f\n", 3.1415926); //f/lf 浮点数float double
    printf("%e\n", 3.1415926); //科学计数法

    printf("%c\n", 'a'); //字符
    printf("%s\n", "hello world"); //字符串

    int a = 10;
    printf("%p\n", &a); //地址

    float pi = 3.1415926;
    printf("%f\n", pi);
    printf("%6.2f\n", pi);
    printf("%6.3f\n", pi); // right 宽度6位，保留2位小数
    printf("%-6.3f\n", pi); // 左对齐 宽度6位，保留2位小数

    printf("%o\n", 10);
    printf("%#o\n", 10);


    printf("%f\n", 3.1415926);
    // * 代替最小输出宽度
    printf("%*f\n", 10, 3.1415926);
    // * 代替最小输出宽度和精度, 下面两种写法等同
    printf("%*.*f\n", 10, 3, 3.1415926);
    printf("%10.3f\n", 3.1415926);

    // long c;
    // scanf("%9ld", &c);
    // printf("%ld\n", c);

    int d,e,f;
    scanf("%d %d %d", &d, &e, &f);
    printf("%d %d %d\n", d, e, f);

    // c++ out 

    return 0;
}