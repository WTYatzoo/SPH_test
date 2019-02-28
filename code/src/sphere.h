#ifndef _SPHERE_
#define _SPHERE_

#include <vector>
#include "myvector.h"
#include "particle.h"
#include "cube.h"
using namespace std;
class sphere
{
public:
	myvector center;
	double radius;
	int num_particles;
	vector<particle > particles_inSphere;
	sphere(myvector center,double radius);
	~sphere();

	void calNumParticles();
	void createParticles();
	void testDrawParticlesinSphere();
};
#endif