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

float* setMatrix(uint8 x, uint8 y,float* a,float * c);

#define declearMatrix(x,y) \
struct easyMatrix##x##N##y {\
    uint8 rows,cols;\
    float element[x*y];\
};\
void initMatrix##x##N##y(float* a,struct easyMatrix##x##N##y* c) {\
    c->rows = x;\
    c->cols = y;\
    if(a!=NULL)\
    setMatrix(x,y,a,c->element);\
};

#define easy_cast(x) ((struct easyMatrix*)x)

#define CREATE_MATRIX(x,y,matrix,initval) \
easyMatrix##x##N##y matrix;\
initMatrix##x##N##y(initval, &matrix);


struct easyMatrix {\
    uint8 rows,cols;\
    float element[4];\
};\
float* copyMatrix(uint8 x, uint8 y,float* a,float * c);

float* transMatrix(uint8 x, uint8 y,float* a,float * c);




float detMatrix(uint8 x, uint8 y, float* a);
float invMatrix(uint8 x, uint8 y, float* a, float*);
float* scaleMatrix(uint8 x, uint8 y,float, float* a, float*);

//float* addMatrix(uint8 x, uint8 y,float* a, float * b, float * c);
void* addMatrix(void* a, void * b, void * c);
float* leftMatrix(uint8 x, uint8 y,uint8, uint8, float* a, float * b);
void* subMatrix(void* a, void* b, void* c);
float* multiMatrix(uint8 x, uint8 y,float* a,uint8 z, float * b, float * c);
void* zerosMatrix(void* e);
float* eyesMatrix(uint8 x, uint8 y, float*e);
void dumpMatrix(uint8 x, uint8 y, float*e);

float* adjMatrix(uint8 x, uint8 y,float* a,float * c);
#endif//_MAGRIDE_PLANNING_EASYMATRIX_H_
