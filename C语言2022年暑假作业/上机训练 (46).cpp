/*7、反素数

对于任何正整数x，其约数的个数记做g(x)，例如g(1)=1,g(6)=4。如果某个正整数x满足：对于任意i(0<i<x)，都有g(i)<g(x)，则称x为反素数。例如：12   24    36    48    60。
以12为例：g(12)=5：g(2)=2; g(6)=4; g(10)=4；g(11)=2。
求10~200内的的所有反素数并按每行5个的形式输出。
对于任意大于2的正整数x，若当0<i<x时都有g(i)<g(x),则称x为反素数（其中g(i)代表i的约数个数，g(x)代表x的约数个数）。例如：由于g(1)=1、g(2)=2、g(3)=2、g(4)=3、g(5)=2、g(6)=4、g(7)=2、g(8)=4，因此4和6是反素数，3、4、5、7、8则不是反素数。
【编程要求】
(1)	编写函数int fun(int a[])。函数功能：将10~200范围内的所有反素数依次存储到a指向的数组中，函数返回反素数的个数。  
    算法提示：编写函数int g(int n)求一个整数n的约数的个数。
(2)	编写函数main()。函数功能：声明一个一维数组a,，用数组a作实参调用fun函数，按每行5个数的形式输出a数组中的数据到屏幕。
【测试数据与运行结果】
屏幕输出： 12   24    36    48    60
           120  180*/
           
#include<stdio.h> 
#include<stdlib.h>     //函数exit(0)需要
#include<conio.h>     //函数getch()需要
#include<math.h>
bool isprime(long n)
{
	int i;         
    if(n==1) return false;  
    for(i=2;i<=sqrt(n);i++)
		if(n%i==0)  return false;
	    return true;
} 
int num_g(long n)
{
	int i,count=0;         
    for(i=1;i<=n;i++)
		if(n%i==0)  count++;
	if(isprime(n))
		count--;
	return count;
}
int fun(int a[])
{
	long num,count=0;
	int j;
	for( num=10 ; num<=200 ; num++ )
	{
		int m=num_g(num);
		for( j=num-1 ; j>0 ; j--)
			if(m<=num_g(j))
				break;
		if(j<=0)
		{
			a[count++]=num;
		}
	}
	return count;
}
main()
{
	int i,a[100],len;
	len=fun(a);
	for( i=0 ; i<len ; i++)
		printf((i+1)%5?"%d,":"%d\n",a[i]); 
	printf("\b \n");
}
