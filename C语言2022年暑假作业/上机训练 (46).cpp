/*7��������

�����κ�������x����Լ���ĸ�������g(x)������g(1)=1,g(6)=4�����ĳ��������x���㣺��������i(0<i<x)������g(i)<g(x)�����xΪ�����������磺12   24    36    48    60��
��12Ϊ����g(12)=5��g(2)=2; g(6)=4; g(10)=4��g(11)=2��
��10~200�ڵĵ����з���������ÿ��5������ʽ�����
�����������2��������x������0<i<xʱ����g(i)<g(x),���xΪ������������g(i)����i��Լ��������g(x)����x��Լ�������������磺����g(1)=1��g(2)=2��g(3)=2��g(4)=3��g(5)=2��g(6)=4��g(7)=2��g(8)=4�����4��6�Ƿ�������3��4��5��7��8���Ƿ�������
�����Ҫ��
(1)	��д����int fun(int a[])���������ܣ���10~200��Χ�ڵ����з��������δ洢��aָ��������У��������ط������ĸ�����  
    �㷨��ʾ����д����int g(int n)��һ������n��Լ���ĸ�����
(2)	��д����main()���������ܣ�����һ��һά����a,��������a��ʵ�ε���fun��������ÿ��5��������ʽ���a�����е����ݵ���Ļ��
���������������н����
��Ļ����� 12   24    36    48    60
           120  180*/
           
#include<stdio.h> 
#include<stdlib.h>     //����exit(0)��Ҫ
#include<conio.h>     //����getch()��Ҫ
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
