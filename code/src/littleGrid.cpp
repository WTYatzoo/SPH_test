#include <vector>
#include "littleGrid.h"
using namespace std;

littleGrid::littleGrid()
{
	particlesInLittleGrid=new vector<int > ;
}

littleGrid::littleGrid(double x,double y,double z,double lengthSide)
{
	this->myvertex[0][0][0].vertex=myvector(x,y,z);
	this->lengthSide=lengthSide;
	particlesInLittleGrid=new vector<int > ;
	calVertex();
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			for(int k=0;k<2;k++)
			{
				myvertex[i][j][k].csComponent=0;
			}
		}
	}
}

littleGrid::~littleGrid()
{
	//delete particlesInLittleGrid;
}

void littleGrid::calVertex()
{
	myvertex[1][0][0].vertex=myvector(myvertex[0][0][0].vertex.x+lengthSide,myvertex[0][0][0].vertex.y,myvertex[0][0][0].vertex.z);
	myvertex[1][1][0].vertex=myvector(myvertex[1][0][0].vertex.x,myvertex[1][0][0].vertex.y+lengthSide,myvertex[1][0][0].vertex.z);
	myvertex[0][1][0].vertex=myvector(myvertex[0][0][0].vertex.x,myvertex[0][0][0].vertex.y+lengthSide,myvertex[0][0][0].vertex.z);
	myvertex[0][0][1].vertex=myvector(myvertex[0][0][0].vertex.x,myvertex[0][0][0].vertex.y,myvertex[0][0][0].vertex.z+lengthSide);
	myvertex[1][0][1].vertex=myvector(myvertex[1][0][0].vertex.x,myvertex[1][0][0].vertex.y,myvertex[1][0][0].vertex.z+lengthSide);
	myvertex[1][1][1].vertex=myvector(myvertex[1][1][0].vertex.x,myvertex[1][1][0].vertex.y,myvertex[1][1][0].vertex.z+lengthSide);
	myvertex[0][1][1].vertex=myvector(myvertex[0][1][0].vertex.x,myvertex[0][1][0].vertex.y,myvertex[0][1][0].vertex.z+lengthSide);
}

void littleGrid::reset()
{
	particlesInLittleGrid->clear();
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			for(int k=0;k<2;k++)
			{
				myvertex[i][j][k].csComponent=myvertex[i][j][k].cs=0;
			}
		}
	}
}
