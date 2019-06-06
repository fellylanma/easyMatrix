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
    float* element;\
    float memory[x*y];\
};\
void initMatrix##x##N##y(float* a,struct easyMatrix##x##N##y* c) {\
    c->rows = x;\
    c->cols = y;\
    c->element = c->memory;\
    if(a!=NULL)\
    setMatrix(x,y,a,c->element);\
};

#define easy_cast(x) ((struct easyMatrix*)x)

#define CREATE_MATRIX(x,y,matrix,initval) \
easyMatrix##x##N##y matrix;\
initMatrix##x##N##y(initval, &matrix);

#define CREATE_DYNAMIC_MATRIX(x,y,matrix,initval) \
struct easyMatrix matrix;\
matrix.rows = x;\
matrix.cols = y;\
matrix.element = initval;

#define DELETE_DYNAMIC_MATRIX(matrix) \
    free((matrix)->element);

struct easyMatrix {\
    uint8 rows,cols;\
    float* element;
};\
float* copyMatrix(uint8 x, uint8 y,float* a,float * c);

void* transMatrix(void* a,void* c);




float detMatrix(void* const a);
float invMatrix(uint8 x, uint8 y, float* a, float*);
void* scaleMatrix(float, void* const a, void*);

//float* addMatrix(uint8 x, uint8 y,float* a, float * b, float * c);
void* addMatrix(void* a, void * b, void * c);
void* leftMatrix(uint8, uint8, void* a, void* b);
void* subMatrix(void* a, void* b, void* c);
void* multiMatrix(void* a, void* b, void* c);
void* zerosMatrix(void* e);
void* eyesMatrix(void* e);
void dumpMatrix(uint8 x, uint8 y, float*e);

void* adjMatrix(void* a,void* c);
#endif//_MAGRIDE_PLANNING_EASYMATRIX_H_
