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
#include <fstream>
#include <filesystem>
#include <regex>
#include "spdlog/spdlog.h"
#include "../task/task.h"

bool createJsonFile(std::string filePath);
std::vector<TASK> readJsonFile(std::string filePath);
bool writeJsonFile(std::string filePath, std::vector<TASK> data);

#endif //FILE_H
