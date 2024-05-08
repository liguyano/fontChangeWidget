//
// Created by kurum on 1/5/2023.
//
#ifndef QTTRY_OPERATE_ENCODING_PORT_H
#define QTTRY_OPERATE_ENCODING_PORT_H
#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>


#include <windows.h>
namespace Encoding{
     std::string GbkToUtf8(const char *src_str);
     std::string Utf8ToGbk(const char *src_str);
}
#endif //QTTRY_OPERATE_SERIAL_PORT_H