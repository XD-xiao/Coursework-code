/*1、改错题
【程序功能】实数x可表示为  形式，称其中的±m为尾数，±n为指数。以下程序中，tail函数将形式参数x中存储的非零正实数分解为上述表示形式（尾数±m中的m的值域为0.1≤m＜1），将指数存储到形式参数n指向的变量中，将尾数作为函数返回值。
【测试数据与运行结果】
测试数据： x=-0.001234
屏幕输出：-0.123400e-2     (注：尾数为-0.123400，指数为-2)
【含有错误的源程序】*/
#include <stdio.h>
#include <conio.h>
/***************FOUND****************/
double tail(double x, int *n)           
{   int m=0;
    while(x>=1)
    {  m++;   x=x/10;  }
    while(x<0.1)
    {  m--;    x=x*10;  }
  *n=m;
  return x;
}
int main()  
{  double x,m;
int n, x_sign=1;
   do
   {   printf("please input the x:");
/***************FOUND****************/
       scanf("%lf",&x);
/***************FOUND****************/
   }while(0==x);
   if(x<0)
   {  x_sign=-1;      x=-x;}
   m=tail(x, &n);
   m=x_sign*m;
   printf("%lfe%d", m,n);
   return 0;
}
