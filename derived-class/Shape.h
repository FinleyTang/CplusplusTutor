//
// Created by ftang on 2023/11/26.
//

#ifndef CPLUSPLUSTUTOR_SHAPE_H
#define CPLUSPLUSTUTOR_SHAPE_H


class Shape {

public:
    virtual int getArea();
};



class Rectangle : public Shape{
private:


    int m_height;
    int m_width;
public:
    Rectangle(int h, int w);
    int getArea() override;
};

#endif //CPLUSPLUSTUTOR_SHAPE_H
