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

DATA_TYPE val[] = {1,2,3,4,5,6,7,8,9};
void expect(int i, int j,DATA_TYPE* a, DATA_TYPE* b) {
    int t = i*j;
    for(int ii=0;ii<t;++ii) {
        EXPECT_NEAR(a[ii],b[ii],1e-5);
    }
}

void expect(struct easyMatrix* a, struct easyMatrix* b) {
    int t = a->cols*a->rows;
    for(int ii=0;ii<t;++ii) {
        EXPECT_NEAR(a->element[ii],b->element[ii],1e-5);
    }
}

void expect(int i, int j,DATA_TYPE* a, DATA_TYPE val) {
    int t = i*j;
    for(int ii=0;ii<t;++ii) {
        EXPECT_NEAR(a[ii],val,1e-5);
    }
}

TEST(testCase, easyMatrixTest_SET) {
    CREATE_MATRIX_ONSTACK(3,3,M0,val);
    expect(3,3,val,M0.element);
};

TEST(testCase, easyMatrixTest_COPY) {
    CREATE_MATRIX_ONSTACK(3,3,M0,val);
    CREATE_MATRIX_ONSTACK(3,3,M1,NULL);
    copyMatrix(&M0,&M1);
    expect(3,3,val,M1.element);
};

TEST(testCase, easyMatrixTest_ZEROS) {
    CREATE_MATRIX_ONSTACK(3,3,M0,val);
    expect(3,3,val,M0.element);
    zerosMatrix(&M0);
    expect(3,3,M0.element,0.0f);
};
TEST(testCase, easyMatrixTest_SCALE) {
    DATA_TYPE val[] = {1,2,3,4,5,6,7,8,9};
    DATA_TYPE val1[] = {2,4,6,8,10,12,14,16,18};
    CREATE_MATRIX_ONSTACK(3,3,M0,val);
    CREATE_MATRIX_ONSTACK(3,3,M1,NULL);
    expect(3,3,val,M0.element);
    scaleMatrix(2,&M0,&M1);
    setMatrix(val1,&M0);
    expect(&M1,&M0);
};
TEST(testCase, easyMatrixTest_ONES) {
    CREATE_MATRIX_ONSTACK(3,3,M0,val);
    expect(3,3,val,M0.element);
    DATA_TYPE val1[] = {1,0,0,0,1,0,0,0,1};
    eyesMatrix(&M0);
    expect(3,3,M0.element,val1);
};
TEST(testCase, easyMatrixTest_TRANS0) {
    CREATE_MATRIX_ONSTACK(3,3,M0,val);
    CREATE_MATRIX_ONSTACK(3,3,M1,NULL);
    transMatrix(&M0,&M1);
    DATA_TYPE val1[] = {1,4,7,2,5,8,3,6,9};
    expect(3,3,M1.element,val1);
}
TEST(testCase, easyMatrixTest_TRANS1) {
    CREATE_MATRIX_ONSTACK(2,3,N1,val);
    CREATE_MATRIX_ONSTACK(3,2,N2,NULL);
    transMatrix(&N1,&N2);
    DATA_TYPE val1[] = {1,4,2,5,3,6};
    expect(3,2,N2.element,val1);
}

TEST(testCase, easyMatrixTest_DET) {
    CREATE_MATRIX_ONSTACK(3,3,M0,val);
    DATA_TYPE result = detMatrix(&M0);
    EXPECT_EQ(result,0);
}
TEST(testCase, easyMatrixTest_DET1) {
    DATA_TYPE val1[] = {1,3,4,5,6,7,2,3,5};
    CREATE_MATRIX_ONSTACK(3,3,M0,val1);
    DATA_TYPE result = detMatrix(&M0);
    EXPECT_EQ(result,-12);
}

TEST(testCase, easyMatrixTest_DET2) {
    DATA_TYPE val1[] = {1,3,4,5};
    CREATE_MATRIX_ONSTACK(2,2,M0,val1);
    DATA_TYPE result = detMatrix(&M0);
    EXPECT_EQ(result,-7);
}
TEST(testCase, easyMatrixTest_DET3) {
    DATA_TYPE val1[] = {1,2,3,4,
                    0,1,2,3,
                    0,0,1,2,
                    0,0,0,1};
    CREATE_MATRIX_ONSTACK(4,4,M0,val1);
    DATA_TYPE result = detMatrix(&M0);
    EXPECT_EQ(result,1);
}

TEST(testCase, easyMatrixTest_DET4) {
    DATA_TYPE val1[] = {1,2,3,
                    0,1,2,
                    0,0,1};
    CREATE_MATRIX_ONSTACK(3,3,M0,val1);
    DATA_TYPE result = detMatrix(&M0);
    EXPECT_EQ(result,1);
}

