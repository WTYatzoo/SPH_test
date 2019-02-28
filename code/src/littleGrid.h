#ifndef _LITTLEGRID_
#define _LITTLEGRID_

#include <vector>
#include "myvector.h"
#include "vertex_data.h"
using namespace std;

class littleGrid
{
public:
	vertex_data myvertex[2][2][2];
	vector<int >*  particlesInLittleGrid;
	double lengthSide;

	littleGrid();
	littleGrid(double x,double y,double z,double lengthSide);

	~littleGrid();
	void calVertex();
	void reset();
};

#endif