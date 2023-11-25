//
// Created by ftang on 2023/11/25.
//
#include "../ClassDemo/Player.h"
#include <iostream>
void testPlayer(){
    Player player =  Player(180.4, 88.9);
    std::cout << player.getHeight() << std::endl;
    player.setHeight(189.2);
    std::cout << player.getHeight() << std::endl;
}