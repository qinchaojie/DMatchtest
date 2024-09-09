
#include <stdio.h>
#include <iostream>


typedef unsigned int	UTF32;	/* at least 32 bits */
typedef unsigned short	UTF16;	/* at least 16 bits */
typedef unsigned char	UTF8;	/* typically 8 bits */
typedef unsigned char	Boolean; /* 0 or 1 */
typedef char VertexType[5]; // 定义数组

int main(){
    std::cout << "######### struct ############" << std::endl;

    
    struct person
    {
        int age;
        char name[3];
        int x,y;
    }p1, p2;
    
    person p3, p4;
    p1.age = 10;
    p3.age = 20;

    printf("%d, %d\n", p1.age, p3.age);
    
    std::cout << "######### struct 数组和嵌套 ############" << std::endl;
    struct fram{
        unsigned int cx,cy;
    };

    struct Frame{
        fram f;
        unsigned int w,h,id;
    } Frame1;

    Frame Frame2[10];

    for (int i =0; i<10; i++){
        Frame2[i].f.cx = i;
        Frame2[i].f.cy = i;
        Frame2[i].w = i;
        Frame2[i].h = i;
    }

    int id = 5;
    printf("%d, %d, %d, %d\n", Frame2[id].f.cx, Frame2[id].f.cy, Frame2[id].w, Frame2[id].h);

    std::cout << "#########struct 指针###########" << std::endl;
    Frame *pFrame = &Frame1;
    Frame (*pFrame2)[10] = &Frame2;

    pFrame->f.cx = 100;
    pFrame->f.cy = 100;
    pFrame->w = 100;
    pFrame->h = 100;
    printf("%d, %d, %d, %d\n", pFrame->f.cx, pFrame->f.cy, pFrame->w, pFrame->h);

    std::cout << "#########枚举###########" << std::endl;



    std::cout << "#########unions typedef###########" << std::endl;
    UTF32 a = 10; // typedef 
    printf("%d\n", a);

    // 更改函数的名字
    typedef struct {
        int a;
        int b;
    } AA;

    // 计算 1/sqrt（x）
    float x = 2;
    float xhalf = 0.5f * x;
    union{
        float x;
        int i;
    }u;
    u.x = x;
    u.i = 0x5f3759df - (u.i >> 1);
    // Newton-Raphson 算法
    u.x = u.x * (1.5f - xhalf * u.x * u.x);
    u.x = u.x * (1.5f - xhalf * u.x * u.x);

    printf("%f\n", u.x);

    return 0;
}