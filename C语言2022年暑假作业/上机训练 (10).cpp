/* 1���Ĵ���
    �������ܡ�
    �Դ洢��string�����ڵ�Ӣ�ľ�����������a��ʼ����e��β�ĵ��������ܴ������ܹ���:�����ʳ���Ϊż�����ַ�������ɸõ��ʵ�������ĸѭ������һ�Σ�����ѭ������һ�Ρ����磬����able��ѭ������һ�κ��Ϊblea;����abide��ѭ������һ�κ��Ϊeabid��
    ���������������н����
    ��������:she is able to abide her.
    ��Ļ���:she is blea to eabid her.
    �����д����Դ����*/
    #include <stdio.h>
    #include <ctype.h>
    void wordchange(char str[])
    {  int i,j,k,m;  
       char c;
       for(i=0;str[i];i++)
       {   for(j=i,k=i;isalpha(str[k]);k++);
/***************FOUND****************/
           if(str[j]=='a' && str[k-1]=='e')
           {   if((k-j)%2==0)
               {   c=str[j];
             /***************FOUND****************/
                   for(m=j;m<k-1;m++)
                       str[m]=str[m+1];
                   str[k-1]=c;
               } 
               else
               {    c=str[k-1];
for(m=k-1;m>j;m--)
                        str[m]=str[m-1];
                    str[j]=c;
               }
           }
           i=k;
       }
  }
  main()
  {   char string[80]="she is able to abide her.";
/***************FOUND****************/
wordchange(string);
        puts(string);
    }
