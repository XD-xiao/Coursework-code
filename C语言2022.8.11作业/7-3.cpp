/*----------------------------------------------------------------------
【程序设计】
------------------------------------------------------------------------
题目：字符串str中包含若干个用空格隔开的英文单词，（单词由a-z，A-Z字母组成），
      单词的每个字母对应一个特定的值：字母a对应1，字母b对应2......，以此类推；
      字母A对应27，字母B对应28......，以此类推。如一个单词各个字母值的总和为素数，
      则称这个单词是素单词。程序找出str中所有素单词。

测试数据： str[N]={"I   am  a    Computer  Science  student   "}
运行结果：数组word中的单词为：
          I am a Computer Science student
          数组word中的素单词为：
          Computer
          student
    

1.编写函数int GetWord(char str[],char word[][M])，取出str数组中用空
  格分隔的单词，存入数组word中，每行存一个单词，函数返回单词的个数。
2.编写函数int IsPrimeword (char word[][M],char primeword[][M],int n)，判
  断word数组中存储的每个单词是否是素单词，如果是素单词，则存入primeword数组中，
  函数返回素单词的个数。          
---------------------------------------------------------
注意：请勿改动主函数main()中的任何语句。
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
    printf("数组word中的单词为：\n");
    for(i=0;i<n;i++)
    {
        printf("%s ",word[i]);
        fprintf(fp,"%s'",word[i]);
    } 
    printf("\n") ;
    fprintf(fp,"\n") ;
    m=IsPrimeword(word,primeword,n);
    printf("数组word中的素单词为：\n");   
    for(i=0;i<m;i++)
    {
        printf("%s\n",primeword[i]);    
        fprintf(fp,"%s,",primeword[i]);    
    }
    fclose(fp);
    return 0;
}

