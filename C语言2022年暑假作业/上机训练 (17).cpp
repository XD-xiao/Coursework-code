/*2�������
�����ܣ���10~200�ڵĵ����з���������ÿ��5������ʽ�����
�����������2��������x������0<i<xʱ����g(i)<g(x)��
���xΪ������������g(i)����i��Լ��������g(x)����x��Լ����������
���磺����
g(1)=1��g(2)=2��g(3)=2��g(4)=3��g(5)=2��g(6)=4��g(7)=2��g(8)=4��
���4��6�Ƿ�������3��4��5��7��8���Ƿ�������
���Ҫ��
��1����д����int fun(int a[])���������ܣ���10~200��Χ�ڵ���
�з��������δ洢��aָ��������У��������ط������ĸ�����
�㷨��ʾ����д����int g(int n)��һ������n��Լ���ĸ�����
��2����д����main()���������ܣ�����һ��һά����a��
������a��ʵ�ε���fun��������ÿ��5��������ʽ���a�����е����ݵ���Ļ����
��Ļ����� 12   24    36    48    60
120180
*/
#include <stdio.h>
#include <stdlib.h>   /*������exit(0);��Ҫ*/
#include <conio.h>   /*������getch();��Ҫ*/
#define P 10         /*Ϊ���ͨ�ó������ó���P=20��K=200*/
#define K 200
#define N 20
bool isprime(int n)
{
	int i;
	for(i=2;i<=(n)/2;i++)
		if(n%i==0)
			return false;
	return true;
}
int g(int n)    /*��һ������n��Լ���ĸ���*/
{   
	int count=0,i;
	for(i=1;i<n/2;i++)
		if(n%i==0)
			count++;
	return count;
}
int fun(int a[])   
{  
	int num,count=0;
	int j;
	for( num=10 ; num<=200 ; num++ )
	{
		int m=g(num);
		for( j=num-1 ; j>0 ; j--)
			if(m<=g(j))
				break;
		if(j<=0)
		{
			a[count++]=num;
		}
	}
	return count;
}

main()
{  int i,a[N],n; 
   n=fun(a); 
   for(i=0;i<n;i++)    
   {   if(i%5==0)  printf("\n");
       printf("%4d",a[i]);   
}
}
