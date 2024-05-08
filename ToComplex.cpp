//
// Created by kurum on 2023/12/1.
//

#include "ToComplex.h"

std::array<std::array<unsigned char, 571>, 130> ComplexChinese::loadDate(const char * path) {
    std::array<std::array<unsigned char,571> ,130> allCOmplex{{}};
    std::ifstream allCOm(path,std::ios::in);
    std::string t="";
    int lineNow=0;
    while (!allCOm.eof())
    {
        allCOm>>t;
        int i=0;
        for (auto c: t) {
            allCOmplex.at(lineNow).at(i++)=c;
        }
        lineNow++;
    }
    return allCOmplex;
}

std::string ComplexChinese::toComplex(std::array<std::array<unsigned char, 571>, 130> allCOmplex, std::string str) {
    auto s=str;
    char buffer[5];
    std::string ss="";
    for (int i = 0; i < s.size(); ++i) {
        unsigned char c=s[i];
        if (c>=0x80)
        {
            auto row=((unsigned char)s[i+1]-0x41)*3;
            /*  printf_s("%c%c%c",allCOmplex[c-0x81][row],allCOmplex[c-0x81][row+1],
                       allCOmplex[c-0x81][row+2]);*/
          /*  printf_s("%d,%d\n",((unsigned char)s[i+1]-0x41),(unsigned char )s[i]-0x80);
            printf_s("%d,%d,%d\n",allCOmplex[c-0x81][row],allCOmplex[c-0x81][row+1],allCOmplex[c-0x81][row+2]);
*/            buffer[0]=allCOmplex[c-0x81][row];
            buffer[1]=allCOmplex[c-0x81][row+1];
            buffer[2]=allCOmplex[c-0x81][row+2];
            buffer[3]='\0';
            if ((unsigned char )buffer[0]==194 &&(unsigned char )buffer[1]==183)
                buffer[2]='\0';
            ss+=buffer;
            i+=1;
        }else
        {
            ss+=c;
        }
    }
    return ss;
}