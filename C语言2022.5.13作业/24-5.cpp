/*用以下展开式求ln(x+)(-1≤x≤1)的近似值，允许误差为10-6。
ln(x+)= 
【编程要求】
（1）编写函数double fun(double x, double eps),计算的近似值（直到最后一项的绝对值小于eps）并作为函数返回值。
（2）编写main函数，接收键盘输入的x值及允许误差eps值并确保-1≤x≤1，用x和eps作为实参调用fun函数，将x、eps值和计算结果输出到屏幕。
【测试数据与运行结果】
测试数据：x=0.5，eps=1e-6
运行结果：x=0.500000，eps=0.000001，sum=0.481212
*/
#include<stdio.h>
#include<math.h> 

double fun(double x,double eps)
{
	double sum=x,fz=1,fm=2,f=-1,t=1,n=1;
	while(abs(f*t*n)>eps)
	{
		t=t*fz/fm;
		n=pow(x,fm+1)/(fm+1);
		sum=sum+f*t*n;
		fz=fz+2;
		fm=fm+2;
		f=-f;
	}
	
	return sum;
}

main()
{
	double x,eps;
	printf("Input x:");
	scanf("%lf",&x);
	printf("Input eps:");
	scanf("%lf",&eps);
	printf("x=%lf,eps=%lf,sum=%lf\n",x,eps,fun(x,eps));
} 
