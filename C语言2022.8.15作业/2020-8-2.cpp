/*----------------------------------------------------------------------
������Ĵ�
------------------------------------------------------------------------

��Ŀ�������ַ�����ʼ��ĩβ�������ո�ɾ����ͬʱ���ַ����м�Ķ���ո�
      ɾ��ֻʣ1���ո�
      �������н��Ϊ��
      "   hello    how are  you    "
      "hello how are you"
------------------------------------------------------------------------
ע�⣺�������л�ɾ�У�Ҳ���ø��ĳ���Ľṹ��
----------------------------------------------------------------------*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>

void getnewstr(char a[])
{
    int isbegin,front,back;
    isbegin=1; 
    front=0;
/***********FOUND***********/
    back=0;
    for( ; a[back]!= '\0'; )
    {
        if (a[back]!=' ')
        {
            isbegin=0;
            a[front++]=a[back++];
        }
        else
        {
/***********FOUND***********/
            if(isbegin==0)
                a[front++]=a[back++];
            while(a[back]==' ')
                ++back;
        }
    }
/***********FOUND***********/
    if(a[front]!=' ')
        --front;
    a[front]='\0';
}
int main()
{
    char a[] = "   hello    how      are you    ";
    printf("\"%s\"\n",a);
    getnewstr(a);
    printf("\"%s\"\n",a);
    return 0;
}
