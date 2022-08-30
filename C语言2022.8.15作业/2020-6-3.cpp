/*----------------------------------------------------------------------
【程序设计】
------------------------------------------------------------------------
题目：已知半径为5,圆心为(3,9)的圆，字符串s给出一组以空格为分隔符的点的
      坐标，每个坐标的横、纵坐标值以逗号分隔，并以二进制字符串表示。
例如：char s[]= {"   10,10   0,101   110,1010   "};
      表示的坐标为：（2,2), (0,5), (6,10), 它们与圆的位置关系如下：
      点(2,2)在圆外
      点(0,5)在圆上
      点(6,10)在圆内

编写程序：
1.编写 int change(char s[],int num[][3])函数，将s中所有二进制数字字符子
  串转换为用整数表示的点的坐标，存放在num数组的同一行前2列。
  函数返回坐标的个数。如果s的格式错，返回0。

2.编写 void calc(int num[][3],int n)函数，根据num数组中每行前2个元素所对
  应的点，判断点在圆的位置，其结果存放在第三列，若在圆上为0，圆外为1，
  圆内为2。
---------------------------------------------------------
注意：请勿改动主函数main()中的任何语句。
-------------------------------------------------------*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
int change(char s[],int num[][3]) 
{
/**********Program**********/
	int count=0;
	for(int i=0 ; s[i] ; i++)
	{
		if(isdigit(s[i]))
		{
			char num1[16],num2[16];
			int len1=0,len2=0;
			while(isdigit(s[i]))
				num1[len1++]=s[i++];
			num1[len1]=0;
			if(s[i]==',')
				i++;
			else
				continue;
			while(isdigit(s[i]))
				num2[len2++]=s[i++];
			num2[len2]=0;
			int number=0;
			for(int j=0 ; num1[j] ; j++)
				number=number*2+num1[j]-'0';
			num[count][0]=number;
			number=0;
			for(int j=0 ; num2[j] ; j++)
				number=number*2+num2[j]-'0';
			num[count++][1]=number;
			i--;
		}
	}
	return count ;
/**********  End  **********/
}

void calc(int num[][3],int n) 
{
/**********Program**********/
	
	for(int i=0 ;i<n;i++)
	{
		int  r2=pow(abs(3-num[i][0]),2)+pow(abs(9-num[i][1]),2);
		if(r2>25)
			num[i][2]=1;
		else if(r2<25)
			num[i][2]=2;
		else
			num[i][0]=0;
	}
	
/**********  End  **********/
}
int main() 
{
    char s[]= {"   10,10   0,101   110,1010   "};
    int num[10][3],i,n;
    char disp[][10]= {"上","外","内"};
    FILE *fp;
    if((fp=fopen("DATA.dat","w"))==NULL) 
    {
        printf("File open error\n");
        exit(0);
    }
    n=change(s,num);
    if (n==0) 
    {
        printf("参数错\n") ;
        fprintf(fp,"参数错\n") ;
    } 
    else 
    {
        calc(num,n);
        for(i=0; i<n; i++) 
        {
            printf("点(%d,%d)在圆%s\n",num[i][0],num[i][1],disp[num[i][2]]);
            fprintf(fp,"点(%d,%d)在圆%s\n",num[i][0],num[i][1],disp[num[i][2]]);
        }
    }
    fclose(fp);
    return 0;

}
