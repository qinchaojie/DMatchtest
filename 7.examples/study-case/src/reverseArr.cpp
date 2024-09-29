#include "reverArr.hpp"


void reverseArr(int num, int* arr){
    int tem;

    for (int i=0; i<num/2; i++){
        tem = arr[i];
        arr[i] = arr[num-i-1];
        arr[num-i-1] = tem;
    }

}

void reverseArr(int num, float* arr){
    int tem;

    for (int i=0; i<num/2; i++){
        tem = arr[i];
        arr[i] = arr[num-i-1];
        arr[num-i-1] = tem;
    }

}