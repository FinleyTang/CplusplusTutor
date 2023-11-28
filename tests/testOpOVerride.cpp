//
// Created by ftang on 2023/11/28.
//

#include "testOpOVerride.h"
#include "../OperatorOverrideDemo/Vector.h"
#include <iostream>

void test_Operator_override(){
    std::cout << "=======================test_Operator_override================="<<std::endl;
    Vector vector = Vector(3,5);
    Vector vector1 = Vector(4,4);
    Vector vector2 = vector + vector1;
    std::cout <<vector2.get_x()<< std::endl;

}
