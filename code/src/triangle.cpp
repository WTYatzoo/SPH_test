#include "triangle.h"

triangle::triangle()
{
	for(int i=0;i<3;i++)
	{
		vertex[i]=myvector();
    	normal_vector[i]=myvector();
	}
}

triangle::~triangle()
{
	;
}