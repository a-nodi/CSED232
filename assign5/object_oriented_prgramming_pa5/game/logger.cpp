#include <memory>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include "logger.h"

Logger::Logger(std::string& _file_name) : file_name(_file_name) {
    log_queue = std::shared_ptr<std::queue<std::shared_ptr<LogUnit>>> (new std::queue<std::shared_ptr<LogUnit>>);
    file.open(file_name); // open file
}

Logger::~Logger() {
    write_file(); // Write leftover logs
    file.close(); // close file
}

std::string Logger::make_log(LogUnit& log_unit){
    std::string log = "";

    // Make log for each type

    if (log_unit.action == "INITIAL") {
        log = "INITIAL    ";
        log.insert(8, std::to_string(log_unit.values[0]));
        log.insert(10, std::to_string(log_unit.values[1]));
        log.insert(12, std::to_string(log_unit.values[2]));
        log.insert(14, std::to_string(log_unit.values[3]));
    }

    else if (log_unit.action == "UP" || log_unit.action == "DOWN" || log_unit.action == "RIGHT" || log_unit.action == "LEFT"){
        log = log_unit.action;
    }

    else if (log_unit.action == "GENERATE"){
        log = "GENERATE   ";
        log.insert(9, std::to_string(log_unit.values[0]));
        log.insert(11, std::to_string(log_unit.values[1]));
        log.insert(13, std::to_string(log_unit.values[2]));
    }

    else if (log_unit.action == "MERGE"){
        log = "MERGE   ";
        log.insert(6, std::to_string(log_unit.values[0]));
        log.insert(8, std::to_string(log_unit.values[1]));
        log.insert(10, std::to_string(log_unit.values[2]));
    }

    else if (log_unit.action == "RESTORE"){
        log = "RESTORE ";
        log.insert(8, std::to_string(log_unit.values[0]));
    }

    else if (log_unit.action == "SCORE"){
        log = "SCORE ";
        log.insert(6, std::to_string(log_unit.values[0]));
    }

    return log;
}

bool Logger::write_line(std::string& log){
    // Write 1 log to file
    if (file.is_open())
        file << log << std::endl;

    return true;
}

int Logger::log_max_count(std::string& action){
    // Returns max count of log action
    if (action == "INITIAL" ||
        action == "UP" || action == "DOWN" || action == "RIGHT" || action == "LEFT" ||
        action == "GENERATE" ||
        action == "RESTORE" ||
        action == "SCORE"
        ) return 1;

    if (action == "MERGE") return 8;

    return -1;
}

bool Logger::write_file() {
    // Write all log in log queue into file
    std::string action = "";
    std::shared_ptr<LogUnit> temp;
    std::shared_ptr<std::vector<std::string>> log_str_vector;
    int max_count = 0;
    int count = 0;

    while(!(log_queue->empty())){
        if (action == "") { // Initiate action
            action = log_queue->front()->action;
            count = 0;
            max_count = log_max_count(action);
            log_str_vector = std::shared_ptr<std::vector<std::string>> (new std::vector<std::string> (max_count));
        }

        if (log_queue->front()->action != action || count >= max_count){ // New action, dump created logs to log file
            if (max_count != 1) std::sort(log_str_vector->begin(), log_str_vector->begin() + count); // Sort log(Merge)

            for(auto pr = log_str_vector->begin(); pr != log_str_vector->begin() + count; pr++){
                write_line(*pr); // Write sorted logs
            }

            action = "";
        }

        // Load same action log to vector (to sort in row col order)
        else if (log_queue->front()->action == action){
            temp = log_queue->front();
            log_queue->pop();
            (*log_str_vector)[count] = make_log(*temp);
            count++;
        }

    }

    // Write leftover logs
    for(auto pr = log_str_vector->begin(); pr != log_str_vector->begin() + count; pr++){
        write_line(*pr);
    }
    return true;
}
