#include <cmath> //abs, pow
#include "Cluster.hpp"

using namespace std;
using namespace LPG;


Cluster::Cluster(Point P){
    lPoints.push_back(P);
    lpIndex=0;
};

Cluster::~Cluster(){
};

Cluster::Cluster(const Cluster &C){
    lPoints = C.lPoints;
    lpIndex = C.lpIndex;
};

Cluster& Cluster::operator=(const Cluster &C){
    if(this != &C)
    {
        lPoints = C.lPoints;
        lpIndex = C.lpIndex;
    }
    return *this;
};

void Cluster::addPoint(Point P){
    lPoints.push_back(P);
    if(lPoints[lpIndex].morePromising(P))
        lpIndex=lPoints.size()-1;
};

Point Cluster::getLaunchPoint() const {

    if(lpIndex>lPoints.size() || lpIndex<0){
        cerr << "lpIndex out of Range!" << endl;
        exit(0);
    }
  return lPoints[lpIndex];
};