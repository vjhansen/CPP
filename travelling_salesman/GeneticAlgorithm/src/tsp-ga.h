//  Travelling Salesman Problem, Genetic algorithms (GAs)


#ifndef TSPG_H
#define TSPG_H

#include <iostream>
#include <vector>
#include <set> 
#include <algorithm> 
#include "point.h"   

class TSPGenome
{
 private:
    double circuitLength;  // total distance covered when points are visited in a specified order
    std::vector<int> visitOrder;  // the order which the points will be visited
 
 public:
    TSPGenome() {}
    TSPGenome(int numPoints);  // constructor that takes # of points to visit
    TSPGenome(const std::vector<int> &order);  // constructor that takes order to visit
    ~TSPGenome() {;}

    std::vector<int> getOrder() const {return visitOrder;}
    double getCircuitLength() const {return circuitLength;}

    void computeCircuitLength(const std::vector<Point>& points);
    void mutate(); 
};


TSPGenome findAShortPath(const std::vector<Point>& points,
    int populationSize, int numGenerations,
    int keepPopulation, int numMutations);

//  create offspring
TSPGenome crosslink(const TSPGenome& g1, const TSPGenome& g2);

#endif
