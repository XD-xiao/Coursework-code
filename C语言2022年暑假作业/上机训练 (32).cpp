/*1��������������ƽ���Ǹ�λ������ͬ����
�������ܡ��ο�2006��C02�������������ϱ�д
�ڸ����ķ�Χ�ڲ��������ض�������������
�����Ҫ��
��1����д����int find(long n1,long n2,long x[])���������ܣ���n1~n2֮�����������������������x��x����������x2�ĸ�λ���ֻ�����ͬ������11172=1247689��1117����������11172�ĸ�λ���ֻ�����ͬ�����1117��������һ���������������ҵ������������������������α�����xָ���������У���������x���������ݸ�����
��2����дmain�������������ܣ�����һ��long int ���������ڱ�����ҽ��������find��������1000~1500֮���������������������������ҽ���������Ļ��
���������������н����
�������ݣ�n1=1000,n2=1500
���н����
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

