/*4�������Ҫ��
��1����д����void squeeze(char s1[],char s2[],char s3[])��
�书���ǣ���s1ָ����ַ�����ɾȥ������s2ָ����ַ������ѳ��ֵ��ַ���
����s1��ɾ�����ַ����浽s3ָ��������С�
��2����дmain�������ø����Ĳ����ַ���s1��s2����squeeze������
��������s1�ַ�����s3�ַ������浽����ļ�myf2.out�С�
	�������ݣ�s1:��abbcdefgghiijkl��,s2:��bdglkw��
	���н����s1: acefhiij, s3:bbdggkl
*/
#include<string.h>
#include<stdio.h>
#define M 63
void squeeze(char s1[],char s2[],char s3[])
{
	int i,j,k,n=0,m;
	m=strlen(s1);
	for(i=0;s2[i];i++)
		for(j=0;s1[j];j++)
			if(s1[j]==s2[i])
			{
				s3[n++]=s1[j];
				for(k=j;s1[k];k++)
					s1[k]=s1[k+1];
				j--;
			}
}

main()
{
	char s1[M]="abbcdefgghiijkl";
	char s2[M]="bdglkw";
	char s3[M];
	squeeze(s1,s2,s3);
	printf("s1:%s\n",s1);
	printf("s3:%s\n",s3);
	FILE *fp;
	fp=fopen("myf2.out","w");
	fprintf(fp,"%s\n",s1);
	fprintf(fp,"%s\n",s3);
	fclose(fp);
}


