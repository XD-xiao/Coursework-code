//1、【程序功能】
/*对一个字符串中每个字符(其编码用ch表示)做如下加密操作：
⑴如果ch是小写字母，就用(ch+5)值的八进制数字字符串替换该字母；
⑵如果ch是大写字母，就用(ch-5)值的十六进制数字字符串替换该字母；
⑶如果ch是非字母字符则保持原样。
函数en的功能是将形参c中字符的编码转换成n进制数字字符串
并保存到s指向的数组中。函数encrypt的功能是将a指向的字符串按以上要求
做加密处理后保存到b指向的数组中。
【测试数据与运行结果】
测试数据：No.1
屏幕输出：49164.1
【含有错误的源程序】*/
#include <stdio.h>
#include <string.h>
/***************FOUND****************/
void en(char c, int n, char s[])
{  int t,i=0;
   char temp;
   while(c!=0)
   {  t=c%n;
      if(t<10)  s[i++]=t+'0';
	   else s[i++]=t-10+'A';
		 /***************FOUND****************/
      c=c/n;
   }
   s[i]='\0';
   for(t=i-1,i=0;i<t;i++,t--)
   {   temp=s[i];s[i]=s[t];s[t]=temp;}
}
void encrypt(char a[], char b[])
{   char s[4];
    int i;
    for(i=0;a[i]!='\0';i++)
    {    if(a[i]>='a'&&a[i]<='z')
            en(a[i]+5,8,s);
         else if(a[i]>='A'&&a[i]<='Z')
		     en(a[i]-5,16,s);
	      else s[0]=a[i],s[1]='\0';
	    /***************FOUND****************/
         strcat(b,s);
   }
}
main()
{   static char a[30]="No.1", b[100];
encrypt(a,b);
	 puts(b);
}
