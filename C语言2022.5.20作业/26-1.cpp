/*1���������ܡ�
����HolandFlag�Ĺ����ǣ���֪��flagָ�����n��Ԫ�ص��ַ������У�
ÿ��Ԫ�ص�ֵ���ַ���R������W����B���е�һ����
�������ա�R������W������B����˳����������flag����������Ԫ�ص�ֵ��
�㷨��ʾ��
��flag�����ʼֵΪRBWBRWRBW,����flag�����г������ݽ����Ĳ�����Ч��Ϊ��
��1����flag[1]��flag[8]����������ΪRWWBRWRBB
��2����flag[3]��flag[6]����������ΪRWWRRWBBB
��3����flag[1]��flag[4]����������ΪRRWRWWBBB
��4����flag[2]��flag[3]����������ΪRRRWWWBBB
���������������н����
�������ݣ�RBWBRWRBW
���н����RRRWWWBBB*/
#include <stdio.h>
#include <string.h>
#define N 10 
void HolandFlag(char flag[],int num)
{   int i,j,k,m;
    char c,color[3]={'B','W','R'};               //
    m=num;
    for(k=0;k<2;k++)
        for(i=0;i<m;i++)
            if(flag[i]==color[k])
            {   for(j=m-1;j>i;j--)
                    if(flag[j]!=color[k])         //
                    {    c=flag[i];
                        flag[i]=flag[j];
                        flag[j]=c;
                        m--;
                        break;
                    }
                    if(i==j) m=i;
            }
}
main()
{   char flag[N]="RBWBRWRBW";
    int i,k,n=strlen(flag);
    HolandFlag(flag,n);                   //
    for(i=0;i<n;i++)
        printf("%c",flag[i]);
}
