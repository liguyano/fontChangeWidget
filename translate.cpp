//
// Created by kurum on 2024/5/6.
//

#include "translate.h"
std::map<std::string,std::map<std::string ,std::string>> readTranslationFile(std::string fileName){
    std::ifstream inFile(fileName); // 假设文件名为translations.txt
    if (!inFile.is_open()) {
        std::cerr << "无法打开文件!" << std::endl;
    }
    // 读取语言列表
    std::string line;
    std::getline(inFile, line);
    std::istringstream langStream(line);
    std::vector<std::string> languages;
    std::string lang;
    while (std::getline(langStream, lang, '^')) {
        languages.push_back(lang);
    }

    // 初始化一个多层映射，使用英文作为最外层键
    std::map<std::string, std::map<std::string, std::string>> translations;
    // 读取剩余的翻译项
    while (std::getline(inFile, line)) {
        std::istringstream translationStream(line);
        std::vector<std::string> parts;
        std::string part;
        while (std::getline(translationStream, part, '^')) {
            parts.push_back(part);
        }

        // 确保每一行都有与语言数量相等的翻译项
        if (parts.size() == languages.size()) {
            for (size_t i = 0; i < languages.size(); ++i) {
                translations[parts[0]][languages[i]] = parts[i];
            }
        } else {
            // std::cerr << "警告: 行 '" << line << "' 的格式不正确，跳过." << std::endl;
        }
    }    inFile.close();
    return translations;
}
std::map<std::string, std::map<std::string, std::string>> readTranslationFromString(const std::string& content) {
    std::istringstream contentStream(content);

    // 读取语言列表
    std::string line;
    std::getline(contentStream, line);
    std::istringstream langStream(line);
    std::vector<std::string> languages;
    std::string lang;
    while (std::getline(langStream, lang, '^')) {
        languages.push_back(lang);
    }

    // 初始化一个多层映射，使用英文作为最外层键
    std::map<std::string, std::map<std::string, std::string>> translations;

    // 直接从contentStream读取剩余的翻译项，不再需要额外的打开或关闭文件操作
    while (std::getline(contentStream, line)) {
        std::istringstream translationStream(line);
        std::vector<std::string> parts;
        std::string part;
        while (std::getline(translationStream, part, '^')) {
            parts.push_back(part);
        }

        // 确保每一行都有与语言数量相等的翻译项
        if (parts.size() == languages.size()) {
            for (size_t i = 0; i < languages.size(); ++i) {
                translations[parts[0]][languages[i]] = parts[i];
            }
        } else {
            // std::cerr << "警告: 行 '" << line << "' 的格式不正确，跳过." << std::endl;
        }
    }

    return translations;
}