#include "pig.h"
#include <stdio.h>
void pig::run()
{
    printf("pig run: I am pig!\n");
}
pig::pig(){
    printf("pig born!\n");
}
pig::~pig(){
    printf("pig die!\n");
}