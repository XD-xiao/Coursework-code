/*----------------------------------------------------------------------
��������ơ�
------------------------------------------------------------------------
��Ŀ����֪�뾶Ϊ5,Բ��Ϊ(3,9)��Բ���ַ���s����һ���Կո�Ϊ�ָ����ĵ��
      ���꣬ÿ������ĺᡢ������ֵ�Զ��ŷָ������Զ������ַ�����ʾ��
���磺char s[]= {"   10,10   0,101   110,1010   "};
      ��ʾ������Ϊ����2,2), (0,5), (6,10), ������Բ��λ�ù�ϵ���£�
      ��(2,2)��Բ��
      ��(0,5)��Բ��
      ��(6,10)��Բ��

��д����
1.��д int change(char s[],int num[][3])��������s�����ж����������ַ���
  ��ת��Ϊ��������ʾ�ĵ�����꣬�����num�����ͬһ��ǰ2�С�
  ������������ĸ��������s�ĸ�ʽ������0��

2.��д void calc(int num[][3],int n)����������num������ÿ��ǰ2��Ԫ������
  Ӧ�ĵ㣬�жϵ���Բ��λ�ã���������ڵ����У�����Բ��Ϊ0��Բ��Ϊ1��
  Բ��Ϊ2��
---------------------------------------------------------
ע�⣺����Ķ�������main()�е��κ���䡣
-------------------------------------------------------*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
int change(char s[],int num[][3]) 
{
/**********Program**********/
	int count=0;
	for(int i=0 ; s[i] ; i++)
	{
		if(isdigit(s[i]))
		{
			char num1[16],num2[16];
			int len1=0,len2=0;
			while(isdigit(s[i]))
				num1[len1++]=s[i++];
			num1[len1]=0;
			if(s[i]==',')
				i++;
			else
				continue;
			while(isdigit(s[i]))
				num2[len2++]=s[i++];
			num2[len2]=0;
			int number=0;
			for(int j=0 ; num1[j] ; j++)
				number=number*2+num1[j]-'0';
			num[count][0]=number;
			number=0;
			for(int j=0 ; num2[j] ; j++)
				number=number*2+num2[j]-'0';
			num[count++][1]=number;
			i--;
		}
	}
	return count ;
/**********  End  **********/
}

void calc(int num[][3],int n) 
{
/**********Program**********/
	
	for(int i=0 ;i<n;i++)
	{
		int  r2=pow(abs(3-num[i][0]),2)+pow(abs(9-num[i][1]),2);
		if(r2>25)
			num[i][2]=1;
		else if(r2<25)
			num[i][2]=2;
		else
			num[i][0]=0;
	}
	
/**********  End  **********/
}
int main() 
{
    char s[]= {"   10,10   0,101   110,1010   "};
    int num[10][3],i,n;
    char disp[][10]= {"��","��","��"};
    FILE *fp;
    if((fp=fopen("DATA.dat","w"))==NULL) 
    {
        printf("File open error\n");
        exit(0);
    }
    n=change(s,num);
    if (n==0) 
    {
        printf("������\n") ;
        fprintf(fp,"������\n") ;
    } 
    else 
    {
        calc(num,n);
        for(i=0; i<n; i++) 
        {
            printf("��(%d,%d)��Բ%s\n",num[i][0],num[i][1],disp[num[i][2]]);
            fprintf(fp,"��(%d,%d)��Բ%s\n",num[i][0],num[i][1],disp[num[i][2]]);
        }
    }
    fclose(fp);
    return 0;

}
