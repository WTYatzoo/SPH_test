#ifndef _CUBE_
#define _CUBE_

#include "myvector.h"
#include "particle.h"
#include <vector>
using namespace std;

class cube
{
public:
	myvector vertex[8]; //顶点
	double width,height,length; 
	double len_side; //边长 用于有序生成粒子时的计算 
	int num_particles;
	
	vector<particle > particles_inCube;
	
	cube(double x_min,double y_min,double z_min,double length,double width,double height);
	~cube();

	void calVertex();
	void createParticles();
	void createParticlesInOrder();
	void testDrawParticlesinPool();
};

#endif
