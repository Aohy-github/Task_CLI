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

std::string trim(const std::string& str){
    size_t first = str.find_first_not_of(" \t\n\r");
    if(first == std::string::npos) return "";
    size_t last = str.find_last_not_of(" \t\n\r");

    return str.substr(first,last);
}


std::vector<TASK> IO_TaskFile::readJsonFile(std::string filePath) {
    std::regex pat_taName("\"([a-zA-Z0-9]+)\"\\s*:\\s*\\[");

    std::regex pat_id("\"id\"\\s*:\\s*([0-9]+),");

    std::regex pat_desc("\"description\"\\s*:\\s*\"(.*?)\",");

    std::regex pat_creAt("\"createAt\"\\s*:\\s*\"([^\"]+)\",?");

    std::regex pat_upAt("\"updateAt\"\\s*:\\s*\"([^\"]+)\",?");

    std::regex pat_status("\"State\"\\s*:\\s*\"([0-9]+)\"");

    std::regex pat_end("\\[");
    
    std::vector<TASK> tasks;
    i_file.open(filePath);
    if (!i_file.is_open()) {
        spdlog::error("File open failed: {}", filePath);
        return tasks; 
    }

    std::string line;
    Pro_STATE status = Pro_STATE::DONE;
    std::string desc;
    std::string creAt;
    std::string upAt;
    int task_status;
    int id;
    while (std::getline(i_file, line)) {
        
        std::string temp = trim(line);
        std::smatch match;
        if(status == Pro_STATE::DONE && std::regex_search(temp, match, pat_taName)){
            spdlog::debug("task name is :{}" , match[1].str());
            status = Pro_STATE::IN_ARRAY;
            
        }else if(status == Pro_STATE::IN_ARRAY){
            
            if(std::regex_search(temp, match, pat_id)){
                spdlog::debug("id : {}", match[1].str());
                
                
                try
                {
                    id =std::stoi(match[1].str());
                }
                catch(const std::exception& e)
                {
                    spdlog::error("status to int false! : {}" , e.what());
                }
            }
            else if(std::regex_search(temp, match, pat_desc)){
                spdlog::debug("pat_desc : {}", match[1].str());
                desc = match[1].str();
            }  
            else if(std::regex_search(temp, match, pat_creAt)){
                spdlog::debug("creAt : {}", match[1].str());
                creAt = match[1].str();

            }else if(std::regex_search(temp, match, pat_upAt)){
                spdlog::debug("pat_upAt : {}", match[1].str());
                upAt = match[1].str();

            }else if(std::regex_search(temp, match, pat_status)){
                spdlog::debug("pat_status : {}", match[1].str());
                status = Pro_STATE::IN_OBJECT;

                try
                {
                    task_status = std::stoi(match[1].str());
                }
                catch(const std::exception& e)
                {
                    spdlog::error("status to int false! : {}" , e.what());
                }
            }else if(std::regex_search(temp, match, pat_end)){
                status = Pro_STATE::DONE;
            }else{
                continue;
            }
        }else if(status == Pro_STATE::IN_OBJECT){
            tasks.push_back(TASK(desc, id, creAt, upAt, task_status));
            status = Pro_STATE::IN_ARRAY;
        }
    }

    i_file.close();
    return tasks;
}