/*----------------------------------------------------------------------
【程序改错】
------------------------------------------------------------------------
题目：在C语言中，为了实现两个大数加法运算，采用字符串s1和s2存放两个数，然后
      用整型数组a和b表示这两个数，再进行加运算，结果保存在整型数组c中。

例如：s1="32025", s2="1200057986"
     a[]={5,2,0,2,3}, b[]={6,8,9,7,5,0,0,0,2,1}
     c[]={1,1,0,0,9,0,0,0,2,1}

程序运行结果：  
    s1=32025
    s2=1200057986
    s1+s2=1200090011
------------------------------------------------------------------------
注意：不得增行或删行，也不得更改程序的结构。
----------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define N 1000

int main()
{
    char s1[N]="32025",s2[N]="1200057986";
    int a[N]={0},b[N]={0},c[N]={0},len1,len2,len3,i,f;
    printf("s1="); 
    puts(s1);
    printf("s2=");
    puts(s2);
    len1=strlen(s1);
    len2=strlen(s2);
    for(i=0;i<len1;i++)
        a[len1-i-1]=s1[i]-48;   
    for(i=0;i<len2;i++)
        b[len2-i-1]=s2[i]-48;
    len3=0;
/***********FOUND***********/ 
    f=0;  
    while(len3<len1 || len3<len2)
    {
/***********FOUND***********/
        c[len3]=a[len3]+b[len3]+f; 
        f=c[len3]/10;
        c[len3]%=10;
        len3++;
    }
    c[len3]=f;   
    if(c[len3]==0)
/***********FOUND***********/
        len3=len3-1;  
    printf("s1+s2=");    
    for(i=len3;i>=0;i--)
        printf("%d",c[i]);
    return 0;
}
