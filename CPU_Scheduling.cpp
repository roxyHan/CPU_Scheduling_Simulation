//
// Created by hanifa on 5/22/20.
//

#include <fstream>
#include <iostream>
#include <cstring>
#include "CPU_Scheduling.h"

using namespace std;

const int PROCESS_OFFSET = 38;


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
    int mySize = getSize(filename);
    int processesCount = mySize/PROCESS_OFFSET;
    cout << "size of file " << mySize << " with " << processesCount << " processes.\n" << endl;

    // Reads the content of the file
    FILE* content;
    content = fopen(filename, "rb");

    if (content == NULL) {
        cout << "Issue with reading the file. No such file." << endl;
        return EXIT_FAILURE;
    }

    //----------------------------------------------

    // Create an array of processes with the calculated length above
    Process array[processesCount];

    // Fill the array of processes with their respective data
    for (int x = 0; x < processesCount; ++x) {
        cout << "current i: " << 38 << endl;
        char buffer[PROCESS_OFFSET];
        fread(buffer, PROCESS_OFFSET, sizeof(char), content);

        char name[16];
        memcpy(&name, &buffer[0], 16);
        memcpy(array[x].name, name, sizeof(name));
        cout << "name: " << array[x].name << endl;

        memcpy(&array[x].id, &buffer[16], 4);
        cout << "id: " << array[x].id << endl;

        char activityStatus[1];
        memcpy(&activityStatus, &buffer[20], 21);
        array[x].activity =  (int) activityStatus[0];
        cout << "status: " << array[x].activity << endl;

        memcpy(&array[x].burst, &buffer[21], 25);
        cout << "burst: " << array[x].burst << endl;

        memcpy(&array[x].base, &buffer[25], 29);
        cout << "base: " << array[x].base << endl;

        memcpy(&array[x].limit, &buffer[29], 37);
        cout << "limit: " << array[x].limit << endl;

        char priority[1];
        memcpy(&priority, &buffer[37], 38);
        array[x].priority = (int) priority[0];
        cout << "priority: " << array[x].priority << "\n" << endl;
    }

    //----------------------------------------------

    // Close the file
    fclose(content);
    return 0;
}


int CPU_Scheduling::getSize(string filename) {
    ifstream infile( filename, ios::binary | ios::ate);
    return infile.tellg();
}