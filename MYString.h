//
// Created by kurum on 西暦2023年6月20日.
//

#ifndef WBUILDER_STRING_H
#define WBUILDER_STRING_H

#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>

namespace String {
    std::vector<std::string> split(std::string input, std::string delimiters);
    std::string getExtensionAfterLastDot(const std::string &input, char what = '.');
    std::string getExtensionBeforLastDot(const std::string &input, char what = '.');
    std::string replaceAllOccurrences(std::string input, std::string search,  std::string replace);
    std::string truncateWithEllipsis(const std::string& input, size_t maxLength);
    std::string intToHex(int value, bool uppercase = false);
    std::vector<unsigned char> stringToUnsignedCharArray(const std::string& input);
}
#endif //WBUILDER_STRING_H
