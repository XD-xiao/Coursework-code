/*2、编程题
【题目】
(1)编写函数fun，函数的功能是：移动字符串中的内容，
移动的规则如下：把第1到第m个字符平移到字符串的最后，把
第m+1到最后的字符串移到字符串的前部。
例如：字符串中原有的内容为：ABCDEFGHIJK，m的值为3，
则移动后，字符串中的内容应该是：DEFGHIJKABC。
(2)编写main函数，在main函数中初始化一个字符串，
调用函数fun，将结果输出到屏幕上。*/
#include<stdio.h>
#include<string.h>
#define M 63
fun(char str[],int m)
{
	char temp[M];
	strcpy(temp,str);
	temp[m+1]=0;
	strcpy(str,&str[m+1]);
	strcat(str,temp);
}

main()
{
	char str[M];
	int m;
	printf("Input string:");
	gets(str);
	printf("Input m:");
	scanf("%d",&m);
	fun(str,m-1);
	puts(str);
	
}

