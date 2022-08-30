/*2、编程题
    【程序功能】
    在给定范围内查找k使得用公式k^2+k+17生成的整数满足以下条件：该数的十进制表示中低3位数字相同，去掉低3位后的整数是回文数。例如，当k=461时用公式生成的整数是212999，该数满足所给条件。
  【编程要求】
    (1)编写函数int findnum(int n1,int n2,long a[][2])实现以下功能：k依次取n1~n2范围
内的每个整数，分别用每个k及公式k2+k+17生成整数y，若y满足给定条件，则将k值及y值保存到a指向的数组中，函数返回a数组中k的个数。
    (2)编写函数main实现以下功能：声明二维数组a和变量n1、n2，输入两个整数并保存到n1、n2中，用n1、n2及a数组作实参调用findnum函数，按所给格式输出a数组中的数据到屏幕。
    【测试数据与运行结果】
    输入：n1=1,n2=10000
    输出：k      number
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



