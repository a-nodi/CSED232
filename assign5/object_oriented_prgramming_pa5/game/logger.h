#ifndef LOGGER_H
#define LOGGER_H

#include <queue>
#include <memory>
#include <fstream>
#include <string>
#include <QFile>
#include <QString>
#include "logunit.h"

class Logger{
private:
    std::ofstream file;
    std::string file_name;
    std::shared_ptr<std::queue<std::shared_ptr<LogUnit>>> log_queue;

    bool write_line(std::string&);
    std::string make_log(LogUnit&);
    int log_max_count(std::string& action);
public:
    Logger(std::string&);
    ~Logger();

    bool write_file();

    std::shared_ptr<std::queue<std::shared_ptr<LogUnit>>> get_queue() { return log_queue; };
};

#endif // LOGGER_H
