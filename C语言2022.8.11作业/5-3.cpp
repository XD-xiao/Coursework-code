/*----------------------------------------------------------------------
【程序设计】
------------------------------------------------------------------------
题目：已知，str是存放若干位16进制数的字符串，将该串中的十六进制字串提取
      出来转换为十进制数保存到num数组中。对于一个给定的目标值obj，找出
      num中所有连续的若干个元素值之和等于obj的子序列。
      
例如：str[]="11a,41,1B,1a,5c,a7"
      提取十六进制数且转换后的num值为： num[]={282,65,27,26,92,167}
      若给定的目标值obj=118, 则 
      num中从下标1到下标3和从下标3到下标4的连续元素值之和等于obj。 

程序运行结果是： 
      从str[N]=11a,41 ,1B, 1a,5c,a7 中提取的数值有：282 65 27 26 92 167
      目标值为:118
      找到满足条件整数序列共有2组。
      第1个满足条件的序列为：65 27 26
      第2个满足条件的序列为：26 92

1.编写函数void change(char str[],int num[])，将str中所有十六进制数字字符提
  取出来转换为十进制整数存入num数组中。提取结束后，在提取的整数之后追加数
  值-1表示结束。    
2.编写函数int sum(int num[],int result[][2], int obj)，从num中找出连续元素
  之和等于目标值obj的每种可能性，并将起始下标和终止下标分别保存在result的
  第一列和第二列中，函数返回能够组成目标值的总个数。
---------------------------------------------------------
注意：请勿改动主函数main()中的任何语句。
-------------------------------------------------------*/
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define N 100

void change(char str[],int num[]) 
{
/**********Program**********/
	int number=0,count=0,bit;
	
	for(int i=0 ; str[i] ; i++)
	{
		if(str[i]==' ')
			i++;
		if(str[i]==0)
			break;
		if(isdigit(str[i]))
			bit=str[i]-'0';
		else if(isupper(str[i]))
			bit=str[i]-'A'+10;
		else if(islower(str[i]))
			bit=str[i]-'a'+10;
		else if(str[i]==',')
		{
			num[count++]=number;
			number=0;
			continue;
		}
		number=number*16+bit;
	}
	num[count++]=number;
	num[count]=-1;

/**********  End  **********/
}

int sum(int num[], int result[][2], int obj)
{
/**********Program**********/
	int count=0;
	for(int start=0 ; num[start+1]!=-1 ; start++)
	{
		int sum=0;
		for(int end=start ; num[end]!=-1 ; end++)
		{
			if(sum<obj)
				sum+=num[end];
			else if(sum>obj)
				break;
			else
			{
				result[count][0]=start;
				result[count++][1]=end-1;
				sum=0;
			}
		}
	}
	
	return count;
/**********  End  **********/
}

int main() 
{    
    char str[N]="11a,41 ,1B, 1a,5c,a7 ", obj = 118;
    int  num[N], result[N][2];    
    int i,j,val,s,re,n;
    FILE *fp;
    if((fp=fopen("DATA.dat","w"))==NULL)
    {
        printf("File open error\n");
        return 0;
    }    
    change(str,num);
    printf("从str[N]=%s中提取的数值有：",str);     
    fprintf(fp,"从str[N]=%s中提取的数值有：",str);     
    for(re=0; num[re]!=-1; re++)
    {
        printf("%d ",num[re]);
        fprintf(fp,"%d,",num[re]);
    }
    printf("\n");
    fprintf(fp,"\n");    
    printf("目标值为:%d\n",obj);   
    n = sum(num,result,obj);
    if (n<0)
    {
        printf("没有找到满足条件整数序列\n");        
        fprintf(fp, "没找到\n");        
    }
    else
    {
        printf("找到满足条件整数序列共有%d组。\n",n);    
        for(i=0; i<n; i++)
        {
            printf("第%d个满足条件的序列为：",i+1);
            for (s = result[i][0]; s<= result[i][1]; s++) 
            {
                printf("%d ",num[s]);                
                fprintf(fp,"%d; ",num[s]); 
            }
            printf("\n");           
        }
    } 
    fclose(fp);
    return 0;
}
