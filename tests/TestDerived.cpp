//
// Created by ftang on 2023/11/26.
//

#include "TestDerived.h"
#include "../derived-class/Shape.h"
#include <iostream>

void testShape(){
    printf("=====================testShape=======================\n");
    Rectangle rectangle = Rectangle(3,4);
    Shape& shape = rectangle;
    std::cout<< shape.getArea() <<std::endl;
}