/*-------------------------------------------------------------------------
【程序设计】
---------------------------------------------------------------------------
题目：主函数的一维字符数组str[]中有4个数字子串，程序将其转换为4个正、负整数。
      并根据这4个整数值对二维整型数组的各行元素进行循环移动。

编写函数
1.函数void abstract(char str[],int p[])将str中的4个连续的数字子串转换为10进
  制整数，保存在一维数组p中。p的值分别是3、-14、16、0。

2.函数void move(int m[][COL],int p[])依据p中元素值对二维数组m的每一行元素左、
  右循环移动，p中元素值为正，m对应行元素向右循环移动，p中元素值为负，则向左
  循环移动。

例如p[]={3,-14,16,0},则二维数组m从上往下各行元素分别向右循环移动3次、向左循
环移动14次、向右循环移动16次、向右循环移动0次。

程序运行结果为：
p数组的值为:
   3 -14  16   0
移动后:
   9   5  -3  12   0
   8   4  -6   7  19
  20  -4   3  11  16
  -7  -5  13  -2   0
---------------------------------------------------------
注意：请勿改动主函数main()中的任何语句。
-------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define ROW 4
#define COL 5
void abst(char str[],int p[])
{
/**********Program**********/
	int count=0;
	for(int i=0 ; str[i] ; i++)
		{
			if(isdigit(str[i])||str[i]=='-')
			{
				int sign=1;
				p[count]=0;
				if(str[i]=='-')
					sign=-1,i++;
				while(isdigit(str[i])&&str[i])
					p[count]=p[count]*10+str[i++]-'0';

				p[count]=sign*p[count];
				count++;
				i--;
			}
		}


/**********  End  **********/
}

void move(int m[][COL],int p[])
{
/**********Program**********/

	for(int i=0 ; i<ROW ; i++)
	{
		if(p[i]>0)
			for(int j=0 ; j<abs(p[i]) ; j++)
			{
				int t=m[i][COL-1];
				for(int j=COL-1 ; j>0 ; --j)
					m[i][j]=m[i][j-1];
				m[i][0]=t;
			}
		else if(p[i]<0)
			for(int j=0 ; j<abs(p[i]) ; j++)
			{
				int t=m[i][0];
				for(int j=0 ; j<COL-1 ; ++j)
					m[i][j]=m[i][j+1];
				m[i][COL-1]=t;
			}
	}


/**********  End  **********/
}
int main(){
    char str[]="vaue3  pos-14+pus16@#$wqzero0";
    int m[ROW][COL]={{12,0,9,5,-3},{4,-6,7,19,8},{-4,3,11,16,20},{-7,-5,13,-2,0}};
    int p[ROW];
    int i,j;
    FILE *fp;
    if((fp=fopen("DATA.dat","w"))==NULL)
    {
        printf("File open error\n");
        exit(0);
    }
    abst(str,p);
    puts("p数组的值为:");
    fputs("p数组的值为:\n",fp);
    for(i=0;i<ROW;i++)
    {
        printf("%4d",p[i]);
        fprintf(fp,"%4d",p[i]);
    }
    printf("\n");
    fprintf(fp,"\n");
    move(m,p);
    puts("移动后:");
    fputs("移动后:\n",fp);
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)
        {
            printf("%4d",m[i][j]);
            fprintf(fp,"%4d",m[i][j]);
        }
        printf("\n");
        fprintf(fp,"\n");
    }
    fclose(fp);
    return 0;
}
