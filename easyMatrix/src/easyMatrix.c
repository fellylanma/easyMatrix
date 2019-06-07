/*************************************************************************
	> File Name: easyMatrix.c
	> Author: Zhang Yuteng
	> Mail:
	> Created Time: 2019年05月23日 星期四 21时57分31秒
 ************************************************************************/

#include <stdlib.h>
#include "easyMatrix.h"
void* setMatrix(float * a,void* c) {
    uint8 x = easy_cast(c)->rows;
    uint8 y = easy_cast(c)->cols;
    int t = x*y;
    for(int i=0;i<t;++i) {
        easy_cast(c)->element[i] = a[i];
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

void* transMatrix(void* a,void* c) {
    int index = 0;
    for(int ii=0;ii<easy_cast(a)->cols;++ii) {
        for(int jj=0;jj<easy_cast(a)->rows;++jj) {
            easy_cast(c)->element[index] = easy_cast(a)->element[jj*easy_cast(a)->cols+ii];
            index++;
        }
    }
    return c;
}

void* leftMatrix(uint8 x_i,uint8 y_i, void* const in, void* out) {
    int index = 0;
    uint8 x = easy_cast(in)->rows;
    uint8 y = easy_cast(in)->cols;
    for(int kk=0;kk<x;++kk) {
        for(int ww=0;ww<y;++ww) {
            if(!(kk==x_i||ww==y_i)) {
                easy_cast(out)->element[index] = easy_cast(in)->element[kk*y+ww];
                index++;
            }
        }
    }
    return out;
}
void* adjMatrix(void* in, void* out) {
    uint8 x = easy_cast(in)->rows;
    uint8 y = easy_cast(in)->cols;
    CREATE_DYNAMIC_MATRIX(x-1,y-1,ret);
    signed char sign1 = 1;
    signed char sign2 = 1;
    for(uint8 ii=0;ii<x;++ii) {
        sign2 = sign1;
        for(uint8 jj=0;jj<y;++jj) {
            leftMatrix(ii,jj,in,&ret);
            easy_cast(out)->element[jj*y+ii] = sign2*detMatrix(&ret);
            sign2 = - sign2;    
        }
        
        sign1 = - sign1;
    }
    DELETE_DYNAMIC_MATRIX(&ret);
    return out;

}
float invMatrix(void *in , void * out) {
    adjMatrix(in,out);
    float scale = detMatrix(in);
    if(scale<1e-5&&scale>-1e-5) return 0.0;
    scale = 1/scale;
    scaleMatrix(scale,out,out);
    return scale;
}

float detMatrix(void* const in) {
    uint8 x = easy_cast(in)->rows;
    uint8 y = easy_cast(in)->cols;
    if(x!=y) return 0;
    if(x==0 ) return 0;
    if(x==1 ) return easy_cast(in)->element[0];
    float *a = easy_cast(in)->element;
    if(x==2) return(a[0]*a[3]-a[1]*a[2]);
    float result = 0;
    signed char sign = 1;
    CREATE_DYNAMIC_MATRIX(x-1,y-1,ret);
    for(uint8 i=0;i<x;++i) {
        leftMatrix(0,i,in,&ret);
        result += sign*a[0+i]*detMatrix(&ret);
        sign = - sign;
    }
    DELETE_DYNAMIC_MATRIX(&ret);
    return result;
}
/*
float* addMatrix(uint8 x, uint8 y,float* a, float * b, float * c) {
    int t = x*y;
    for(int i=0;i<t;++i) {
        c[i] = a[i]+b[i];
    }
    return c;
}
*/
void* addMatrix(void* a, void* b, void* c) {
    struct easyMatrix* obj = (struct easyMatrix*)a;
    int t = obj->rows*obj->cols;
    for(int i=0;i<t;++i) {
        easy_cast(c)->element[i] = obj->element[i]+easy_cast(b)->element[i];
    }
    return c;
}
void* subMatrix(void* a, void* b, void* c) {
    struct easyMatrix* obj = (struct easyMatrix*)a;
    int t = obj->rows*obj->cols;
    for(int i=0;i<t;++i) {
        easy_cast(c)->element[i] = obj->element[i]-easy_cast(b)->element[i];
    }
    return c;
}
void* scaleMatrix(float scale, void* const a, void* b) {
    int t = easy_cast(a)->cols*easy_cast(a)->rows;
    for (int i = 0;i<t;++i) {
        easy_cast(b)->element[i] = easy_cast(a)->element[i]*scale;
    }
    return b;
}
void* multiMatrix(void* a,void* b, void* c) {
    if(NULL==c) return NULL;
    if(c == a || c == b) return NULL;
    int count = 0;
    int t_cnt = 0;
    int z_cnt = 0;
    uint8 x = easy_cast(a)->rows;
    uint8 y = easy_cast(a)->cols;
    uint8 z = easy_cast(b)->cols;
    for(int i = 0;i<x;++i) {
        for(int k = 0;k<z;++k) {
            easy_cast(c)->element[count] = 0;
            z_cnt = 0;
            for(int j = 0;j<y;++j) {
                easy_cast(c)->element[count] += easy_cast(a)->element[t_cnt+j]*easy_cast(b)->element[z_cnt+k];
                z_cnt += z;
            }
            count++;
        }
        t_cnt+=y;
    }
    return c;
}
void* zerosMatrix(void* e) {
    int t = easy_cast(e)->cols*easy_cast(e)->rows;
    for(int i=0;i<t;++i) {
        easy_cast(e)->element[i] = 0;
    }
    return e;
}
void* eyesMatrix(void* e) {
    int index = 0;
    for(int i=0;i<easy_cast(e)->rows;++i) {
        for(int j=0;j<easy_cast(e)->cols;++j) {
            if(i==j)
                easy_cast(e)->element[index] = 1.0;
            else
                easy_cast(e)->element[index] = 0.0;
            index++;
        }
    }
    return e;
}
void dumpMatrix(void*e) {
    int count = 0;
    uint8 x = easy_cast(e)->rows;
    uint8 y = easy_cast(e)->cols;
    printf("cols is:%d, rows is:%d\n",x,y);
    for(int i = 0;i<x;++i) {
        for(int j = 0;j<y;++j) {
            printf("%8f,",easy_cast(e)->element[count]);
            ++count;
        }
        printf("\n");
    }
    return;
}

