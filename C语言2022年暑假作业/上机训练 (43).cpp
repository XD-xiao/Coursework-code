/*4、百位数的左截短素数
【程序功能】
寻找百位素数的左截短素数，左截短素数定义为当一个素数从左方逐一移除時，每一个余下來的数都是素数的数称之“左截短素数”。例如113，该数逐一除去左数字，13、3都是素数。【编程要求】
(1)编写函数int fun(long  b[])，其功能是寻找所有百位数的左截短素数.，将满足条件的百位数的左截短素数保存到b指向的数组中。
(2)编写main函数，调用fun函数找出十位数的左截短素数，函数返回返回满足条件的个数，将找到的十位数的左截短素数，按五列一行，输出到屏幕。
【测试数据与运行结果】
运行结果：113, 137, 167, 173, 197
223, 283, 307,313, 317
337,347, 353, 367, 373
383, 397, 443, 467, 503
523, 547, 607, 613, 617
643, 647, 653,673, 683
743,773, 797,823, 853
883, 907,937, 947,953
967, 983, 997*/
#include<stdio.h>
#include<stdlib.h>    //函数exit(0)需要
#include<conio.h>    //函数getch()需要
#include<math.h>

int prime(long n)       //判别素数的函数
{   
	int j;
	if(n<2)
		return false;
	for( j=2 ; j<=sqrt(n) ; j++ )
		if(n%j==0)
			return false;
	return true;
}
int numlen(long num)
{
	int len=0;
	while(num=num/10)
		len++;
	return len+1;
}
int fun(int  b[])
{   
	long num=110;
	int count=0;
	do
	{
		int len=numlen(num),j;
		int q =pow(10,len);
		int sign=1;
		for(;q/10;q/=10)
		{
			int t=num%q;
			if(!prime(t))
			{
				sign=0;
				break;
			}	
		}
		
		
		if(sign)
		{
			
			b[count++]=num;
			if(count>=100)break;
		}
		num++;
	}while(num<1000);
	return count;
}
main()
{  int i, n, a[100]={0}; 
   n=fun(a);
   for(i=1;i<=n;i++)
      printf(i%5!=0?"%d,":"%d\n",a[i-1]); 
}
