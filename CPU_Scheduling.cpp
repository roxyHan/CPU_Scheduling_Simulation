//
// Created by hanifa on 5/22/20.
//

#include <fstream>
#include <iostream>
#include <cstring>
#include "CPU_Scheduling.h"

using namespace std;

// Constructor
CPU_Scheduling::CPU_Scheduling() {}


vector<string> CPU_Scheduling::readFile(std::string fname) {
    ifstream isObj(fname, ios::in| ios::binary);
    if (!isObj) {
        cout << "Failed to open the file." << endl;
    }
    vector<string> all;
    string current;
    while (isObj >> current){
        all.push_back(current);
    }
    isObj.close();

    return all;
}

void CPU_Scheduling::writeToFile(std::string fname) {
    ofstream osObj(fname, ios::out| ios::binary);
    if (!osObj) {
        cout << "Failed to open the file." << endl;
    }

    osObj.close();

}


/**
 *
 * @return
 */
int CPU_Scheduling::main(const char *filename) {
    // Reads the content of the file
    //ifstream fileContent(filename);
    FILE* content;
    content = fopen("processes.bin", "rb");
    process one[3];
    if (content == NULL) {
        cout << "Issue with reading the file. No such file." << endl;
    }
    char buffer[38];
    int idx = 0;

    fread(buffer, 38, 1, content);
    char name[16];
    memcpy(name, &buffer[0], 16);
    cout << "name: " << name << endl;

    int id;
    memcpy(&id, &buffer[16], 4);
    cout << "id: " << id << endl;

    char activityStatus[1];
    memcpy(activityStatus, &buffer[20], 21);
    cout << "status: " << (int)buffer[20] << endl;

    int burst;
    memcpy(&burst, &buffer[21], 25);
    cout << "burst: " << burst << endl;

    int base;
    memcpy(&base, &buffer[25], 29);
    cout << "base: " << base << endl;

    long limit;
    memcpy(&limit, &buffer[29], 37);
    cout << "limit: " << (long) limit << endl;

    char priority;//[sizeof(char)];
    memcpy(&priority, &buffer[37], 38);
    cout << "priority: " << (int)priority << "\n" << endl;

    //----------------------------------------------


    return 0;
}