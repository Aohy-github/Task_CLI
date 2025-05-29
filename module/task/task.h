//
// Created by Aohy on 2025/5/26.
//

#ifndef TASK_H
#define TASK_H

#include <string>
#include <iostream>
#include <sstream>

std::string get_time();
class TASK {

public:
    TASK(std::string _des , int _id , std::string _cre_at) : description(_des) , id(_id) , createAt(_cre_at){
        currentState = State::TODO;
        updateAt = _cre_at;
    };
    TASK(
        std::string _des , 
        int _id , 
        std::string _cre_at ,
        std::string _up_at,
        int state){

        description = _des;
        id = _id;
        createAt = _cre_at;
        updateAt = _up_at;
        currentState = static_cast<State>(state);
    }
    std::string get_description(){ return description; };
    std::string get_createAt(){return createAt; };
    std::string get_updateAt(){return updateAt; };
    int get_id(){return id;};
    bool set_description(std::string&& _des);
    std::string to_json() const
    {
        // 创建一种字符串转化方式
        std::ostringstream oss;
        oss <<"{\n"
            <<"  \"id\":" << this->id << ",\n"
            <<"  \"description\":\"" << this->description << "\",\n"
            <<"  \"createAt\":\"" << this->createAt << "\",\n"
            <<"  \"updateAt\":\"" << this->updateAt << "\" ,\n"
            <<"  \"State\":\"" << static_cast<int>(this->currentState) << "\" \n"
            <<"}";
        return oss.str();
    }
    void to_string() const
    {
        std::cout << this << std::endl;
    }
private:
    std::string description;
    int id;
    enum class State{
        TODO,
        DONE,
        IN_PROGRESS
    };
    std::string createAt;
    std::string updateAt;
    State currentState;
};



#endif //TASK_H
