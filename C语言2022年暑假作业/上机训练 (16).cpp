/*1�������ܣ�string�����ڴ�������ɸ��ַ��������³�������ҳ�����ַ���������ж��������ͬ��Ϊ����ַ�������Լ����һ��Ϊ����ַ����������ڸ��ַ����е�ÿ�������ַ�ǰ����һ���ո�
���磬���string�����е��ַ���Ϊ��A1B23CD45������EF2G34������ER45DF678������985GHJ211FGH����������ַ���Ϊ��985GHJ211FGH��������ո����ַ�����Ϊ�� 9 8 5G HJ 2 1 1FGH����
����maxstr�Ĺ������ڴ����ss�����е�m���ַ���
�в�������ַ���������������ַ������ڵ������е�


���±ꡣ����insert�Ĺ�������str����������ŵ��ַ�����ÿ��
�����ַ�ǰ����һ���ո�
���������������н����
�������ݣ���A1B23CD45������EF2G34������ER45DF678������985GHJ211FGH��
��Ļ�����The maxstring: 985GHJ211FGH
The changestring: 9 8 5G HJ 2 1 1FGH
*/
#include<ctype.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#define M 4
#define N 80
/***************FOUND****************/
int maxstr(char ss[][N],int m)
{   int i,len,maxlen,n;
maxlen=strlen(ss[0]);
n=0;
for(i=0;i<m;i++)
{  len=strlen(ss[i]);
   if(len>maxlen)
   {  maxlen=len;
      n=i;
}
}
return n;
}
void insert(char str[])
{  int i,j=0,len=strlen(str);
   while(str[j])
     if(isdigit(str[j]))
      {   for(i=len;i>=j;i--)
           str[i+1]=str[i];
 			str[j]=' ';
/***************FOUND****************/
          j+=2; 		//
          len++;
}
else j++;
}
int main()
{  int n;
   char string[][N]={ "A1B23CD45 ", "EF2G34 ", "ER45DF678 ", "985GHJ211FGH "};
   n=maxstr(string,M);
   printf("The maxstring:%s\n",string[n]);
   /***************FOUND****************/
insert(string[n]); 
   printf("The changestring:%s\n",string[n]);
   getch();
   return 0;
}
