#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
//#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <vector>
#include <string>
#include <sstream>
#include "physic.h"
#include "particle.h"
#include "sphere.h"
#include "cube.h"
#include "grid.h"
#include "fluidsystem.h"
#include "vertex_data.h"
#include "triangle.h"

using namespace std;


static int loaction_add[8][3]={
	-1,-1,-1,
		-1,-1,1,
		-1,1,-1,
		-1,1,1,
		1,-1,-1,
		1,-1,1,
		1,1,-1,
		1,1,1
};



unsigned int fluidsystem::loadTexture(char* filename)
{
    // 	FILE *filePtr;								
    // 	BITMAPFILEHEADER	bitmapFileHeader;		
    // 	BITMAPINFOHEADER  bitmapInfoHeader;
    // 	unsigned char		*bitmapImage;		
    // 	int					imageIdx = 0;		
    // 	unsigned char		tempRGB;				
	
    // 	filePtr = fopen(filename, "rb");
    // 	fread(&bitmapFileHeader, sizeof(BITMAPFILEHEADER), 1, filePtr);
    // 	fread(&bitmapInfoHeader, sizeof(BITMAPINFOHEADER), 1, filePtr);
    // 	fseek(filePtr, bitmapFileHeader.bfOffBits, SEEK_SET);
    // 	bitmapImage = (unsigned char*)malloc(bitmapInfoHeader.biSizeImage);
    // 	fread(bitmapImage, 1, bitmapInfoHeader.biSizeImage, filePtr);
	
    // 	// BGR to RGB
    // 	for (imageIdx = 0; imageIdx < bitmapInfoHeader.biSizeImage; imageIdx+=3)
    // 	{
    // 		tempRGB = bitmapImage[imageIdx];
    // 		bitmapImage[imageIdx] = bitmapImage[imageIdx + 2];
    // 		bitmapImage[imageIdx + 2] = tempRGB;
    // 	}
    // 	fclose(filePtr);
	
    	unsigned int Texture; 
    // glGenTextures(1,&Texture);
    // 	glBindTexture(GL_TEXTURE_2D,Texture);
    // 	glPixelStorei(GL_UNPACK_ALIGNMENT,1);
	
    // 	glTexImage2D(GL_TEXTURE_2D,0,3,bitmapInfoHeader.biWidth,bitmapInfoHeader.biHeight,0,GL_RGB, GL_UNSIGNED_BYTE,bitmapImage);
    // 	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    // 	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    // 	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT);
    // 	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	
    // 	if (bitmapImage)
    // 	{
    // 		free(bitmapImage); 
    // 	}
	
  return Texture;
}

void fluidsystem::drawThisInAnotherWayPart1()
{
	
	int i;
	glBindTexture(GL_TEXTURE_2D,key);
	
	glColor3d(1,1,1);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE); //设置纹理和材料颜色的混合方式
	
	glBegin(GL_QUADS);
	{
		glNormal3b(0,0,1); glTexCoord2d(0,0);
		glVertex3d(vertex[0].x,vertex[0].y,vertex[0].z);
		glNormal3b(0,0,1); glTexCoord2d(1,0);
		glVertex3d(vertex[1].x,vertex[1].y,vertex[1].z);
		glNormal3b(0,0,1); glTexCoord2d(1,1);
		glVertex3d(vertex[2].x,vertex[2].y,vertex[2].z);
		glNormal3b(0,0,1); glTexCoord2d(0,1);
		glVertex3d(vertex[3].x,vertex[3].y,vertex[3].z);
		
	}
	glEnd();
	
	glBegin(GL_QUADS);
	{
		glNormal3b(1,0,0); glTexCoord2d(0,0);
		glVertex3d(vertex[0].x,vertex[0].y,vertex[0].z);
		glNormal3b(1,0,0); glTexCoord2d(1,0);
		glVertex3d(vertex[3].x,vertex[3].y,vertex[3].z);
		glNormal3b(1,0,0); glTexCoord2d(1,1);
		glVertex3d(vertex[7].x,vertex[7].y,vertex[7].z);
		glNormal3b(1,0,0); glTexCoord2d(0,1);
		glVertex3d(vertex[4].x,vertex[4].y,vertex[4].z);
	}
	glEnd();
	
	glBegin(GL_QUADS);
	{
		glNormal3b(0,-1,0); glTexCoord2d(0,0);
		glVertex3d(vertex[3].x,vertex[3].y,vertex[3].z);
		glNormal3b(0,-1,0); glTexCoord2d(1,0);
		glVertex3d(vertex[2].x,vertex[2].y,vertex[2].z);
		glNormal3b(0,-1,0); glTexCoord2d(1,1);
		glVertex3d(vertex[6].x,vertex[6].y,vertex[6].z);
		glNormal3b(0,-1,0); glTexCoord2d(0,1);
		glVertex3d(vertex[7].x,vertex[7].y,vertex[7].z);
	}
	glEnd();

	glColor3f(0.5,0,0);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_BLEND);
	
}

