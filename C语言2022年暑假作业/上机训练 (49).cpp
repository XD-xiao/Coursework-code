/*10、
【程序功能】
寻找从2000-2010之间，能分解为第一对两个素数之和的所有偶数，例如2008的第一对两个素数为(5,2003)。因为2008有三对素数对：(5,2003)、(7，2001)、(11，1997)。
【编程要求】
(1)编写函数int fun( int s, int e,  int b[][3])，其功能是寻找能满足一对素数之和，在变量s～变量e之间所有偶数，,函数返回满足条件的偶数个数.，若找到则将满足条件的偶数和、两个素数保存到b指向的数组一行变量中。
(2)编写main函数，声明变量s、e，并用测试数据初始化，调用fun函数找出能满足一对素数之和，在变量s～变量e之间所有偶数，将找到的偶数及其相应一对素数输出到屏幕。
【测试数据与运行结果】
测试数据：start =2000
          end=2010
运行结果：3+1997=2000
3+1999=2002
5+1999=2004
3+2003=2006
5+2003=2008
          7+2003=2010*/
#include <stdio.h>
#include <stdlib.h>  //函数exit(0);需要
#include <conio.h>   //函数getch();需要
#include <math.h>
int prime(int n)    //适合判别大于1的自然数是否是素数的标准函数
{   
	int i;         
    if(n==1) return false;  
    for(i=2;i<=sqrt(n);i++)
		if(n%i==0)  return false;
	    return true;

}
int fun( int s, int e, int b[][3])
{   
	int n,i,j,count=0;
	for(n=s;n<=e;n++)
	{
		if(n%2==0)
			for( i=2 ; i<n/2 ; i++ )
			{
				if(prime(i)&&prime(j=n-i))
				{
					b[count][0]=n;
					b[count][1]=i;
					b[count++][2]=j;
					break;
				}
			}
	}
	return count; 

}
main()
{   int s=2000,e=2010,i,p=0,x[20][3]={0};
	    printf("start=%d\nend=%d\nOutput:\n",s,e);
    p=fun(s,e,x);
    for(i=0;i<p;i++)
		   printf("%d+%d=%d\n ",x[i][1],x[i][2],x[i][0]); 
}
