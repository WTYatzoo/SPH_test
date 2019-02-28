#ifndef _PHYSIC_
#define _PHYSIC_

#include "myvector.h"
class physic
{
public:
	static const double stiffness; //墙的硬度系数
	static const double dampening; //墙的回潮系数
	static const  double speedLimiting; //速度限制
	static const double r_smoothCore; //光滑核半径   
	static const double staticDensity; //水的静态密度  
	static const double staticViscosity; //粘度系数   
	static const double gasK; //理想气体方程常量K     
	static const double particleMass; //粒子质量    
	static const myvector a_gravity; //重力加速度
	static const double pi;
    static const double color[7][3]; //彩虹颜色值
	static const double  threshold; //阈值用来判断是否是水面 trick

};

#endif