void fluidsystem::drawThisInAnotherWayPart2()
{
	
	glColor3f(0.5,0,0);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_BLEND);
	
	glBegin(GL_LINES);
	glVertex3d(vertex[4].x,vertex[4].y,vertex[4].z);
	glVertex3d(vertex[5].x,vertex[5].y,vertex[5].z);
	glVertex3d(vertex[5].x,vertex[5].y,vertex[5].z);
	glVertex3d(vertex[1].x,vertex[1].y,vertex[1].z);
	glVertex3d(vertex[5].x,vertex[5].y,vertex[5].z);
	glVertex3d(vertex[6].x,vertex[6].y,vertex[6].z);
	glEnd();
}

void fluidsystem::drawThis()
{
	int i;
	glColor3f(0.5,0,0);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_BLEND);
	
	glBegin(GL_LINE_LOOP);
	{
		for(i=0;i<4;i++)
		{
			glVertex3d(vertex[i].x,vertex[i].y,vertex[i].z);
		}
	}
	glEnd();
	
	glBegin(GL_LINE_LOOP);
	{
		for(i=4;i<8;i++)
		{
			glVertex3d(vertex[i].x,vertex[i].y,vertex[i].z);
		}
	}
	glEnd();
	
	glBegin(GL_LINES);
	{
		for(i=0;i<4;i++)
		{
			glVertex3d(vertex[i].x,vertex[i].y,vertex[i].z);
			glVertex3d(vertex[i+4].x,vertex[i+4].y,vertex[i+4].z);
		}
	}
	glEnd();
	
}

void fluidsystem::calVertex()
{
	vertex[0]=myvector(0,0,0);
	vertex[1]=myvector(length_max,0,0);
	vertex[2]=myvector(length_max,width_max,0);
	vertex[3]=myvector(0,width_max,0);
	for(int i=4;i<8;i++)
	{
		vertex[i]=myvector(vertex[i-4].x,vertex[i-4].y,vertex[i-4].z+height_max);
	}
}

fluidsystem::fluidsystem(cube* mycube,sphere* mysphere)
{
	int i;
	key=loadTexture("D://texture3.bmp"); 
	
	buffer_now=0; //当前所有格子初始化使用0号vector
	
        length_max=0.1; width_max=0.1; height_max=0.06;
	/*length_max=mycube->vertex[0].x+mycube->vertex[6].x;
	width_max=mycube->vertex[0].y+mycube->vertex[6].y;
	height_max=max(mysphere->center.z+mysphere->radius,mycube->vertex[6].z);*/
	
	calVertex();
	
	//tim=0.0005;
	tim=0.001;

	length_grid_side=physic::r_smoothCore*2;
	
	l_div=ceil(length_max/length_grid_side); 
	length_max=l_div*length_grid_side;
	
	w_div=ceil(width_max/length_grid_side);
	width_max=w_div*length_grid_side;
	
	h_div=ceil(height_max/length_grid_side);
	height_max=h_div*length_grid_side;
	
	kernelPoly6=physic::particleMass*315/(64.0*physic::pi*pow(physic::r_smoothCore,9));
	kernelSpiky=physic::particleMass*45/(physic::pi*pow(physic::r_smoothCore,6));
	kernelViscosity=physic::particleMass*physic::staticViscosity*45/(physic::pi*pow(physic::r_smoothCore,6));
	
	myparticles.clear();
	int siz1=mycube->particles_inCube.size();
	particle here=particle();
	for(i=0;i<siz1;i++)
	{
		here=mycube->particles_inCube[i];
		myparticles.push_back(particle(here));
	}
/*
	int siz2=mysphere->particles_inSphere.size();
	for(i=0;i<siz2;i++)
	{
		here=mysphere->particles_inSphere[i];
		myparticles.push_back(particle(here));
	}*/

	allocateGrids();
	allocateParticlesToGrids();
	calVertex();
	
	mytriangles.clear();
}


fluidsystem::~fluidsystem()
{
	int i,j;
	int ll=l_div+2; int ww=w_div+2;
	for(i=0;i<ll;i++)
	{
		for(j=0;j<ww;j++)
		{
			delete [] mygrid[i][j];
		}
		delete [] mygrid[i];
	}
	delete [] mygrid;
}

void fluidsystem::drawParticles(int frame_now)
{
	int siz=myparticles.size();
	for(int i=0;i<siz;i++)
	{
		myparticles[i].drawParticle(density_max,density_min);
		//myparticles[i].drawParticle();
	}

	// just for generating the single dam benchmark
	stringstream ss;string frame_str;ss<<frame_now; ss>>frame_str;
	string name="./demo/test_"+frame_str+".vtk";
	FILE *fp=fopen(name.c_str(),"w");
	fprintf(fp,"# vtk DataFile Version 2.0\n");
	fprintf(fp,"tet\n");
	fprintf(fp,"ASCII\n\n");
	fprintf(fp,"DATASET UNSTRUCTURED_GRID\n");
	fprintf(fp,"POINTS %d double\n",siz);
	for(int i=0;i<siz;++i)
	  {
	    fprintf(fp,"%lf %lf %lf\n",myparticles[i].location.x,myparticles[i].location.y,myparticles[i].location.z);
	  }
	fprintf(fp,"CELLS %d %d\n",siz,2*siz);
	for(int i=0;i<siz;++i)
	  {
	    fprintf(fp,"1 %d\n",i);
	  }
	fprintf(fp,"CELL_TYPES %d\n",siz);
	for(int i=0;i<siz;++i)
	  {
	    fprintf(fp,"1\n");
	  }
	fclose(fp);
}

