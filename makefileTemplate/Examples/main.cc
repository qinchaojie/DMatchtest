#include <stdio.h>

#include "pig.h"
#include "cat.h"
#include "dog.h"

int main(int argc, char **argv){
    printf("这是一个测试的项目！\n");

    pig p;
    p.run();

    dog d;
    d.run();

    cat c;
    c.run();
    
    return 0;
}
