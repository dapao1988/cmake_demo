#include <stdio.h>
#include <iostream>
#include "add.h"
#include <stdlib.h>

int main (int argc , char* argv[]){
    int a = 1;
    int b = 2;

    printf ("argc=%d", argc);
    if (argc >= 3) {
        a = atoi(argv[1]);
        b = atoi(argv[2]);
    }
    std::string c = "hello world";

    int d = add(a,b,c);
    printf("%d + %d = %d\n", a, b, d);
#ifdef DEBUG
    printf ("main demo DEBUG is on!!!!\n");
#endif
    return 0;
}
