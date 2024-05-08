//
// Created by kurum on 2023/7/31.
//
#pragma once
#ifndef OPENGL_DEMO_LOGGER_H
#define OPENGL_DEMO_LOGGER_H
#define STSTART static Logger logger(Logger::GetContentAfterLastSlash(__FILE__));
#define SNSTART(NAme )static Logger logger(Logger::GetContentAfterLastSlash(__FILE__),NAme);
#include <iostream>
#include <fstream>
#include <chrono>
#include "self_made.h"
#include <filesystem>
#include <ctime>
#include <mutex>
#include <cstdarg>
/*
 * configue
 * */
#define  FILESAVEON //this means if the log need to be save in a .log file. FILESAVEOFF means not FILESAVEON means yes
#define STDOUTON// if the log need output in the console. Same as the FILESAVEON
#define CLEARON
//end configue
#define PROJECTNAME  "include_test"

#define linfo(mess,...)logger.logs(mess,__LINE__,"info","\n", ##__VA_ARGS__)
#define linfo_end(mess,enc,...)logger.logs(mess,__LINE__,"info",endc, ##__VA_ARGS__)
#define info_f(format,...) logger.logs(format,__LINE__,"info","\n", ##__VA_ARGS__)
#define lerror(mess,...)logger.logs(RED mess RESET ,__LINE__,"error","\n", ##__VA_ARGS__)
#define lerro(mess,...)logger.logs(RED mess RESET ,__LINE__,"error","\n", ##__VA_ARGS__)
#ifdef __MINGW32__
#ifdef NDEBUG
#define ldebug(mess,...)
#else
#define ldebug(mess,...) logger.logs(mess,__LINE__,"debug","\n", ##__VA_ARGS__)
#endif
#else
#ifdef _DEBUG
#define ldebug(mess,...) logger.logs(mess,__LINE__,"debug","\n", ##__VA_ARGS__)
#else
#define ldebug(mess,...)
#endif
#endif
class Logger {
private:
    std::mutex mtx; // 增加一个互斥锁成员变量
    std::string name;
#ifdef FILESAVEON
    std::fstream logFile;

#else
#endif
public:
#ifdef __MINGW32__
    #ifdef NDEBUG
bool isDebug=false;
#else
bool isDebug=true;
#endif
#else
#ifdef _DEBUG
    bool isDebug=true;
#else
    bool isDebug=false;
#endif
#endif
    static std::string GetContentAfterLastSlash(const std::string& path);
    /**
     * @param proName this define where to save the log file, add .log in the end auto.
     * @param nam define the output part name
     * */
    explicit Logger(std::string nam ,std::string   proName=PROJECTNAME);

    void logs(std::string format,int line, std::string level,std::string endc,...);
    /**
     * @return return time now by a string
     * */
    std::string getTime();
    ~Logger();
};




#endif //OPENGL_DEMO_LOGGER_H
