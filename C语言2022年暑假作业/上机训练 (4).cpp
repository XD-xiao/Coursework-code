/*1、改错题
  【程序功能】
  验证n范围内的任意两个相邻素数的平方之间至少存在4个素数。例如，5和7是两个相邻素数，5^2(25)与7^2(49)之间存在6个素数：29  31  37  41  43  47。
  【测试数据与运行结果】
  显示：input n：
  输入：10
  输出：
    3~5    k=5
    11  13   17   19    23
    5~7    k=6
    29    31    37    41    43    47
  【含有错误的源程序】*/
    #include<stdio.h>
    #include<math.h>  
    int prime(int n)
{   int i,flag=1;
/***************FOUND****************/
        for(i=2;i<=sqrt(n);i++)  
            if(n%i==0)flag=0;
        return flag;  
    }
    int fun(int a[],int n)
    {   int i,k=0;
        for(i=3;i<=n;i++)   
           if(prime(i)) a[k++]=i; 
      return k;
}
/***************FOUND****************/
int fun1(int m,int n, int b[])
    {  int i,k=0;
       if(m>n) return 0;
       for(i=m*m;i<n*n;i++)
           if(prime(i)) b[k++]=i;
      return k;
    }
    main()
    {   int a[50]={0},b[100]={0},i,m,k,j,n;
        printf("Input n：");
        scanf("%d",&n);    
        m=fun(a,n);
        for(i=0;i<m-1;i++)
{/***************FOUND****************/
k=fun1(a[i],a[i+1],b);
            printf("%d~%d  k=%d",a[i],a[i+1],k);
            if(k<4){printf("false");break;}
            for(j=0;j<k;j++)
{/***************FOUND****************/
if(j%10==0)printf("\n");
                printf("%5d",b[j]);
            }   
            printf("\n");
       }
    }
