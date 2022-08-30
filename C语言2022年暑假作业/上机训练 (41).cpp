/*2、Kynea素数
每一个素数皆符合 的数式。n为自然数。
 7, 23, 79, 1087, 66047, 263167, 16785407, 1073807359, 17180131327, 68720001023, 4398050705407, 70368760954879, 18014398777917439, 18446744082299486207
【程序功能】
寻找前6个Kynea 素数，Kynea 素数定义为对于每个自然数n，其是素数的数称之“Kynea 素数”。例如n=5，则M=1087是素数。但n=4，此时M=287（287/7=41）不是素数。
【编程要求】
(1)编写函数void fun(long  b[][2])，其功能是寻找前六个Kynea 素数.，将满足条件的六个Kynea素数及其的反序数保存到b指向的数组中。
(2)编写main函数，声明变量n=3，调用fun函数找出前六个Kynea素数及其反序数，将找到的Kynea素数及其反序数输出到屏幕。
【测试数据与运行结果】
运行结果：7，23，79，1087，66047，263167
7，32，97，7801，74066，761326
由于整型量(int)的内存存储单元为2个字节，程序中类型定义符“int”全部改为长整型量“long”。*/
#include<stdio.h>
#include<stdlib.h>    //函数exit(0)需要
#include<conio.h>    //函数getch()需要
#include<math.h>
#define N 6
long prime(long n)    //的判别素数的函数
{  
	unsigned long j;
	for( j=2 ; j<sqrt(n) ; j++ )
		if(n%j==0)
			return false;
	return true;
}
long reorder( int m)    //求取反序数的函数
{   
	unsigned long x=0;
	while(m)
	{
		x=x*10+m%10;
		m/=10;
	}
	return x;
}
Kynea(long num)
{
	return pow(pow(2,num)+1,2)-2;
} 
void fun(long  b[][2])
{ 
	unsigned long num=1;
	int count=0;
	do
	{
		if(prime(Kynea(num)))
		{
			unsigned long t=Kynea(num);
			b[count][0]=t;
			unsigned long t1=reorder(t);
			b[count++][1]=t1;
		}
		num++;
	}while(count<N);
	
}
main()
{  long i, a[N][2]={0};
    
   fun(a);
   for(i=0;i<N;i++)
      printf(i<5?"%ld,":"%ld\n",a[i][0]);
   for(i=0;i<N;i++)
      printf(i<5?"%ld,":"%ld\n",a[i][1]); 
}	
