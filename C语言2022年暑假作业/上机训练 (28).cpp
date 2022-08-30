/*6、改错题
【题目】函数fun的功能是：将m（1≤m≤10）个
字符连接起来，组成一个新串，放入pt所指字符串中。
例如：把3个串：“abc”，“CD”，“EF”串连起来，
结果是“abcCDEF”。
含有错误的程序如下：*/
#include <conio.h>
#include <stdio.h>
#include <string.h>
/****************FOUND**************/         
int fun(char str[][10],int m,char pt[])
{
    int k,q,i,j=0;
    for(k=0;k<m;k++)
    {  q=strlen(str[k]);
       for(i=0;i<q;i++)
          pt[j++]=str[k][i]; 
    }
/****************FOUND**************/         
	pt[j]=0;
}
main( )
{    int m=3,h;
     char s[10][10],p[120];
     printf("\nPlease enter %d string:\n",m);
     for(h=0;h<3;h++) {
		 gets(s[h]);
		 printf("%d:%s\n",h,s[h]);
	 }
 /****************FOUND**************/         
     fun(s,m,p);
     printf("\nThe result  is :%s\n",p);
} 
