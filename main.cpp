#include <iostream>
#include "spdlog/spdlog.h"
#include "module/file/FILE.h"
#include <spdlog/sinks/rotating_file_sink.h>

static std::string JsonFilePath;
static void DirInit()
{
    bool bo = std::filesystem::create_directory("jsonFile");
    bool bo2 = std::filesystem::create_directory("log");

    static auto logger = spdlog::rotating_logger_mt("rot_logger" , "log/log.txt", 1024*1024*5,2);
    // logger->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%l] %v");
    logger->set_pattern("[%m-%d %H:%M:%S.%e] [%l] %v");
    spdlog::set_default_logger(logger);

    if(bo)
    {
        spdlog::info("jsonFile directory success");
    }else
    {
        spdlog::info("jsonFile exist!");
    }
    if(bo2)
    {
        spdlog::info("log directory success");
    }else
    {
        spdlog::info("log exist!");
    }
    JsonFilePath = "jsonFile/";

}
int main(int arg , char** argv){
    DirInit();
    
    
    std::cout << "Hello" << std::endl;
    std::string fileName = "test.json";
    
    
    std::string filePath = JsonFilePath + fileName;

    IO_TaskFile io_taskFile(filePath);
    io_taskFile.readJsonFile(filePath);

    std::vector<TASK> tasks;
    for(int i = 0; i < 10 ; i ++){
        tasks.push_back(TASK("thi is a new taks : " + std::to_string(i) , i ,get_time()));
        // tasks[i].to_string();
    }
    
    io_taskFile.writeJsonFile(filePath, tasks);
    
    return 0;
}