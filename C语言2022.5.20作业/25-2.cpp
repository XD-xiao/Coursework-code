/*2�������Ҫ��
��1����д����int findword(char s[],char t[],char ch[][20])��
�������ܣ��������ɾ�����ɵ��ַ���s�����������ַ���t�����е��ʣ�
����Щ���ʴ��������ch�У����������ҵ��ĵ��ʸ�ʽ��
���ַ���sΪ���������ַ��������ַ���tΪ�������ַ�������
��2����дmain�������������ܣ���������s��t��
�ñ������ַ����������ַ�����ʼ�����������顣
���ú���findword�Ը����Ĳ������ݽ��м�����
�����������İ����ַ���t�����е��ʼ����ʵĸ�����
���������ݼ����н����
	�������ַ�����No living man all things can. Graspall,loseall.
	�����ַ�����all
	���������all,Graspall,loseall. 3*/
#include<stdio.h>
#include<ctype.h>
#define N 40
#define M 20
int findword(char s[],char t[],char ch[][20])
{
	int i=0,str_j,t_j,sign,n=0;
	while(s[i])
		if(isalpha(s[i]))
		{
			sign=str_j=t_j=0;
			while(isalpha(s[i]))
			{
				ch[n][str_j]=s[i++];
				if(ch[n][str_j++]==t[t_j])
					t_j++;
				else
					t_j=0;
				if(t[t_j]==0)
					sign=1;
			}
			ch[n][str_j]=0;
			if(sign)
				n++;
		}
		else
			i++;
	return n;
}

main()
{
	int i=0,n=0;
	char str[N][M],s[N*M]="No living man all things can. Graspall,loseall.",t[M]="all";
	n=findword(s,t,str);
	for(i=0;i<n;i++)
		printf("%s,",str[i]);
	printf("\b.%2d",n);
}



