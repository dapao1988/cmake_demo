/*
 * add.c
 *  Copyright © 2018年 rokid. All rights reserved.
 *
 *  Created on: Aug 2, 2019
 *      Author: Wenbing.Wang
 */
#include <iostream>
#include "add1.h"

int add1(int a, int b, std::string c) {
    printf("add1 called\n");
    return add2(a,b,c);
}
