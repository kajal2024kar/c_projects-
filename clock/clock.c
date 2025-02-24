#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

void getTime(char *buffer, size_t bufferSize);
void getdate(char *buffer, size_t bufferSize);
void clear()
{
   #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
    
}

int main()
{
    char timeStr[30];
    char date[50];

    while(1){
        getTime(timeStr, sizeof(timeStr));
        getdate(date, sizeof(date));
        printf("Current time: %s\n", timeStr);
        printf("Current date: %s\n", date);

        sleep(1);
        clear();
    }
    return 0;
}
void getTime(char *buffer, size_t bufferSize)
{
    time_t rawtime;
    struct tm *localTime;

    time(&rawtime);
    localTime = localtime(&rawtime);
    strftime(buffer, bufferSize, "%I:%M:%S %p", localTime);
}
void getdate(char *buffer, size_t bufferSize)
{
    time_t rawtime;
    struct tm *localTime;

    time(&rawtime);
    localTime = localtime(&rawtime);
    strftime(buffer, bufferSize, "%A %B %d %Y", localTime);
}