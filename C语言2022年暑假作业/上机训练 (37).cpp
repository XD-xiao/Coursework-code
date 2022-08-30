/*6、水仙花数
【程序功能】
    如果一个3位数等于它的各位数字的立方和，则这个3位数称为“水仙花”数。例如：153=13+53+33。试编程求出100-999的所有水仙花数。
【编程要求】
    （1）编写函数int Narcissus ( int m[], int n1, int n2)。n1、n2是取值范围，函数返回符合条件的水仙花数数组m和返回符合条件的水仙花数目。
    （2）编写main函数，定义取值范围d1，d2；调用Narcissus函数求出在d1和d2范围内，符合条件的水仙花整型数组s，并按下面输出数据格式输出到屏幕。
【测试数据与运行结果】
输入数据：100, 999
输出数据：153=1*1*1+5*5*5+3*3*3
          370=3*3*3+7*7*7+0*0*0
371=3*3*3+7*7*7+1*1*1
407=4*4*4+0*0*0+7*7*7*/
#include<stdio.h>
#define N 100
#define M 999 
main()
{
	int a,b,c,n;
	/*查找判断并输出*/
	for(n=N;n<=M;n++)
	{
		a=n/100;
		b=n/10%10;
		c=n%10;
		if(a*a*a+b*b*b+c*c*c==n)
			printf("%d=%d*%d*%d+%d*%d*%d+%d*%d*%d\n",n,a,a,a,b,b,b,c,c,c);
	}
}



