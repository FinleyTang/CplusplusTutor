file(GLOB CPP_SOURCES *.cpp)
add_library(tests_test1 ${CPP_SOURCES})
#add_library(tests_test1 TestPlayerClass.cpp TestString.cpp TestDerived.cpp TestXmlParser.cpp TestFileOperator.cpp)
target_link_libraries(tests_test1 PlayerLib Derived-shape parseXml template-demo operatorOverride)