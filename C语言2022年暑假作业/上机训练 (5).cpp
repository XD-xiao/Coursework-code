/*2�������
    �������ܡ�
    �ڸ�����Χ�ڲ���kʹ���ù�ʽk^2+k+17���ɵ�������������������������ʮ���Ʊ�ʾ�е�3λ������ͬ��ȥ����3λ��������ǻ����������磬��k=461ʱ�ù�ʽ���ɵ�������212999��������������������
  �����Ҫ��
    (1)��д����int findnum(int n1,int n2,long a[][2])ʵ�����¹��ܣ�k����ȡn1~n2��Χ
�ڵ�ÿ���������ֱ���ÿ��k����ʽk2+k+17��������y����y���������������kֵ��yֵ���浽aָ��������У���������a������k�ĸ�����
    (2)��д����mainʵ�����¹��ܣ�������ά����a�ͱ���n1��n2�������������������浽n1��n2�У���n1��n2��a������ʵ�ε���findnum��������������ʽ���a�����е����ݵ���Ļ��
    ���������������н����
    ���룺n1=1,n2=10000
    �����k      number
         461      212999
         586      343999
         3839     14741777
*/
#include<stdio.h>
#define N 63
bool ispalindromes(int num)
{
	int x=num,y=0;
	
	while(x)
	{
		y=y*10+x%10;
		x/=10;
	}
	if(y==num)
		return true;
	else
		return false;
}

int findnum(int n1,int n2,long a[][2])
{
	int num,count=0,y;
	for(num=n1;num<=n2;num++)
	{
		int y=num*num+num+17;
		if(y%10==y/10%10&&y/100%10==y%10)
			if(ispalindromes(y/1000))
			{
				a[count][0]=num;
				a[count++][1]=y;
			}
	}
	return count;
}
main()
{
	int i,n,m;
	long a[N][2];
	printf("Input n m:");
	scanf("%d%d",&n,&m);
//	n=1,m=10000;
	int len=findnum(n,m,a);
	for(i=0;i<len;i++)
		printf("%5d\t%5d\n",a[i][0],a[i][1]);
}



