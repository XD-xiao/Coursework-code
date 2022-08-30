/*----------------------------------------------------------------------
【程序填空】
------------------------------------------------------------------------
题目：move函数将字符串中的所有数字字符和小数点移到所有其他字符之后，并保
      持数字字符、小数点和其他字符原先的先后次序。
例如：原来字符串为"This5. is Dev-C++ 11"，处理后为"This is Dev-C++ 5.11"。
------------------------------------------------------------------------
注意：除要求填空的位置之外，请勿改动程序中的其他部分。
----------------------------------------------------------------------*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>

void move(char a[],int len)
{
    int i,j;
    char c;
    for(i=0;i<len;i++)
    {
        if(isdigit(a[i]) || a[i]=='.')
        {
            c=a[i];
/**************************SPACE*************************/
            for(j=i+1;j<strlen(a);j++)
            {
                a[j-1]=a[j];
            }
            a[j-1]=c;
/**************************SPACE*************************/
            len--;
            i--;
        }
    }    
}

int main()
{
    char a[]="This5. is Dev-C++ 11";
    int len=strlen(a);
    move(a,len);
    puts(a);
    return 0;
}
