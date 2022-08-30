/*9、编程题
【题目】求能被3整除且其中至少有两位数字为6的四位数，
并求出满足的四位数的个数。如9696、9669均为满足条件
的四位数。*/
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

