#ifndef _VERTEX_DATA_
#define _VERTEX_DATA_

#include "myvector.h"

class vertex_data
{
public:
	myvector vertex;
	myvector normal_vector; //法向量
	double  csComponent; //颜色域分量
	double cs; //总的颜色域的量
	int mark; //用来判断比阈值大还是小
	vertex_data();
	~vertex_data();

};

#endif