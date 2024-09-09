#include <stdio.h>
#include <iostream>


class System{

    public:
        int a = 1;
        System(){};
        System(int x){
            a = x;
            printf("value of a: %d\n", a);
        };
        
    private:
        int mb = 2;
    
};

int main(int argv, char**argc){

    System system1;
    System system2(4);
    
    return 0;
}