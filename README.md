
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