TEST(testCase, easyMatrixTest_DET5) {
    DATA_TYPE val1[] = {1,5,3,5,
                    5,6,8,1,
                    9,8,3,1,
                    4,3,2,7 };
    CREATE_MATRIX_ONSTACK(4,4,M0,val1);
    DATA_TYPE result = detMatrix(&M0);
    EXPECT_EQ(result,1475);
}

TEST(testCase, easyMatrixTest_DET7x7) {
    DATA_TYPE val1[] = {1,5,3,5,5,4,3,
                    5,6,8,1,1,6,9,
                    9,8,3,1,2,6,3,
                    4,3,2,7,3,4,5,
                    2,5,7,2,3,5,8,
                    1,2,5,3,7,9,3,
                    9,5,7,9,3,1,5
                    };
    CREATE_MATRIX_ONSTACK(7,7,M0,val1);
    DATA_TYPE result = detMatrix(&M0);
    EXPECT_EQ(result,-108006);
}

TEST(testCase, easyMatrixTest_ADD0) {
    DATA_TYPE val1[] = {1,3,4,5,3,2,5,6,1,2,3,4,1,2,3,4};
    DATA_TYPE val2[16];
    DATA_TYPE val3[16];
    for(int i=0;i<16;++i) val2[i] = val1[i] +1;
    for(int i=0;i<16;++i) val3[i] = 1;
    CREATE_MATRIX_ONSTACK(4,4,M0,val1);
    CREATE_MATRIX_ONSTACK(4,4,M1,val3);
    CREATE_MATRIX_ONSTACK(4,4,M2,NULL);
    addMatrix(&M1,&M0,&M2);

    expect(4,4,M2.element,val2);
}

TEST(testCase, easyMatrixTest_SUB0) {
    DATA_TYPE val1[] = {1,3,4,5,3,2,5,6,1,2,3,4,1,2,3,4};
    DATA_TYPE val2[16];
    DATA_TYPE val3[16];
    for(int i=0;i<16;++i) val2[i] = val1[i] -1;
    for(int i=0;i<16;++i) val3[i] = 1;
    CREATE_MATRIX_ONSTACK(4,4,M0,val1);
    CREATE_MATRIX_ONSTACK(4,4,M1,val3);
    subMatrix(&M0,&M1,&M1);

    expect(4,4,M1.element,val2);
}

TEST(testCase, easyMatrixTest_MUL0) {
    DATA_TYPE val1[] = {1,2,3,4};
    CREATE_MATRIX_ONSTACK(1,4,M0,val1);
    CREATE_MATRIX_ONSTACK(4,1,M1,val1);
    CREATE_MATRIX_ONSTACK(1,1,M2,NULL);
    multiMatrix(&M0,&M1,&M2);

    EXPECT_EQ(M2.element[0],30);
}

TEST(testCase, easyMatrixTest_MUL1) {
    DATA_TYPE val1[] = {1,2,3,4};
    DATA_TYPE val2[] = {1,2,3,4,2,4,6,8,3,6,9,12,4,8,12,16};
    CREATE_MATRIX_ONSTACK(1,4,M0,val1);
    CREATE_MATRIX_ONSTACK(4,1,M1,val1);
    CREATE_MATRIX_ONSTACK(4,4,M2,NULL);
    multiMatrix(&M1,&M0,&M2);
    expect(4,4,M2.element,val2);
}

TEST(testCase, easyMatrixTest_LEFT) {
    DATA_TYPE val1[] = {1,2,3,4,2,4,6,8,3};
    CREATE_MATRIX_ONSTACK(3,3,M0,val1);
    CREATE_MATRIX_ONSTACK(2,2,M1,NULL);
    DATA_TYPE val2[] = {1,2,4,2};
    leftMatrix(2,2,&M0,&M1);

    expect(2,2,M1.element,val2);
}

TEST(testCase, easyMatrixTest_ADJ) {
    DATA_TYPE val1[] = {1,2,3,1,0,-1,0,1,1};
    DATA_TYPE val2[] = {1,1,-2,-1,1,4,1,-1,-2};
    CREATE_MATRIX_ONSTACK(3,3,M0,val1);
    CREATE_MATRIX_ONSTACK(3,3,M1,NULL);
    adjMatrix(&M0,&M1);
    expect(3,3,M1.element,val2);
}

