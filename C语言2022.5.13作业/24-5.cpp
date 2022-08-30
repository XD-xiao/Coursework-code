/*������չ��ʽ��ln(x+)(-1��x��1)�Ľ���ֵ���������Ϊ10-6��
ln(x+)= 
�����Ҫ��
��1����д����double fun(double x, double eps),����Ľ���ֵ��ֱ�����һ��ľ���ֵС��eps������Ϊ��������ֵ��
��2����дmain���������ռ��������xֵ���������epsֵ��ȷ��-1��x��1����x��eps��Ϊʵ�ε���fun��������x��epsֵ�ͼ������������Ļ��
���������������н����
�������ݣ�x=0.5��eps=1e-6
���н����x=0.500000��eps=0.000001��sum=0.481212
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
