/*5�������
����Ŀ��
(1)��д����fun�����Ĺ����ǣ���3��4�о���x����4��3�о���y���������3��3�о���xy�С�������˵Ļ��������ǣ�����xy�������±�ֱ�Ϊi,j��Ԫ�ص�ֵ���Ǿ���x�е�i����4��Ԫ�������y�е�j����4��Ԫ�ض�Ӧ��˵ĺ͡�
���磺����xΪ������yΪ�������xyΪ��
(2)��дmain��������ʼ���������飬���ú���fun������������������Ļ�ϡ�*/
#include<stdio.h>
#define N 3
#define M 4
#define Q 3
fun(int a[][M],int b[][Q],int c[][Q])
{
	int i,j,k;
	for(i=0;i<N;i++)
		for(j=0;j<Q;j++)
			for(k=0;k<M;k++)
				c[i][j]+=a[i][k]*b[k][j];
	
}

main()
{
	int a[N][M]={1,0,1,1,2,1,0,1,1,2,0,3};
	int b[M][Q]={1,1,1,0,0,0,2,1,1,1,1,3};
	int c[N][Q]={0};
	int i,j,k,t[N*M];
	/*��ʾ��������*/
	printf("a[][]:\n"); 
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
			printf("%4d",a[i][j]);
		printf("\n");
	}	
	printf("\nb[][]:\n"); 
	for(i=0;i<M;i++)
	{
		for(j=0;j<Q;j++)
			printf("%4d",b[i][j]);
		printf("\n");
	}	

	fun(a,b,c);
	
	printf("\nc[][]:\n"); 
	for(i=0;i<N;i++)
	{
		for(j=0;j<Q;j++)
			printf("%4d",c[i][j]);
		printf("\n");
	}	
} 
