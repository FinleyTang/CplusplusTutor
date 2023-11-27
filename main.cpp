#include <iostream>

#include "ClassDemo/Player.h"
#include "tests/TestPlayerClass.h"
#include "tests/TestString.h"
#include "tests/TestDerived.h"
#include "tests/TestXmlParser.h"
extern  int s_var;

int main() {

    testPlayer();
    testString();
    testCString();
    testShape();
    testParseXML();

    return 0;
}
