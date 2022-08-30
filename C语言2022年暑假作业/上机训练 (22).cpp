/*2、程序改错
程序功能：函数int fun(int num[],int n,char res[][50])的功能是对num指向的数组中n个整数中的
每个整数r寻找满足等式“xyz+yzz=r”的x、y、z（x、y、z分别代表一位十进制数字）。如果找到一组x、y、z使得等式成立，
则生成等式字符串存储到res数组的一行中，如果未找到就将“not found for”字符串存入res数组的一行中，函数返回num数组中满足上述等式的整数个数。
函数void itostr(int n,char s[])的功能是将整数n转换为一个十进制表示的字符串存入s指向的数组中。
测试数据：762，145，678
    输出：foumd 2 equations for 3 nums
          251+511=762
          not found for 145
          334+344=678
含有错误的源程序：*/
#include<stdio.h>
#include<string.h>
#include<conio.h>
main()
{
    int fun(int num[],int n,char res[][50]);
    int num[3]={762,145,678};
    char res[10][50],ct,i;
    ct=fun(num,3,res);
    printf("found %d equstions for %d nums\n",ct ,3);
    for(i=0;i<3;i++)
/***************FOUND****************/
        puts(res[i]);
}
void itostr(int n,char s[])
{
    int i=0,j;
    char ch;
    while(n>0){
        s[i++]=n%10+'0';
        n=n/10;
    }
    s[i]='\0';
    j=0,i--;
    while(j<i){
        ch=s[i];s[i]=s[j];s[j]=ch;
        i--,j++;
    }
}
int fun(int num[],int n,char res[][50])
{
    int x,y,z,i,j,k,f,ct=0;
    char tmp[50];
    for(k=0;k<n;k++){
        for(f=0,i=100;i<=999;i++)
		{
/***************FOUND****************/
            y=i/10%10;
            z=i%10;
/***************FOUND****************/
            if(i+100*y+10*z+z==num[k])
			{
                 itostr(i,tmp);
                 strcpy(res[k],tmp);
                 strcat(res[k],"+");
                 itostr(100*y+10*z+z,tmp);
                 strcat(res[k],tmp);
                 strcat(res[k],"=");
                 itostr(num[k],tmp);
                 strcat(res[k],tmp);
                 f=1;
                 ct++;
                 break;
             }
        }
        if(!f)
		{
            strcpy(res[k],"not found for ");
            itostr(num[k],tmp);
            strcat(res[k],tmp);
        }
    }
    return ct;
 }
