#include "TimeKeeper.hpp"

using namespace std;
using namespace LPG;

TimeKeeper::TimeKeeper() {

    reset();
};

double TimeKeeper::getElapsedTimeSec() const {
#ifndef _WIN32
    rusage ru;
    getrusage(RUSAGE_SELF, &ru);

    const timeval curTime = ru.ru_utime; // time now

    double tS = startTime.tv_sec + (startTime.tv_usec) * 1e-6;
    double tE = curTime.tv_sec  + (curTime.tv_usec) * 1e-6;

    return tE - tS;
#else
    FILETIME creationTime;
    FILETIME exitTime;
    FILETIME kernelTime;
    FILETIME curTime;

    if (!GetProcessTimes(GetCurrentProcess(),
                         &creationTime,
                         &exitTime,
                         &kernelTime,
                         &curTime)) {
        return 0.0;    // TODO: Handle error
    }

    ULARGE_INTEGER curTimeUInt;
    ULARGE_INTEGER startTimeUInt;

    curTimeUInt.LowPart = curTime.dwLowDateTime;
    curTimeUInt.HighPart = curTime.dwHighDateTime;

    startTimeUInt.LowPart = startTime.dwLowDateTime;
    startTimeUInt.HighPart = startTime.dwHighDateTime;

    return (curTimeUInt.QuadPart - startTimeUInt.QuadPart) * 1e-7;
#endif
};

void TimeKeeper::reset() {
#ifndef _WIN32
    rusage ru;
    getrusage(RUSAGE_SELF, &ru);
    startTime = ru.ru_utime;    //set start time
#else
    FILETIME creationTime;
    FILETIME exitTime;
    FILETIME kernelTime;

    if (!GetProcessTimes(GetCurrentProcess(),
                         &creationTime,
                         &exitTime,
                         &kernelTime,
                         &startTime)) {
        startTime.dwLowDateTime = 0;
        startTime.dwHighDateTime = 0;
    }

    return;
#endif
};