#include <iostream>

#include "ClassDemo/Player.h"
#include "tests/TestPlayerClass.h"
#include "tests/TestString.h"
#include "tests/TestDerived.h"
#include "tests/TestXmlParser.h"
#include "tests/TestFileOperator.h"
#include "tests/TestTemplate.h"
#include "tests/testOpOVerride.h"
extern  int s_var;

int main() {

//    testPlayer();
//    testString();
//    testCString();
//    testShape();
//    testParseXML();
//    test_file_read_by_line();
//    test_file_write();
    test_template_func();
    test_template_class();
    test_Operator_override();
    return 0;
}
