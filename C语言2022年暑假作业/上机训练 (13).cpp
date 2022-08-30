/*2、编程题
【程序功能】
    将一个二维数组中的若干行数据按要求插入到另一个二维数组中。
【编程要求】
    (1)定义符号常量N代表4
    (2)编写函数int insert_row(int a[][N],int n,int b[][N],int m)。
	已知形参a指向的二维数组(简称a数组)前n行数据已按每行数据之
	和升序排列，形参b指向的二维数组中有m行数据。
	insert_row函数实现将b数组中m行数据插入到a数组中，
	完成插入操作后a数组中所有行的数据仍按每行数据之和升序排列。
	函数返回a数组中有效数据的行数。
    (3)编写main函数。函数功能是：
	声明两个二维数组x和y并用测试数据初始化，
	用x和y数组作为实参调用insert_row函数将y数组中的两行数据
	插入到x数组中。输出x数组中全部数据到屏幕。
【测试数据与运行结果】
    测试数据:
    x数组原数据:
    2  2   3   4
    9  10  11  12
    y数组数据:
    1    3     5     7
    5    10    15    20
    屏幕输出:
    2    2    3    4
    1    3    5    7
    9    10   11   12
    5    10   15   20*/
#include<stdio.h>
#define N 4
int insert_row(int a[][N],int n,int b[][N],int m)
{
	int c[10][4];
	int i,j,k,len=0;
	for(i=0,j=0;i<n||j<m;i++,b++)
	{
		if(i<n)
		{
			for(k=0;k<4;k++)
				c[len][k]=a[i][k];
			len++;
		}
		if(j<m)
		{
			for(k=0;k<4;k++)
				c[len][k]=b[j][k];
			len++;
		}	
	}
	for(i=0;i<len;i++)
		for(j=0;j<4;j++)
			a[i][j]=c[i][j];
	return len;
	
}
main()
{
	int x[10][4]={2,2,3,4,9,10,11,12};
	int y[2][4]={1, 3,   5 ,  7, 5 , 10 , 15 ,20};
	int len=insert_row(x,2,y,2);
	for(int i=0;i<len;i++)
	{
		for(int j=0;j<4;j++)
			printf("%5d",x[i][j]);
		printf("\n");
	}
 } 
