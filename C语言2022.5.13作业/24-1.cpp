/*�ڱ���ΪScrabble���ݺ������Ϸ�У���ĸ���е�ÿһ����ĸ����һ����ֵ�����±���ʾ��
��ֵ	��ĸ

1	A, E, I, L, N, O, R, S, T, U
2	D, G
3	B, C, M, P
4	F, H, V, W, Y
5	K
8	J, X
10	Q, Z
�����ϱ�ÿ�����ʶ���һ��Scrabble��ֵ�����磬���ʡ�FARM����Scrabble��ֵΪ 9�֣�FΪ4�֣�A��R��1�֣�MΪ3�֣���
���³����У�����count�Ĺ����Ǽ���wordָ������������洢���ʵ�Scrabble��ֵ�������ظ÷�ֵ���ڼ����ֵʱ������д��ĸ����κ��ַ��ķ�ֵ��
��0�ּ��㡣
���������������н����
�������ݣ�FARM
���н����score for 'FARM' is 9*/
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
