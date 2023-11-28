//
// Created by ftang on 2023/11/28.
//

#ifndef CPLUSPLUSTUTOR_VECTOR_H
#define CPLUSPLUSTUTOR_VECTOR_H


class Vector {
private:
    int m_x;
    int m_y;

public:
    Vector(int x , int y);
    Vector operator+(const Vector& v);
    int get_x();
    int get_y();

};




#endif //CPLUSPLUSTUTOR_VECTOR_H
