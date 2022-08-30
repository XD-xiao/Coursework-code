/*5、编程题
【题目】
(1)编写函数fun，它的功能是：将3行4列矩阵x乘以4行3列矩阵y，结果放在3行3列矩阵xy中。矩阵相乘的基本方法是：矩阵xy中行列下标分别为i,j的元素的值，是矩阵x中第i行上4个元素与矩阵y中第j列上4个元素对应相乘的和。
例如：矩阵x为，矩阵y为，则矩阵xy为。
(2)编写main函数，初始化两个数组，调用函数fun，将结果矩阵输出到屏幕上。*/
#include<stdio.h>
#define N 3
#define M 4
#define Q 3
fun(int a[][M],int b[][Q],int c[][Q])
{
	int i,j,k;
	for(i=0;i<N;i++)
		for(j=0;j<Q;j++)
			for(k=0;k<M;k++)
				c[i][j]+=a[i][k]*b[k][j];
	
}

main()
{
	int a[N][M]={1,0,1,1,2,1,0,1,1,2,0,3};
	int b[M][Q]={1,1,1,0,0,0,2,1,1,1,1,3};
	int c[N][Q]={0};
	int i,j,k,t[N*M];
	/*显示数组内容*/
	printf("a[][]:\n"); 
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
			printf("%4d",a[i][j]);
		printf("\n");
	}	
	printf("\nb[][]:\n"); 
	for(i=0;i<M;i++)
	{
		for(j=0;j<Q;j++)
			printf("%4d",b[i][j]);
		printf("\n");
	}	

	fun(a,b,c);
	
	printf("\nc[][]:\n"); 
	for(i=0;i<N;i++)
	{
		for(j=0;j<Q;j++)
			printf("%4d",c[i][j]);
		printf("\n");
	}	
} 
