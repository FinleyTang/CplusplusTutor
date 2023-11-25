//
// Created by ftang on 2023/11/25.
//
#include <string>
#include "Player.h"
#include <utility>

//Player::Player(float h, float w) {
//    this->height = h;
//    this->weight = w;
//}

//Player::Player(float h, float w) : height(h), weight(w) {
//    // 构造函数体
//}

float Player::getHeight() const {
    return height;
}

float Player::getWeight() const {
    return  weight;
}


void Player::setHeight(float h) {
    height = h;
}

void Player::setWeight(float w) {
    weight = w;
}

Player::Player(std::string name) {
    this->name  = std::move(name);
}

void Player::setAge(int a) {
    this->age = a;
}

std::string Player::getName() {
    return name;
}
