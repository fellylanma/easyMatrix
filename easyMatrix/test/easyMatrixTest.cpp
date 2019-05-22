/*************************************************************************
	> File Name: easyMatrix.c
	> Author: Zhang Yuteng
	> Mail:
	> Created Time: 2019年05月13日 星期一 22时15分52秒
 ************************************************************************/

#include<stdio.h>
extern C {
#include "easyMatrix.h"
}
#include "gtest/gtest.h"
declearMatrix(3,3);
declearMatrix(2,3);
declearMatrix(3,2);
declearMatrix(2,2);
TEST(testCase, easyMatrixTest0) {

}
/*
int main() {
    struct easyMatrix3N3 a;
    struct easyMatrix3N3 b;
    struct easyMatrix3N3 c;
    struct easyMatrix3N3 z;
    float val[] = {1,2,3,4,5,6,7,8,9};
    setMatrix(3,3,val,c.element);
    printf("dump c:\n");
    dumpMatrix(3,3,c.element);
    zerosMatrix(3,3,a.element);
    printf("dump a:\n");
    dumpMatrix(3,3,a.element);
    eyesMatrix(3,3,b.element);
    printf("dump b:\n");
    dumpMatrix(3,3,b.element);
    addMatrix(3,3,a.element,b.element, a.element);
    multiMatrix(3,3,a.element,3,b.element,z.element);
    printf("dump a*b = z:\n");
    dumpMatrix(3,3,z.element);
    multiMatrix(3,3,a.element,3,c.element,z.element);
    printf("dump z:\n");
    dumpMatrix(3,3,z.element);
    float val1[] = {1,4,3,2,7,5,3,5,8};
    setMatrix(3,3,val1,c.element);
    printf("dump c:\n");
    dumpMatrix(3,3,c.element);
    float result = detMatrix(3,3,c.element);
    printf("result is %f\n",result);
    transMatrix(3,3,c.element,a.element);
    printf("dump a:\n");
    dumpMatrix(3,3,a.element);
    transMatrix(3,3,a.element,c.element);
    printf("dump a:\n");
    dumpMatrix(3,3,a.element);
    struct easyMatrix2N3 nm;
    struct easyMatrix3N2 nm2;
    struct easyMatrix2N2 re;
    struct easyMatrix2N3 nm1;
    printf("dump nm:\n");
    float val2[] = {1,2,3,4,5,6};
    setMatrix(2,3,val2,nm.element);
    copyMatrix(2,3,nm.element,nm1.element);
    printf("dump nm1:\n");
    dumpMatrix(2,3,nm1.element);
    printf("dump nm:\n");
    dumpMatrix(2,3,nm.element);
    transMatrix(2,3,nm.element,nm2.element);
    printf("dump nm2:\n");
    dumpMatrix(3,2,nm2.element);
    multiMatrix(2,3,nm.element,2,nm2.element,re.element);
    dumpMatrix(2,2,re.element);
    adjMatrix(3,3,a.element,c.element);
    float det = detMatrix(3,3,a.element);
    printf("a det:%f\n",det);
    printf("dump c:\n");
    dumpMatrix(3,3,c.element);
    struct easyMatrix2N2 a22,b22;
    float val22[] = {7,5,5,8};
    float ret22 = detMatrix(2,2,val22);
    printf("dump b22 det:%d\n",ret22);



    return 0;
    */
}
