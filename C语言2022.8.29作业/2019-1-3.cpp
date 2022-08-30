/*-------------------------------------------------------------------------
【程序设计】
---------------------------------------------------------------------------
题目：判断a数组中的数是否是回文数，若是，将其转换成对应的数字字符串，并在
      字符串后添加若干"*"号，个数与对应回文数的最后一位数相等，将该字符串
      存放在二维字符数组ch的一行中。

1.编写函数 int huiwei(int x) ，判断某数是否是回文数， 如果是则返回1，
  不是返回0；

2.编写函数 int change(int a[M][N],char ch[M*N][80]),调用函数 
  int huiwei(int x)，判断a数组的数是否是回文数，若是，将其转换成对应的数字
  字符串，并在字符串后添加若干"*"号,个数与对应回文数的最后一位数相等，将该
  字符串存放在二维字符数组ch的一行中。函数返回字符串的个数。
 
程序运行结果：
1221*
7557*******
646******
24442**
787*******
2112**
515*****

---------------------------------------------------------
注意：请勿改动主函数main()中的任何语句。
-------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

#define M 3
#define N 4

int huiwen(int x)
{
/**********Program**********/
	int rev=0,num=x;
	while(x)
	{
		rev=rev*10+x%10;
		x/=10;
	}
	if(rev==num)
		return 1;
	else
		return 0;

/**********  End  **********/
}
int change(int a[M][N],char ch[M*N][80])
{
/**********Program**********/
	int count = 0 ;
	for(int i=0 ; i<M ; i++)
		for(int j=0 ; j<N ; j++)
			if(huiwen(a[i][j]))
			{
				int k=0,num=a[i][j];
				while(num)
				{
					ch[count][k++]=num%10+'0';
					num/=10;
				}
				for(int p=0 ; p<a[i][j]%10 ; p++)
					ch[count][k++]='*';
				ch[count++][k]=0;
			}

	return count;
/**********  End  **********/
}   

int main()
{   
    FILE *fp; 
    int a[M][N]={123,1221,345,3224,7557,646,573,24442,787,2112,912,515};
    char ch[M*N][80];
    int k,i;
    if((fp=fopen("data.dat","w"))==NULL)
    {
        printf("File open error\n");
        exit(0);
    }
    k=change(a,ch);
    for(i=0;i<k;i++)
    {
        printf("%s\n",ch[i]);
        fprintf(fp,"%s\n",ch[i]);
    }          
    fclose(fp);     
    return 0;
}
