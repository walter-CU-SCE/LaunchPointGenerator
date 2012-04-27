#ifndef TIMEKEEPER_HPP
#define TIMEKEEPER_HPP

#include <iostream>

#ifndef _WIN32 // Assume POSIX
#include <sys/resource.h>
#else
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#endif

using namespace std;

namespace LPG{


	// user space execution time counter
	class TimeKeeper{
	  private:
#ifndef _WIN32
		struct timeval startTime;	//time clock starts
#else
		FILETIME startTime;
#endif
	  public:
		TimeKeeper();
		
		double getElapsedTimeSec() const; 	//get the time elapsed from startTime til now
		void reset();                   //set the timer
	};

};

#endif