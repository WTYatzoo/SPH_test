#ifndef _PARTICLE_
#define _PARTICLE_

#include "myvector.h"

class particle 
{
public:
	myvector location;  //位置
	myvector speed; //速度
	myvector speed_equal; // 此刻速度和下一刻速度的均值
	myvector a_sp; //加速度
	double density; //密度
	double pressure; //压力
	
	particle();
	particle(double x,double y,double z);
	particle(const particle& part); //拷贝构造函数参数必须是const性质的同类引用
	~particle();
	
	void drawParticle();
	void drawParticle(double d_max,double d_min);
	
	void reSet();
	void calPressure();
	void calLoactionAndSpeed(double tim,double l,double w,double h);
};

#endif

