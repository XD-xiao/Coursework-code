/* 1���Ĵ���
  �������ܡ�
���³����к���void csort(char str[][N],int n)��strָ��Ķ�ά����ǰn���д洢��n���ַ����ֱ������´������м佫�ַ���һ��Ϊ������벿���ַ��Ӵ����ַ���ASCII��ֵ�Ӵ�С����(���ַ����ĳ���Ϊ����,���м��ַ����μ�����)��
  ���������������н����
   �����ַ���:"abcdefgh","123498765"
   ��Ļ���:dcbaefgh
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
