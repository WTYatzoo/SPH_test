#include "physic.h"

const double physic::stiffness=10000;
const double physic::dampening=20; //40
const double physic::speedLimiting=700; //500
const double physic::r_smoothCore=0.01;
const double physic::staticDensity=1000;
const double physic::staticViscosity=0.2; //1
const double physic::gasK=1;
//const double physic::particleMass=0.00004;
const double physic::particleMass=0.000005; //0.00002
const myvector physic::a_gravity=myvector(0,0,-9.8);
const double physic::pi=3.141592653589793238;
const double physic::color[7][3]={0.54,0,1,0,0,1,0,1,1,0,1,0,1,1,0,1,0.5,0,1,0,0 }; //²ÊºçµÄRGB·ÖÁ¿
const double physic::threshold=400;
