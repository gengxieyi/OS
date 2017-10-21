#include "KVDatabase.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <sys/types.h>  
#include <sys/stat.h>  
#include <unistd.h>
#include <stdio.h>
int main()
{
    gxy_result_t ret = SUCCESS;
    KVDatabase db("/home/gxy/","unit","index");
    db.Open();
    string key;
    string value;
    while (1) {
        std::cout << "input a key : " << std::endl;
        std::cin >> key;
        if (key == "stop") {
            break;
        }
        std::cout << "input a value : " << std::endl;
        std::cin >> value;
        ret = db.Write(key,value);
        std::cout << ToString(ret) << std::endl;

    }
    std::vector<string> keys;
    std::vector<string> values;
    ret = db.List(keys,values);
    for (int i = 0; i < keys.size();i++) {
        std::cout << keys[i]  << ":" << values[i] <<std::endl;
    }
    return 0;
};
