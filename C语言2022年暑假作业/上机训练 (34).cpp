/*3、可分解的整数
【程序功能】取材于2006秋笔试题第14题(说明：该题内容有严重错误，本题已改正)
编程要求：输出小于键盘输入M的所有可分解的整数。
可分解的整数是指这个整数的所有数位上的数字之和等于
该数的所有素数因子的各位数字之和。
例如2688是一个可分解整数，
该数的所有数位上的数字之和为24（2+6+8+8=24）；
该数的所有质因子是3、5、5、7、19（其乘积为2×3×7×2×2×2×2×2=2688），
所有素数因子的各位数字之和为24（2+3+7+2+2+2+2+2）=24）。
【编程要求】
（1）编写函数int Change (int x,int b[])。
函数能实现整数x的各位上的数字之和等于整数x所有质因子之和，
则将该数存入数组b。函数返回满足条件的个数。
（2）编写main函数，定义数组int a[100]，
从键盘输入一个整型量y为9999，调用Change函数后，
返回小于键盘输入y的所有可分解的整数列，并按列换行原则，分别输出到屏幕。
【测试数据与运行结果】
输入数据：9999
输出数据：2688
729
          648
588
576
378
27
7
5
4
3
2*/

#include<stdio.h> 
#include<math.h>
//没有理解题目意思，有一些小的错误 

bool isprime(int x)
{
	for(int j=2 ;j<x/2;j++)
		if(x%j==0)
			return false;
	return true;
}
int sum_bit(int num)
{
	int sum=0; 
	while(num) 
	{
		sum+=num%10;
		num/=10;
	}
	return sum;
}
int factor(int x)
{

	int s=0;
	int sum=0;
	for(int j=2;j<=x;j++)//
	{
		if(x%j==0)
			sum+=sum_bit(j);
			
	}
	return sum;
}
int Change (int x,int b[])
{
	int len=0;
	for(int num=x; num>=2 ; num--)
		if(factor(num)==sum_bit(num))
			b[len++]=num;
			

	return len;
}
main()
{
	int y;
	printf("Input max:");
	scanf("%d",&y);
	int a[100];
	int len=Change(y,a);
	for(int i=0 ; i<len ; i++)
		printf("%5ld",a[i]);
	printf("\n");
}