void fluidsystem::allocateGrids()
{
	int i,j,k;
	//分配格子
	int ll=l_div+2; int ww=w_div+2; int hh=h_div+2;
	mygrid=(grid***)new grid**[ll];   //长宽高 各多分配两个分量单位 方便后来marching cubes的计算  
	//原来设想 长宽高 各多分配一个分量单位  但是这样会造成一个困境，就是超过水池范围的部分未被计算到其中，而多加两个单位分量 ，则可以解决这个
	//问题，从而形成若干个完整的可见闭合曲面
	
	for(i=0;i<ll;i++)
	{
		mygrid[i]=(grid**)new grid*[ww];
		for(j=0;j<ww;j++)
		{
			mygrid[i][j]=new grid[hh];
		}
	}
	double x,y,z;
	for(i=0,x=vertex[0].x-length_grid_side;i<ll;i++,x+=length_grid_side)
	{
		for(j=0,y=vertex[0].y-length_grid_side;j<ww;j++,y+=length_grid_side)
		{
			for(k=0,z=vertex[0].z-length_grid_side;k<hh;k++,z+=length_grid_side)
			{
				mygrid[i][j][k]=grid(x,y,z,length_grid_side);//匿名对象赋值给左边 这是对象赋值  而如果new则是返回给一个对象指针
			}
		}
	}
	
}

void fluidsystem::allocateParticlesToGrids()
{
	int siz=myparticles.size();
	int i;
	int x,y,z;
	myvector location;
	for(i=0;i<siz;i++)
	{
		location=myparticles[i].location;
		x=(int)floor(location.x/length_grid_side)+1;
		y=(int)floor(location.y/length_grid_side)+1;
		z=(int)floor(location.z/length_grid_side)+1;
		mygrid[x][y][z].particlesInGrid[buffer_now]->push(i);
	}
}

void fluidsystem::resetParticles()
{
	int siz=myparticles.size();
	for(int i=0;i<siz;i++)
	{
		myparticles[i].reSet();
	}
}

