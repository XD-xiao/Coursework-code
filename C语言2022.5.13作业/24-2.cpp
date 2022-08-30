/*2.【程序功能】
验证3～2008之间的所有素数中存在这样两个素数，它们的和等于2008。
【编程要求】
（1）编写函数 int fun(int n,int *a,int *b)，其功能是在3～n之间寻找一对素数，
它们的和等于n。若找到则将这两个素数分别保存到a、b指向的变量中，
函数返回1；若找不到，函数返回0。
（2）编写main函数，声明变量n并用测试数据初始化，
调用fun函数找出3～n之间和值为n的一对素数，将找到的这对素数输出到屏幕。
【测试数据与运行结果】
      测试数据: n=2008
      运行结果: a=5   b=2003  a+b=2008
*/
#include<stdio.h>
#include<math.h>
int fun(int n,int *a,int *b)
{
	int i,j;
	for( i=3 ; i<n ; i++ )
	{
		for( j=2 ; j<=sqrt(i) ; j++ )
			if(i%j==0)
				break;
		if(j>sqrt(i))
		{
			for( j=2 ; j<=sqrt(n-i) ; j++ )
			if((n-i)%j==0)
				break;
			if(j>sqrt(n-i))
			{
				*a=i;
				*b=n-i;
				return 1;
			}
		} 
	}
	return 0;
}
main()
{
	int n,a,b;
	scanf("%d",&n);
	fun(n,&a,&b);
	printf("a=%5d,b=%5d,a+b=%5d\n",a,b,a+b);
}
