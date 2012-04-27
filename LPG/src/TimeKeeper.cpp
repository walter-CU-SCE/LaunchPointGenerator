#include "TimeKeeper.hpp"

using namespace std;
using namespace LPG;

TimeKeeper::TimeKeeper(){

    reset();
	//getrusage(RUSAGE_SELF, &ru);
	//startTime=ru.ru_utime;		//set start time
	
};

double TimeKeeper::getElapsedTimeSec() const{

    rusage ru;
    getrusage(RUSAGE_SELF, &ru);

    const timeval curTime=ru.ru_utime;	// time now

    double tS = startTime.tv_sec + (startTime.tv_usec)*1e-6;
    double tE = curTime.tv_sec  + (curTime.tv_usec)*1e-6;

    return tE-tS;

};

void TimeKeeper::reset(){
    rusage ru;
    getrusage(RUSAGE_SELF, &ru);
    startTime=ru.ru_utime;		//set start time
};