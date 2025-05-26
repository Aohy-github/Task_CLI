//
// Created by Aohy on 2025/5/26.
//

#ifndef FILE_H
#define FILE_H

#include <string>
#include <vector>
#include "../task/task.h"

bool createJsonFile(std::string filePath);
std::vector<TASK> readJsonFile(std::string filePath);
bool writeJsonFile(std::string filePath, std::vector<TASK> data);

#endif //FILE_H
