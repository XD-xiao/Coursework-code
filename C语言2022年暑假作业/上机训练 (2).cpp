 /*����1:���б仯����
    ��֪x�����д洢��n�׾�����һ������
	(������ָ��λ���ϵ����������е��������
	ͬʱҲ�������е���С��)��
	����ʵ�ֽ������а����������ƶ������Ҳࡣ
    �������������н����
    ��������;
          1    3    2    0
          4    6    5   -1
          7    9    8    0
          -1  l0    3    2
     ���н��;
     An dian;a[0][1]
        1    2    0    3
        4    5    -1   6
        7    8    0    9
        -1   3    2   10*/
#include<stdio.h>
#define   N    4               /* ���峣��*/
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
