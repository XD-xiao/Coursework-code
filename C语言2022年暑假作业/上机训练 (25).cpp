/*3、改错题
【题目】函数fun的功能是：
将p所指字符串中的所有字符复制到b中，
要求每复制三个字符之后插入一个空格。
例如，在调用fun函数之前给a输入字符串：ABCDEFGHIJK，
调用函数之后，字符数组b中的内容则为：ABC DEF GHI JK。
含有错误的程序如下：*/
#include <stdio.h>
/****************FOUND**************/
void  fun(char p[], char b[])
{  int  i=0, j,k=0;
   while(p[i])
   {  j=1;
 /****************FOUND**************/     
while( j<=3 && p[i] )
 {
          b[k++]=p[i++];
          j++; 
}
      if(p[i]!=0)
/****************FOUND**************/
         b[k++]=' ';
  }
   b[k]='\0';
}
main()
{   char  a[80],b[80];
    printf("Enter a string:"); gets(a);
    printf("The original string: "); puts(a);
    fun(a,b);
    printf("\nThe string after insert space:"); 
puts(b); 
}
