//
// Created by Aohy on 2025/5/26.
//

#include "FILE.h"

bool IO_TaskFile::writeJsonFile(std::string filePath, std::vector<TASK> data) {
    o_file.open(filePath, std::ios::app);

    if (!o_file.is_open()) {
        spdlog::error("File open failed: {}", filePath);
        return false;
    }
    o_file << "{\n"; // Start of JSON array
    o_file << "  \"tasks\": "; // Key for the array of tasks
    o_file << "[\n"; // Start of JSON array
    for (const auto& task : data) {
        o_file << "  " << task.to_json();
        if (&task != &data.back()) {
            o_file << ",\n";
        } else {
            o_file << "\n";
        }
    }
    o_file << "]\n"; // End of JSON array
    o_file << "}\n"; // End of JSON array

    o_file.close();
    return true;
}

enum class Pro_STATE{
    WAIT_FOR_ARRAY,
    IN_ARRAY,
    IN_OBJECT,
    DONE
};
std::regex list_pa("\"");
std::vector<TASK> IO_TaskFile::readJsonFile(std::string filePath) {
    std::vector<TASK> tasks;
    i_file.open(filePath);
    if (!i_file.is_open()) {
        spdlog::error("File open failed: {}", filePath);
        return tasks;
    }
    std::string line;
    Pro_STATE state = Pro_STATE::WAIT_FOR_ARRAY;
    while (std::getline(i_file, line)) {
        line.erase(remove_if(line.begin() , line.end() ,isspace) , line.end());
        spdlog::info("Read line: {}", line);
        if(state = Pro_STATE::WAIT_FOR_ARRAY && ){

        }
    }

    i_file.close();
    return tasks;
}