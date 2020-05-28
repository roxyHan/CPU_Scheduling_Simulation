//
// Created by hanifa on 5/22/20.
//

#ifndef LAB4_CPU_SCHEDULING_H
#define LAB4_CPU_SCHEDULING_H

#include <vector>
#include <string>


struct Process {
    char name[16];
    int id;
    int activity;
    int burst;
    int base;
    long limit;
    int priority;
};

class CPU_Scheduling {

public:
    CPU_Scheduling();
    std::vector<std::string> readFile(std::string fname);
    void writeToFile(std::string fname);
    int getSize(std::string filename);

    int main(const char *fname);

};


#endif //LAB4_CPU_SCHEDULING_H
