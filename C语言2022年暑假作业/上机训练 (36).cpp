/*5�����Ʊ任
�������ܡ�
Ҫ������һ��ʮ���Ƴ�������ת��Ϊ�����ơ��˽��ƺ�ʮ��������ʽ��һά�������е��������顣
�����Ҫ��
��1����д����Change( long m, int type, char str[])����ʽ����mΪʮ����������ת��������Ϊtype���ֱ���2��8��16���������ù����ַ���ɱ任���ַ�������str���ء�
��2����дmain����������long a;  char s[20]������Change��������Զ����ơ��˽��ƺ�ʮ��������ʽ��һά�������е���������s�����ֱ��������Ļ��
���������������н����
�������ݣ�12345
������ݣ�11000000111001B
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
