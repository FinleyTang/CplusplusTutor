#include <iostream>

#include "ClassDemo/Player.h"
#include "tests/TestPlayerClass.h"
#include "tests/TestString.h"

extern  int s_var;

int main() {

    testPlayer();
    testString();
    testCString();


    return 0;
}
