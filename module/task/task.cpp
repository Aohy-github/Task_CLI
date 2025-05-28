//
// Created by Aohy on 2025/5/26.
//

#include "task.h"
#include <ctime>

std::string get_time()
{
    time_t timeTemp;
    time(&timeTemp);
    struct tm *myTime = localtime(&timeTemp);
    std::string temp = asctime(myTime);
    temp.pop_back();
    return temp;
}

bool TASK::set_description(std::string&& _des){
    time_t timestamp;
    time(&timestamp);
    struct tm * myTime = localtime(&timestamp);

    if (_des.empty())
    {
        std::cerr << "Error: text connot be empty." << std::endl;

        return false;
    }
    description = std::move(_des);

    updateAt = get_time();
    return true;
}