TEST(testCase, easyMatrixTest_INV) {
    DATA_TYPE val1[] = {1,2,3,1,0,-1,0,1,1};
    CREATE_MATRIX_ONSTACK(3,3,M0,val1);
    CREATE_MATRIX_ONSTACK(3,3,M1,NULL);
    CREATE_MATRIX_ONSTACK(3,3,M2,NULL);
    DATA_TYPE val2[] = {0.5,0.5,-1.0,
                    -0.5,0.5,2.0,
                    0.5,-0.5,-1.0};
    invMatrix(&M0,&M1);
    expect(3,3,M1.element,val2);
    multiMatrix(&M0,&M1,&M2);
    eyesMatrix(&M0);
    expect(&M0,&M2);
}

TEST(testCase, easyMatrixTest_INV1) {
    DATA_TYPE val1[] = {1,5,3,5,5,4,3,
                    5,6,8,1,1,6,9,
                    9,8,3,1,2,6,3,
                    4,3,2,7,3,4,5,
                    2,5,7,2,3,5,8,
                    1,2,5,3,7,9,3,
                    9,5,7,9,3,1,5
                    };
    CREATE_MATRIX_ONSTACK(7,7,M0,val1);
    CREATE_MATRIX_ONSTACK(7,7,M1,NULL);
    CREATE_MATRIX_ONSTACK(7,7,M2,NULL);
    invMatrix(&M0,&M1);
    multiMatrix(&M0,&M1,&M2);
    eyesMatrix(&M0);
    dumpMatrix(&M2);
    expect(&M0,&M2);
}

TEST(testCase, easyMatrixTest_LU) {
    DATA_TYPE val1[] = {1,2,3,1,0,-1,0,1,1};
    CREATE_MATRIX_ONSTACK(3,3,M0,val1);
    CREATE_MATRIX_ONSTACK(3,3,M1,NULL);
    CREATE_MATRIX_ONSTACK(3,3,L,NULL);
    CREATE_MATRIX_ONSTACK(3,3,U,NULL);
    getLUMatrix(&M0,&L,&U);
    multiMatrix(&L,&U,&M1);
    expect(&M0,&M1);
}

TEST(testCase, easyMatrixTest_LINV) {
    DATA_TYPE val1[] = {1,2,3,1,0,-1,0,1,1};
    CREATE_MATRIX_ONSTACK(3,3,M0,val1);
    CREATE_MATRIX_ONSTACK(3,3,M1,NULL);
    CREATE_MATRIX_ONSTACK(3,3,L,NULL);
    CREATE_MATRIX_ONSTACK(3,3,U,NULL);
    CREATE_MATRIX_ONSTACK(3,3,LINV,NULL);
    getLUMatrix(&M0,&L,&U);
    invLMatrix(&L,&LINV);
    multiMatrix(&L,&LINV,&M1);
    eyesMatrix(&L);
    expect(&L,&M1);
}

TEST(testCase, easyMatrixTest_UINV) {
    DATA_TYPE val1[] = {1,2,3,1,0,-1,0,1,1};
    CREATE_MATRIX_ONSTACK(3,3,M0,val1);
    CREATE_MATRIX_ONSTACK(3,3,M1,NULL);
    CREATE_MATRIX_ONSTACK(3,3,L,NULL);
    CREATE_MATRIX_ONSTACK(3,3,U,NULL);
    CREATE_MATRIX_ONSTACK(3,3,UINV,NULL);
    getLUMatrix(&M0,&L,&U);
    invUMatrix(&U,&UINV);
    multiMatrix(&U,&UINV,&M1);
    eyesMatrix(&M0);
    expect(&M0,&M1);
}

TEST(testCase, easyMatrixTest_LUINV) {
    DATA_TYPE val1[] = {1,2,3,1,0,-1,0,1,1};
    CREATE_MATRIX_ONSTACK(3,3,M0,val1);
    CREATE_MATRIX_ONSTACK(3,3,M1,NULL);
    CREATE_MATRIX_ONSTACK(3,3,M2,NULL);
    CREATE_MATRIX_ONSTACK(3,3,L,NULL);
    CREATE_MATRIX_ONSTACK(3,3,LINV,NULL);
    CREATE_MATRIX_ONSTACK(3,3,U,NULL);
    CREATE_MATRIX_ONSTACK(3,3,UINV,NULL);
    getLUMatrix(&M0,&L,&U);
    invUMatrix(&U,&UINV);
    invLMatrix(&L,&LINV);
    multiMatrix(&UINV,&LINV,&M1);
    multiMatrix(&M1,&M0,&M2);
    dumpMatrix(&M2);
    eyesMatrix(&M0);
    expect(&M0,&M2);
}
