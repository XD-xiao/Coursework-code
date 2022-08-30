/*在被称为Scrabble的纵横猜字游戏中，字母表中的每一个字母都有一个分值，如下表所示：
分值	字母

1	A, E, I, L, N, O, R, S, T, U
2	D, G
3	B, C, M, P
4	F, H, V, W, Y
5	K
8	J, X
10	Q, Z
依据上表，每个单词都有一个Scrabble分值。例如，单词“FARM”的Scrabble分值为 9分（F为4分，A和R各1分，M为3分）。
以下程序中，函数count的功能是计算word指向的数组中所存储单词的Scrabble分值，并返回该分值。在计算分值时，除大写字母外的任何字符的分值均
按0分计算。
【测试数据与运行结果】
测试数据：FARM
运行结果：score for 'FARM' is 9*/
#include<stdio.h>
int (char a[])
{
	int sum=0,i;
	for(i=0;a[i];i++)
		switch(a[i])
		{
			case 'A':
			case 'E':
			case 'I':
			case 'L':
			case 'N':
			case 'O':
			case 'R':
			case 'S':
			case 'T':
			case 'U':	sum+=1;break;
			case 'D':
			case 'G':	sum+=2;break;
			case 'B':
			case 'C':
			case 'M':
			case 'P':	sum+=3;break;
			case 'F':
			case 'H':
			case 'V':
			case 'W':
			case 'Y':	sum+=4;break;
			case 'K':	sum+=5;break;
			case 'J':
			case 'X':	sum+=6;break;	
			case 'Q':
			case 'Z':	sum+=7;break;	
		}
	return sum;
}
main()
{
	char a[10]="FARM";
	int sum;
	sum=count(a);
	printf("score for '%s' is %d",a,sum);
}
