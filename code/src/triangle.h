#ifndef _TRIANGLE_
#define _TRIANGLE_

#include "myvector.h"
class triangle
{
public :
	myvector vertex[3];
	myvector normal_vector[3]; 
	triangle();
	~triangle();
};

#endif