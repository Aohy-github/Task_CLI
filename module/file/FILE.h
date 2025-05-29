//
// Created by Aohy on 2025/5/26.
//

#ifndef FILE_H
#define FILE_H

#include <string>
#include <vector>
#include <fstream>
#include <filesystem>
#include <regex>
#include "spdlog/spdlog.h"
#include "../task/task.h"


class IO_TaskFile
{
public:
    IO_TaskFile(std::string filePath){
        i_file.open(filePath);
        if(!i_file.is_open())
        {
            spdlog::error("File open failed: {}",filePath);
        }
        i_file.close();
        // std::ios::app 追加到文件末尾
        o_file.open(filePath, std::ios::app);
        if(!o_file.is_open())
        {
            spdlog::error("File open failed: {}",filePath);
        }
        o_file.close();
    }
    ~IO_TaskFile() = default;
    std::vector<TASK> readJsonFile(std::string filePath);
    bool writeJsonFile(std::string filePath, std::vector<TASK> data);
private:
    std::ifstream i_file;
    std::ofstream o_file;
};

#endif //FILE_H
