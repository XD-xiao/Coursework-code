/*9�������
����Ŀ�����ܱ�3������������������λ����Ϊ6����λ����
������������λ���ĸ�������9696��9669��Ϊ��������
����λ����*/
#include<stdio.h>
bool double_six(long x)
{
	int sign=0;
	while(x)
	{
		if(x%10==6)
			sign++;
		if(sign>=2)
			return true;
		x/=10;
	}
	return false;
}
main()
{
	int count=0;
	for(long num=1000 ; num<=9999 ; num++)
	{
		if(num%3==0&&double_six(num))
		{
			printf("%6ld\n",num);
			count++;
		}
	}
	printf("There are %3d in total",count);
}

