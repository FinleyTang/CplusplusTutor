#include <iostream>

#include "ClassDemo/Player.h"
#include "tests/TestPlayerClass.h"
#include "tests/TestString.h"
#include "tests/TestDerived.h"
extern  int s_var;

int main() {

    testPlayer();
    testString();
    testCString();
    testShape();
    return 0;
}
