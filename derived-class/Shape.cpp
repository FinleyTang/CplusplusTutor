//
// Created by ftang on 2023/11/26.
//

#include "Shape.h"



int Shape::getArea() {
    return 0;
}

Rectangle::Rectangle(int h, int w):m_height(h),m_width(w) {}

int Rectangle::getArea() {
    return m_height*m_width;
}
