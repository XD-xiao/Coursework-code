/*-------------------------------------------------------------------------
��������ơ�
---------------------------------------------------------------------------
��Ŀ����������һά�ַ�����str[]����4�������Ӵ���������ת��Ϊ4��������������
      ��������4������ֵ�Զ�ά��������ĸ���Ԫ�ؽ���ѭ���ƶ���

��д����
1.����void abstract(char str[],int p[])��str�е�4�������������Ӵ�ת��Ϊ10��
  ��������������һά����p�С�p��ֵ�ֱ���3��-14��16��0��

2.����void move(int m[][COL],int p[])����p��Ԫ��ֵ�Զ�ά����m��ÿһ��Ԫ����
  ��ѭ���ƶ���p��Ԫ��ֵΪ����m��Ӧ��Ԫ������ѭ���ƶ���p��Ԫ��ֵΪ����������
  ѭ���ƶ���

����p[]={3,-14,16,0},���ά����m�������¸���Ԫ�طֱ�����ѭ���ƶ�3�Ρ�����ѭ
���ƶ�14�Ρ�����ѭ���ƶ�16�Ρ�����ѭ���ƶ�0�Ρ�

�������н��Ϊ��
p�����ֵΪ:
   3 -14  16   0
�ƶ���:
   9   5  -3  12   0
   8   4  -6   7  19
  20  -4   3  11  16
  -7  -5  13  -2   0
---------------------------------------------------------
ע�⣺����Ķ�������main()�е��κ���䡣
-------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define ROW 4
#define COL 5
void abst(char str[],int p[])
{
/**********Program**********/
	int count=0;
	for(int i=0 ; str[i] ; i++)
		{
			if(isdigit(str[i])||str[i]=='-')
			{
				int sign=1;
				p[count]=0;
				if(str[i]=='-')
					sign=-1,i++;
				while(isdigit(str[i])&&str[i])
					p[count]=p[count]*10+str[i++]-'0';

				p[count]=sign*p[count];
				count++;
				i--;
			}
		}


/**********  End  **********/
}

void move(int m[][COL],int p[])
{
/**********Program**********/

	for(int i=0 ; i<ROW ; i++)
	{
		if(p[i]>0)
			for(int j=0 ; j<abs(p[i]) ; j++)
			{
				int t=m[i][COL-1];
				for(int j=COL-1 ; j>0 ; --j)
					m[i][j]=m[i][j-1];
				m[i][0]=t;
			}
		else if(p[i]<0)
			for(int j=0 ; j<abs(p[i]) ; j++)
			{
				int t=m[i][0];
				for(int j=0 ; j<COL-1 ; ++j)
					m[i][j]=m[i][j+1];
				m[i][COL-1]=t;
			}
	}


/**********  End  **********/
}
int main(){
    char str[]="vaue3  pos-14+pus16@#$wqzero0";
    int m[ROW][COL]={{12,0,9,5,-3},{4,-6,7,19,8},{-4,3,11,16,20},{-7,-5,13,-2,0}};
    int p[ROW];
    int i,j;
    FILE *fp;
    if((fp=fopen("DATA.dat","w"))==NULL)
    {
        printf("File open error\n");
        exit(0);
    }
    abst(str,p);
    puts("p�����ֵΪ:");
    fputs("p�����ֵΪ:\n",fp);
    for(i=0;i<ROW;i++)
    {
        printf("%4d",p[i]);
        fprintf(fp,"%4d",p[i]);
    }
    printf("\n");
    fprintf(fp,"\n");
    move(m,p);
    puts("�ƶ���:");
    fputs("�ƶ���:\n",fp);
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)
        {
            printf("%4d",m[i][j]);
            fprintf(fp,"%4d",m[i][j]);
        }
        printf("\n");
        fprintf(fp,"\n");
    }
    fclose(fp);
    return 0;
}
