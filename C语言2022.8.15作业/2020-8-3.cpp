/*----------------------------------------------------------------------
��������ơ�
------------------------------------------------------------------------
��Ŀ��������ݶ�ά����n[ROW][COL]�кŵ���ż�ԣ��ҳ�ÿ�еļ�ֵ�������ά��
      ��c�ĵ�һ�С��ټ���c�����һ�и�Ԫ�ر���������Ԫ��ĩβ�����Ĵ���
      ��ĩβ�����ĺ��������4��4314ĩβ����,31����4314ĩβ��������
      �������н�����£�
       n����ĳ�ʼ����
       4    17    5   10
       3  4314    7    6
      59    60   31   32
      14     6    7    0
       ���м�ֵΪ
       4  4314   31   14   
       ����ֵ�������Ĵ���Ϊ
       2     0    0    1

1.��д����void max_min(int n[][COL],c[][COL)���ҳ���ά����nÿ��Ԫ�صļ�
  ֵ��ż��������СԪ��ֵ,�����������Ԫ��ֵ,�������c�ĵ�һ�У��к�Ϊ��
  �ŵ�λ�ô���
2.int contain(int c[],int col)������һά����c��col��Ԫ�ر�c��������Ԫ��
  (����������)ĩβ�����Ĵ������������ر������Ĵ�����
---------------------------------------------------------
ע�⣺����Ķ�������main()�е��κ���䡣
-------------------------------------------------------*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>

#define ROW 4
#define COL 4

void max_min(int n[][COL],int c[][COL])
{
/**********Program**********/
int i,j,max,min,k,t;
for(i=0;i<4;i++)
{
	if(i%2==0)
	{
		min=n[i][0];
		for(j=1;j<4;j++)
			if(n[i][j]<min)
				min=n[i][j];
		c[0][i]=min;
	}
	else
	{
		max=n[i][0];
		for(j=1;j<4;j++)
			if(n[i][j]>max)
				max=n[i][j];
		c[0][i]=max;	
	}
}
/**********  End  **********/
}
int contain(int c[],int col)
{
/**********Program**********/
int i,j,k,s=0;
for(i=0;i<4;i++)
{
	if(c[col]<10)
	{
		if(c[i]%10==c[col])
			s++;
	}
	else if(c[col]<100)
		if(c[i]%100==c[col])
			s++;
}
return s==0?s:s-1;
/**********  End  **********/
}
int main()
{
    int n[ROW][COL]={{4,17,5,10},{3,4314,7,6},{59,60,31,32},{14,6,7,0}};
    int c[2][COL]={0};
    int i,j;
    FILE *fp;
    if((fp=fopen("DATA.dat","w"))==NULL) 
    {
        printf("File open error\n");
        exit(0);
    }
    printf("n����ĳ�ʼ����\n");
    for(i=0;i<ROW;++i)
    {        
        for(j=0;j<COL;++j)
        {
            printf("%5d",n[i][j]);
            fprintf(fp,"%5d",n[i][j]);
        }
        printf("\n");
        fprintf(fp,"\n");
     }
    max_min(n,c);
    printf("���м�ֵΪ\n");
    for(j=0;j<COL;++j)
    {        
        printf("%5d",c[0][j]);
        fprintf(fp,"%5d",c[0][j]);
    }
    printf("\n");
    fprintf(fp,"\n");
    printf("����ֵ�������Ĵ���Ϊ\n");
    for(i=0;i<4;++i)
        c[1][i]=contain(c[0],i);
    for(i=0;i<COL;++i)
    {
        printf("%5d",c[1][i]);
        fprintf(fp,"%5d",c[1][i]);
    }
    printf("\n");
    fprintf(fp,"\n");
    fclose(fp);
    return 0;
}

