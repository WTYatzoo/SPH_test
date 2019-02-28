#include <stdio.h>
#include <stdlib.h>
//#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include "physic.h"
#include "myvector.h"
#include "particle.h"
#include "sphere.h"

using namespace std;

sphere::sphere(myvector center,double radius)
{
	this->center=myvector(center);
	this->radius=radius;
	calNumParticles();
	createParticles();
}

sphere::~sphere()
{
	;
}

void sphere::calNumParticles()
{
	double siz=4.0/3.0*physic::pi*pow(radius,3);
	double siz_particle=physic::particleMass/physic::staticDensity;
	num_particles=siz/siz_particle;
}

void sphere::createParticles()
{
	particles_inSphere.clear();
	double r,a,b,x,y,z;
	double pi=physic::pi;
	for(int i=0;i<num_particles;i++)
	{
		r=(double)rand()/(double)RAND_MAX*radius;
		a=(double)rand()/(double)RAND_MAX;
		b=(double)rand()/(double)RAND_MAX;
		x=center.x+r*sin(pi*a)*cos(2*pi*b);
		y=center.y+r*sin(pi*a)*sin(2*pi*b);
		z=center.z+r*cos(pi*a);
		particles_inSphere.push_back(particle(x,y,z));
	}
}

void sphere::testDrawParticlesinSphere()
{
	int siz=particles_inSphere.size();
	for(int i=0;i<siz;i++)
	{
		glBegin(GL_POINTS);
		{
			glVertex3d(particles_inSphere[i].location.x,particles_inSphere[i].location.y,particles_inSphere[i].location.z);
		}
		glEnd();
	}
}
