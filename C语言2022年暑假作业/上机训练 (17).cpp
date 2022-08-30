/*2、编程题
程序功能：求10~200内的的所有反素数并按每行5个的形式输出。
对于任意大于2的正整数x，若当0<i<x时都有g(i)<g(x)，
则称x为反素数（其中g(i)代表i的约数个数，g(x)代表x的约数个数）。
例如：由于
g(1)=1、g(2)=2、g(3)=2、g(4)=3、g(5)=2、g(6)=4、g(7)=2、g(8)=4，
因此4和6是反素数，3、4、5、7、8则不是反素数。
编程要求：
（1）编写函数int fun(int a[])。函数功能：将10~200范围内的所
有反素数依次存储到a指向的数组中，函数返回反素数的个数。
算法提示：编写函数int g(int n)求一个整数n的约数的个数。
（2）编写函数main()。函数功能：声明一个一维数组a，
用数组a作实参调用fun函数，按每行5个数的形式输出a数组中的数据到屏幕及。
屏幕输出： 12   24    36    48    60
120180
*/
#include <stdio.h>
#include <stdlib.h>   /*主函数exit(0);需要*/
#include <conio.h>   /*主函数getch();需要*/
#define P 10         /*为设计通用程序，设置常量P=20和K=200*/
#define K 200
#define N 20
bool isprime(int n)
{
	int i;
	for(i=2;i<=(n)/2;i++)
		if(n%i==0)
			return false;
	return true;
}
int g(int n)    /*求一个整数n的约数的个数*/
{   
	int count=0,i;
	for(i=1;i<n/2;i++)
		if(n%i==0)
			count++;
	return count;
}
int fun(int a[])   
{  
	int num,count=0;
	int j;
	for( num=10 ; num<=200 ; num++ )
	{
		int m=g(num);
		for( j=num-1 ; j>0 ; j--)
			if(m<=g(j))
				break;
		if(j<=0)
		{
			a[count++]=num;
		}
	}
	return count;
}

main()
{  int i,a[N],n; 
   n=fun(a); 
   for(i=0;i<n;i++)    
   {   if(i%5==0)  printf("\n");
       printf("%4d",a[i]);   
}
}
