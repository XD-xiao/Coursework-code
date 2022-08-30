/*5、数制变换
【程序功能】
要求输入一个十进制长整数，转换为二进制、八进制和十六进制形式的一维数组排列的整型数组。
【编程要求】
（1）编写函数Change( long m, int type, char str[])。形式参数m为十进制数、欲转换的数制为type，分别是2、8、16。函数采用共享地址法由变换后字符串数组str返回。
（2）编写main函数，定义long a;  char s[20]；调用Change函数求出以二进制、八进制和十六进制形式的一维数组排列的整型数组s，并分别输出到屏幕。
【测试数据与运行结果】
输入数据：12345
输出数据：11000000111001B
          30071Q
          3039H*/


#include<stdio.h>
#include<string.h>

void Change( long m, int type, char str[])
{
	int i=0;
	while(m)
	{
		str[i++]=m%type+'0';
		m/=type;

	}
	str[i]=0;
	strrev(str);
}

main()
{
	long m;
	printf("Input num:");
	scanf("%ld",&m);
	char str[93];
	Change(m,2,str);
	puts(str);
	Change(m,8,str);
	puts(str);
	Change(m,16,str);
	puts(str);
	
	
}
