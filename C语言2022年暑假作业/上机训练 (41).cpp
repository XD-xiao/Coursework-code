/*2��Kynea����
ÿһ�������Է��� ����ʽ��nΪ��Ȼ����
 7, 23, 79, 1087, 66047, 263167, 16785407, 1073807359, 17180131327, 68720001023, 4398050705407, 70368760954879, 18014398777917439, 18446744082299486207
�������ܡ�
Ѱ��ǰ6��Kynea ������Kynea ��������Ϊ����ÿ����Ȼ��n����������������֮��Kynea ������������n=5����M=1087����������n=4����ʱM=287��287/7=41������������
�����Ҫ��
(1)��д����void fun(long  b[][2])���书����Ѱ��ǰ����Kynea ����.������������������Kynea��������ķ��������浽bָ��������С�
(2)��дmain��������������n=3������fun�����ҳ�ǰ����Kynea�������䷴���������ҵ���Kynea�������䷴�����������Ļ��
���������������н����
���н����7��23��79��1087��66047��263167
7��32��97��7801��74066��761326
����������(int)���ڴ�洢��ԪΪ2���ֽڣ����������Ͷ������int��ȫ����Ϊ����������long����*/
#include<stdio.h>
#include<stdlib.h>    //����exit(0)��Ҫ
#include<conio.h>    //����getch()��Ҫ
#include<math.h>
#define N 6
long prime(long n)    //���б������ĺ���
{  
	unsigned long j;
	for( j=2 ; j<sqrt(n) ; j++ )
		if(n%j==0)
			return false;
	return true;
}
long reorder( int m)    //��ȡ�������ĺ���
{   
	unsigned long x=0;
	while(m)
	{
		x=x*10+m%10;
		m/=10;
	}
	return x;
}
Kynea(long num)
{
	return pow(pow(2,num)+1,2)-2;
} 
void fun(long  b[][2])
{ 
	unsigned long num=1;
	int count=0;
	do
	{
		if(prime(Kynea(num)))
		{
			unsigned long t=Kynea(num);
			b[count][0]=t;
			unsigned long t1=reorder(t);
			b[count++][1]=t1;
		}
		num++;
	}while(count<N);
	
}
main()
{  long i, a[N][2]={0};
    
   fun(a);
   for(i=0;i<N;i++)
      printf(i<5?"%ld,":"%ld\n",a[i][0]);
   for(i=0;i<N;i++)
      printf(i<5?"%ld,":"%ld\n",a[i][1]); 
}	
