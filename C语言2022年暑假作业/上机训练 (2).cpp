 /*题型1:行列变化问题
    已知x数组中存储的n阶矩阵有一个鞍点
	(鞍点是指该位置上的数是所在行的最大数，
	同时也是所在列的最小数)，
	程序实现将矩阵中鞍点所在列移动到最右侧。
    测试数据与运行结果】
    测试数据;
          1    3    2    0
          4    6    5   -1
          7    9    8    0
          -1  l0    3    2
     运行结果;
     An dian;a[0][1]
        1    2    0    3
        4    5    -1   6
        7    8    0    9
        -1   3    2   10*/
#include<stdio.h>
#define   N    4               /* 定义常量*/
void exchange(int a[][N])
{
	int i,j,f,p;
	
	
	for(i=0;i<N;i++)
	{
		p=0;
		for(j=1;j<N;j++)
			if(a[i][p]<a[i][j])	p=j;
		f=1;
		for(j=0;j<N;j++)
			if(a[j][p]<a[i][p])
			{	f=0;break;	}
		if(f==1)
			//i,p
			break;
	}
	printf("i=%3d,j=%3d\n",i,p);
	
	for(i=0;i<N;i++)
	{
		int f=p;
		while(N-1!=f)
		{
			int t=a[i][N-1];
			for(j=N-1;j>0;j--)
				a[i][j]=a[i][j-1];
			a[i][j]=t;
			f++;
		}
		
	}	
	
	
}
main()
{
	int x[N][N]={{1,3,2,0},{4,6,5,-1},{7,9,8,0},{-1,10,3,2}},i,j;
	for(i=0;i<N;i++)
	{   
		for(j=0;j<N;j++)
	        printf("%3d",x[i][j]);
	    printf("\n");
	}
	printf("\n");
	exchange(x);
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			printf("%3d",x[i][j]);
		printf("\n");
	}
}
