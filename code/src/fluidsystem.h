#ifndef _FLUIDSYSTEM_
#define _FLUIDSYSTEM_

#include <vector>
#include "myvector.h"
#include "particle.h"
#include "cube.h"
#include "sphere.h"
#include "grid.h"
#include "littleGrid.h"
#include "triangle.h"
using namespace std;
class fluidsystem
{
public:
	myvector vertex[8];
	double length_max,width_max,height_max; 
	double tim;//时间步长 

	int key;

	double kernelPoly6; // 光滑核常量 
	double kernelSpiky; // 光滑核常量    
	double kernelViscosity; //光滑核常量  

	double density_max,density_min;
	
	vector<particle >  myparticles;
	vector<triangle >  mytriangles;
	
	double length_grid_side; //立方体边长
	
	int l_div,w_div,h_div;
	
	grid*** mygrid;
	littleGrid**** mylittlegird;
	int buffer_now; //当前格子维护粒子所使用的链表下标
	
	fluidsystem(cube* mycube,sphere* mysphere);
	~fluidsystem();

	void calVertex();

	unsigned int loadTexture(char* filename);
	
	void drawThis();
	void drawThisInAnotherWayPart1();
	void drawThisInAnotherWayPart2();

	void allocateGrids();
	void allocateParticlesToGrids();
	void drawParticles(int frame_now);
	
	void testDrawGrids();
	void testDrawParticlesFromGrids();
	
	void resetParticles();
	
	void createGrid(int num,int loc_test[8][3]);
	int isCorrect(int who,int loc_test[8][3]);
	double R_square_sub_dis_square(int a,int b);
	double R_square_sub_dis_square(myvector& a,myvector& b);
	double R_sub_dis(int a,int b);
	void calDensity();
	void calPressure();
	void calA();
	void calLocationAndSpeed();
	void Re_allocateParticlesToGrids();

	myvector calinWhichLittleGrid(myvector& a,myvector& b);
	void allocateParticlesToLittleGrids();
	void calDenstityComponentInLittleGrid();
	void calDensityOfVertexOfLittleGrid();
	void calNormalOfVertexOfLittleGrid() ;
	void getTriangleFrom(vector<vertex_data >& vector_x);
	void getTriangleFromLittleGrid();
	void correctTriangles();
	void drawTriangles();
	
	void flowOfCalculate(int frame_now);
	
};

#endif
