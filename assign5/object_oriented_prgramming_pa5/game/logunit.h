#ifndef LOGUNIT_H
#define LOGUNIT_H

#include <string>
#include <memory>

struct LogUnit{
    std::string action;
    std::shared_ptr<int[]> values;
};

#endif // LOGUNIT_H
