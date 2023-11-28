//
// Created by ftang on 2023/11/27.
//

#ifndef CPLUSPLUSTUTOR_PAIR_H
#define CPLUSPLUSTUTOR_PAIR_H

template <typename T>
class Pair {
private:
    T m_first;
    T m_second;

public:
    Pair(T first, T second);
    T get_first();
    T get_second();

};





#include "Pair.cpp"

#endif //CPLUSPLUSTUTOR_PAIR_H
