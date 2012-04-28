#ifndef CLUSTERBUILDER_HPP
#define CLUSTERBUILDER_HPP

#include <iostream>
#include <vector>

#include "Point.hpp"
#include "Cluster.hpp"
#include "TimeKeeper.hpp"

using namespace std;

namespace LPG {

    struct PromPeak {       //structure for prominent peaks
        int bin;            //index of pp
        double d;           //distance pp corresponds to
        int F;           //frequency at index
    };

    struct Dist {
        int p1;             //index of first point
        int p2;             //index of second point
        double dist;        //distance between points
    };

    struct Freq {
        int F;              //frequency
        double d;           //bin center
    };

    class ClusterBuilder {
        private:
            vector<Point> allPoints;        //all points
            vector<PromPeak> promPeaks;     //prominent peaks
            vector<Cluster> lClusters;      //list of clusters
            int w;                          //window size
            int tau;                        //maximuim number of clusters
            double cDist;                   //critical distance
            double dmin;                    //minimum distance
            double dmax;                    //maximum distance
            double dwidth;                  //width of each bin
            vector<Dist> d;                 //distances
            vector<Freq> F;                 //frequencies
            double time;                    //time variable
            TimeKeeper Tk;                  //measure elapsed time

            void calcDistances();           //calcualte the distances between each point
            void calcFrequencies();         //calcualte the frequencies associated with each bin
            void extractPP();               //extract the prominent peaks from the interpoint frequncy distribution
            int cluster();                  //use sinlge linkage and cDist to form clusters

        public:
            ClusterBuilder(const vector<Point> &lPoints, int w, int tau);
            ~ClusterBuilder();              //destructor

            vector<Freq> getFreq() const;         //returns the frequency distrbution
            vector<Cluster> getClusters() const;  //returns the vector of clusters
            vector<Point> getLaunchPoints() const;//return a vector of launch points
            double getTime() const;               //return calculation time
    };

};

#endif