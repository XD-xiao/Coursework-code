/*2�������
����Ŀ��
(1)��д����fun�������Ĺ����ǣ��ƶ��ַ����е����ݣ�
�ƶ��Ĺ������£��ѵ�1����m���ַ�ƽ�Ƶ��ַ�������󣬰�
��m+1�������ַ����Ƶ��ַ�����ǰ����
���磺�ַ�����ԭ�е�����Ϊ��ABCDEFGHIJK��m��ֵΪ3��
���ƶ����ַ����е�����Ӧ���ǣ�DEFGHIJKABC��
(2)��дmain��������main�����г�ʼ��һ���ַ�����
���ú���fun��������������Ļ�ϡ�*/
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

