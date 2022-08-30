/*9、特殊素数对
【程序功能】
验证从3-2008之间的所有素数中存在这样两个素数，它们之和为2008。
【编程要求】
(1)编写函数int fun( int n, int *a, int *b)，其功能是在3~n之间寻找一对素数,它们的和等于n，若找到则将两个素数分别保存到a,b指向的变量中，函数返回1；若找不到，函数返回0。
(2)编写main函数，声明变量n并用测试数据初始化，调用fun函数找出3~n之间和值为n的一对素数，将找到的这对素数输出到屏幕。
【测试数据与运行结果】
测试数据：n=2008
运行结果：a=5     b=2003    a+b=2008*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
int prime(int n)
{  
	int i;         
    if(n==1) return false;  
    for(i=2;i<=sqrt(n);i++)
		if(n%i==0)  return false;
	    return true;

}
int fun( int n, int a[])
{   
	int i,j;
	for( i=2 ; i<n/2 ; i++ )
	{
		if(prime(i)&&prime(j=n-i))
		{
			a[0]=i;
			a[1]=j;
			return 1;
		}
	}
	return 0;
}
main()
{   int p,x[2];
    printf("Input p="); scanf("%d",&p);
    if(fun(p,x)==1)
		   printf("n=%d\na=%-6db=%-6da+b=%-6d\n ",p,x[0],x[1],x[0]+x[1]);  	
else 
	       printf("Not be found!\n "); 
}
