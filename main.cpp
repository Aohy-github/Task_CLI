#include <iostream>
#include "spdlog/spdlog.h"
#include "module/file/FILE.h"
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

static std::string JsonFilePath;
static void SpdInit(){ // 双sink输出
   // 创建两个 sink
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    console_sink->set_level(spdlog::level::warn);  
    console_sink->set_pattern("[console %^%l%$] %v");

    auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs/log.txt", true);
    file_sink->set_level(spdlog::level::debug);    // 文件输出所有等级
    file_sink->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%l] %v");

    // 合并 sink
    std::vector<spdlog::sink_ptr> sinks{console_sink, file_sink};
    auto logger = std::make_shared<spdlog::logger>("multi_logger", sinks.begin(), sinks.end());

    logger->set_level(spdlog::level::debug);        // 设置 logger 总等级（最低输出等级）
    spdlog::set_default_logger(logger);             // 设置为全局默认
}
static void DirInit()
{
    bool bo = std::filesystem::create_directory("jsonFile");
    bool bo2 = std::filesystem::create_directory("logs");

    SpdInit();
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
    std::string ToUser = "user1";
    
int main(int arg , char** argv){
    DirInit();
    
    
    std::cout << "Hello" << std::endl;
    std::string fileName = "test.json";
    
    
    std::string filePath = JsonFilePath + fileName;

    IO_TaskFile io_taskFile(filePath);
    std::vector<TASK> tasks = io_taskFile.readJsonFile(filePath);
    
    return 0;
}