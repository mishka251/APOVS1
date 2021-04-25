#pragma hdrstop

//#include <condefs.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <math.h>
#include <windows.h>


//#define CREATE_SUSPENDED 0x00000004

time_t t, t1;
long int ii;
float x, y, step = .001;


int getProcessorsCount(){
    SYSTEM_INFO SystemInfo;
    GetSystemInfo(&SystemInfo);
    return SystemInfo.dwNumberOfProcessors; // shows number of processors
}

// Функция пользовательского потока
DWORD WINAPI MyThread(LPVOID lpParameter) {
    BOOL *Active;
    Active = (BOOL *) lpParameter;
    *Active = TRUE;    // флаг активности потока

    // Поместите сюда свой код
    //....................................
    //....................................
    // Завершение потока
    *Active = FALSE;  // Сбрасываем флаг активности
   // ...........(0);    // Специальный вызов для закрытия потока
    return (0);
}

//+++++++++++++++++++++++++
long int ii1;
//float x1, y1, step1 = .001;
// Функция второго пользовательского потока
//...................................
//...................................
//+++++++++++++++++++++++++

void InitThread(void) {
    int nmbPrc;
    HANDLE hThread, hThread1;
    DWORD ThreadId, ThreadId1;
    BOOL Active = TRUE, Active1 = TRUE;

    SYSTEM_INFO SystemInfo;
    GetSystemInfo(&SystemInfo);
    nmbPrc = SystemInfo.dwNumberOfProcessors; // shows number of processors
    printf("\nNumber of CPU Cores: nmbPrc=%d\n", nmbPrc);

    // Создаем поток, передавая определенную пользователем
    // переменную, которая используется для хранения
    // состояния потока
//    hThread = .............(NULL, 0,
//            (LPTHREAD_START_ROUTINE) MyThread,
//            (void *) &Active, ......., &ThreadId);

//-----------------------------
    // Создаем второй поток, передавая определенную пользователем
    // переменную, которая используется для хранения
    // состояния потока

    //...........................
    //...............................
    printf("\nThreads IDs %x %x \n", ThreadId, ThreadId1);

    t = time(NULL);

    HANDLE hProcess = GetCurrentProcess();
    DWORD dwProcessAffinityMask, dwSystemAffinityMask;
//    GetProcessAffinityMask(hProcess, &dwProcessAffinityMask, &dwSystemAffinityMask);

//    printf("\nProcessAffinityMask / SystemAffinityMask: %x / %x\n",
//           dwProcessAffinityMask, dwSystemAffinityMask);

    // Ждем завершения выполнения потоков, проверяя состояние флагов

    //while ((Active == TRUE) || (Active1 == TRUE));

    // Закрываем дескрипторы потоков
   // ...........(hThread);
//    ...........(hThread1);
//-----------------------------
}

//+++++++++++++++++++++++++++
int main(int argc, char *argv[]) {
//    t = time(NULL);
//    printf("\nThe number of seconds since January 1, 1970 is %ld", t);
//
//    InitThread();
//    t1 = time(NULL);
//    t1 = t1 - t;
//    printf("Elapsed time in seconds is %ld, Bye!\n", t1);

    printf("processors=%d\n", getProcessorsCount());
    getch();
    return 0;
}



