/*8���Ĵ���
����Ŀ�������ַ���s1��s2,����find()�ж�s1��
�Ƿ�����ַ���s2,��s1����s2,������ַ���s2��s1�е�
��ʼλ�ã����������No substring!����
���д����Դ����Ϊ��*/
#include<stdio.h>
#include<string.h>
/****************FOUND**************/ 
int find(char s1[],char s2[])
{   int i=0,j,k=0;
while(s1[i]){
/****************FOUND**************/
        j=0,k=i;			//û�и� 
        while(s1[i]==s2[j]) {
			i++;
			j++;
		}
/****************FOUND**************/
        if(s2[j]==0) return(k);
		i++;
    }
    return(-1);
}

main()
{   int i;
    char s1[200],s2[100];
    gets(s1);gets(s2);
    i=find(s1,s2);
    if(i==-1)
        printf("s1=%s  s2=%s\n No substring!\n",s1,s2);
    else
        printf("s1=%s  s2=%s\n starting pos of substring is %d\n",s1,s2,i);
}
