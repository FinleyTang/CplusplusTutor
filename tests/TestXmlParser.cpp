//
// Created by ftang on 2023/11/27.
//

#include "TestXmlParser.h"
#include "../xmlParse/tinyxml2.h"
#include <iostream>
using namespace tinyxml2;

void testParseXML(){
    XMLDocument doc;
    // 加载XML文件
    if (doc.LoadFile("C:\\Users\\ftang\\CLionProjects\\CplusplusTutor\\tests\\test.xml") == tinyxml2::XML_SUCCESS) {
        // 获取根元素
        tinyxml2::XMLElement* root = doc.RootElement();

//        // 遍历子元素
//        for (tinyxml2::XMLElement* element = root->FirstChildElement(); element != nullptr; element = element->NextSiblingElement()) {
//            // 获取元素名称和文本内容
//            const char* name = element->Value();
//            const char* text = element->GetText();
//
//            std::cout << "Element: " << name << ", Text: " << text << std::endl;
//        }
        // 遍历item元素
        for (tinyxml2::XMLElement* item = root->FirstChildElement("item"); item != nullptr; item = item->NextSiblingElement("item")) {
            // 获取rule元素
            tinyxml2::XMLElement* rule = item->FirstChildElement("rule");
            if (rule) {
                const char* regexContent = rule->GetText();
                std::cout << regexContent << std::endl;
            }

            // 获取description元素
//            tinyxml2::XMLElement* description = item->FirstChildElement("description");
//            if (description) {
//                const char* descText = description->GetText();
//                std::cout << "Description: " << descText << std::endl;
//            }
        }

    } else {
        std::cout << "Failed to load XML file." << std::endl;
    }
}