/*************************************************************************
	> File Name: easyMatrix.c
	> Author: Zhang Yuteng
	> Mail:
	> Created Time: 2019年05月13日 星期一 22时15分52秒
 ************************************************************************/

#include <stdio.h>
extern "C" {
#include "easyMatrix.h"
}
#include "gtest/gtest.h"

declearMatrix(3,3);
declearMatrix(2,3);
declearMatrix(3,2);
declearMatrix(2,2);
declearMatrix(4,4);
declearMatrix(1,4);
declearMatrix(4,1);
declearMatrix(1,1);
declearMatrix(7,7);

float val[] = {1,2,3,4,5,6,7,8,9};
void expect(int i, int j,float* a, float* b) {
    int t = i*j;
    for(int ii=0;ii<t;++ii) {
        EXPECT_NEAR(a[ii],b[ii],1e-6);
    }
}

void expect(int i, int j,float* a, float val) {
    int t = i*j;
    for(int ii=0;ii<t;++ii) {
        EXPECT_NEAR(a[ii],val,1e-6);
    }
}
TEST(testCase, easyMatrixTest_SET) {
    CREATE_MATRIX(3,3,M0,val);
    expect(3,3,val,M0.element);
};

TEST(testCase, easyMatrixTest_ZEROS) {
    CREATE_MATRIX(3,3,M0,val);
    expect(3,3,val,M0.element);
    zerosMatrix(&M0);
    expect(3,3,M0.element,0.0f);
};
TEST(testCase, easyMatrixTest_ONES) {
    CREATE_MATRIX(3,3,M0,val);
    expect(3,3,val,M0.element);
    float val1[] = {1,0,0,0,1,0,0,0,1};
    eyesMatrix(&M0);
    expect(3,3,M0.element,val1);
};
TEST(testCase, easyMatrixTest_TRANS0) {
    CREATE_MATRIX(3,3,M0,val);
    CREATE_MATRIX(3,3,M1,NULL);
    transMatrix(&M0,&M1);
    float val1[] = {1,4,7,2,5,8,3,6,9};
    expect(3,3,M1.element,val1);
}
TEST(testCase, easyMatrixTest_TRANS1) {
    CREATE_MATRIX(2,3,N1,val);
    CREATE_MATRIX(3,2,N2,NULL);
    transMatrix(&N1,&N2);
    float val1[] = {1,4,2,5,3,6};
    expect(3,2,N2.element,val1);
}

TEST(testCase, easyMatrixTest_DET) {
    CREATE_MATRIX(3,3,M0,val);
    float result = detMatrix(3,3,M0.element);
    EXPECT_EQ(result,0);
}

TEST(testCase, easyMatrixTest_DET1) {
    easyMatrix3N3 M0;
    float val1[] = {1,3,4,5,6,7,2,3,5};
    setMatrix(3,3,val1,M0.element);
    float result = detMatrix(3,3,M0.element);
    EXPECT_EQ(result,-12);
}

TEST(testCase, easyMatrixTest_DET2) {
    easyMatrix2N2 M0;
    float val1[] = {1,3,4,5};
    setMatrix(2,2,val1,M0.element);
    float result = detMatrix(2,2,M0.element);
    EXPECT_EQ(result,-7);
}

TEST(testCase, easyMatrixTest_DET3) {
    easyMatrix4N4 M0;
    float val1[] = {1,2,3,4,
                    0,1,2,3,
                    0,0,1,2,
                    0,0,0,1};
    setMatrix(4,4,val1,M0.element);
    float result = detMatrix(4,4,M0.element);
    EXPECT_EQ(result,1);
}

TEST(testCase, easyMatrixTest_DET4) {
    easyMatrix3N3 M0;
    float val1[] = {1,2,3,
                    0,1,2,
                    0,0,1};
    setMatrix(3,3,val1,M0.element);
    float result = detMatrix(3,3,M0.element);
    EXPECT_EQ(result,1);
}

TEST(testCase, easyMatrixTest_DET5) {
    easyMatrix4N4 M0;
    float val1[] = {1,5,3,5,
                    5,6,8,1,
                    9,8,3,1,
                    4,3,2,7 };
    setMatrix(4,4,val1,M0.element);
    float result = detMatrix(4,4,M0.element);
    EXPECT_EQ(result,1475);
}

TEST(testCase, easyMatrixTest_DET7x7) {
    easyMatrix4N4 M0;
    float val1[] = {1,5,3,5,5,4,3,
                    5,6,8,1,1,6,9,
                    9,8,3,1,2,6,3,
                    4,3,2,7,3,4,5,
                    2,5,7,2,3,5,8,
                    1,2,5,3,7,9,3,
                    9,5,7,9,3,1,5
                    };
    setMatrix(7,7,val1,M0.element);
    float result = detMatrix(7,7,M0.element);
    EXPECT_EQ(result,-108006);
}

