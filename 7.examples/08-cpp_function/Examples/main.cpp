#include <stdio.h>
#include <iostream>

#include "add.hpp"
#include "minus.hpp"

int main(int argv, char**argc){
    int a=10;
    int b=5;
    printf("a+b=%d\n", add(a, b));
    printf("a-b=%d\n", minus(a, b));

    printf("********函数参数********\n");

    return 0;
}


// #include <stdio.h>
// #include <iostream>
// using namespace std;

// int addition(int a, int b) {
//     return (a + b);
// }

// int subtraction(int a, int b) {
//     return (a - b);
// }
// int(*myfunc)(int, int)  = subtraction;

// int operation(int x, int y, int(*functocall)(int, int)) {
//     int res;
//     res = (*functocall)(x, y);
//     return (res);
// }

// int main(){
//     int m, n;
//     m = operation(7, 5, addition);
//     n = operation(20, 10, myfunc);
//     cout << n << endl;

//     return 0;
// }
