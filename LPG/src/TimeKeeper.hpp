#ifndef TIMEKEEPER_HPP
#define TIMEKEEPER_HPP

#include <iostream> 
#include <sys/resource.h>

using namespace std;

namespace LPG{


	// user space execution time counter
	// POSIX specific code!
	class TimeKeeper{		
	  private:
		struct timeval startTime;	//time clock starts
	  public:
		TimeKeeper();
		
		double getElapsedTimeSec() const; 	//get the time elapsed from startTime til now
		void reset();                   //set the timer
	};

};

#endif