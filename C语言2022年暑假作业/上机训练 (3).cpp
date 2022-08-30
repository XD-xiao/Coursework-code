/*����2:��������
    ���ж�һ��M��N�����Ƿ���һ��Monge�����ٶԸþ�����ת�����жϱ任���M��N�����Ƿ�����Monge����
    ���һ��M��N����ΪMonge����,���ҽ���i=1,2,��,m-1��j=1,2,��,n-1ʱ
    A[i,j]+A[i+1,j+1]<=A[i,j+1]+A[i+1,j]����
    �����Ҫ��
    1.��д����int Monge(int a[ ][5],int n),�书�����ж�aָ���a��5�������д洢�ľ����Ƿ���Monge����������������1�����򷵻�0��
    2.��д�������书���Ƕ�aָ���n��5�������еľ���������ת��,��һ�������һ�н������ڶ����뵹���ڶ��н�������.ֱ��ÿһ�ж�������һ��Ϊֹ��
*/
#include<stdio.h>
#define N 3
#define M 5

int Monge(int a[ ][5],int n)
{
	int i,j;
	for(i=1;i<N-1;i++)
	{
		for(j=1;j<M-1;j++)
			if(a[i][j]+a[i+1][j+1]>a[i][j+1]+a[i+1][j])
				break;
		if(j<M-1)
			break;
	}
	if(i>N-1)
		return 0;
	return 1;
	
	
}
void change(int a[ ][5],int n)
{
	int i,j,t;
	for(i=0;i<N/2;i++)
		for(j=0;j<M;j++)
		{
			t=a[i][j];
			a[i][j]=a[N-1-i][j];
			a[N-1-i][j]=t;
		}
}
main()
{
	int a[N][M]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	if(Monge(a,N))
	{
		change(a,N);
		if(Monge(a,N))
			puts("Yes");
		else
			puts("No");
	}
	else
		puts("No");
	
	
}
