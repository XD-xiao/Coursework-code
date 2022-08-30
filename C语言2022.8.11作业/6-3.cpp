/*----------------------------------------------------------------------
��������ơ�
------------------------------------------------------------------------
��Ŀ�����Ƚ��ַ���s�������������ַ�ת�������������ٽ���Щ������ѭ���ƶ�����λ��

�������н�����£�
56789   5678   567   56   5
89567   7856   756   65   5

1.��д����int abstract(char s[],int num[],int wid[])�����ַ���s��������
  �����ַ�ת������������������һά����num�У�ÿ����������λ��������
  һά����wid�С���������������������
2.��д����void shift(int num[],int wid[],int n),num�����б���n����������
  wid�б�����n����������λ������ÿ��������ѭ���ƶ�����λ���õ�����
  ��ʾ�����н������λ���ֵ��Ȼ������Ԫ��ԭ����λ���С�
---------------------------------------------------------
ע�⣺����Ķ�������main()�е��κ���䡣
-------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define N 10

int abstract(char s[],int num[],int wid[])
{
/**********Program**********/
	int count=0;
	for(int i=0 ; s[i] ; i++)
	{
		if(isdigit(s[i]))
		{
			int number=0,Num_digits=0;
			while(isdigit(s[i]))
			{
				number=number*10+s[i++]-'0';
				Num_digits++;
			}
			num[count]=number;
			wid[count++]=Num_digits;
			i--;
		}
	}
	
	return count;
/**********  End  **********/
}
void shift(int num[],int wid[],int n)
{
/**********Program**********/
	int times,bit;
	for(int i=0 ; i<n ; i++)
	{
		if(wid[i]>=4)
			times=2;
		else if(wid[i]>=2)
			times=1;
		else
			times=0;
		
		for(int j=0 ; j<times ; j++)
		{
			bit=num[i]%10;
			num[i]=num[i]/10;
			num[i]=bit*pow(10,wid[i]-1)+num[i];
		}
		
	}
	
	
/**********  End  **********/
}

int main()
{
    char s[]={"file56789a5678,$567prin56tt 5 "};
    int i,n,num[N],wid[N];
    FILE *fp;
    if((fp=fopen("DATA.dat","w"))==NULL)
    {
        printf("File open error\n");
        exit(0);
    }
    n=abstract(s,num,wid);
    for(i=0;i<n;++i)
        printf("%d\t",num[i]);
    printf("\n");
    shift(num,wid,n);
    for(i=0;i<n;++i)
    {
        printf("%d\t",num[i]);
        fprintf(fp,"%d\t",num[i]);
    }
    printf("\n");
    fprintf(fp,"\n");
    fclose(fp);
    return 0;
}
