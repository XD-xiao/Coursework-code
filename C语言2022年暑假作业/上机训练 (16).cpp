/*1、程序功能：string数组内存放了若干个字符串，以下程序从中找出最长的字符串（如果有多个长度相同且为最长的字符串，则约定第一个为最长的字符串），并在该字符串中的每个数字字符前插入一个空格。
例如，如果string数组中的字符串为“A1B23CD45”、“EF2G34”、“ER45DF678”、“985GHJ211FGH”，则最长的字符串为“985GHJ211FGH”，插入空格后该字符串变为“ 9 8 5G HJ 2 1 1FGH”。
函数maxstr的功能是在存放于ss数组中的m个字符串
中查找最长的字符串，函数返回最长字符串所在的数组行的


行下标。函数insert的功能是在str数组中所存放的字符串内每个
数字字符前插入一个空格。
【测试数据与运行结果】
测试数据：“A1B23CD45”、“EF2G34”、“ER45DF678”、“985GHJ211FGH”
屏幕输出：The maxstring: 985GHJ211FGH
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
