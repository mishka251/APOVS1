#define _USE_MATH_DEFINES =

#include<iostream>
#include <windows.h>
#include <math.h>
#include <cmath>
#include <map>
#include<vector>
#include <time.h>

using namespace std;

struct ThreadInfo {
    HANDLE handle;
    int id;
    bool active;
};

map<double, double> slowFunction() {
    //долго работающая функция
    int n = 10000;

    map<double, double> cos_map;
    for (int i = 0; i < n; ++i) {
        cos_map.clear();
        for (int degrees = 0; degrees < 360; degrees++) {
            double radians = degrees / 180.0 * M_PI;
            cos_map[radians] = cos(radians);
        }
    }
    return cos_map;
}

int getProcessorsCount() {
    SYSTEM_INFO SystemInfo;
    GetSystemInfo(&SystemInfo);
    return SystemInfo.dwNumberOfProcessors; // shows number of processors
}


// Функция пользовательского потока
DWORD WINAPI MyThread(LPVOID lpParameter) {
    bool *Active;
    Active = (bool *) lpParameter;
    *Active = true;    // флаг активности потока

    // Поместите сюда свой код
    map<double, double> cos_map = slowFunction();
    for (auto par: cos_map) {
        cout << "cos(" << par.first << ") = " << par.second << endl;
    }

    // Завершение потока
    *Active = false;  // Сбрасываем флаг активности
    // ...........(0);    // Специальный вызов для закрытия потока
    return (0);
}

vector<ThreadInfo> threads;

void InitThread() {
    int numberProcessors = getProcessorsCount();

    std::cout << "processors=" << numberProcessors << std::endl;

    threads = vector<ThreadInfo>(numberProcessors);
    for (auto & thread : threads) {
        thread.active = true;
        // Создаем поток, передавая определенную пользователем
        // переменную, которая используется для хранения
        // состояния потока
        thread.handle = CreateThread(NULL,
                                         0,
                                         (LPTHREAD_START_ROUTINE) MyThread,
                                         (void *) &thread.active,
                                         0,
                                         NULL);
    }

    // Ждем завершения выполнения потоков, проверяя состояние флагов

    while (true) {
        bool anyActive = false;
        for (auto threadInfo: threads) {
            anyActive = anyActive || threadInfo.active;
        }
        if (!anyActive) {
            break;
        }
    }

    // Закрываем дескрипторы потоков
    for (auto threadInfo: threads) {
        HANDLE hThread = threadInfo.handle;
        CloseHandle(hThread);
    }

}

int main(int argc, char *argv[]) {
    time_t t = time(NULL);
    cout << "The number of seconds since January 1, 1970 is " << t << endl;
    InitThread();
//    printf("OK\n");
    time_t t1 = time(NULL);
    t1 = t1 - t;
    cout << "Elapsed time in seconds is "<< t1 <<", Bye!" << endl;
    return 0;
}

