/*7��������������
�������ܡ�
    ���a�����Ӻ͵���b��b�����Ӻ͵���a�������ӻ����������ָ����1��
	�������������������a������b�����a��bΪ�������ԡ�
	Ҫ���������λ��1000-3000����Ӧ���������ԡ�
�����Ҫ��
    ��1����д����int Relation(int a[][2], int m1, int m2)��
	����������λ�����������Ķ������������Դ���ڶ�ά����a[][2]���ء�
    ��2�� ��дmain������������������int b[10][2]��������n1,n2����
	��������n1��n2�����Relation�������1000-3000��֮�����������b[][2]��
	���������Ļ��
���������������н����
�������ݣ�1000��3000
������ݣ�(1184,1210)
          (2620,2924)*/
#include<stdio.h>
#include<math.h>
//���������ԵȺ����� 
int factorsum(int x)
{	
	int sum=0;
	for(int j=1;j<x;j++)
		if(x%j==0)
			sum+=j;
	return sum;
}
 int Relation(int a[][2], int m1, int m2)
{
	int count=0;
	for(int i=m1;i<=m2;i++)
		for(int j=m1;j<=m2;j++)
		{
			if(i!=j&&i==factorsum(j)&&j==factorsum(i))
				a[count][0]=i,a[count++][1]=j;
			
		}
	return count ;
}
main()
{
	int n1,n2;
	printf("Input n1~n2:");
	scanf("%d%d",&n1,&n2);
	int a[90][2];
	int len =Relation(a, n1, n2);
	for(int i=0;i<len;i++)
		printf("%3d,%3d\n",a[i][0],a[i][1]);
}

