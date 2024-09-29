#include <iostream>
using namespace std;
#include <cmath>
#include <math.h>

int main()
{   
    cout << "#########if else#############" << endl;
   int a = 5;
   if (a>5){
        std::cout << "a is greater than 5" << std::endl;
   }
   else if (a<5){
        std::cout << "a is less than 5" << std::endl;
   }
   else{
        std::cout << "a is equal to 5" << std::endl;
   }
    cout << "#########for and while#############" << endl;
    int sum = 0;
    for (int i =1; i<=100; i++){
        sum += i;
    }
    printf("for: sum is %d\n", sum);
    
    sum = 0;
    int i = 1;
    while (true){
        if (i <= 100){
            sum += i;
        }
        else break;
        i++;
    }
    printf("while: sum is %d\n", sum);

    sum = 0;
    i = 1;
    do{
        sum += i;
        i++;
    }while( i > 100);
    printf("do while: sum is %d\n", sum);

    cout << "######### switch case #############" << endl;
    int choice = 1;
    switch (choice)
    {
    case 1:
        std::cout << "choice 1" << std::endl;
        break;
    case 2:
        std::cout << "choice 2" << std::endl;
        break;
    default:
        std::cout << "choice other" << std::endl;
        break;
    }

    return 0;
}