# easyMatrix
A pure C language nano Matrix library with best user experience ever!

easyMatrix is a lite open source Matrix operating library in C language which will help those who develop on embedded systems even without operating systems.
If you can not use other libraries in C++ such as Eigen, easyMatrix is your best choice.

easyMatrix is really easy and small . You can configure the data type for the matrix. 
8-bit data such as cols and rows number is used instead of 32-bit integer.

#How to use

//create matrix on stack
 	float val1[] = {1,2,3,4,5,6,7,8,9};
	float val2[] = {1,1,1,1,1,1,1,1,1};
	CREATE_MATRIX_ONSTACK(3,3,A,val1);
	CREATE_MATRIX_ONSTACK(3,3,B,val2);
	CREATE_MATRIX_ONSTACK(3,3,C,NULL);
	addMatrix(&A,&B,&C);
	dumpMatrix(&C);
    printf("det is:%f\n",detMatrix(&A));
	int x = A.rows;
	int y = A.cols;
	printf("element[1,1] is:%f\n",A.element[1*x+1]);
	//create matrix on heap and you need to delete the pointer
	CREATE_DYNAMIC_MATRIX_ONHEAP(x,y,D,val1);
	CREATE_DYNAMIC_MATRIX_ONHEAP(x,y,E,val2);
	CREATE_DYNAMIC_MATRIX_ONHEAP(x,y,F,NULL);
	multiMatrix(D,E,&C);
	multiMatrix(D,E,F);

	DELETE_DYNAMIC_MATRIX(D);
	DELETE_DYNAMIC_MATRIX(E);
	DELETE_DYNAMIC_MATRIX(F);
--------------------- 
作者：腾TO的技术输出 
来源：CSDN 
原文：https://blog.csdn.net/weixin_43870191/article/details/92417340 
版权声明：本文为博主原创文章，转载请附上博文链接！
