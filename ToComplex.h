//
// Created by kurum on 2023/12/1.
//
#include <array>
#include <iostream>
#include <fstream>
#ifndef EPUBTORIGHT_TOCOMPLEX_H
#define EPUBTORIGHT_TOCOMPLEX_H
namespace ComplexChinese{
    std::array<std::array<unsigned char,571> ,130> loadDate(const char*);
    std::string toComplex(std::array<std::array<unsigned char,571> ,130> allCOmplex,std::string str);
}

#endif //EPUBTORIGHT_TOCOMPLEX_H
