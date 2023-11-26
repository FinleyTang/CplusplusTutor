//
// Created by ftang on 2023/11/25.
//

#include "TestString.h"
#include <iostream>
#include <string>
#include <cstring>

void testString(){
//    Declaring a C++ string object
    std::string  str;
//    Initializing a C++ string object
    std::string str1("call home!");
    std::string str2 = "send money";
    std::string  str3("OK");
    std::string str4(10, 'x');
    std::cout << str4 <<std::endl;
//    Assigning to a C++ string object
    str = "Hello";
    str = "otherString";
    std::cout << str <<std::endl;

//    Concatenating two C++ string objects
    str1 =  str1 + str2;
    std::cout << str1 <<std::endl;

//    Accessing a single character

    std::cout << str1.at(0)<<std::endl;
    std::cout <<str1[0]<< std::endl;
//    Comparing two C++ string objects
    if (str1 < str2){
        std::cout<< "str1 comes 1st" <<std::endl;
    }
    if (str1 == str2){
        std::cout<< "equal" <<std::endl;
    }
    if (str1 > str2){
        std::cout<< "str2 comes 1st" <<std::endl;
    }

}


void testCString(){
    printf("=====================testCString=======================\n");
//    Declaring a C-string variable
//    Initializing a C-string variable
    char str1[11] = "call home!";
    char str2[] = "send money ";
    char str3[] ={'O','K','\0'}; //char str3[] = "OK";
//    Assigning to a C-string variable
    strcat(str1, str2); //将 str2 追加到 str1 的末尾  //
    printf("str1: %s", str1);
    // 运行后发生： Process finished with exit code -1073741819 (0xC0000005) 实际是
    // 该异常代号对应“访问冲突”，即内存的读写权限冲突。
    //
    //发生这个问题时，一般意味着：
    //
    //访问数组的元素时发生了 越界；
    //将静态常量的地址赋给了普通指针（可读写的指针），随后又尝试写该普通指针指向的实体，这等价于写访问一个只读的内存块；
    //对空指针或野指针解引用 也有很大概率产生这个问题。
    //重新尝试，看是不是会栈溢出
//    char str4[10240]; // 长度为1024的字符数组
//    int i;
//    for (i = 0; i < 10240; i++) {
//        str4[i] = 'a';
//    }
//    str4[1024] = '\0'; // 手动添加字符串终止符
//    printf("%s\n", str1);
//    printf("test\n");
//    strcat(str1, str4);
//    printf("str1: %s",str1);
//    strcpy(str, strcat(str1, str2));
//    printf("str: %s\n", str);

}
