#include "myvector.h"
#include "vertex_data.h"

vertex_data::vertex_data()
{
	vertex=myvector();
	normal_vector=myvector();
	csComponent=0;
}
vertex_data::~vertex_data()
{
	;
}