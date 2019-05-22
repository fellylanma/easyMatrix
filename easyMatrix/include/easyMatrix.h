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
    float element[x*y];\
}\

float* setMatrix(uint8 x, uint8 y,float* a,float * c) {
    int t = x*y;
    for(int i=0;i<t;++i) {
        c[i] = a[i];
    }
    return c;
}

float* copyMatrix(uint8 x, uint8 y,float* a,float * c) {
    int t = x*y;
    for(int i=0;i<t;++i) {
        c[i] = a[i];
    }
    return c;
}
float* transMatrix(uint8 x, uint8 y,float* a,float * c) {
    for(int ii=0;ii<y;++ii) {
        for(int jj=0;jj<x;++jj) {
            c[ii*x+jj] = a[jj*y+ii];
        }
    }
    return c;
}



void swap(float* a, float* b) {
    float swap = *a;
    *a = *b;
    *b = swap;
}


float detMatrix(uint8 x, uint8 y, float* a) {
    if(x!=y) return 0;
    float val = 1.0;
    float result = 0;
    uint8 t = 0;
    for(uint8 seed = 0;seed<x;++seed) {
        val = 1.0;
        t = 0;
        for(uint8 i=0,j=seed;i<x;++i,++j) {
            if(j>=y) j-=(y);
            val*=a[t+j];
            t+=y;
            if(val==0) break;
        }
        result += val;
    }
    uint8 MAX = 0-1;
    for(uint8 seed = y-1;seed<MAX;seed--) {
        val = 1.0;
        t = 0;
        for(uint8 i=0,j=seed;i<x;++i,--j) {
            val*=a[t+j];
            if(j==0) j=y;
            t+=y;
            if(val==0) break;
        }
        result -= val;
    }
    return result;
}

float* addMatrix(uint8 x, uint8 y,float* a, float * b, float * c) {
    int t = x*y;
    for(int i=0;i<t;++i) {
        c[i] = a[i]+b[i];
    }
    return c;
}
float* subMatrix(uint8 x, uint8 y,float* a, float * b, float * c) {
    int t = x*y;
    for(int i=0;i<t;++i) {
        c[i] = a[i]-b[i];
    }
    return c;
}
float* multiMatrix(uint8 x, uint8 y,float* a,uint8 z, float * b, float * c) {
    if(NULL==c) return NULL;
    if(c == a || c == b) return NULL;
    int count = 0;
    int t_cnt = 0;
    int z_cnt = 0;
    /*
    for(int i = 0;i<x;++i) {
        for(int k = 0;k<z;++k) {
            c[count] = 0;
            for(int j = 0;j<y;++j) {
                c[count] += a[i*y+j]*b[j*z+k];
                printf("%f",a[i*y+j]);
                printf("%f",b[j*z+k]);
                printf("%f\n",c[count]);
            }
            ++count;
        }
    }
    */
    for(int i = 0;i<x;++i) {
        for(int k = 0;k<z;++k) {
            c[count] = 0;
            z_cnt = 0;
            for(int j = 0;j<y;++j) {
                c[count] += a[t_cnt+j]*b[z_cnt+k];
                z_cnt += z;
            }
            count++;
        }
        t_cnt+=y;
    }
    return c;
}
float* zerosMatrix(uint8 x, uint8 y,float* e) {
    int t = x*y;
    for(int i=0;i<t;++i) {
        e[i] = 0;
    }
    return e;
}
float* eyesMatrix(uint8 x, uint8 y, float*e) {
    int t = x*y;
    for(int i=0;i<t;++i) {
        e[i] = 1.0;
    }
    return e;
}
void dumpMatrix(uint8 x, uint8 y, float*e) {
    //TODO:
    int count = 0;
    printf("cols is:%d, rows is:%d\n",x,y);
    for(int i = 0;i<x;++i) {
        for(int j = 0;j<y;++j) {
            printf("%8f,",e[count]);
            ++count;
        }
        printf("\n");
    }
    return;
}

float* adjMatrix(uint8 x, uint8 y,float* a,float * c) {
    float* adj =(float*) malloc(sizeof(float)*(x-1)*(y-1));
    int index = 0;
    for(int ii=0;ii<x;++ii) {
        for(int jj=0;jj<y;++jj) {
            index = 0;
            for(int kk=0;kk<x;++kk) {
                for(int ww=0;ww<y;++ww) {
                    if(!(kk==ii||ww==jj)) {
                        adj[index] = a[kk*y+ww];
                        index++;
                    }
                }
            }
            dumpMatrix(2,2,adj);
            printf("x,y:%d,%d",x,y);
            c[ii*y+jj] = detMatrix(2,2,adj);
            printf("adj det is:%d\n",c[ii*y+jj]);
        }
    }
    return c;
}
#endif//_MAGRIDE_PLANNING_EASYMATRIX_H_
