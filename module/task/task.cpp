//
// Created by Aohy on 2025/5/26.
//

#include "task.h"


bool TASK::set_description(std::string&& _des){
    if (_des.empty())
    {
        std::cerr << "Error: text connot be empty." << std::endl;

        return false;
    }
    description = std::move(_des);
    return true;
}
