/*************************************************************************
	> File Name: easyMatrix.c
	> Author: Zhang Yuteng
	> Mail:
	> Created Time: 2019年05月23日 星期四 21时57分31秒
 ************************************************************************/

#include <stdlib.h>
#include "easyMatrix.h"

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
float* leftMatrix(uint8 x, uint8 y,uint8 x_i,uint8 y_i, float* in, float* out) {
    int index = 0;
    for(int kk=0;kk<x;++kk) {
        for(int ww=0;ww<y;++ww) {
            if(!(kk==x_i||ww==y_i)) {
                out[index] = in[kk*y+ww];
                index++;
            }
        }
    }
    return out;
}
float* adjMatrix(uint8 x, uint8 y, float* in, float *out) {
    float* ret =(float*) malloc(sizeof(float)*(x-1)*(y-1));
    signed char sign1 = 1;
    signed char sign2 = 1;
    for(uint8 ii=0;ii<x;++ii) {
        sign2 = sign1;
        for(uint8 jj=0;jj<y;++jj) {
            leftMatrix(x,y,ii,jj,in,ret);
            out[jj*y+ii] = sign2*detMatrix(x-1,y-1,ret);
            sign2 = - sign2;    
        }
        
        sign1 = - sign1;
    }
    return out;

}
float* invMatrix(uint8 x, uint8 y, float *in , float* out) {
    adjMatrix(x,y,in,out);
    float scale = detMatrix(x,y,in);
    scale = 1/scale;
    scaleMatrix(x,y,scale,out,out);
    return out;
}

float detMatrix(uint8 x, uint8 y, float* a) {
    if(x!=y) return 0;
    //dumpMatrix(x,y,a);
    if(x==2) return(a[0]*a[3]-a[1]*a[2]);
    //if(x==3) return(a[0]*a[4]*a[8]+a[1]*a[5]*a[6]+a[2]*a[3]*a[7]-a[2]*a[4]*a[6]-a[1]*a[3]*a[8]-a[0]*a[5]*a[7]);
    float result = 0;
    signed char sign = 1;
    float* ret =(float*) malloc(sizeof(float)*(x-1)*(y-1));
    for(uint8 i=0;i<x;++i) {
        leftMatrix(x,y,0,i,a,ret);
        result += sign*a[0+i]*detMatrix(x-1,y-1,ret);
        sign = - sign;
    }
    return result;
    /*
    for(uint8 seed = 0;seed<x;++seed) {
        val = 1.0;
        t = 0;
        for(uint8 i=0,j=seed;i<x;++i,++j) {
            if(j>=y) j-=(y);
            val*=a[t+j];
            t+=y;
            if(val==0) break;
        }
        printf("numis:%f\n",val);
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
        printf("numis:%f\n",val);
        result -= val;
    }
    
    return result;
    */
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
float* scaleMatrix(uint8 x, uint8 y, float scale, float*a, float* b) {
    int t = x*y;
    for (int i = 0;i<t;++i) {
        b[i] = a[i]*scale;
    }
    return b;
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
    for(int i=0;i<x;++i) {
    for(int j=0;j<y;++j) {
        if(i==j)
        e[i*y+j] = 1.0;
        else
        e[i*y+j] = 0.0;
    }
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

