/*4����λ������ض�����
�������ܡ�
Ѱ�Ұ�λ��������ض���������ض���������Ϊ��һ������������һ�Ƴ��r��ÿһ�����������������������֮����ض�������������113��������һ��ȥ�����֣�13��3���������������Ҫ��
(1)��д����int fun(long  b[])���书����Ѱ�����а�λ������ض�����.�������������İ�λ������ض��������浽bָ��������С�
(2)��дmain����������fun�����ҳ�ʮλ������ض��������������ط������������ĸ��������ҵ���ʮλ������ض�������������һ�У��������Ļ��
���������������н����
���н����113, 137, 167, 173, 197
223, 283, 307,313, 317
337,347, 353, 367, 373
383, 397, 443, 467, 503
523, 547, 607, 613, 617
643, 647, 653,673, 683
743,773, 797,823, 853
883, 907,937, 947,953
967, 983, 997*/
#include<stdio.h>
#include<stdlib.h>    //����exit(0)��Ҫ
#include<conio.h>    //����getch()��Ҫ
#include<math.h>

int prime(long n)       //�б������ĺ���
{   
	int j;
	if(n<2)
		return false;
	for( j=2 ; j<=sqrt(n) ; j++ )
		if(n%j==0)
			return false;
	return true;
}
int numlen(long num)
{
	int len=0;
	while(num=num/10)
		len++;
	return len+1;
}
int fun(int  b[])
{   
	long num=110;
	int count=0;
	do
	{
		int len=numlen(num),j;
		int q =pow(10,len);
		int sign=1;
		for(;q/10;q/=10)
		{
			int t=num%q;
			if(!prime(t))
			{
				sign=0;
				break;
			}	
		}
		
		
		if(sign)
		{
			
			b[count++]=num;
			if(count>=100)break;
		}
		num++;
	}while(num<1000);
	return count;
}
main()
{  int i, n, a[100]={0}; 
   n=fun(a);
   for(i=1;i<=n;i++)
      printf(i%5!=0?"%d,":"%d\n",a[i-1]); 
}
