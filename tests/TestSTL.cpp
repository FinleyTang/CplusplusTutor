//
// Created by ftang on 2023/11/29.
//
#include <vector>
#include <deque>
#include <list>
#include <iostream>
#include "TestSTL.h"
void test_deque() {
    std::deque<int> deq;
    deq.push_back(9);
    deq.push_back(8);
    for (auto it: deq) {
        std::cout << it << std::endl;
    }
    for (auto it = deq.begin(); it != deq.end(); it ++){
        std::cout << *it <<std::endl;
    }

}

void test_vector() {
    std::vector<int> vec;
    vec.push_back(3);
    vec.push_back(5);
    for (const auto &item: vec) {
        std::cout << item<< std::endl;
    }
    for (auto it = vec.begin(); it !=vec.end(); it++){
        std::cout << *it << "\n";
    }
}

void test_list() {
    std::list<float> l1;
    l1.push_back(1.5);
    l1.push_back(2.3);
    for (auto it: l1) {
        std::cout << it <<std::endl;
    }

    for(auto it = l1.begin(); it!=l1.end(); it++){
        std::cout << *it << std::endl;
    }

}
