//
// Created by kurum on 2023/8/2.
//

#include "Logger.h"
Logger::~Logger()
{
#ifdef FILESAVEON
    if (logFile.is_open())
        logFile.close();
#endif
}
std::string Logger::getTime() {
    auto now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
    // Convert the time_t value to a string representation
    char timeStr[100];
    std::strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", std::localtime(&currentTime));
    return timeStr;
}
Logger::Logger(std::string nam,std::string proName) :name(nam){
#ifdef FILESAVEON
    proName+=".log";
    if (std::filesystem::exists(proName))
    {
#ifdef CLEARON
        logFile.open(proName,std::ios::out);
#else
        logFile.open(proName,std::ios::app);
#endif

    }else
    {
        logFile.open(proName,std::ios::out);
    }
#else
#endif
}


std::string Logger::GetContentAfterLastSlash(const std::string &path) {
        size_t lastSlashPos = path.find_last_of('\\');
        if (lastSlashPos != std::string::npos && lastSlashPos + 1 < path.length()) {
            return path.substr(lastSlashPos + 1);
        }
        lastSlashPos = path.find_last_of('/');
        if (lastSlashPos != std::string::npos && lastSlashPos + 1 < path.length()) {
            return path.substr(lastSlashPos + 1);
        }
        return path;
}


void Logger::logs(std::string format, int line, std::string level, std::string endc, ...) {
    std::lock_guard<std::mutex> lock(mtx); // 使用std::lock_guard自动管理互斥锁的锁定和解锁

#ifdef FILESAVEON
    logFile<<getTime()<< "  ["<<name<<'-' AN line<< '-' AN level<<"]  ";
#else
#endif
#ifdef STDOUTON
    va_list args;
            va_start(args, endc);

    bluePrint(getTime());
    pr"  [";
    pr name;
    pr'-' AN line;
    pr'-' AN level;
    pr"]  ";

    bool needOut = false;
    int d;
    double f;
    std::string str;
    for (auto c : format) {
        if (needOut) {
            switch (c) {
                case 'd':
                    d = va_arg(args, int);
                    pr(d);
#ifdef FILESAVEON
                    logFile << d;
#else
#endif
                    break;
                case 's':
                    str = va_arg(args, const char*);
                    pr(str);
#ifdef FILESAVEON
                    logFile << str;
#else
#endif
                    break;
                case 'f':
                    f = va_arg(args, double);
                    pr(f);
#ifdef FILESAVEON
                    logFile << f;
#else
#endif
                    break;
                case '%':
                    pr('%');
#ifdef FILESAVEON
                    logFile << '%';
#else
#endif
                    break;
            }
            needOut = false;
        } else if (c != '%') {
            pr(c);
#ifdef FILESAVEON
            logFile << c;
#else
#endif
        } else {
            needOut = true;
        }
    }

            va_end(args);
    pr(endc);
#ifdef FILESAVEON
    logFile << endc;
#endif
#endif
}
