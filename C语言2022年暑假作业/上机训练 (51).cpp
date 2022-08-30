/*����1:��������
    2009�����¿���:
    �����ܣ��ҳ�7��Ĭɭ������������ѧ��Ĭɭ����������й�ʽ��Mp=2^p-1����p����������MpҲ������ʱ����MpΪĬɭ���������磬p=5��Mp=2^5-1=31��5��31�������������31��Ĭɭ��������Mp=2^11-1=2047,11������,2047�������������2047����Ĭɭ������
      [���Ҫ��]
��1����д����void Mersenne(long a[ ],int m),�书�������ǰm��Ĭɭ�������Դ˽����Ǳ��浽aָ��������С�        
��2����дmain����������Mersenne����������ǰ7��Ĭɭ�����������н���������Ļ��
      ���������������н����
      3   7   31  127  8191  131071  524287*/
#include <stdio.h>
#include<math.h>
#define N 7
int prime(long n)               /*�������Ĺ������ж�����*/
{
	long j;
	for( j=2 ; j<=sqrt(n) ; j++ )
		if(n%j==0)
			return false;
	return true;
}
void Mersenne(long a[ ],int m)
{
	long num=2;
	int count=0;
	do
	{
		if(prime(num))
		{
			int Mer_num=pow(2,num)-1;
			if(prime(Mer_num))
				a[count++]=Mer_num;
		}
		num++;
	}while(count<N);
	
}

main()
{
	long a[7];
	int i;;
	Mersenne(a,N);
	for(i=0;i<N;i++)
		printf("%8ld",a[i]); 
}
