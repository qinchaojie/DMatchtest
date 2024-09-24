#include <stdio.h>

int main()
{
    int array[10];
    for(int i=0; i<10; i++){
        array[i] = 33+i;
    }

    int* ptr = array; 

    printf("value of ptr  : %p\n", ptr);
    printf("value of *ptr  : %d\n", *ptr);
    printf("value of array: %p\n\n", array);

    printf("value of array[0]  : %d\n", array[0]);
    printf("address of array[0]: %p\n", &array[0]);

    return 0;
}