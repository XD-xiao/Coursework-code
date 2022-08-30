/*----------------------------------------------------------------------
【程序填空】
------------------------------------------------------------------------
题目：a为一维整型降序数组，函数find(int a[],int x)在数组a中寻找三个
      元素值之和等于x的一种组合。

程序运行结果如下：
24=15+ 8+ 1
17=12+ 4+ 1
5  No
------------------------------------------------------------------------
注意：除要求填空的位置之外，请勿改动程序中的其他部分。
----------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define N 8
char fmt[]="%2d=%2d+%2d+%2d\n";

void find(int a[],int x)
{
    int i,tot,sed,thd;
    for(i=0;i<N-2;++i)
    {
/**************************SPACE*************************/
        tot=x-a[i];				
        sed=i+1;
        thd=N-1;
/**************************SPACE*************************/
        while(sed<thd)			
        {
            if(a[sed]+a[thd]==tot)
            {
                printf(fmt,x,a[i],a[sed],a[thd]);
                return;
            }
            else if(a[sed]+a[thd]<tot)
                --thd;
            else
                ++sed;
        }
    }
    printf("%d No\n",x);
    return ;
}

int main() 
{
    int a[N] = {15,12,10,8,4,3,2,1};
    int sum[3]={24,17,5};
    int i;
    for(i=0;i<3;++i)
        find(a,sum[i]);
    return 0;
}
