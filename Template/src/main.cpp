#include <stdio.h>
#include "cat.h"




int main(int argc, char** argv){
    cat c;
    c.run();
    int a = 1;
    int b = a +1;
    printf("%d\n", b);
    printf("run!!\n");
    return 0;
}
