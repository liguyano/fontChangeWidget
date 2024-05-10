//
// Created by kurum on 2024/2/26.
//
#include "MYString.h"
std::vector<std::string>  String::split(std::string input, std::string delimiters) {
    std::vector<std::string> result;
    size_t pos = 0;
    size_t prev = 0;

    while ((pos = input.find_first_of(delimiters, prev)) != std::string::npos) {
        if (pos > prev) {
            result.push_back(input.substr(prev, pos - prev));
        }
        prev = pos + 1;
    }

    if (prev < input.length()) {
        result.push_back(input.substr(prev));
    }
    return result;
}

std::string String::getExtensionAfterLastDot(const std::string &input, char what ) {

    auto lastDotPos = input.rfind(what);
    if (lastDotPos != std::string::npos) {

        return input.substr(lastDotPos + 1);
    } else {

        return "";
    }
}

std::string String::getExtensionBeforLastDot(const std::string &input, char what ) {

    size_t lastDotPos = input.rfind(what);

    if (lastDotPos != std::string::npos) {

        return input.substr(0, lastDotPos);
    } else {

        return "";
    }
}
//have some problem when use in Chinese char
std::string String::replaceAllOccurrences(std::string input, std::string search,  std::string replace) {
    std::string result = input;
    size_t startPos = 0;
    while ((startPos = result.find(search, startPos)) != std::string::npos) {
        result.replace(startPos, search.length(), replace);
        startPos += replace.length();
    }

    return result;
}
std::string String::truncateWithEllipsis(const std::string& input, size_t maxLength) {
    if (input.length() <= maxLength) {
        return input; // 如果字符串长度不大于最大长度，则直接返回原字符串
    } else {
        // 截取前maxLength - 3个字符，并添加省略号
        return input.substr(0, maxLength - 3) + "...";
    }
}
std::string String::     intToHex(int value, bool uppercase ) {
    std::stringstream ss;
    if (uppercase)
        ss << std::uppercase << std::hex << std::setw(2) << std::setfill('0') << value;
    else
        ss << std::hex << std::setw(2) << std::setfill('0') << value;

    return ss.str();
}
std::vector<unsigned char> String::stringToUnsignedCharArray(const std::string& input)
{
    std::vector<unsigned char> result;
    auto allNum = String::split(input, " ");
    for (const auto& s : allNum) {
        if (s.size() != 2) {
            throw std::invalid_argument("invalid value: " + s);
        }
        unsigned char num = 0;
        for (int i = 0; i < 2; ++i) {
            if (std::isxdigit(s[i])) {
                int val = std::isdigit(s[i]) ? (s[i] - '0') : (std::tolower(s[i]) - 'a' + 10);
                num = (num << 4) | val;
            } else {
                throw std::invalid_argument("invalid value: " + s);
            }
        }
        result.push_back(num);
    }

    return result;
}
