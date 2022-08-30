/*----------------------------------------------------------------------
【程序设计】
------------------------------------------------------------------------
题目：一个十进制正整数转换为二进制后，若数字1的个数大于等于0的个数，则称
      该数为A类数，否则称为B类数。

例如：13转换为二进制1101，其中1的个数为3，0的个数为1，则称13为A类数
      10转换为二进制1010，其中1的个数为2，0的个数为2，则称10为A类数
      24转换为二进制11000，其中1的个数为2，0的个数为3，则称24为B类数

1.编写函数 int change(int a[],int n)，将数组a中所有A类数找出后存入a的前部，
  所有B类数存入a的后部，两类数保持原有相对位置不变。函数返回A类数的个数。
2.编写函数 void sort(int a[],int n,int m),对数组a中m个A类数按升序排序，n-m
  个B类数按降序排序，排序结果仍保存在a中。

测试数据：    
      13  4  24   84  127    10  40  35  204  39
      找出 A类数存入数组a前部：13  127  10  35  204  39
      找出 B类数存入数组a后部：4  24   84   40
      运行结果： 
      13  127  10  35  204   39   4  24   84  40
      10   13  35  39  127  204  84  40   24   4 
---------------------------------------------------------
注意：请勿改动主函数main()中的任何语句。
-------------------------------------------------------*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>

#define N  10

int change(int a[],int n)
{
/**********Program**********/
	int j,start=0,t;
	for(int i=n-1;i>=start;i--)
	{
		int x=a[i],one=0,zero=0;
		while(x)
		{
			if(x%2)
				one++;
			else
				zero++;
			x/=2;
		}
		if(one>=zero) //A
		{
			t=a[i];
			for(j=i;j>0;j--)
				a[j]=a[j-1];
			a[j]=t;
			i++;
			start++;
		}
	} 

	return start;
/**********  End  **********/
}
void sort(int a[],int n,int m)
{
/**********Program**********/

	for(int i=0 ;i<m-1;i++)
		for(int j=i+1;j<m;j++)
			if(a[i]>a[j])
			{
				int t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
	for(int i=m ;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(a[i]<a[j])
			{
				int t=a[i];
				a[i]=a[j];
				a[j]=t;
			}


/**********  End  **********/
} 


int main()
{
    int i,a[N]={13,4,24,84,127,10,40,35,204,39},m;
    FILE *fp;
    if((fp=fopen("DATA.dat","w"))==NULL) 
    {
        printf("File open error\n");
        exit(0);
    }
    m=change(a,N);
    for(i=0;i<N;++i)
    {
        printf("%5d",a[i]);
        fprintf(fp,"%5d,",a[i]);
    }    
    sort(a,N,m);
    printf("\n");
    fprintf(fp,"\n");
    for(i=0;i<N;++i)
    {
        printf("%5d",a[i]);
        fprintf(fp,"%5d,",a[i]);
    }
    fclose(fp);
    return 0;
}
