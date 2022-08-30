/*1、改错题
【程序功能】*/
/*统计一个字符串中包含的字母串个数并找出其中最长的字母串。
    所谓字母串是指一个连续的字母序列(不区分大小写)，字母串之间用非字母字符分隔。
	函数count的功能是：统计p指向的字符串中包含的字母串个数，找出的最长字母串存放在pmax指向的数组中，函数返回字母串的个数。
【测试数据与运行结果】
  测试数据:you are teaeher234too.
  屏幕输出:a=you are teacher234too.
           number is 4
           max string is:teacher    */
    #include <stdio.h>
    #include <string.h>
    #include <ctype.h>    
    int count(char p[],char pmax[])
    {   int j=0,k,i=0,m=0;
        char temp[100];
        while(p[i])
        {   while((!isalpha(p[i])) && p[i]) i++;
            k=0;
            if(p[i]!='\0') m++;
            while(isalpha(p[i]))
                temp[k++]=p[i++];
            temp[k]='\0';    
          /***************FOUND****************/
            if(k>j)    
            {   j=k;
       /***************FOUND****************/
                strcpy(pmax,temp);
            }
       }
       return m;
    }
    main()
    {   char a[100]="you are teacher234too.",max[100];
        int i;
/***************FOUND****************/
        i=count(a,max);
        if(i==0)
            printf("a=%s:  No letter strings!\n",a);
        else
            printf("a=%s\nnumber is %d\nmax string is:%s\n",a,i,max);
}
