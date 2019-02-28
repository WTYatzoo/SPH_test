#include <stdio.h>
#include <stdlib.h>
//#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include "physic.h"
#include "particle.h"
#include "cube.h"

using namespace std;

cube::cube(double x_min,double y_min,double z_min,double length,double width,double height)
{
	vertex[0]=myvector(x_min,y_min,z_min);
	this->length=length; this->width=width; this->height=height;
	double siz=length*width*height;
	double siz_particle=physic::particleMass/physic::staticDensity;
	num_particles=floor(siz/siz_particle);
	calVertex();
	createParticlesInOrder();
	//createParticlesInOrder();
}

cube::~cube()
{
	;
}

void cube::calVertex()
{
	vertex[1]=myvector(vertex[0].x+length,vertex[0].y,vertex[0].z);
	vertex[2]=myvector(vertex[1].x,vertex[1].y+width,vertex[1].z);
	vertex[3]=myvector(vertex[0].x,vertex[0].y+width,vertex[0].z);
	
	for(int i=4;i<8;i++)
	{
		vertex[i]=myvector(vertex[i-4].x,vertex[i-4].y,vertex[i-4].z+height);
	}
}

void cube::createParticlesInOrder()
{
	int i,j,k;
	particles_inCube.clear();

	double siz_particle=physic::particleMass/physic::staticDensity;
	double len_side=pow(siz_particle,1.0f/3.0f);

	int l_div=floor(length/len_side);
	int w_div=floor(width/len_side);
	int h_div=floor(height/len_side);
	num_particles=l_div*w_div*h_div;  //重新计算粒子数，因为与以前的值可能因为计算精度而存在误差

	double x,y,z;
	for(i=0,x=vertex[0].x+len_side/2.0;i<l_div;i++,x+=len_side)
	{
		for(j=0,y=vertex[0].y+len_side/2.0;j<w_div;j++,y+=len_side)
		{
			for(k=0,z=vertex[0].z+len_side/2.0;k<h_div;k++,z+=len_side)
			{
				particles_inCube.push_back(particle(x,y,z));
			}
		}
	}
}


void cube::createParticles()
{
	particles_inCube.clear();
	double x,y,z;
	for(int i=0;i<num_particles;i++)
	{
		x=(double)rand()/(double)RAND_MAX*length+vertex[0].x;
		y=(double)rand()/(double)RAND_MAX*width+vertex[0].y;
		z=(double)rand()/(double)RAND_MAX*height+vertex[0].z;
		particles_inCube.push_back(particle(x,y,z));
	}
}

void cube::testDrawParticlesinPool()
{
	int siz=particles_inCube.size();
	for(int i=0;i<siz;i++)
	{
		glBegin(GL_POINTS);
		{
			glVertex3d(particles_inCube[i].location.x,particles_inCube[i].location.y,particles_inCube[i].location.z);
		}
		glEnd();
	}
}
