//
// Created by kurum on 2024/5/25.
//

#ifndef FILEEDITOR_FILESEARCHSTR_H
#define FILEEDITOR_FILESEARCHSTR_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>
#include <MYString.h>
namespace fs = std::filesystem;

struct MatchResult {
    std::string fileName;
    int lineNo;
    std::string lineContent;
    std::string fullPath;
};
std::vector<MatchResult> searchDirectoryRecursively(std::string dirPath, const std::string& targetStr);
std::vector<MatchResult> searchSingleFile(std::string filePath, const std::string& targetStr);
#endif //FILEEDITOR_FILESEARCHSTR_H
