//
// Created by ftang on 2023/11/25.
//

#ifndef CPLUSPLUSTUTOR_PLAYER_H
#define CPLUSPLUSTUTOR_PLAYER_H


class Player {
private:
    float height;
    float weight;
public:
    Player(float h, float w);
    float getHeight();
    float getWeight();
    void setHeight(float h);
    void setWeight(float w);


};


#endif //CPLUSPLUSTUTOR_PLAYER_H
