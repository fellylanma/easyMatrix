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

void* setMatrix(float* a,void* c);

#define easy_cast(x) ((struct easyMatrix*)x)

#define CREATE_MATRIX(x,y,matrix,initval) \
struct easyMatrix matrix;\
float val##x##N##y##N##matrix[x*y];\
    matrix.rows = x;\
    matrix.cols = y;\
    matrix.element = val##x##N##y##N##matrix;\
    if(initval!=NULL)\
    setMatrix(initval, &(matrix));

#define CREATE_DYNAMIC_MATRIX(x,y,matrix,initval) \
struct easyMatrix matrix;\
matrix.rows = x;\
matrix.cols = y;\
matrix.element = (float*) malloc(sizeof(float)*(x)*(y));\
if(initval!=NULL)\
    setMatrix(initval, &(matrix));

#define DELETE_DYNAMIC_MATRIX(matrix) \
    free((matrix)->element);

struct easyMatrix {\
    uint8 rows,cols;\
    float* element;
};\
float* copyMatrix(uint8 x, uint8 y,float* a,float * c);

void* transMatrix(void* a,void* c);




float detMatrix(void* const a);
float invMatrix(void* a, void*b);
void* scaleMatrix(float, void* const a, void*);

//float* addMatrix(uint8 x, uint8 y,float* a, float * b, float * c);
void* addMatrix(void* a, void * b, void * c);
void* leftMatrix(uint8, uint8, void* a, void* b);
void* subMatrix(void* a, void* b, void* c);
void* multiMatrix(void* a, void* b, void* c);
void* zerosMatrix(void* e);
void* eyesMatrix(void* e);
void dumpMatrix(void*e);

void* adjMatrix(void* a,void* c);
#endif//_MAGRIDE_PLANNING_EASYMATRIX_H_
