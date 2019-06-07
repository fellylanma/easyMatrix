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

struct easyMatrix* setMatrix(float* a,struct easyMatrix* c);

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

struct easyMatrix* transMatrix(struct easyMatrix* a,struct easyMatrix* c);




float detMatrix(struct easyMatrix* const a);
float invMatrix(struct easyMatrix* a, struct easyMatrix*b);
struct easyMatrix* scaleMatrix(float, struct easyMatrix* const a, struct easyMatrix*);

//float* addMatrix(uint8 x, uint8 y,float* a, float * b, float * c);
struct easyMatrix* addMatrix(struct easyMatrix* a, struct easyMatrix * b, struct easyMatrix * c);
struct easyMatrix* leftMatrix(uint8, uint8, struct easyMatrix* a, struct easyMatrix* b);
struct easyMatrix* subMatrix(struct easyMatrix* a, struct easyMatrix* b, struct easyMatrix* c);
struct easyMatrix* multiMatrix(struct easyMatrix* a, struct easyMatrix* b, struct easyMatrix* c);
struct easyMatrix* zerosMatrix(struct easyMatrix* e);
struct easyMatrix* eyesMatrix(struct easyMatrix* e);
void dumpMatrix(struct easyMatrix*e);

struct easyMatrix* adjMatrix(struct easyMatrix* a,struct easyMatrix* c);
#endif//_MAGRIDE_PLANNING_EASYMATRIX_H_
