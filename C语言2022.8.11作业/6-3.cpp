/*----------------------------------------------------------------------
【程序设计】
------------------------------------------------------------------------
题目：首先将字符串s中连续的数字字符转换成正整数，再将这些正整数循环移动若干位。

程序运行结果如下：
56789   5678   567   56   5
89567   7856   756   65   5

1.编写函数int abstract(char s[],int num[],int wid[])，将字符串s中连续的
  数字字符转换成正整数，保存在一维数组num中，每个正整数的位数保存在
  一维数组wid中。函数返回正整数个数。
2.编写函数void shift(int num[],int wid[],int n),num数组中保存n个正整数，
  wid中保存了n个正整数的位数。将每个正整数循环移动若干位，得到上面
  所示的运行结果。移位后的值仍然保存在元素原来的位置中。
---------------------------------------------------------
注意：请勿改动主函数main()中的任何语句。
-------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define N 10

int abstract(char s[],int num[],int wid[])
{
/**********Program**********/
	int count=0;
	for(int i=0 ; s[i] ; i++)
	{
		if(isdigit(s[i]))
		{
			int number=0,Num_digits=0;
			while(isdigit(s[i]))
			{
				number=number*10+s[i++]-'0';
				Num_digits++;
			}
			num[count]=number;
			wid[count++]=Num_digits;
			i--;
		}
	}
	
	return count;
/**********  End  **********/
}
void shift(int num[],int wid[],int n)
{
/**********Program**********/
	int times,bit;
	for(int i=0 ; i<n ; i++)
	{
		if(wid[i]>=4)
			times=2;
		else if(wid[i]>=2)
			times=1;
		else
			times=0;
		
		for(int j=0 ; j<times ; j++)
		{
			bit=num[i]%10;
			num[i]=num[i]/10;
			num[i]=bit*pow(10,wid[i]-1)+num[i];
		}
		
	}
	
	
/**********  End  **********/
}

int main()
{
    char s[]={"file56789a5678,$567prin56tt 5 "};
    int i,n,num[N],wid[N];
    FILE *fp;
    if((fp=fopen("DATA.dat","w"))==NULL)
    {
        printf("File open error\n");
        exit(0);
    }
    n=abstract(s,num,wid);
    for(i=0;i<n;++i)
        printf("%d\t",num[i]);
    printf("\n");
    shift(num,wid,n);
    for(i=0;i<n;++i)
    {
        printf("%d\t",num[i]);
        fprintf(fp,"%d\t",num[i]);
    }
    printf("\n");
    fprintf(fp,"\n");
    fclose(fp);
    return 0;
}