TEST(testCase, easyMatrixTest_ADD0) {
    easyMatrix4N4 M0;
    easyMatrix4N4 M1;
    easyMatrix4N4 M2;
    float val1[] = {1,3,4,5,3,2,5,6,1,2,3,4,1,2,3,4};
    float val2[] = {1,3,4,5,3,2,5,6,1,2,3,4,1,2,3,4};
    float val3[] = {1,3,4,5,3,2,5,6,1,2,3,4,1,2,3,4};
    for(int i=0;i<16;++i) val2[i] = val1[i] +1;
    for(int i=0;i<16;++i) val3[i] = 1;
    initMatrix4N4(val1,&M0);
    initMatrix4N4(val3,&M1);
    addMatrix(&M1,&M0,&M2);

    expect(4,4,M2.element,val2);
}

TEST(testCase, easyMatrixTest_SUB0) {
    easyMatrix4N4 M0;
    easyMatrix4N4 M1;
    float val1[] = {1,3,4,5,3,2,5,6,1,2,3,4,1,2,3,4};
    float val2[] = {1,3,4,5,3,2,5,6,1,2,3,4,1,2,3,4};
    float val3[] = {1,3,4,5,3,2,5,6,1,2,3,4,1,2,3,4};
    for(int i=0;i<16;++i) val2[i] = val1[i] -1;
    for(int i=0;i<16;++i) val3[i] = 1;
    initMatrix4N4(val1,&M0);
    initMatrix4N4(val3,&M1);
    subMatrix(&M0,&M1,&M1);

    expect(4,4,M1.element,val2);
}

TEST(testCase, easyMatrixTest_MUL0) {
    float val1[] = {1,2,3,4};
    CREATE_MATRIX(1,4,M0,val1);
    CREATE_MATRIX(4,1,M1,val1);
    CREATE_MATRIX(1,1,M2,NULL);
    multiMatrix(&M0,&M1,&M2);

    EXPECT_EQ(M2.element[0],30);
}
TEST(testCase, easyMatrixTest_MUL1) {
    float val1[] = {1,2,3,4};
    float val2[] = {1,2,3,4,2,4,6,8,3,6,9,12,4,8,12,16};
    CREATE_MATRIX(1,4,M0,val1);
    CREATE_MATRIX(4,1,M1,val1);
    CREATE_MATRIX(4,4,M2,NULL);
    multiMatrix(&M1,&M0,&M2);
    expect(4,4,M2.element,val2);
}
TEST(testCase, easyMatrixTest_LEFT) {
    easyMatrix3N3 M0;
    easyMatrix2N2 M1;
    float val1[] = {1,2,3,4,2,4,6,8,3};
    float val2[] = {1,2,4,2};
    setMatrix(3,3,val1,M0.element);
    leftMatrix(3,3,2,2,M0.element,M1.element);

    expect(2,2,M1.element,val2);
}

TEST(testCase, easyMatrixTest_ADJ) {
    easyMatrix3N3 M0;
    easyMatrix3N3 M1;
    float val1[] = {1,2,3,1,0,-1,0,1,1};
    float val2[] = {1,1,-2,-1,1,4,1,-1,-2};
    setMatrix(3,3,val1,M0.element);
    adjMatrix(3,3,M0.element,M1.element);
    expect(3,3,M1.element,val2);
}
TEST(testCase, easyMatrixTest_INV) {
    float val1[] = {1,2,3,1,0,-1,0,1,1};
    CREATE_MATRIX(3,3,M0,val1);
    CREATE_MATRIX(3,3,M1,NULL);
    CREATE_MATRIX(3,3,M2,NULL);
    float val2[] = {0.5,0.5,-1.0,
                    -0.5,0.5,2.0,
                    0.5,-0.5,-1.0};
    invMatrix(3,3,M0.element,M1.element);
    expect(3,3,M1.element,val2);
    multiMatrix(&M0,&M1,&M2);
    eyesMatrix(&M0);
    expect(3,3,M0.element,M2.element);
}
TEST(testCase, easyMatrixTest_INV1) {
    float val1[] = {1,5,3,5,5,4,3,
                    5,6,8,1,1,6,9,
                    9,8,3,1,2,6,3,
                    4,3,2,7,3,4,5,
                    2,5,7,2,3,5,8,
                    1,2,5,3,7,9,3,
                    9,5,7,9,3,1,5
                    };
    CREATE_MATRIX(7,7,M0,val1);
    CREATE_MATRIX(7,7,M1,NULL);
    CREATE_MATRIX(7,7,M2,NULL);
    invMatrix(7,7,M0.element,M1.element);
    //invMatrix(&M0,&M1);
    multiMatrix(&M0,&M1,&M2);
    eyesMatrix(&M0);
    expect(7,7,M0.element,M2.element);
}
