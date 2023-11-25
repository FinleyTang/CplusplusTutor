#include <iostream>
#include "hello/hello.h"
#include "TestStatic.h"
#include "ClassDemo/Player.h"
// 在类或结构体之外声明的 STATIC 意味着你声明的 static 只对该翻译单元可见，也就是说，只对与声明静态对象相同的 cpp 文件中的代码可见。
// 这种情况下在main.cpp中也定义一个s_var是可行的
//static  int s_var = 1;    //可行

// 如果没有static，它将具有通用链接性（可见性），因此与其链接起来的任何代码都可以访问它， 重复定义会报错（它们可能需要声明为extern）
//int s_var = 1;  //会报错

// 如果确实想要访问TestStatic中的s_var； 可以使用extern
extern  int s_var;

int main() {
    std::cout << "Hello, World!" << std::endl;
    int result = add(3, 4);
    std::cout << result << std::endl;

    std::cout << s_var << std::endl;

    //测试extern
    std::cout << s_var1<< std::endl;

    Player player =  Player(180.4, 88.9);
    std::cout << player.getHeight() << std::endl;
    player.setHeight(189.2);
    std::cout << player.getHeight() << std::endl;



    return 0;
}
