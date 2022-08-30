/* 1、改错题
  【程序功能】
以下程序中函数void csort(char str[][N],int n)对str指向的二维数组前n行中存储的n个字符串分别作如下处理：从中间将字符串一分为二，左半部分字符子串按字符的ASCII码值从大到小排序(若字符串的长度为奇数,则中间字符不参加排序)。
  【测试数据与运行结果】
   测试字符串:"abcdefgh","123498765"
   屏幕输出:dcbaefgh
           432198765*/
    #include<stdio.h>
    #include<string.h>
    #include<conio.h>
    #define N 80
    void csort(char str[][N],int n);
    main()
    {   char s[2][N]={"abcdefgh","123498765"};
        int i;
        csort(s,2);
for(i=0;i<2;i++)
/***************FOUND****************/
           puts(s[i]);    
    }
    void csort(char str[][N],int n)
    {   int i,j,k,len,half;
        char temp;
        for(i=0;i<n;i++)
        {/***************FOUND****************/
len=strlen(str[i]);
            half=len/2;
            for(j=0;j<half-1;j++)
          /***************FOUND****************/
for(k=half-1;k>j+1;k--)
                    if(str[i][j]<str[i][k])
                    {   temp=str[i][j];
                        str[i][j]=str[i][k];
                        str[i][k]=temp;
                    }
        }
    }
