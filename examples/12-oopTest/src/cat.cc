#include "cat.h"
#include <stdio.h>
void cat::run()
{
    printf("cat run: I am cat!\n");
}

cat::cat(){
    printf("cat born!\n");
}

cat::~cat(){
    printf("cat die!\n");
}