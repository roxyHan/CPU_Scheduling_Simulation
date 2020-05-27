#include <iostream>
#include "CPU_Scheduling.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Only the filename needs to be provided to proceed with this program." << std::endl;
        return EXIT_FAILURE;
    }
    // Get the filename from cmd arguments
    const char *filename = argv[1];

    CPU_Scheduling* scheduling = new CPU_Scheduling();
    scheduling->main(filename);
    delete scheduling;
    return 0;
}
