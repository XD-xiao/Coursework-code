/*2������Ĵ�
�����ܣ�����int fun(int num[],int n,char res[][50])�Ĺ����Ƕ�numָ���������n�������е�
ÿ������rѰ�������ʽ��xyz+yzz=r����x��y��z��x��y��z�ֱ����һλʮ�������֣�������ҵ�һ��x��y��zʹ�õ�ʽ������
�����ɵ�ʽ�ַ����洢��res�����һ���У����δ�ҵ��ͽ���not found for���ַ�������res�����һ���У���������num����������������ʽ������������
����void itostr(int n,char s[])�Ĺ����ǽ�����nת��Ϊһ��ʮ���Ʊ�ʾ���ַ�������sָ��������С�
�������ݣ�762��145��678
    �����foumd 2 equations for 3 nums
          251+511=762
          not found for 145
          334+344=678
���д����Դ����*/
#include<stdio.h>
#include<string.h>
#include<conio.h>
main()
{
    int fun(int num[],int n,char res[][50]);
    int num[3]={762,145,678};
    char res[10][50],ct,i;
    ct=fun(num,3,res);
    printf("found %d equstions for %d nums\n",ct ,3);
    for(i=0;i<3;i++)
/***************FOUND****************/
        puts(res[i]);
}
void itostr(int n,char s[])
{
    int i=0,j;
    char ch;
    while(n>0){
        s[i++]=n%10+'0';
        n=n/10;
    }
    s[i]='\0';
    j=0,i--;
    while(j<i){
        ch=s[i];s[i]=s[j];s[j]=ch;
        i--,j++;
    }
}
int fun(int num[],int n,char res[][50])
{
    int x,y,z,i,j,k,f,ct=0;
    char tmp[50];
    for(k=0;k<n;k++){
        for(f=0,i=100;i<=999;i++)
		{
/***************FOUND****************/
            y=i/10%10;
            z=i%10;
/***************FOUND****************/
            if(i+100*y+10*z+z==num[k])
			{
                 itostr(i,tmp);
                 strcpy(res[k],tmp);
                 strcat(res[k],"+");
                 itostr(100*y+10*z+z,tmp);
                 strcat(res[k],tmp);
                 strcat(res[k],"=");
                 itostr(num[k],tmp);
                 strcat(res[k],tmp);
                 f=1;
                 ct++;
                 break;
             }
        }
        if(!f)
		{
            strcpy(res[k],"not found for ");
            itostr(num[k],tmp);
            strcat(res[k],tmp);
        }
    }
    return ct;
 }
