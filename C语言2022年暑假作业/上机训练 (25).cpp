/*3���Ĵ���
����Ŀ������fun�Ĺ����ǣ�
��p��ָ�ַ����е������ַ����Ƶ�b�У�
Ҫ��ÿ���������ַ�֮�����һ���ո�
���磬�ڵ���fun����֮ǰ��a�����ַ�����ABCDEFGHIJK��
���ú���֮���ַ�����b�е�������Ϊ��ABC DEF GHI JK��
���д���ĳ������£�*/
#include <stdio.h>
/****************FOUND**************/
void  fun(char p[], char b[])
{  int  i=0, j,k=0;
   while(p[i])
   {  j=1;
 /****************FOUND**************/     
while( j<=3 && p[i] )
 {
          b[k++]=p[i++];
          j++; 
}
      if(p[i]!=0)
/****************FOUND**************/
         b[k++]=' ';
  }
   b[k]='\0';
}
main()
{   char  a[80],b[80];
    printf("Enter a string:"); gets(a);
    printf("The original string: "); puts(a);
    fun(a,b);
    printf("\nThe string after insert space:"); 
puts(b); 
}
