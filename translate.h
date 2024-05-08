//
// Created by kurum on 2024/5/6.
//

#ifndef QTTRY_TRANSLATE_H
#define QTTRY_TRANSLATE_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <string>
#define key_exsist(m,k) m.find(k) != m.end()
#define trs(k) key_exsist(trs[k],lang)?trs[k][lang].c_str():trs[k]["en_US"].c_str()
#define trss(k) key_exsist(trs[k],lang)?trs[k][lang].c_str():trs[k]["en_US"].c_str()
#define trQtInit()   QLocale systemLocale = QLocale::system();auto lang=systemLocale.name().toStdString();auto trs=readTranslationFile("tr.csv")
#define trQtInitFromString()   QLocale systemLocale = QLocale::system();auto lang=systemLocale.name().toStdString();    auto str= readQStringFromQrc(":/images/tr.csv");auto trs=readTranslationFromString(str.toStdString())
std::map<std::string,std::map<std::string ,std::string>> readTranslationFile(std::string fileName);
std::map<std::string, std::map<std::string, std::string>> readTranslationFromString(const std::string& content);
#endif //QTTRY_TRANSLATE_H
