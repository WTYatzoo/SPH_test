#include <stdio.h>
#include <stdlib.h>
//#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <vector>
#include "grid.h"

using namespace std;

grid::grid()
{
	;
}

grid::grid(double x,double y,double z,double lengthSide)
{
	vertex[0]=myvector(x,y,z);
	calVertex();
	this->lengthSide=lengthSide;
	particlesInGrid[0]=new queue<int >;
	particlesInGrid[1]=new queue<int >;

	double halfL=lengthSide/2.0;
	//空间格子细分
	{
		subgrid[0][0][0]=littleGrid(x,y,z,halfL);
		subgrid[1][0][0]=littleGrid(x+halfL,y,z,halfL);
		subgrid[1][1][0]=littleGrid(x+halfL,y+halfL,z,halfL);
		subgrid[0][1][0]=littleGrid(x,y+halfL,z,halfL);
		subgrid[0][0][1]=littleGrid(x,y,z+halfL,halfL);
		subgrid[1][0][1]=littleGrid(x+halfL,y,z+halfL,halfL);
		subgrid[1][1][1]=littleGrid(x+halfL,y+halfL,z+halfL,halfL);
    	subgrid[0][1][1]=littleGrid(x,y+halfL,z+halfL,halfL);
	}

	
}

void grid::calVertex()
{
	vertex[1]=myvector(vertex[0].x+lengthSide,vertex[0].y,vertex[0].z);
	vertex[2]=myvector(vertex[1].x,vertex[1].y+lengthSide,vertex[1].z);
	vertex[3]=myvector(vertex[0].x,vertex[0].y+lengthSide,vertex[0].z);
	
	for(int i=4;i<8;i++)
	{
		vertex[i]=myvector(vertex[i-4].x,vertex[i-4].y,vertex[i-4].z+lengthSide);
	}
}

void grid::reset()
{
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			for(int k=0;k<2;k++)
			{
				subgrid[i][j][k].reset();
			}
		}
	}
}

grid::~grid()
{
/*
	delete particlesInGrid[0];
	delete particlesInGrid[1];*/

}