void fluidsystem::createGrid(int num,int loc_test[8][3])
{
	myvector here=myvector(myparticles[num].location.x-physic::r_smoothCore,myparticles[num].location.y-physic::r_smoothCore,myparticles[num].location.z-physic::r_smoothCore);
    loc_test[0][0]=floor(here.x/length_grid_side)+1;
	loc_test[0][1]=floor(here.y/length_grid_side)+1;
	loc_test[0][2]=floor(here.z/length_grid_side)+1;
	
	loc_test[1][0]=loc_test[0][0]+1; loc_test[1][1]=loc_test[0][1]; loc_test[1][2]=loc_test[0][2];
	loc_test[2][0]=loc_test[1][0]; loc_test[2][1]=loc_test[1][1]+1; loc_test[2][2]=loc_test[1][2];
	loc_test[3][0]=loc_test[0][0]; loc_test[3][1]=loc_test[0][1]+1; loc_test[3][2]=loc_test[0][2];
	
	for(int i=4;i<8;i++)
	{
		loc_test[i][0]=loc_test[i-4][0]; loc_test[i][1]=loc_test[i-4][1]; loc_test[i][2]=loc_test[i-4][2]+1;
	}
}
int fluidsystem::isCorrect(int who,int loc_test[8][3])
{
	if(loc_test[who][0]>=1&&loc_test[who][0]<=l_div&&loc_test[who][1]>=1&&loc_test[who][1]<=w_div&&loc_test[who][2]>=1&&loc_test[who][2]<=h_div)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

double fluidsystem::R_square_sub_dis_square(int a,int b)
{
	myvector dis=myparticles[a].location-myparticles[b].location;
	return physic::r_smoothCore*physic::r_smoothCore-dis.len_sq();	
}

double fluidsystem::R_square_sub_dis_square(myvector& a,myvector& b)
{
	myvector dis=a-b;
	return physic::r_smoothCore*physic::r_smoothCore-dis.len_sq();
}

double fluidsystem::R_sub_dis(int a,int b) 
{
	myvector dis=myparticles[a].location-myparticles[b].location;
	return physic::r_smoothCore-sqrtf(dis.len_sq());	
}

void fluidsystem::calDensity()
{
	int i,j,k,a,b,c;
	int num,num_test;
	int loc_test[8][3];
	int siz_test,siz;
	double len,data;
	int x1,y1,z1;
	
	density_max=-1;density_min=1000000;
	for(i=1;i<=l_div;i++)
	{
		for(j=1;j<=w_div;j++)
		{
			for(k=1;k<=h_div;k++)
			{
				siz=mygrid[i][j][k].particlesInGrid[buffer_now]->size();
				for(a=0;a<siz;a++)
				{
					num=mygrid[i][j][k].particlesInGrid[buffer_now]->front();
					mygrid[i][j][k].particlesInGrid[buffer_now]->pop();
					mygrid[i][j][k].particlesInGrid[1-buffer_now]->push(num);
					createGrid(num,loc_test);
					for(b=0;b<8;b++)
					{
						if(isCorrect(b,loc_test))
						{
							x1=loc_test[b][0];y1=loc_test[b][1];z1=loc_test[b][2];
							siz_test=mygrid[x1][y1][z1].particlesInGrid[buffer_now]->size();
							for(c=0;c<siz_test;c++)
							{
								num_test=mygrid[x1][y1][z1].particlesInGrid[buffer_now]->front();
								mygrid[x1][y1][z1].particlesInGrid[buffer_now]->pop();
								mygrid[x1][y1][z1].particlesInGrid[buffer_now]->push(num_test);
								len=R_square_sub_dis_square(num,num_test);
								if(len>0.0)
								{
									data=kernelPoly6*pow(len,3);
									myparticles[num].density+=data;
									myparticles[num_test].density+=data;
								}
							}
						}
					}
					myparticles[num].density+=kernelPoly6*pow(physic::r_smoothCore*physic::r_smoothCore,3); //加上自己那部分
					if(myparticles[num].density>density_max)
					{
						density_max=myparticles[num].density;
					}
					if(myparticles[num].density<density_min)
					{
						density_min=myparticles[num].density;
					}
				}	
			}
		}
	}
	buffer_now=1-buffer_now;
}

void fluidsystem::calPressure()
{
	int siz=myparticles.size();
	for(int i=0;i<siz;i++)
	{
		myparticles[i].calPressure();
	}
}

void fluidsystem::calA()
{
	int i,j,k,a,b,c;
	int num,num_test;
	int loc_test[8][3];
	int siz_test,siz;
	double len,data1,data2; //data1 data2 保存两个分量的系数 
	myvector vec;
	int x1,y1,z1;
	for(i=1;i<=l_div;i++)
	{
		for(j=1;j<=w_div;j++)
		{
			for(k=1;k<=h_div;k++)
			{
				siz=mygrid[i][j][k].particlesInGrid[buffer_now]->size();
				for(a=0;a<siz;a++)
				{
					num=mygrid[i][j][k].particlesInGrid[buffer_now]->front();
					mygrid[i][j][k].particlesInGrid[buffer_now]->pop();
					mygrid[i][j][k].particlesInGrid[1-buffer_now]->push(num);
					createGrid(num,loc_test);
					for(b=0;b<8;b++)
					{
						if(isCorrect(b,loc_test))
						{
							x1=loc_test[b][0];y1=loc_test[b][1];z1=loc_test[b][2];
							siz_test=mygrid[x1][y1][z1].particlesInGrid[buffer_now]->size();
							for(c=0;c<siz_test;c++)
							{
								num_test=mygrid[x1][y1][z1].particlesInGrid[buffer_now]->front();
								mygrid[x1][y1][z1].particlesInGrid[buffer_now]->pop();
								mygrid[x1][y1][z1].particlesInGrid[buffer_now]->push(num_test);
								len=R_sub_dis(num,num_test);
								if(len>0.0)
								{
									data1=kernelSpiky*(myparticles[num].pressure+myparticles[num_test].pressure)*len*len/(2.0*myparticles[num].density*myparticles[num_test].density*(physic::r_smoothCore-len));
									data2=kernelViscosity*len/(myparticles[num].density*myparticles[num_test].density);
									
									vec=data1*(myparticles[num].location-myparticles[num_test].location)+data2*(myparticles[num_test].speed-myparticles[num].speed);
									myparticles[num].a_sp+=vec;
									myparticles[num_test].a_sp+=(-1.0*vec);
									
								}
							}
						}
					}
				}	
			}
		}
	}
	buffer_now=1-buffer_now;
}

void fluidsystem::calLocationAndSpeed()
{
	int siz=myparticles.size();
	for(int i=0;i<siz;i++)
	{
		myparticles[i].calLoactionAndSpeed(tim,length_max,width_max,height_max);
	}
}

void fluidsystem::Re_allocateParticlesToGrids()
{
	int i,j,k,a;
	int num;
	int siz;
	myvector location;
	int x,y,z;
	for(i=1;i<=l_div;i++)
	{
		for(j=1;j<=w_div;j++)
		{
			for(k=1;k<=h_div;k++)
			{
				siz=mygrid[i][j][k].particlesInGrid[buffer_now]->size();
				for(a=0;a<siz;a++)
				{
					num=mygrid[i][j][k].particlesInGrid[buffer_now]->front();
					mygrid[i][j][k].particlesInGrid[buffer_now]->pop();
					location=myparticles[num].location;
					x=(int)floor(location.x/length_grid_side)+1;
					y=(int)floor(location.y/length_grid_side)+1;
					z=(int)floor(location.z/length_grid_side)+1;
					mygrid[x][y][z].particlesInGrid[1-buffer_now]->push(num);
				}	
			}
		}
	}
	buffer_now=1-buffer_now;
}

myvector fluidsystem::calinWhichLittleGrid(myvector& a,myvector& b)
{
	myvector c=a-(b+physic::r_smoothCore);
	if(c.x>=0&&c.y>=0&&c.z>=0)
	{
		return myvector(1,1,1);
	}
	else if(c.x>=0&&c.y>=0&&c.z<0)
	{
		return myvector(1,1,0);
	}
	else if(c.x>=0&&c.y<0&&c.z>=0)
	{
		return  myvector(1,0,1);
	}
	else if(c.x>=0&&c.y<0&&c.z<0)
	{
		return  myvector(1,0,0);
	}
	else if(c.x<0&&c.y>=0&&c.z>=0)
	{
		return myvector(0,1,1);
	}
	else if(c.x<0&&c.y>=0&&c.z<0)
	{
		return myvector(0,1,0);
	}
	else if(c.x<0&&c.y<0&&c.z>=0)
	{
		return  myvector(0,0,1);
	}
	else if(c.x<0&&c.y<0&&c.z<0)
	{
		return  myvector(0,0,0);
	}
}

void fluidsystem::allocateParticlesToLittleGrids()
{
	int i,j,k,a;
	int num;
	int siz;
	myvector location;
	int ll=l_div+2; int ww=w_div+2; int hh=h_div+2;
	for(i=0;i<ll;i++)
	{
		for(j=0;j<ww;j++)
		{
			for(k=0;k<hh;k++)
			{
				mygrid[i][j][k].reset();
			}
		}
	}
	for(i=1;i<=l_div;i++)
	{
		for(j=1;j<=w_div;j++)
		{
			for(k=1;k<=h_div;k++)
			{
				siz=mygrid[i][j][k].particlesInGrid[buffer_now]->size();
				for(a=0;a<siz;a++)
				{
					num=mygrid[i][j][k].particlesInGrid[buffer_now]->front();
					mygrid[i][j][k].particlesInGrid[buffer_now]->pop();
					location=myparticles[num].location;
					myvector which=calinWhichLittleGrid(location,mygrid[i][j][k].vertex[0]);
					mygrid[i][j][k].subgrid[(int)which.x][(int)which.y][(int)which.z].particlesInLittleGrid->push_back(num);
					mygrid[i][j][k].particlesInGrid[buffer_now]->push(num);
				}	
			}
		}
	}
}

void fluidsystem::calDenstityComponentInLittleGrid()
{
	int i,j,k,a1,a2,a3,b,c1,c2,c3;
	int num;
	int siz,siz1;
	myvector location;
	double len;
	
	int ll=2*(l_div+2);int ww=2*(w_div+2); int hh=2*(h_div+2);
	
	mylittlegird=(littleGrid****)new littleGrid***[ll];   //长宽高 各多分配一个分量单位 方便后来marching cubes的计算
	for(i=0;i<ll;i++)
	{
		mylittlegird[i]=(littleGrid***)new littleGrid**[ww];
		for(j=0;j<ww;j++)
		{
			mylittlegird[i][j]=(littleGrid**)new littleGrid*[hh];
		}
	}
	int l2=l_div+2; int w2=w_div+2; int h2=h_div+2;
	for(i=0;i<l2;i++)
	{
		for(j=0;j<w2;j++)
		{
			for(k=0;k<h2;k++)
			{
				for(a1=0;a1<2;a1++)
				{
					for(a2=0;a2<2;a2++)
					{
						for(a3=0;a3<2;a3++)
						{
							mylittlegird[i*2+a1][j*2+a2][k*2+a3]=&(mygrid[i][j][k].subgrid[a1][a2][a3]);
						}
					}
				}
				
			}
		}
	}
	
	for(i=1;i<=l_div;i++)
	{
		for(j=1;j<=w_div;j++)
		{
			for(k=1;k<=h_div;k++)
			{
				siz=mygrid[i][j][k].particlesInGrid[buffer_now]->size();
				/*
				if(siz!=0)
				{*/
				
				for(a1=0;a1<2;a1++)
				{
					for(a2=0;a2<2;a2++)
					{
						for(a3=0;a3<2;a3++)
						{
							siz1=mygrid[i][j][k].subgrid[a1][a2][a3].particlesInLittleGrid->size();
							for(b=0;b<siz1;b++)
							{
								num=(*mygrid[i][j][k].subgrid[a1][a2][a3].particlesInLittleGrid)[b];
								location=myparticles[num].location;
								for(c1=0;c1<2;c1++)
								{
									for(c2=0;c2<2;c2++)
									{
										for(c3=0;c3<2;c3++)
										{
											len=R_square_sub_dis_square(location,mygrid[i][j][k].subgrid[a1][a2][a3].myvertex[c1][c2][c3].vertex);
											if(len>0.0)
											{
												len=kernelPoly6*pow(len,3);
												mygrid[i][j][k].subgrid[a1][a2][a3].myvertex[c1][c2][c3].csComponent+=len;
											}
										}
									}
								}
							}
						}
					}
				}
				//	}
			}
		}
	}
}

void fluidsystem::calDensityOfVertexOfLittleGrid()
{
	int ll=2*(l_div+2);int ww=2*(w_div+2); int hh=2*(h_div+2);
	int i,j,k,a,b,c;
	double data;
	for(i=0;i<ll;i++)
	{
		for(j=0;j<ww;j++)
		{
			for(k=0;k<hh;k++)
			{
				data=0;
				for(a=-1;a<1;a++)
				{
					for(b=-1;b<1;b++)
					{
						for(c=-1;c<1;c++)
						{
							if(i+a>=0&&j+b>=0&&k+c>=0)
							{
								data+=mylittlegird[i+a][j+b][k+c]->myvertex[-a][-b][-c].csComponent;
							}
						}
					}
				}
				mylittlegird[i][j][k]->myvertex[0][0][0].cs=data;
			}
		}
	}
	ll-=1; ww-=1; hh-=1;
	for(i=0;i<ll;i++)
	{
		for(j=0;j<ww;j++)
		{
			for(k=0;k<hh;k++)
			{
				for(a=0;a<2;a++)
				{
					for(b=0;b<2;b++)
					{
						for(c=0;c<2;c++)
						{
							mylittlegird[i][j][k]->myvertex[a][b][c].cs=mylittlegird[i+a][j+b][k+c]->myvertex[0][0][0].cs;
						}
					}
				}
			}
		}
	}
}


void fluidsystem::calNormalOfVertexOfLittleGrid() //计算法线以外并标记各个顶点的值是比阈值大还是小
{
	int i,j,k,a,b,c;
	myvector dd1=myvector();
	myvector dd2=myvector();
	int ll=(l_div+2)*2; int ww=(w_div+2)*2; int hh=(h_div+2)*2;
	for(i=0;i<ll;i++)
	{
		for(j=0;j<ww;j++)
		{
			for(k=0;k<hh;k++)
			{
				
			/*
			if(mylittlegird[i][j][k]->particlesInLittleGrid->size()>0)
			{
				*/
				
				for(a=0;a<2;a++)
				{
					for(b=0;b<2;b++)
					{
						for(c=0;c<2;c++)
						{
							dd1.x=(i-1>=0?mylittlegird[i-1][j][k]->myvertex[a][b][c].cs:0);
							dd2.x=(i+1<ll?mylittlegird[i+1][j][k]->myvertex[a][b][c].cs:0);
							dd1.y=(j-1>=0?mylittlegird[i][j-1][k]->myvertex[a][b][c].cs:0);
							dd2.y=(j+1<ww?mylittlegird[i][j+1][k]->myvertex[a][b][c].cs:0);
							dd1.z=(k-1>=0?mylittlegird[i][j][k-1]->myvertex[a][b][c].cs:0);
							dd2.z=(k+1<hh?mylittlegird[i][j][k+1]->myvertex[a][b][c].cs:0);
							
							mylittlegird[i][j][k]->myvertex[a][b][c].normal_vector=(dd2-dd1)/(2*physic::r_smoothCore)*(-1);
							
							mylittlegird[i][j][k]->myvertex[a][b][c].mark=(mylittlegird[i][j][k]->myvertex[a][b][c].cs>=physic::threshold?1:0); //标记是比阈值大还是小
							
						}
					}
				}
				//}	
			}
		}
	}
}

bool cmp1(const vertex_data& x,const vertex_data& y)
{
	return  x.mark>y.mark;
}
bool cmp2(const vertex_data& x,const vertex_data& y)
{
	return  x.mark<y.mark;
}

void fluidsystem::getTriangleFrom( vector <vertex_data >& vector_x)
{
	int i;
	int ct=0;
	for(i=0;i<4;i++)
	{
		if(vector_x[i].mark==1)
		{
			ct++;
		}
	}
	if(ct==0||ct==4)
	{
		return;
	}
	//线性插值
	//P=P1+(isovalue一V1)(P2一P1)/(V2一V1) 
	else if(ct==1)
	{
		sort(vector_x.begin(),vector_x.end(),cmp1);
		triangle get1=triangle();
		for(i=0;i<3;i++)
		{
			get1.vertex[i]=vector_x[0].vertex+(physic::threshold-vector_x[0].cs)*(vector_x[i+1].vertex-vector_x[0].vertex)/(vector_x[i+1].cs-vector_x[0].cs);
			get1.normal_vector[i]=vector_x[0].normal_vector+(get1.vertex[i]-vector_x[0].vertex).len()*(vector_x[i+1].normal_vector-vector_x[0].normal_vector)/(vector_x[i+1].vertex-vector_x[0].vertex).len();
		}
		for(i=0;i<3;i++)
		{
			get1.normal_vector[i].normalize();
		//	printf("%lf %lf %lf nnn\n",get1.normal_vector[i].x,get1.normal_vector[i].y,get1.normal_vector[i].z);
		}
		mytriangles.push_back(get1);		
		
		return;
	}
	else if(ct==3)
	{
		sort(vector_x.begin(),vector_x.end(),cmp2);
		triangle get1=triangle();
		for(i=0;i<3;i++)
		{
			get1.vertex[i]=vector_x[0].vertex+(physic::threshold-vector_x[0].cs)*(vector_x[i+1].vertex-vector_x[0].vertex)/(vector_x[i+1].cs-vector_x[0].cs);
			get1.normal_vector[i]=vector_x[0].normal_vector+(get1.vertex[i]-vector_x[0].vertex).len()*(vector_x[i+1].normal_vector-vector_x[0].normal_vector)/(vector_x[i+1].vertex-vector_x[0].vertex).len();
		}
		for(i=0;i<3;i++)
		{
			get1.normal_vector[i].normalize();
			//printf("%lf %lf %lf nnn\n",get1.normal_vector[i].x,get1.normal_vector[i].y,get1.normal_vector[i].z);
		}
		mytriangles.push_back(get1);
		
		return;
	}
	else if(ct==2)
	{
		sort(vector_x.begin(),vector_x.end(),cmp1);
		triangle get1=triangle(); triangle get2=triangle();
		get1.vertex[0]=vector_x[0].vertex+(physic::threshold-vector_x[0].cs)*(vector_x[2].vertex-vector_x[0].vertex)/(vector_x[2].cs-vector_x[0].cs);
		get1.vertex[1]=vector_x[0].vertex+(physic::threshold-vector_x[0].cs)*(vector_x[3].vertex-vector_x[0].vertex)/(vector_x[3].cs-vector_x[0].cs);
		get1.normal_vector[0]=vector_x[0].normal_vector+(get1.vertex[0]-vector_x[0].vertex).len()*(vector_x[2].normal_vector-vector_x[0].normal_vector)/(vector_x[2].vertex-vector_x[0].vertex).len();
		get1.normal_vector[1]=vector_x[0].normal_vector+(get1.vertex[1]-vector_x[0].vertex).len()*(vector_x[3].normal_vector-vector_x[0].normal_vector)/(vector_x[3].vertex-vector_x[0].vertex).len();
		get1.vertex[2]=vector_x[1].vertex+(physic::threshold-vector_x[1].cs)*(vector_x[2].vertex-vector_x[1].vertex)/(vector_x[2].cs-vector_x[1].cs);
		get1.normal_vector[2]=vector_x[1].normal_vector+(get1.vertex[2]-vector_x[1].vertex).len()*(vector_x[2].normal_vector-vector_x[1].normal_vector)/(vector_x[2].vertex-vector_x[1].vertex).len();
		
		get2.vertex[1]=get1.vertex[1];  get2.normal_vector[1]=get1.normal_vector[1];
		get2.vertex[2]=get1.vertex[2];  get2.normal_vector[2]=get1.normal_vector[2];
		
		get2.vertex[0]=vector_x[1].vertex+(physic::threshold-vector_x[1].cs)*(vector_x[3].vertex-vector_x[1].vertex)/(vector_x[3].cs-vector_x[1].cs);
		get2.normal_vector[0]=vector_x[1].normal_vector+(get2.vertex[0]-vector_x[1].vertex).len()*(vector_x[3].normal_vector-vector_x[1].normal_vector)/(vector_x[3].vertex-vector_x[1].vertex).len();
		
		for(i=0;i<3;i++)
		{
			get1.normal_vector[i].normalize();
			//	printf("%lf %lf %lf nnn\n",get1.normal_vector[i].x,get1.normal_vector[i].y,get1.normal_vector[i].z);
			get2.normal_vector[i].normalize();
			//	printf("%lf %lf %lf nnn\n",get2.normal_vector[i].x,get2.normal_vector[i].y,get2.normal_vector[i].z);
		}
		mytriangles.push_back(get1);
		mytriangles.push_back(get2);	
		
		return ;
	}
}

void fluidsystem::getTriangleFromLittleGrid()
{
	int i,j,k;
	int ll=l_div*2+3; int ww=w_div*2+3; int hh=h_div*2+3;
	vector<vertex_data > here;
	for(i=1;i<ll;i++)
	{
		for(j=1;j<ww;j++)
		{
			for(k=1;k<hh;k++)
			{
			/*
			if(mylittlegird[i][j][k]->particlesInLittleGrid->size()>0)
				{*/
				
				here.clear();
				here.push_back(mylittlegird[i][j][k]->myvertex[0][0][0]); 
				here.push_back(mylittlegird[i][j][k]->myvertex[0][0][1]); 
				here.push_back(mylittlegird[i][j][k]->myvertex[0][1][1]);
				here.push_back(mylittlegird[i][j][k]->myvertex[1][0][0]);
				getTriangleFrom(here);
				
				here.clear();
				here.push_back(mylittlegird[i][j][k]->myvertex[0][0][0]); 
				here.push_back(mylittlegird[i][j][k]->myvertex[0][1][1]); 
				here.push_back(mylittlegird[i][j][k]->myvertex[0][1][0]);
				here.push_back(mylittlegird[i][j][k]->myvertex[1][0][0]);
				getTriangleFrom(here);
				
				here.clear();
				here.push_back(mylittlegird[i][j][k]->myvertex[0][1][1]); 
				here.push_back(mylittlegird[i][j][k]->myvertex[0][1][0]); 
				here.push_back(mylittlegird[i][j][k]->myvertex[1][0][0]);
				here.push_back(mylittlegird[i][j][k]->myvertex[1][1][0]);
				getTriangleFrom(here);
				
				here.clear();
				here.push_back(mylittlegird[i][j][k]->myvertex[0][0][1]); 
				here.push_back(mylittlegird[i][j][k]->myvertex[0][1][1]); 
				here.push_back(mylittlegird[i][j][k]->myvertex[1][0][0]);
				here.push_back(mylittlegird[i][j][k]->myvertex[1][0][1]);
				getTriangleFrom(here);
				
				here.clear();
				here.push_back(mylittlegird[i][j][k]->myvertex[0][1][1]); 
				here.push_back(mylittlegird[i][j][k]->myvertex[1][1][1]); 
				here.push_back(mylittlegird[i][j][k]->myvertex[1][0][0]);
				here.push_back(mylittlegird[i][j][k]->myvertex[1][1][0]);
				getTriangleFrom(here);
				
				here.clear();
				here.push_back(mylittlegird[i][j][k]->myvertex[0][1][1]); 
				here.push_back(mylittlegird[i][j][k]->myvertex[1][1][1]); 
				here.push_back(mylittlegird[i][j][k]->myvertex[1][0][0]);
				here.push_back(mylittlegird[i][j][k]->myvertex[1][0][1]);
				getTriangleFrom(here);
				
				
				//	}
			}
		}
	}
}

void fluidsystem::correctTriangles() //纠正三角形的顶点坐标
{
	int siz=mytriangles.size();
	for(int i=0;i<siz;i++)
	{
		for(int j=0;j<3;j++)
		{
			mytriangles[i].vertex[j].x=mytriangles[i].vertex[j].x<0?0:mytriangles[i].vertex[j].x;
			mytriangles[i].vertex[j].x=mytriangles[i].vertex[j].x>length_max?length_max:mytriangles[i].vertex[j].x;
			mytriangles[i].vertex[j].y=mytriangles[i].vertex[j].y<0?0:mytriangles[i].vertex[j].y;
			mytriangles[i].vertex[j].y=mytriangles[i].vertex[j].y>width_max?width_max:mytriangles[i].vertex[j].y;
			mytriangles[i].vertex[j].z=mytriangles[i].vertex[j].z<0?0:mytriangles[i].vertex[j].z;
			mytriangles[i].vertex[j].z=mytriangles[i].vertex[j].z>height_max?height_max:mytriangles[i].vertex[j].z;
		}
	}
}

void fluidsystem::drawTriangles()
{
	int siz=mytriangles.size();
	glColor4d(0,0.8,0.8,0.4);
	for(int i=0;i<siz;i++)
	{
		glBegin(GL_TRIANGLES);
		{
			glNormal3d(mytriangles[i].normal_vector[0].x,mytriangles[i].normal_vector[0].y,mytriangles[i].normal_vector[0].z);
			glVertex3d(mytriangles[i].vertex[0].x,mytriangles[i].vertex[0].y,mytriangles[i].vertex[0].z);
			glNormal3d(mytriangles[i].normal_vector[1].x,mytriangles[i].normal_vector[1].y,mytriangles[i].normal_vector[1].z);
			glVertex3d(mytriangles[i].vertex[1].x,mytriangles[i].vertex[1].y,mytriangles[i].vertex[1].z);
			glNormal3d(mytriangles[i].normal_vector[2].x,mytriangles[i].normal_vector[2].y,mytriangles[i].normal_vector[2].z);
			glVertex3d(mytriangles[i].vertex[2].x,mytriangles[i].vertex[2].y,mytriangles[i].vertex[2].z);
		}
		glEnd();
		
	}
	mytriangles.clear();
}

void fluidsystem::flowOfCalculate(int frame_now)
{
	resetParticles();
	calDensity();
	calPressure();
	calA();
	calLocationAndSpeed();
	Re_allocateParticlesToGrids();
	drawParticles(frame_now);
	
	/*
	allocateParticlesToLittleGrids();
	calDenstityComponentInLittleGrid();
	calDensityOfVertexOfLittleGrid();
	calNormalOfVertexOfLittleGrid();
	getTriangleFromLittleGrid();
	correctTriangles();
	drawTriangles();
	*/
}


