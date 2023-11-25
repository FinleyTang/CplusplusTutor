//
// Created by ftang on 2023/11/25.
//
#include "../ClassDemo/Player.h"
#include <iostream>
#include <string>

void testPlayer(){
    std::string  name = "ftang";
    auto player =  Player(name);
    player.setHeight(189.2);
    player.setWeight(79.2);
    std::cout<< player.getName()<<std::endl;
    std::cout << player.getWeight() << std::endl;
    std::cout << player.getHeight() << std::endl;


}