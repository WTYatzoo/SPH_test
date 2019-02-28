#ifndef _GRID_
#define _GRID_

#include <queue>
#include "myvector.h"
#include "particle.h"
#include "littleGrid.h"
using namespace std;

class grid  
{
public:
	myvector vertex[8]; 
	queue<int >*  particlesInGrid[2];
	double lengthSide;
	littleGrid subgrid[2][2][2];

	grid();
	grid(double x,double y,double z,double lengthSide);
	void calVertex();
	void reset();
	~grid();
};

#endif
