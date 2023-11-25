//
// Created by ftang on 2023/11/25.
//

#include "Player.h"

Player::Player(float h, float w) {
    this->height = h;
    this->weight = w;
}

float Player::getHeight() {
    return height;
}

float Player::getWeight() {
    return  weight;
}


void Player::setHeight(float h) {
    height = h;
}

void Player::setWeight(float w) {
    weight = w;
}
