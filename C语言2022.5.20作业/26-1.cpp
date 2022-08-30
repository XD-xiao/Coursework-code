/*1、【程序功能】
函数HolandFlag的功能是：已知在flag指向的有n个元素的字符数组中，
每个元素的值是字符’R’、’W’或’B’中的一个。
函数按照’R’、’W’、’B’的顺序重新排列flag数组中所有元素的值。
算法提示：
若flag数组初始值为RBWBRWRBW,则在flag数组中出现数据交换的步骤与效果为：
第1步：flag[1]与flag[8]交换后数据为RWWBRWRBB
第2步：flag[3]与flag[6]交换后数据为RWWRRWBBB
第3步：flag[1]与flag[4]交换后数据为RRWRWWBBB
第4步：flag[2]与flag[3]交换后数据为RRRWWWBBB
【测试数据与运行结果】
测试数据：RBWBRWRBW
运行结果：RRRWWWBBB*/
#include <stdio.h>
#include <string.h>
#define N 10 
void HolandFlag(char flag[],int num)
{   int i,j,k,m;
    char c,color[3]={'B','W','R'};               //
    m=num;
    for(k=0;k<2;k++)
        for(i=0;i<m;i++)
            if(flag[i]==color[k])
            {   for(j=m-1;j>i;j--)
                    if(flag[j]!=color[k])         //
                    {    c=flag[i];
                        flag[i]=flag[j];
                        flag[j]=c;
                        m--;
                        break;
                    }
                    if(i==j) m=i;
            }
}
main()
{   char flag[N]="RBWBRWRBW";
    int i,k,n=strlen(flag);
    HolandFlag(flag,n);                   //
    for(i=0;i<n;i++)
        printf("%c",flag[i]);
}
