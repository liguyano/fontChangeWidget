//
// Created by kurum on 2023/7/7.
//

#ifndef WBUILDER_MYFILE_H
#define WBUILDER_MYFILE_H
#include <filesystem>
#include <iostream>
#include <windows.h>
#include <vector>

std::vector<std::string> ListFiles(const std::string& path);
std::vector<std::string> GetFilesInFolder(std::string folderPath, std::string prefix = "");
//"BooK Files\0*.epub;*.txt;*.mobi;*.azw3;\0All Files\0*.*\0"
bool OpenFileSelectionDialog(std::string& selectedFilePath,std::string );
bool createFolderIfNotExists(const std::string& folderPath);
bool folderExists(const std::string& folderPath);
bool copyFile(const char* sourceFile, const char* destinationFile);
bool deleteFolder(const std::string& folderPath);
std::string ReadFileContents(const std::string& filename);

#endif //WBUILDER_MYFILE_H
