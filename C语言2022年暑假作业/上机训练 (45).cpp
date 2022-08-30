/*6、奇异的“费马数”
若n为自然数，则?的数都是素数，称为“费马数”
当年费马发现
F_1=2^(21)+1=5 
F_2=2^(22)+1=17 
F_3=2^(23)+1=257 
F_4=2^(24)+1=65537
F_5=2^(25)+1=4294967297
前4个是素数，因为第5个数实在太大了,费马认为它是素数,并提出所有费马数都是是素数的猜想(但费马没给出证明)

6、【程序功能】
寻找前五个费马素数(Fermat?Prime)，费马素数定义为对于每个自然数n(1~5)，其是素数。例如n=4，则F=4294967297是素数。
【编程要求】
(1)编写函数void fun(long b[][2])，其功能是寻找前5个费马素数.，将满足条件的前5个费马素数及其的反序数保存到b指向的数组中。
(2)编写main函数，声明变量n=5，调用fun函数找出前5个费马素数及其反序数，将找到的5个费马素数及其反序数输出到屏幕。
【测试数据与运行结果】
运行结果：5，17，257，65537，4294967297
5，71，752，73556，7927694924
调试程序中数据类型采用double和特殊处理，显示用“%.0lf”显示格式。*/
#include<stdio.h> 
#include<stdlib.h>     //函数exit(0)需要
#include<conio.h>     //函数getch()需要
#include<math.h>
#define N 5
int prime(double n)    //判别素数的函数
{  
 int i;            //int在内存存储单元为4个字节
    if(n==1) return 0;  //数字1不是素数
    for(i=2;i<=sqrt(n);i++)
		if((long)n%i==0)  return false;
	    return true;
}
double reorder(  long m)   //求取反序数的函数
{   
double x=0;
	while(m)
	{
		x=x*10+m%10;
		m/=10;
	}
	return x;
}
void fun(double  b[][2])
{   
	int n,count=0;
	for( n=1 ; n<=5 ; n++ )
	{
		double num=pow(2,pow(2,n))+1;
		if(prime(num))
		{
			b[count][0]=num;
			b[count++][1]=reorder(num);
		}
	}
	
}
main()
{  int i;   double a[N][2]={0.0}; 
   fun(a); 
   printf("%.0lf,",a[0][0]); 
   printf("%.0lf,",a[1][0]); 
   printf("%.0lf,",a[2][0]); 
   printf("%.0lf,",a[3][0]); 
   printf("%.0lf\n",a[4][0]);    //超出范围 

   for(i=1;i<=N;i++)
      printf(i<N?"%.0lf,":"%.0lf\n",a[i-1][1]); 
}	
