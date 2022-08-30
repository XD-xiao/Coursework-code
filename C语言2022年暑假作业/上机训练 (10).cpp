/* 1、改错题
    【程序功能】
    对存储在string数组内的英文句子中所有以a开始并以e结尾的单词做加密处理。加密规则:若单词长度为偶数个字符，则将组成该单词的所有字母循环左移一次；否则循环右移一次。例如，单词able经循环左移一次后变为blea;单词abide经循环右移一次后变为eabid。
    【测试数据与运行结果】
    测试数据:she is able to abide her.
    屏幕输出:she is blea to eabid her.
    【含有错误的源程序】*/
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
