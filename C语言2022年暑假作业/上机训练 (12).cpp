/*1���Ĵ���
�������ܡ�*/
/*ͳ��һ���ַ����а�������ĸ���������ҳ����������ĸ����
    ��ν��ĸ����ָһ����������ĸ����(�����ִ�Сд)����ĸ��֮���÷���ĸ�ַ��ָ���
	����count�Ĺ����ǣ�ͳ��pָ����ַ����а�������ĸ���������ҳ������ĸ�������pmaxָ��������У�����������ĸ���ĸ�����
���������������н����
  ��������:you are teaeher234too.
  ��Ļ���:a=you are teacher234too.
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
