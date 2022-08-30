/*2、编程题
【程序功能】字符串变换。
【编程要求】
(1) 编写函数void change(char a[],char b[],char c[])。
函数功能是首先把b指向的字符串逆向存放,
然后将a指向的字符串和b指向的字符串按顺序交叉合并到c指向的数组中,
两个字符串中过长的剩余字符接在c指向数组的尾部。
例如,当a指向的字符串为"abcdefg",b指向的字符串为"1324"时,
c指向的数组中字符串应为"a4b2c3dlefg"。
(2)编写main函数。函数功能是声明字符型数组s1、s2和t,
用测试数据初始化数组s1和 s2,再用s1、s2和t作为实参调用函数change,将
数组s1、s2和t中的字符串输出到屏幕。
【测试数据与运行结果】
  测试数据:s1:abcdefg
          s2:1324
  屏幕输出:s1:abcdefg
          s2:4231
The result is:a4b2c3dlefg*/
#include<stdio.h>
#include<string.h>
void change(char a[],char b[],char c[])
{
	strrev(b);
	int i,j,len=0;
	for(i=0,j=0;a[i]||b[j];i++,j++)
	{
		if(a[i])
			c[len++]=a[i];
		if(b[j])
			c[len++]=b[j];
	}
	c[len]=0;
}

main()
{
	char a[]="abcdefg";
	char b[]="1324";
	char c[100];
	
	change(a,b,c);
	
	puts(c);
}



