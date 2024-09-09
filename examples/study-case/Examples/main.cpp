#include <stdio.h>
#include "add.hpp"
#include <iostream>
using  namespace std;
#include "reverArr.hpp"  // 反转数组 int

int main()
{   
    std::cout << "反转数组" << std::endl;
    int arr[] = {1,2,3,4,5};
    for (int i = 0; i < 5; i++)
    {
        std::cout << arr[i]<< " ";
    }

    reverseArr(5, arr);
    std::cout << std::endl;
    for (int i = 0; i < 5; i++)
    {
        std::cout << arr[i]<< " ";
    }
    std::cout << std::endl;
    return 0;
}