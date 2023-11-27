//
// Created by ftang on 2023/11/27.
//
#include "../template-demo/add.h"
#include "TestTemplate.h"
#include <iostream>

void test_template_func(){
    int result1 = add(3,4);
    std::cout << result1<< std::endl;

    float  result2 = add(4.5, 3.7);
    std::cout << result2 <<std::endl;
}