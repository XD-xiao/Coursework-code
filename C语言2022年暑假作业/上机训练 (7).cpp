/*2�������
�������ܡ��ַ����任��
�����Ҫ��
(1) ��д����void change(char a[],char b[],char c[])��
�������������Ȱ�bָ����ַ���������,
Ȼ��aָ����ַ�����bָ����ַ�����˳�򽻲�ϲ���cָ���������,
�����ַ����й�����ʣ���ַ�����cָ�������β����
����,��aָ����ַ���Ϊ"abcdefg",bָ����ַ���Ϊ"1324"ʱ,
cָ����������ַ���ӦΪ"a4b2c3dlefg"��
(2)��дmain���������������������ַ�������s1��s2��t,
�ò������ݳ�ʼ������s1�� s2,����s1��s2��t��Ϊʵ�ε��ú���change,��
����s1��s2��t�е��ַ����������Ļ��
���������������н����
  ��������:s1:abcdefg
          s2:1324
  ��Ļ���:s1:abcdefg
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



