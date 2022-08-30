/*2、编程题
    【程序功能】 
    对于所给的一个自然数n，查找并输出所有满足以下条件的等差数列：
	(1)公差为1;
(2)数列中各项数值之和等于n。
    【编程要求】
    (1)编写函数int found(int a[][30],int n)。函数的功能：
	查找满足上述条件的所有等差数列并依次将其保存到a指向的数组中
	(一行保存一个数列)，函数返回找到的数列个数。
    (2)编写函数main()。函数的功能：声明一个二维整型数组用于
	保存查找结果,输入一个整数并保存到变量n中(n≤600)。
	用n和整型数组作实参调用found函数,将找到的所有等差数输出到屏幕。
    【测试数据与运行结果】
    输入:n=500
    屏幕输出:
    8 9 10 11 12 13 14 15 16 17 18 19 20 2l 22 23 24 25 26 27 28 29 30 31 32
    59 60 6l 62 63 64 65 66
    98 99 100 101 102
    500*/
#include<stdio.h>    
#define N 30
int found(int a[][N],int n)
{
	
	int i,j,k,x=0,m;
	for(i= 1;i<=n;i++)
	{
		k=0;
		for(j=i;j<=n;j++)
		{
			k=k+j;
			if(k>=n) break;
		}
		if(k==n) //说明: i到j之间的等差数列之和等于n，将i到j之间的数列写到数组中去;
		{
			int xiabiao=0;
			for(m=i;m<=j;m++)
			{
				a[x][xiabiao]=m;
				xiabiao++;
				
			}
			a[x][xiabiao]=0;
			x++;
		}
	}
	return x;
}
main()
{
	int a[10][N],n=500;
	printf("Input n:");
	int len=found(a,n);
	int i,j;
	for(i=0;i<len;i++)
	{
		for(j=0;a[i][j]!=0;j++)
			printf("%5d",a[i][j]);
		printf("\n");
	}
}
