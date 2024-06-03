//
// Created by kurum on 2024/5/25.
//

#include "fileSearchStr.h"

std::vector<MatchResult> searchDirectoryRecursively(std::string dirPath, const std::string& targetStr) {
    std::vector<MatchResult> results;
    for (const auto& entry : fs::recursive_directory_iterator(dirPath)) {
        if (entry.is_regular_file()) {
            std::ifstream file(entry.path());
            if (file.is_open()) {
                std::string line;
                int lineNumber = 0;
                while (std::getline(file, line)) {
                    ++lineNumber;
                    if (line.find(targetStr) != std::string::npos) {
                        auto p=entry.path().string();
                        p=String::replaceAllOccurrences(p,"\\","/");
                        results.push_back({entry.path().filename().string(), lineNumber, line,p});
                    }
                }
                file.close();
            } else {
                std::cerr << "Could not open the file: " << entry.path() << std::endl;
            }
        }
    }
    return results;
}
std::vector<MatchResult> searchSingleFile(std::string filePath, const std::string& targetStr)
{ std::vector<MatchResult> results;
    std::ifstream file(filePath);
    if (file.is_open()) {
        std::string line;
        int lineNumber = 0;
        auto p=String::replaceAllOccurrences(filePath,"\\","/");
        p=String::getExtensionAfterLastDot(p,'/');
        while (std::getline(file, line)) {
            ++lineNumber;
            if (line.find(targetStr) != std::string::npos) {
                results.push_back({p, lineNumber, line,filePath});
            }
        }
        file.close();
    } else {
        std::cerr << "Could not open the file: " << filePath << std::endl;
    }
    return results;
}