/*----------------------------------------------------------------------
��������ơ�
------------------------------------------------------------------------
��Ŀ���ַ���str�а������ɸ��ÿո������Ӣ�ĵ��ʣ���������a-z��A-Z��ĸ��ɣ���
      ���ʵ�ÿ����ĸ��Ӧһ���ض���ֵ����ĸa��Ӧ1����ĸb��Ӧ2......���Դ����ƣ�
      ��ĸA��Ӧ27����ĸB��Ӧ28......���Դ����ơ���һ�����ʸ�����ĸֵ���ܺ�Ϊ������
      �������������ص��ʡ������ҳ�str�������ص��ʡ�

�������ݣ� str[N]={"I   am  a    Computer  Science  student   "}
���н��������word�еĵ���Ϊ��
          I am a Computer Science student
          ����word�е��ص���Ϊ��
          Computer
          student
    

1.��д����int GetWord(char str[],char word[][M])��ȡ��str�������ÿ�
  ��ָ��ĵ��ʣ���������word�У�ÿ�д�һ�����ʣ��������ص��ʵĸ�����
2.��д����int IsPrimeword (char word[][M],char primeword[][M],int n)����
  ��word�����д洢��ÿ�������Ƿ����ص��ʣ�������ص��ʣ������primeword�����У�
  ���������ص��ʵĸ�����          
---------------------------------------------------------
ע�⣺����Ķ�������main()�е��κ���䡣
-------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define N 100  
#define M 20

int GetWord(char str[],char word[][M])
{
/**********Program**********/
	int count=0,j=0;
	for(int i=0 ; str[i] ; i++)
	{
		if(isalpha(str[i]))
			word[count][j++]=str[i];
		else 
		{
			word[count++][j]=0;
			j=0;
		}
	}

	return count;
/**********  End  **********/
}
int IsPrimeword(char word[][M],char primeword[][M],int n)
{
/**********Program**********/
    int count=0,j,sum;
	for(int i=0 ; i<n ; i++)
	{
		sum=0;
		for(j=0;word[i][j];j++)
			sum+=word[i][j]-96;
		for(j=2;j<=sqrt(sum);j++)
			if(sum%j==0)
				break;
		if(sum>1&&j>sqrt(sum))
			strcpy(primeword[count++],word[i]);
	}

	return count;
/**********  End  **********/
}

int main()
{
    char str[N]={"I   am  a    Computer  Science  student   "},word[N][M], primeword[N][M]; 
    int i,n,m;
    FILE *fp;
    if((fp=fopen("DATA.dat","w"))==NULL)
    {
        printf("File open error\n");
        exit(0);
    }    
    n=GetWord(str,word); 
    printf("����word�еĵ���Ϊ��\n");
    for(i=0;i<n;i++)
    {
        printf("%s ",word[i]);
        fprintf(fp,"%s'",word[i]);
    } 
    printf("\n") ;
    fprintf(fp,"\n") ;
    m=IsPrimeword(word,primeword,n);
    printf("����word�е��ص���Ϊ��\n");   
    for(i=0;i<m;i++)
    {
        printf("%s\n",primeword[i]);    
        fprintf(fp,"%s,",primeword[i]);    
    }
    fclose(fp);
    return 0;
}

