/*2、【程序功能】
输入一个字符串，从中依次取出连续的数字字符作为一个数字串，
并将其首字符按下列要求做变换：若是‘0’则变为‘+’，
若是‘1’则变为‘-’，其他情况下不作变换；然后将取出的所有数字串输出。
例如，输入数字串“we112are35*045Chinese.”，
输出的数字串依次为： -12、35和+45
【编程要求】
(1)定义符号常量N表示20。
(2)编写int getmun(char str[], char w[][N]) 函数。
函数功能：从str指向的字符串中逐个取出数字串，
对每个数字串的第一个数字字符按上述要求变换，
然后 然后存储到w指向的二维数字数组中（每行存放一个字符串），
函数返回w数组中存放的有效数字串个数。
(3)编写main函数。函数功能：声明一维字符数组str和二维字符数组w，
用测试数据初始化str数组，以数组str、w为实参调用getnum函数，
将w数组中所有数字串输出到屏幕。
【测试数据与运行结果】
测试数据：we112are35*045Chinese.
屏幕输出： -12  35  +45
*/
#include<stdio.h>
#include<ctype.h>
#define N 9
int getmun(char str[], char w[][N])
{
	int i,j,count=0;
	for(i=0;str[i];i++)
	{
		j=1;
		if(isdigit(str[i]))
		{
			if(str[i++]=='1')
				w[count][0]='-';
			else
				w[count][0]='+';
			while(isdigit(str[i]))
				w[count][j++]=str[i++];
			count++;
		}
	}
	return count;
}


main()
{
	char str[]="we112are35*045Chinese.";
	char w[10][9];
	int len=getmun(str,w);
	for(int i=0;i<len ;i++)
		puts(w[i]);
}



