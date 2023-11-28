
## 使用CMake组织代码

在使用CMake组织代码时，你可以选择将目录内的代码生成为静态连接库（Static Library）或直接调用。这取决于你的具体需求和项目结构。

如果你希望将目录内的代码生成为静态连接库，可以使用CMake的add_library命令来创建一个静态库目标，并在外层的CMakeLists.txt文件中链接该静态库。这样做的好处是能够将代码逻辑封装在一个库中，使得外层调用更加简洁和模块化。

另一种方式是直接将目录内的代码添加到外层的源文件中，并在外层的CMakeLists.txt文件中对所有源文件进行编译和链接。这种方式适用于较小的项目或者你希望直接将目录内的代码嵌入到外层代码中的情况。

无论你选择哪种方式，都需要在CMakeLists.txt文件中正确设置源文件路径、包含目录和链接库等参数，以确保代码能够正确编译和链接。


##  this
在C++类中，this指针指向当前对象的地址。因此，this->height = h;和height = h;实际上是等价的，都用于将参数值h赋给类成员变量height。

区别在于，当成员变量和参数名称相同时，使用this->可以明确指示要操作的是成员变量，而不是参数。这在参数名称与成员变量名称相同或非常相似时特别有用。例如：

cpp
class MyClass {
public:
void setHeight(int height) {
this->height = height;
}
private:
int height;
};
在这个例子中，this->height明确指示要将参数height的值赋给类成员变量height，而不是将其赋给自身。

总的来说，使用this->是一种显式、明确的方式来引用成员变量，以避免命名冲突。但在大多数情况下，直接使用变量名（height = h;）已经足够清晰，并且更加简洁。

## Why must string variables be declared as "std: :string" and not "string" in C++?

在C++中，使用"std::string"语法表示字符串类属于"std"命名空间，即C++标准库的标准命名空间。使用"std::string"语法显式地将字符串类标识为标准库的一部分，避免与其他库或用户定义的类型发生命名冲突。

当你写"std::string"时，你正在指定"string"类是"std"命名空间的一部分，这有助于编译器理解你所指的"string"类。这一区别非常重要，因为不同命名空间或用户定义的代码中可能存在其他名为"string"的类型或类。

通过使用"std::string"，你确保编译器准确知道你所指的"string"类是哪一个，避免潜在的命名冲突，并确保代码的清晰性。

## readfile 
```shell
void test_file_read_by_line(){
    std::string line;
    std::ifstream infile("C:\\Users\\ftang\\CLionProjects\\CplusplusTutor\\tests\\CMakeLists.txt");
    while (std::getline(infile, line)) {
        std::cout << line << std::endl;
    }
}

```
结果如下：
![](2023-11-27%20215908.png)

## WriteFile
```c++
char*  str = "hello ofstream!\n";
outfile.write(str, 16);
outfile << "c++ style " <<std::endl;
```
这两种写法都可以用于将数据写入文件，但使用的方法有所不同。

**write() 函数：**

`char* str = "hello ofstream!\n";
outfile.write(str, 16);`
这个写法使用了 write() 函数，该函数接受一个指向字符数组的指针和要写入的字节数。在这个例子中，我们将字符串 "hello ofstream!\n" 写入文件，并指定写入的字节数为 16。如果字符串的长度小于 16，write() 函数将只写入字符串的一部分。

**<< 运算符：**


`outfile << "c++ style " << std::endl;`
这个写法使用了 << 运算符，它是 C++ 中流操作符的一种重载形式。这种写法更加简洁和直观，可以像向标准输出流 (std::cout) 输出数据一样，连续使用 << 运算符将数据写入文件。在这个例子中，我们依次写入字符串 "c++ style " 和换行符 std::endl。

无论使用哪种写法，当你完成文件写入操作后，记得关闭文件以确保数据被正确地写入到文件中。例如：


`outfile.close();`
请注意，第二种写法使用 std::ofstream 类的对象 outfile 来进行输出操作，而第一种写法使用的是 C 风格的字符指针。建议使用 C++ 的字符串类 std::string 来操作字符串，以更好地利用 C++ 的特性和避免潜在的问题。


## 模版函数

add.h:

```c++

#ifndef ADD_H
#define ADD_H

template <typename T>
T add(T num1, T num2);

#include "add.cpp"  // 包含模板函数的实现文件

#endif  // ADD_H
```
add.cpp:

```c++
template <typename T>
T add(T num1, T num2){
return  num1 + num2;
}
```

main.cpp:

```c++
#include <iostream>
#include "add.h"  // 包含头文件即可

int main() {
int sum1 = add(5, 10);
std::cout << "Sum: " << sum1 << std::endl;

    double sum2 = add(2.5, 1.8);
    std::cout << "Sum: " << sum2 << std::endl;

    return 0;
}
```

需要注意的是：这里写法和正常的写法不一样，add.cpp这里不能include "add.h"; 而add.h中反而要include add.cpp

通常情况下，模板的声明和定义会放在一起，都包含在头文件中。这样做有利于代码的可读性和维护性，并且也符合通常的编程实践。

在C++中，模板类和函数通常会同时包含在头文件中，而不像普通类或函数那样分成声明和定义两部分。这是因为模板的特殊性，需要在编译时生成实际的代码，所以编译器需要访问模板的定义以便实例化出相应的代码。

因此，通常情况下，模板类和函数的声明和定义会放在同一个头文件中，然后其他源文件可以直接包含该头文件来使用模板。这样可以确保模板实例化时能够正确展开模板定义的部分。

## C++ 中T Pair<T>::getFirst()  这里为什么要写成Pair<T> 为什么不这么写呢T Pair::getFirst()  
在C++中，Pair<T>是一个模板类，T是类型参数。通过在类名后面加上尖括号和类型参数，可以将类模板实例化为具体的类型。

在定义成员函数getFirst()时，需要指定返回类型，这里的返回类型是T。由于Pair类是一个模板类，它的类型参数是T，因此需要在类名后面加上尖括号和类型参数<T>，以表示当前成员函数属于Pair<T>这个具体的实例化类型。

所以，Pair<T>::getFirst()的写法是为了明确指定getFirst()函数是属于Pair<T>这个模板类实例化后的具体类型的成员函数。

如果你写成T Pair::getFirst()，这样的语法会让编译器误解成Pair类有一个名为getFirst的静态成员函数，而不是一个模板类的成员函数。因此，编译器会报错，因为它无法找到非静态成员函数getFirst的定义。

另外，假设Pair是一个模板类，那么T Pair::getFirst()也无法体现出getFirst函数的返回类型是由模板类Pair的类型参数决定的这一特点。