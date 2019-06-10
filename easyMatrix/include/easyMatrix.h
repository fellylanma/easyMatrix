/*************************************************************************
	> File Name: easyMatrix.h
	> Author: Zhang Yuteng
	> Mail:fellylanma@aliyun.com
	> Created Time: 2019年05月13日 星期一 22时06分13秒
 ************************************************************************/

#ifndef _MAGRIDE_PLANNING_EASYMATRIX_H_
#define _MAGRIDE_PLANNING_EASYMATRIX_H_

#include <stdlib.h>
typedef unsigned char uint8;
typedef float DATA_TYPE;


#define CREATE_MATRIX_ONSTACK(x,y,matrix,initval) \
struct easyMatrix matrix;\
DATA_TYPE val##x##N##y##N##matrix[x*y];\
    matrix.rows = x;\
    matrix.cols = y;\
    matrix.element = val##x##N##y##N##matrix;\
    if(initval!=NULL) setMatrix(initval, &(matrix))

#define CREATE_DYNAMIC_MATRIX_ONHEAP(x,y,matrix,initval) \
struct easyMatrix *matrix = (struct easyMatrix*)malloc(sizeof(struct easyMatrix));\
matrix->rows = x;\
matrix->cols = y;\
matrix->element = (DATA_TYPE*) malloc(sizeof(DATA_TYPE)*(x)*(y));\
if(initval!=NULL) setMatrix(initval, (matrix))

#define DELETE_DYNAMIC_MATRIX(matrix) \
    free((matrix)->element);\
    free(matrix)

struct easyMatrix {\
    uint8 rows,cols;\
    DATA_TYPE* element;
};\

struct easyMatrix* setMatrix(DATA_TYPE* const a,struct easyMatrix* c);

struct easyMatrix* copyMatrix(struct easyMatrix* const a,struct easyMatrix* c);

struct easyMatrix* transMatrix(struct easyMatrix* const a,struct easyMatrix* c);

DATA_TYPE detMatrix(struct easyMatrix* const a);

DATA_TYPE invMatrix(struct easyMatrix* const a, struct easyMatrix*b);

struct easyMatrix* scaleMatrix(DATA_TYPE, struct easyMatrix* const a, struct easyMatrix*);

struct easyMatrix* addMatrix(struct easyMatrix* const a, struct easyMatrix *const  b, struct easyMatrix * c);

struct easyMatrix* leftMatrix(uint8, uint8, struct easyMatrix* const a, struct easyMatrix* b);

struct easyMatrix* subMatrix(struct easyMatrix* const a, struct easyMatrix* const  b, struct easyMatrix* c);

struct easyMatrix* multiMatrix(struct easyMatrix* const a, struct easyMatrix* const b, struct easyMatrix* c);

struct easyMatrix* zerosMatrix(struct easyMatrix* e);

struct easyMatrix* eyesMatrix(struct easyMatrix* e);

void dumpMatrix(struct easyMatrix* const e);

struct easyMatrix* adjMatrix(struct easyMatrix* const a,struct easyMatrix* c);

struct easyMatrix* getLUMatrix(struct easyMatrix* const A, struct easyMatrix* L,struct easyMatrix* U) ;
#endif//_MAGRIDE_PLANNING_EASYMATRIX_H_
