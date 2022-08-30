/*3、【程序功能】
   输入两个自然数P和Q（P<Q），找出满足下列条件的整数组（K,M,N）。
(1)P≤K<M≤Q
(2)K*K+M*M=N*N
【编程要求】
（1）编写函数int chlm(int p,int q,int a[ ][3])实现以下功能：
查找K,M在[p,q]范围内取值且满足以上条件的所有整数组（K,M,N）。
若找到则将这些整数组保存到a指向的数组中，
函数返回找到的整数组的组数。若找不到则函数返回0。
（2）编写函数main实现以下功能：声明二维数组a和变量p、q，
输入两个自然数并保存到p和q中（p<q），
调用chlm函数在[p,q]范围内查找满足以上条件的整数组。
若找不到则在屏幕上输出“out found”，否则将查找结果保存到a数组中，
输出a数组数据到屏幕。
【测试数据与运行结果】
输入：
 p=12  q=38
输出
12  16  20
12  35  37 
15  20  25
15  36  39 
16  30  34
18  24  30
20  21  29
21  28  35
24  32  40
27  36  45
*/
#include<stdio.h>
#include<math.h>
int chlm(int p,int q,int a[][3])
{
	int i,j,n=0;
	for(i=p;i<q;i++)
		for(j=p+1;j<q;j++)
			if(i<j)
			{
				if(sqrt(i*i+j*j)==(int)sqrt(i*i+j*j))
				{
					a[n][0]=i;
					a[n][1]=j;
					a[n++][2]=(int)sqrt(i*i+j*j);
				}
			}
	return n;
}
main()
{
	int a[100][3],i,n;
	int p,q;
	printf("Input p,q:");
	scanf("%d,%d",&p,&q);
	n=chlm(p,q,a);
	if(n)
		for(i=0;i<n;i++)
			printf("%5d%5d%5d\n",a[i][0],a[i][1],a[i][2]);
	else
		printf("out found\n");
}

