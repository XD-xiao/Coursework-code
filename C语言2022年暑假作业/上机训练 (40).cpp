/*1��÷ɭ����(Mersenne Prime)
��ָÿһ�������Է��� 2p ? 1����ʽ������2p��1��������������ָ��p������������ΪMp ����Mp�����������Ϊ÷ɭ������p=2��3��5��7ʱ��Mp
Ѱ������������M11=2047=23��89�������� ���Ƿ���������÷ɭ������������δ���������֮һ����9��÷ɭ������:
3, 7, 31, 127, 8191, 131071, 524287, 2147483647, 2305843009213693951
�������ܡ�
��ǰ����˫÷ɭ����(Mersenne Prime)��˫÷ɭ��������Ϊ����ÿ������p����Ҳ������������p=5����M=2,147,483,647��������
�����Ҫ��
(1)��д����void fun(long  b[][2])���书����Ѱ��ǰ����˫÷ɭ����������������������˫÷ɭ��������ķ��������浽bָ��������С�
(2)��дmain�������������飬����fun�����ҳ�����÷ɭ�������䷴���������ҵ���÷ɭ�������䷴�����������Ļ��
���������������н����
���н����7��127��2147483647
7��721��7463847412
���Գ����в���double���ʹ�����ʾ�á�%.0lf����ʾ��ʽ��*/
#include<stdlib.h>    //����exit(0)��Ҫ
#include<conio.h>    //����getch()��Ҫ
#include<math.h>
#include<stdio.h>
#define N 3
unsigned long reverse(unsigned long num)
{
	unsigned long x=0;
	while(num)
	{
		x=x*10+num%10;
		num/=10;
	}
	return x;
}
bool isprime(unsigned long num)
{
	unsigned long j;
	for( j=2 ; j<sqrt(num) ; j++ )
		if(num%j==0)
			return false;
	return true;
}
unsigned long Mersenne_Prime(unsigned long num)
{
	return pow(2,num)-1;
}
void fun(unsigned long  b[][2])
{
	unsigned long num=2;
	int count=0;
	do
	{
		if(isprime(num)&&isprime(Mersenne_Prime(num)))
		{
			unsigned long t=Mersenne_Prime(num);
			if(isprime(Mersenne_Prime(t)))
			{
				b[count][0]=Mersenne_Prime(t);
				unsigned long t1=reverse(Mersenne_Prime(t));
				b[count++][1]=t1;
			}
		}
		num++;
	}while(count<N);
}
main()
{   int i;
   unsigned long a[N][2]={0}; //
    fun(a);
    for(i=0;i<N;i++)
       printf(i<2?"%ld,":"%ld\n",a[i][0]); 
    for(i=0;i<N;i++)
       printf(i<2?"%ld,":"%ld\n",a[i][1]);//����һ������� 
}	
