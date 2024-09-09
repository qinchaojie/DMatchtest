#include <iostream>
using namespace std;
#include <cmath>
#include <math.h>

int main()
{   
    cout << "######### 初始化 #############" << endl;
    int array[5];
    int array1[5] = {1,2,3,4,5};
    char array2[] = {'a', 'b', 'c', 'd', 'e'};
    for (int i=0; i<5; i++){
        printf("%d ", array[i]);
        printf("%d ", array1[i]);
        printf("%c ", array2[i]);
    }
    cout << "######### 读取和改变 #############" << endl;
    
    for (int i=0; i<5; i++){
        array1[i] = i + 20;
    }
    for(int i=0; i<5;i++){
        printf("%d ", array1[i]);
    }
    printf("\n");
    
    cout << "######### 字符串 #############" << endl;
    char str1[] = {'H', 'e','l','l','o','\0'};
    char str2[] = {'H', 'e','l','l','o'}; // 有的编译器或者C++版本中，如果没有 `\0`, 则会一直打印后面的字符
    char str3[] = "Hello"; // 字符串常量初始化，自动加 \0

    std::cout << str1 << std::endl;
    std::cout << str2 << std::endl; 
    std::cout << str3 << std::endl;

    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);
    printf("str3: %s\n", str3);

    cout << "######### 多维数组 #############" << endl;
    int array3[3][2][2] = {1,2,3,4,5,6,7,8,9,10,11,12};

    for (int i=0; i<3; i++){
        for (int j=0; j<2; j++){
            for (int k=0; k<2; k++){
                printf("%4d ", array3[i][j][k]);
            }
        }
        printf("\n");
    }
    printf("\n");

    cout << "######### 练习 #############" << endl;
    float x[3] = {1,2,3};
    float y[3] = {4,5,6};
    float z[3] = {7,8,9};

    float xy[3];
    for (int i=0; i<3; i++){
        xy[i] = x[i] + y[i];
    }
    for (int i=0; i<3; i++){
        printf("%f ", xy[i]);
    }
    printf("\n");
    
    // 矩阵乘法
    cout << "######### 矩阵乘法 #############" << endl;

    float sum;
    for (int i=0; i<3; i++){
        sum  = sum + (x[i] * x[i]);
    }
    int a_ = sqrt(sum);

    for (int i=0; i<3; i++){
        z[i] = x[i] / a_;
    }
    for (int i=0; i<3; i++){
        printf("%f ", z[i]);
    }

    return 0;
}