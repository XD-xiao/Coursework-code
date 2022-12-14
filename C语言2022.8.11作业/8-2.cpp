/*----------------------------------------------------------------------
【程序改错】
------------------------------------------------------------------------
题目：对一个字符串中每个字符做如下处理：
     （1）如果是小写字母，用该字符的ASCII码减5之后的八进制数字串替换该字符；
     （2）如果是大写字母，用该字符的ASCII码加5之后的十六进制数字串替换该字符；
     （3）如果是非字母字符则保持不变。
函数encrypt(char a[],char b[])的功能是将存放于字符数组a中的字符串按以上
要求处理后保存到字符数组b中。
						Jn.22
本程序的正确输出结果是：4F151.22 
------------------------------------------------------------------------
注意：不得增行或删行，也不得更改程序的结构。
----------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define EL 100

int encrypt(char a[], char b[])
{
    int i,bp=0,sp;
    char t,s[4]={0,0,0,0};
    for(i=0; a[i]; i++)
    {
        t=a[i];
        sp=0;
        if(t>='a'&&t<='z')
        {
            t=t-5;
            while(t)
            {              
/***********FOUND***********/
                s[sp++]=(t%8)<10? t%8+48:t%8+55;
                t=t/8;
            }
         }
        else if(t>='A'&&t<='Z')
        {
            t=t+5;
            while(t)
            {
                s[sp++]=(t%16)<10? t%16+48:t%16+55;
                t=t/16;
            }
        }
        else
/***********FOUND***********/
            s[sp++]=t;
        while(sp) 
/***********FOUND***********/
            b[bp++]=s[--sp];
    }
    b[bp]='\0';
}
int main()
{
    char a[]="Jn.22", b[EL];
    encrypt(a,b);
    puts(b);
}
