/*1、特殊数：素数平方是各位数不相同的数
【程序功能】参考2006秋C02编程题和网上资料编写
在给定的范围内查找满足特定条件的整数。
【编程要求】
（1）编写函数int find(long n1,long n2,long x[])。函数功能：在n1~n2之间查找满足以下条件的整数x：x是素数并且x2的各位数字互不相同。例如11172=1247689，1117是素数并且11172的各位数字互不相同，因此1117是满足这一条件的整数。将找到的满足上述条件的整数依次保存在x指定的数组中，函数返回x数组中数据个数。
（2）编写main函数，函数功能：声明一个long int 型数组用于保存查找结果，调用find函数查找1000~1500之间满足上述条件的整数，将查找结果输出到屏幕。
【测试数据与运行结果】
测试数据：n1=1000,n2=1500
运行结果：
    x            x2
   1117       1247689
   1277       1630729
   1307       1708249
   1433       2053489*/
#include<stdio.h> 
#include<math.h>
#define N 63
bool onlynum(long num)
{
	long sign[N];
	for( int i=0 ; num ; num/=10,i++ )
	{
		sign[i]=num%10;
		for(int j=0 ; j<i ; j++)
			if(sign[i]==sign[j])
				return false;
	}
	return true ;
}
int find(long n1,long n2,long x[])
{
	int count=0;
	for( int num=n1 ; n1<=n2 ; n1++)
	{
		int j;
		for( j=2 ; j<=sqrt(n1) ; j++)
			if(n1%j==0)
				break;
		if(j>sqrt(n1))
			if(onlynum(n1*n1))
				x[count++]=n1;
	}
	return count ;
}
main()
{
	long n1,n2,x[N];
	printf("Input n1~n2:");
	scanf("%ld%ld",&n1,&n2);
	int nums=find(n1,n2,x);
	for(int i=0 ; i<nums ; i++)
		printf("%5ld",x[i]);
	printf("\n");
}

