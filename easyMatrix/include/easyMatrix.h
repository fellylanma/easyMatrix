/*************************************************************************
	> File Name: easyMatrix.h
	> Author: Zhang Yuteng
	> Mail:
	> Created Time: 2019年05月13日 星期一 22时06分13秒
 ************************************************************************/

#ifndef _MAGRIDE_PLANNING_EASYMATRIX_H_
#define _MAGRIDE_PLANNING_EASYMATRIX_H_

#include <stdlib.h>
typedef unsigned char uint8;

#define declearMatrix(x,y) \
struct easyMatrix##x##N##y {\
    uint8 rows,cols;\
    float element[x*y];\
}\

float* setMatrix(uint8 x, uint8 y,float* a,float * c);

float* copyMatrix(uint8 x, uint8 y,float* a,float * c);

float* transMatrix(uint8 x, uint8 y,float* a,float * c);
float* upTriangleMatrix(uint8 l,uint8 x, uint8 y, float*a);


void swap(float* a, float* b);


float detMatrix(uint8 x, uint8 y, float* a);
float* invMatrix(uint8 x, uint8 y, float* a, float*);
float* scaleMatrix(uint8 x, uint8 y,float, float* a, float*);

float* addMatrix(uint8 x, uint8 y,float* a, float * b, float * c);
float* leftMatrix(uint8 x, uint8 y,uint8, uint8, float* a, float * b);
float* subMatrix(uint8 x, uint8 y,float* a, float * b, float * c);
float* multiMatrix(uint8 x, uint8 y,float* a,uint8 z, float * b, float * c);
float* zerosMatrix(uint8 x, uint8 y,float* e);
float* eyesMatrix(uint8 x, uint8 y, float*e);
void dumpMatrix(uint8 x, uint8 y, float*e);

float* adjMatrix(uint8 x, uint8 y,float* a,float * c);
#endif//_MAGRIDE_PLANNING_EASYMATRIX_H_
