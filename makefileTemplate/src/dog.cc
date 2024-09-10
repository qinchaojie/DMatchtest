#include "dog.h"
#include <stdio.h>
void dog::run()
{
    printf("dog run: I am dog!\n");
}

dog::dog()
{
    printf("dog born!\n");
}

dog::~dog(){
    printf("dog die!\n");
}