/*----------------------------------------------------------------------
【程序设计】
------------------------------------------------------------------------
题目：找出一维数组a中回文整数，保存在a数组前面，非回文数保存在a数组的后面。
      回文数字和非回文数字的相对位置不能改变。再对所有非回文数进行如下处理：
      用距离该数最近的2的正整数次幂取代该数。如果距离相同,则取小于该数最近
      的2的正整数次幂取代该数,例如48距离32和64相同,则用32取代48。
      程序运行结果如下：
      a数组中原始数据为  48  808     9   123   121  2048
      找出回文数后为    808    9   121    48   123  2048
      最终结果为        808    9   121    32   128  2048

1.编写函数 int find(int a[])，从一维数组a的N个元素中找出回文整数，保存在a数组
  的前面，非回文数保存在a数组的后面。回文数字和非回文数字的相对位置不能改变。
  函数返回第一个非回文数在a中的下标。
2.编写函数 void change(int a[],int n),将a数组中下标n至N-1的所有元素进行处理，
  用距离该数最近的2的正整数次幂取代该数，保存在该数原来位置上。如果距离相同，
  则取小于该数最近的2的正整数次幂取代该数。

---------------------------------------------------------
注意：请勿改动主函数main()中的任何语句。
-------------------------------------------------------*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#define N 6
int find(int a[])
{
/**********Program**********/
	int n=N;
	for(int i=0 ; i<n ; i++)
	{
		int num=a[i],rev_num=0;
		while(num)
		{
			rev_num=rev_num*10+num%10;
			num/=10;
		}
		if(rev_num!=a[i])
		{
			int j,t=a[i];
			for(j=i-- ; j<N-1 ; j++)
				a[j]=a[j+1];
			a[j]=t;
			n--;
		}
	}
	return n;
/**********  End  **********/
}
void change(int a[],int n)
{
/**********Program**********/
	for(int i=n ; i<N ; i++)
	{
		int exp=0;
		while(pow(2,exp)<=a[i])
			exp++;
		a[i]=pow(2,exp-1);
	}
	
/**********  End  **********/
}
int main() 
{
    FILE *fp;
    int a[N]={48,808,9,123,121,2048};
    int i,n;
    if((fp=fopen("DATA.dat","w"))==NULL)
    {
        printf("File open error\n");
        exit(0);
    }
    printf("a数组中原始数据为");
    for(i=0;i<N;++i)
    {
        printf("%6d",a[i]);
        fprintf(fp,"%6d",a[i]);
    }
    printf("\n");
    fprintf(fp,"\n");
    n=find(a);
    printf("找出回文后数据为 ");
    for(i=0;i<N;++i)
    {
        printf("%6d",a[i]);
        fprintf(fp,"%6d",a[i]);
    }
    printf("\n");
    fprintf(fp,"\n");
    change(a,n);
    printf("最终结果为       "); 
    for(i=0;i<N;++i)
    {
        printf("%6d",a[i]);
        fprintf(fp,"%6d",a[i]);
    }        
    printf("\n");
    fprintf(fp,"\n");
    fclose(fp);
    return 0;
}
