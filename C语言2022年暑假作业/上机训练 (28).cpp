/*6���Ĵ���
����Ŀ������fun�Ĺ����ǣ���m��1��m��10����
�ַ��������������һ���´�������pt��ָ�ַ����С�
���磺��3��������abc������CD������EF������������
����ǡ�abcCDEF����
���д���ĳ������£�*/
#include <conio.h>
#include <stdio.h>
#include <string.h>
/****************FOUND**************/         
int fun(char str[][10],int m,char pt[])
{
    int k,q,i,j=0;
    for(k=0;k<m;k++)
    {  q=strlen(str[k]);
       for(i=0;i<q;i++)
          pt[j++]=str[k][i]; 
    }
/****************FOUND**************/         
	pt[j]=0;
}
main( )
{    int m=3,h;
     char s[10][10],p[120];
     printf("\nPlease enter %d string:\n",m);
     for(h=0;h<3;h++) {
		 gets(s[h]);
		 printf("%d:%s\n",h,s[h]);
	 }
 /****************FOUND**************/         
     fun(s,m,p);
     printf("\nThe result  is :%s\n",p);
} 
