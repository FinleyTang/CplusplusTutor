#include <iostream>
#include "hello/hello.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    int result = add(3, 4);
    std::cout << result << std::endl;
    return 0;
}
