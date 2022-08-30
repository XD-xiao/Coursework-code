/*3、【编程要求】
（1）编写函数void  josephu(int a[],int b[],int n,int m)
实现如下模拟处理功能：a指向的数组中存储了n个人的编号（从1开始按序编号到n）。
n个人围坐成一圈，从编号为1 的人开始报数（从1到m报数），
凡报到m的人出列。将每次出列的人的编号依次保存在b指向的数组中，
直到最后一个人出列为止。
 （2）编写main函数。用给定的测试数据调用josephu函数，
 将经函数处理后得到的n个依次出列的人的编号保存到结果文件myf2.out中。
【测试数据及运行结果】
	测试数据： n=10,m=3
	运行结果： 3，	6，	9，	2，	7，	1，	8，	5，	10,	4
*/
#include<stdio.h>
#define NUM 40
#define M 20
void  josephu(int a[],int b[],int n,int m)
{
	int k=0,i=0,j=0;
	while(k<n)
	{
		if(a[i%n])
			j++;
		if(j==m&&a[i%n])
		{
			b[k++]=a[i%n];
			a[i%n]=0;
			j=0;
		}
		i++;
	}
}
main()
{
	int a[NUM]={1,2,3,4,5,6,7,8,9,10};
	int i=0,k=0,j=0,b[NUM];
	int n=10,m=3;
	josephu(a,b,n,m);
	for(i=0;i<n;i++)
		printf("%5d",b[i]);
	printf("\n");
}
