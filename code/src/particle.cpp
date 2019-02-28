#include <stdio.h>
#include <stdlib.h>
//#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <vector>
#include "physic.h"
#include "myvector.h"
#include "particle.h"

using namespace std;

particle::particle()
{
	;
}

particle::particle(double x,double y,double z) 
{
	location.set(x,y,z);
}
//形参如果不是引用，会在内存中分配空间，无论是不是基本数据类型还是类，而如果是引用，则只有实参一份存在内存中，形参不分配空间
particle::particle(const particle& part)  //拷贝构造函数参数必须是const性质的同类引用  const保证不能在函数中修改原来的类
{
	location=myvector(part.location);
	speed=myvector(part.speed);
}

particle::~particle()
{
	;
}

void particle::drawParticle()
{
	if(density>=physic::threshold)
	{
		double r=physic::r_smoothCore/6;
		glColor3d(0,0,1);
		glPushMatrix();
		glTranslated(location.x,location.y,location.z);
		glutSolidSphere(r,30,30);
    	glPopMatrix();
	}	
}


void particle::drawParticle(double d_max,double d_min)
{
	double percentage=(density-d_min)/(d_max-d_min);
	int key=floor(percentage*7.0);
	if(key==0)
	{
		printf("%lf\n",density);
	}
	glBegin(GL_POINTS);
	glColor3dv(physic::color[key]);
	glVertex3d(location.x,location.y,location.z);
	glEnd();
}

void particle::reSet() //密度重新计算  压力和加速度均根据密度重算以后的新值重新计算 加速度重置成只受系统重力加速度
{
	density=0.0; 
	a_sp=myvector(0,0,0);
}

void particle::calPressure()
{
	pressure=physic::gasK*(density-physic::staticDensity);
}

void particle::calLoactionAndSpeed(double tim,double l,double w,double h)
{
	double speed_limit_square=physic::speedLimiting*physic::speedLimiting;
	
	//速度限制
	double a_sp_2 = a_sp.len_sq();
	if(a_sp_2>speed_limit_square)
	{
		a_sp*= physic::speedLimiting/sqrt(a_sp_2);
	}	
	
	//X轴
	double diff=0.005-location.x;
	if (diff>0) 
	{
		myvector norm=myvector(1,0,0);
		double adj=physic::stiffness*diff-physic::dampening*norm.dot(speed_equal);
		a_sp+=(adj*norm);			
	}
	
	diff=0.005-(l-location.x);	
	if (diff>0) 
	{
		myvector norm=myvector(-1,0,0);
		double adj=physic::stiffness*diff-physic::dampening*norm.dot(speed_equal);
		a_sp+=(adj*norm);	
	}
	
	//Y轴
	diff=0.005-location.y;
	if (diff>0) 
	{
		myvector norm=myvector(0,1,0);
		double adj=physic::stiffness*diff-physic::dampening*norm.dot(speed_equal);
		a_sp+=(adj*norm);					
	}
	
	diff=0.005-(w-location.y);	
	if (diff>0) 
	{
		myvector norm=myvector(0,-1,0);
		double adj=physic::stiffness*diff-physic::dampening*norm.dot(speed_equal);
		a_sp+=(adj*norm);	
	}
	
	//Z轴
	diff=0.012-location.z;
	if(diff>0) 
	{
		myvector norm=myvector(0,0,1);
		double adj=physic::stiffness*diff-physic::dampening*norm.dot(speed_equal);
		a_sp+=(adj*norm);						
	}
	
	diff=0.012-(h-location.z);	
	if(diff>0) 
	{
		myvector norm=myvector(0,0,-1);
		double adj=physic::stiffness*diff-physic::dampening*norm.dot(speed_equal);
		a_sp+=(adj*norm);		
	}

	a_sp+=physic::a_gravity;
	//蛙跳积分法
	myvector speed_next;
	speed_next=speed+tim*a_sp;
	speed_equal=(speed+speed_next)*0.5;
	speed=speed_next;
	location+=speed*tim;
	
	location.x=max(0.00000000001,location.x); location.x=min(location.x,l-0.00000000001);
	location.y=max(0.00000000001,location.y); location.y=min(location.y,w-0.00000000001);
	location.z=max(0.00000000001,location.z); location.z=min(location.z,h-0.00000000001);
	
}
