/*1、梅森素数(Mersenne Prime)
是指每一个素数皆符合 2p ? 1的数式，形如2p－1的正整数，其中指数p是素数，常记为Mp 。若Mp是素数，则称为梅森素数。p=2，3，5，7时，Mp
寻都是素数，但M11=2047=23×89不是素数 ，是否有无穷多个梅森素数是数论中未解决的难题之一。首9个梅森质数是:
3, 7, 31, 127, 8191, 131071, 524287, 2147483647, 2305843009213693951
【程序功能】
找前三个双梅森素数(Mersenne Prime)，双梅森素数定义为对于每个素数p，其也是素数。例如p=5，则M=2,147,483,647是素数。
【编程要求】
(1)编写函数void fun(long  b[][2])，其功能是寻找前三个双梅森素数，将满足条件的三个双梅森素数及其的反序数保存到b指向的数组中。
(2)编写main函数，声明数组，调用fun函数找出三个梅森素数及其反序数，将找到的梅森素数及其反序数输出到屏幕。
【测试数据与运行结果】
运行结果：7，127，2147483647
7，721，7463847412
调试程序中采用double类型处理，显示用“%.0lf”显示格式。*/
#include<stdlib.h>    //函数exit(0)需要
#include<conio.h>    //函数getch()需要
#include<math.h>
#include<stdio.h>
#define N 3
unsigned long reverse(unsigned long num)
{
	unsigned long x=0;
	while(num)
	{
		x=x*10+num%10;
		num/=10;
	}
	return x;
}
bool isprime(unsigned long num)
{
	unsigned long j;
	for( j=2 ; j<sqrt(num) ; j++ )
		if(num%j==0)
			return false;
	return true;
}
unsigned long Mersenne_Prime(unsigned long num)
{
	return pow(2,num)-1;
}
void fun(unsigned long  b[][2])
{
	unsigned long num=2;
	int count=0;
	do
	{
		if(isprime(num)&&isprime(Mersenne_Prime(num)))
		{
			unsigned long t=Mersenne_Prime(num);
			if(isprime(Mersenne_Prime(t)))
			{
				b[count][0]=Mersenne_Prime(t);
				unsigned long t1=reverse(Mersenne_Prime(t));
				b[count++][1]=t1;
			}
		}
		num++;
	}while(count<N);
}
main()
{   int i;
   unsigned long a[N][2]={0}; //
    fun(a);
    for(i=0;i<N;i++)
       printf(i<2?"%ld,":"%ld\n",a[i][0]); 
    for(i=0;i<N;i++)
       printf(i<2?"%ld,":"%ld\n",a[i][1]);//最有一个会溢出 
}	
