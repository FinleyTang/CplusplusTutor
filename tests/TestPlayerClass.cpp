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


    auto* player1 = new Player("alic");
    player1->setAge(18);
    player1->setHeight(167);
    player1->setWeight(100);
    std::cout << player1->getName() << std::endl;
    std::cout<< player1->getWeight()<<std::endl;

}