//
// Created by ftang on 2023/11/25.
//
#include <string>
#ifndef CPLUSPLUSTUTOR_PLAYER_H
#define CPLUSPLUSTUTOR_PLAYER_H

class Player {
private:
    float height;
    float weight;
    std::string name;
    int age;
public:
    explicit Player(std::string name);
    float  getHeight() const;
    float getWeight() const;
    void setHeight(float h);
    void setWeight(float w);
    void setAge(int age);
    std::string getName();

};


#endif //CPLUSPLUSTUTOR_PLAYER_H
