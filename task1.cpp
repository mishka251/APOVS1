#include <iostream>
#include <windows.h>


int getProcessorsCount() {
    SYSTEM_INFO SystemInfo;
    GetSystemInfo(&SystemInfo);
    return SystemInfo.dwNumberOfProcessors; // get number of processors
}

int main(int argc, char *argv[]) {
    std::cout << "processors=" << getProcessorsCount() << std::endl;
    return 0;
}

