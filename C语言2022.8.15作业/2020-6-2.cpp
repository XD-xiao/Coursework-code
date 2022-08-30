/*----------------------------------------------------------------------
【程序改错】
------------------------------------------------------------------------

题目：程序将正整数转换成8421码(又称BCD码)形式的字符串。8421码的编码规则是：
      两位10进制正整数可以用1个字节的8421码表示，其中一位10进制整数占用4位
      bit。或者说一个字节的8421编码可以表示两位10进制正整数。 
例如：10进制的45，对应BCD码是01000101。
      BCD码10010111对应的10进制数正整数是97。

      程序运行结果为： 
      10011001 10000000 01110101 00000100

------------------------------------------------------------------------
注意：不得增行或删行，也不得更改程序的结构。
----------------------------------------------------------------------*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>

#define N 4

void inttobcd(char bcd[],unsigned x)
{
    int i,j,y;
    char t[]="00000000";
    for(i=2;i>0;--i)
    {
/***********FOUND***********/
        j=i*4-1;
        for(y=x%10; y; y/=2)
            t[j--]+=y%2;
/***********FOUND***********/
        x/=10;
    }
/***********FOUND***********/
    strcpy(bcd,t);
    strcat(bcd," ");
}

int main()
{
    unsigned n[N]={99,80,75,4};
    char bcd[40]={0};
    int i;
    for(i=0;i<N;++i)//
    {
	      inttobcd(bcd,n[i]);
    puts(bcd);}
    return 0;
}
