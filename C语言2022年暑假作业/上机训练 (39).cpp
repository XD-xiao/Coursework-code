/*8������
�����Ҫ��
    ��1����д���� int fun(int m, int n[])����С�ڻ����m��ȫ������������
	�������ذ������������������������������д��������n�С�
	������ָ�����������⡢����1���������ӵĺ͵���ԭ��������6=1+2+3��
    ��2����дmain���������ռ��������1000��һ��������
	����fun���������������������ȫ����������ȫ�������������Ļ��
���������������н����
����1000ʱ
���6��Its factors are 1, 2, 3
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
		printf("%d��Its factors are:",n[i++]);
		for(int j=0;j<count;j++)
			printf("%4d",n[i++]);
		printf("\n");
	}
}

