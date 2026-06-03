#include "Logger.h"
#include <fstream>
#include <ctime>

using namespace std;

void Logger::scrieLog(string mesaj)
{
    ofstream fisier("log.txt", ios::app);

    if (fisier.is_open())
    {
        time_t acum = time(0);
        char buffer[26];

        ctime_s(buffer, sizeof(buffer), &acum);

        fisier << "[" << buffer << "] " << mesaj << endl;
        fisier.close();
    }
}