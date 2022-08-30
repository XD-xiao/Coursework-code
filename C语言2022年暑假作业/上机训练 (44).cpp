/*5、4连素数

即是连续4个相差2的素数:(p, p+2, p+6, p+8)。
(5, 7, 11, 13), (11, 13, 17, 19), (101, 103, 107, 109), (191, 193, 197, 199), (821, 823, 827, 829), (1481, 1483, 1487, 1489), (1871, 1873, 1877, 1879), (2081, 2083, 2087, 2089), (3251, 3253, 3257, 3259), (3461, 3463, 3467, 3469), (5651, 5653, 5657, 5659), (9431, 9433, 9437, 9439) 
【程序功能】
寻找前4对4连素数，4连素数定义为，连续4组相差2的素数：(p, p+2, p+6, p+8)。例如(5, 7, 11, 13)。
【编程要求】
(1)编写函数void fun(long  b[][8])，其功能是寻找前4个4连素数.，将满足条件的前4个4连素数及其的反序数保存到b指向的数组中。
(2)编写main函数，宏定义N为4，调用fun函数找出前4个4连素数及其的反序数，将找到的4个4连素数及其反序数输出到屏幕。
【测试数据与运行结果】
运行结果：5，7，11，13-> 5，7，11，31
11，13，17，19-> 11，31，71，91
101，103，107，109->101，301，701，901
191，193，197，199->191，391，79 1，991*/
#include<stdio.h>
#include<stdlib.h>    //函数exit(0)需要
#include<conio.h>    //函数getch()需要
#include<math.h>
#define N 4
int prime(int n)      //判别素数的函数
{
   int i;            //int在内存存储单元为4个字节
    if(n==1) return 0;  //数字1不是素数
    for(i=2;i<=sqrt(n);i++)
		if(n%i==0)  return false;
	    return true;
}
int reorder( int m)     //求取反序数的函数
{   
	int x=0;
	while(m)
	{
		x=x*10+m%10;
		m/=10;
	}
	return x;
}
void fun(int  b[][8])
{   
	int num,count=0;
	int sign=0;
	for(num=2 ; count<N ; num++)
	{
		
		if(prime(num)&&prime(num+2)&&prime(num+6)&&prime(num+8))
		{
			b[count][0]=num;
			b[count][1]=num+2;
			b[count][2]=num+6;
			b[count][3]=num+8;
			b[count][4]=reorder(num);
			b[count][5]=reorder(num+2);
			b[count][6]=reorder(num+6);
			b[count][7]=reorder(num+8);
			
			count++;
		}
	}

}
main()
{  int i,j, a[N][8]={0};  
   fun(a);
   for(i=0;i<N;i++)
       for(j=0;j<8;j++)
	          if(j<4)
              printf(j<3?"%d,":"%d->",a[i][j]); 
		      else
             printf(j<7?"%d,":"%d\n",a[i][j]);
  
}	
