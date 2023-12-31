
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


## 运算符重载

重载比较好的文章
https://blog.csdn.net/Mo3328679412/article/details/132754315




## STL迭代器 
除了使用下标访问向量的元素，还有以下两种常见的方法遍历并输出向量中的元素：

使用迭代器（Iterator）
```c++
#include <vector>
#include <iostream>

int main() {
std::vector<int> vec = {10, 20, 30}; // 定义一个整型向量

    for (auto it = vec.begin(); it != vec.end(); it++) {
        std::cout << *it << " "; // 遍历并输出向量中的元素
    }

    return 0;
}
```

使用范围（Range）循环
```c++
#include <vector>
#include <iostream>

int main() {
std::vector<int> vec = {10, 20, 30}; // 定义一个整型向量

    for (const auto& elem : vec) {
        std::cout << elem << " "; // 遍历并输出向量中的元素
    }

    return 0;
}
```

以上两种方法都可以避免使用下标访问方式可能存在的越界问题，并且代码更加简洁易读。其中，迭代器是STL的一种基本组件，可用于遍历各种容器；而范围循环则是C++11引入的新特性，用于遍历支持迭代器的容器。

一般来说，优先使用范围（Range）循环是更好的选择。以下是一些原因：

简洁性：范围循环提供了一种更简洁的语法，避免了手动处理迭代器的复杂性和可能的错误。

安全性：范围循环使用迭代器，并且会自动处理边界条件，避免了访问越界的风险。

可读性：范围循环的语法更加直观和易懂，能够更清晰地表达意图，提高代码的可读性和可维护性。

适用性：范围循环适用于大多数情况下对容器进行遍历和操作的场景，可以应用于任何支持迭代器的容器，包括STL容器和用户自定义容器。

然而，在某些情况下，使用迭代器可能更为合适，例如需要在遍历过程中进行迭代器的增减操作或精确控制迭代的位置。

## RAII是什么　　
RAII全称是“Resource Acquisition is Initialization”，即资源获取即初始化。RAII技术被认为是C++中管理资源、避免泄露的最佳方法，可以实现安全、简洁的状态管理，编写出优雅的异常安全的代码。因为C++的语言机制保证了，当一个对象创建的时候，自动调用构造函数，当对象超出作用域的时候会自动调用析构函数。RAII的做法是使用一个对象，在其构造时获取对应的资源，在对象生命期内控制对资源的访问，使之始终保持有效，最后在对象析构的时候，释放构造时获取的资源。

如网络套接字、互斥锁、文件句柄和内存等等，它们属于系统资源。使用RAII对这些资源进行管理。智能指针（std::shared_ptr和std::unique_ptr）即RAII最具代表的实现，使用智能指针，可以实现自动的内存管理，再也不需要担心忘记delete造成的内存泄漏。
## 智能指针

https://zhuanlan.zhihu.com/p/526147194

**为什么需要智能指针：**

```c++
class Test {
public:
	Test() { cout << "Test的构造函数..." << endl; }
	~Test() { cout << "Test的析构函数..." << endl; }

	int getDebug() { return this->debug; }

private:
	int debug = 20;
}; 
```

下面是调用的代码，有什么问题：
```c++
int main(void) {
Test *test = new Test;

	return 0;
} 
```

内存泄漏：使用 new 创建了 Test 类的实例，但没有在程序结束前使用 delete 进行释放。这会导致内存泄漏，即分配的内存空间无法被释放，造成系统资源浪费。

没有调用析构函数：由于没有调用 delete，Test 类的析构函数也不会被调用，这可能会导致一些清理工作无法完成，例如释放动态分配的资源等。

**析构函数需要显式调用吗**

在一般情况下，析构函数不需要显式调用。C++编译器会自动在对象的生命周期结束时调用析构函数，进行资源的清理和释放工作。

在给定的代码示例中，当程序执行到 main 函数的末尾时，test 对象超出了其作用域，因此编译器会自动调用 Test 类的析构函数来销毁对象。

显式调用析构函数通常只在特殊情况下使用，例如需要手动管理动态分配的资源（通过 new 分配的内存或打开的文件等），可以在析构函数中完成资源的释放操作。但在大多数情况下，不需要手动调用析构函数，编译器会负责处理对象的销毁过程。


new 运算符分配的对象不会自动调用析构函数是因为它们是在堆上动态分配的，而不是在栈上创建的。

在 C++ 中，对象可以存储在两个主要的存储区域：栈和堆。栈上的对象由编译器自动管理其生命周期，当对象超出其作用域时，编译器会自动调用析构函数来进行资源的清理。而堆上的对象是通过手动分配和释放内存来管理的。

使用 new 运算符在堆上分配内存时，它会返回一个指向对象的指针。这个指针指向的对象在没有手动释放之前将一直存在。由于编译器无法确定何时应该自动调用析构函数，因此需要手动调用析构函数来进行资源的清理。

这种手动调用析构函数并释放内存的方式，给了程序员更高的灵活性和控制权。但同时也增加了责任，需要确保在适当的时候手动调用析构函数和释放内存，以避免内存泄漏和资源泄漏等问题。为了避免手动管理内存的复杂性，C++ 提供了智能指针等工具，可以自动管理动态分配的内存，从而减少了手动释放内存的烦扰。