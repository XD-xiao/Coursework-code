/*8、完数
【编程要求】
    （1）编写函数 int fun(int m, int n[])，求小于或等于m的全部“完数”，
	函数返回包含符合条件的完数个数，完数数列存放在数组n中。
	完数是指除了自身以外、包含1的所有因子的和等于原数。例如6=1+2+3。
    （2）编写main函数，接收键盘输入的1000的一个整数，
	调用fun函数求得满足上述条件的全部完数，将全部完数输出到屏幕。
【测试数据与运行结果】
输入1000时
输出6，Its factors are 1, 2, 3
    28,  Its factors are 1, 2, 4, 7, 14
    496,  Its factors are 1, 2, 4, 8, 16, 31, 62, 124, 248*/
#include<stdio.h>
#include<math.h>
int fun(int m, int n[])
{
	int count=0;
	int i,j,len;
	for(i=2;i<=m;i++)
	{
		int s=0;
		len=0;
		int a[100];
		for(j=1;j<=i/2;j++)
		{
			if(i%j==0)
			{
				a[len++]=j;
				s=s+j;	
			}
			if(s==i)
			{
				n[count++]=-len;
				n[count++]=i;
				for(int k=0;k<len;k++)
					n[count++]=a[k];
				break;
			}
		}
	}
	
	return count;
}
main()
{	
	int m,n[100];
	printf("Input m:");
	scanf("%d",&m);
	
	int len=fun(m,n),count=0;
	
	for(int i=0; i<len ;)
	{
		if(n[i]<0)
			count=-n[i++];
		printf("%d，Its factors are:",n[i++]);
		for(int j=0;j<count;j++)
			printf("%4d",n[i++]);
		printf("\n");
	}
}

