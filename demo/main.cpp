#include <stdio.h>
#include <iostream>
#include "add.h"

int main (int argc , char* argv[]){
    int a = 1;
    int b = 2;
    std::string c = "hello world";

    int d = add(a,b,c);
    printf("%d + %d = %d\n", a, b, d);
    return 0;
}
