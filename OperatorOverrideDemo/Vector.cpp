//
// Created by ftang on 2023/11/28.
//

#include "Vector.h"

Vector::Vector(int x = 0, int y = 0) : m_x(x), m_y(y) {}

// + 运算符重载为成员函数
Vector Vector::operator+(const Vector& v) {
    return Vector(m_x + v.m_x, m_y + v.m_y);
}


int Vector::get_x() {

    return m_x;
}

int Vector::get_y() {

    return m_y;
}