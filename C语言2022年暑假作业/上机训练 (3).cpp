/*题型2:矩阵运算
    先判断一个M×N矩阵是否是一个Monge矩阵，再对该矩阵作转换，判断变换后的M×N矩阵是否仍是Monge矩阵。
    如果一个M×N矩阵为Monge矩阵,当且仅当i=1,2,…,m-1和j=1,2,…,n-1时
    A[i,j]+A[i+1,j+1]<=A[i,j+1]+A[i+1,j]成立
    【编程要求】
    1.编写函数int Monge(int a[ ][5],int n),其功能是判断a指向的a行5列数组中存储的矩阵是否是Monge矩阵，若是则函数返回1，否则返回0。
    2.编写函数，其功能是对a指向的n行5列数组中的矩阵作如下转换,第一行与最后一行交换，第二行与倒数第二行交换，….直到每一行都交换过一次为止。
*/
#include<stdio.h>
#define N 3
#define M 5

int Monge(int a[ ][5],int n)
{
	int i,j;
	for(i=1;i<N-1;i++)
	{
		for(j=1;j<M-1;j++)
			if(a[i][j]+a[i+1][j+1]>a[i][j+1]+a[i+1][j])
				break;
		if(j<M-1)
			break;
	}
	if(i>N-1)
		return 0;
	return 1;
	
	
}
void change(int a[ ][5],int n)
{
	int i,j,t;
	for(i=0;i<N/2;i++)
		for(j=0;j<M;j++)
		{
			t=a[i][j];
			a[i][j]=a[N-1-i][j];
			a[N-1-i][j]=t;
		}
}
main()
{
	int a[N][M]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	if(Monge(a,N))
	{
		change(a,N);
		if(Monge(a,N))
			puts("Yes");
		else
			puts("No");
	}
	else
		puts("No");
	
	
}
