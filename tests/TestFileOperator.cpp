//
// Created by ftang on 2023/11/27.
//

#include "TestFileOperator.h"
#include <fstream>
#include <iostream>
#include <string>

void test_file_read_by_line(){
    std::string line;
    std::ifstream infile("C:\\Users\\ftang\\CLionProjects\\CplusplusTutor\\tests\\CMakeLists.txt");
    while (std::getline(infile, line)) {
        std::cout << line << std::endl;
    }
}

void test_file_write() {
    std::ofstream outfile("C:\\Users\\ftang\\CLionProjects\\CplusplusTutor\\tests\\out.txt");
//    for (int i = 0; i < 10; ++i) {
//        string s_i = std::string(i);
//    }
    char*  str = "hello ofstream!\n";
    outfile.write(str, 16);
    outfile << "c++ style " <<std::endl;
}
