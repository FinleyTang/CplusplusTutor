add_library(tests_test1 TestPlayerClass.cpp TestString.cpp TestDerived.cpp TestXmlParser.cpp)
target_link_libraries(tests_test1 PlayerLib Derived-shape parseXml)