//
// Created by Aohy on 2025/5/26.
//

#ifndef TASK_H
#define TASK_H

#include <string>
#include <iostream>
class TASK {

public:
    TASK(std::string _des , int _id , std::string _cre_at) : description(_des) , id(_id) , createAt(_cre_at),currentState(TODO) {};
    std::string get_description(){ return description; };
    std::string get_createAt(){return createAt; };
    std::string get_updateAt(){return updateAt; };
    int get_id(){return id;};
    bool set_description(std::string&& _des);

private:
    std::string description;
    int id;
    enum State{
        TODO,
        DONE,
        IN_PROGRESS
    };
    std::string createAt;
    std::string updateAt;
    State currentState;
};



#endif //TASK_H
