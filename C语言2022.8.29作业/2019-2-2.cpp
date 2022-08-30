/*------------------------------------------------------------------------
【程序改错】
--------------------------------------------------------------------------

题目：函数int judge(int m[],int n)判断一维数组m中n个元素的有序性：
      递增、递减、相等、无序，并返回相应值。

程序运行结果如下：
a[0] 递增
a[1] 递减
a[2] 相等
a[3] 无序

--------------------------------------------------------------------------
注意：不得增行或删行，也不得更改程序的结构。
------------------------------------------------------------------------*/
#include <stdio.h>
int judge(int m[],int n)
{
    int i,f;
    for(i=0;i<n-1;i++)
/***********FOUND***********/
        if(m[i]!=m[i+1])
            break;
    if(i==n-1)
        return 1;
    f=(m[i]<m[i+1]?2:3);
    for(;i<n-1;i++)
/***********FOUND***********/
        if(f==2 && m[i]>m[i+1] || f==3 && m[i]<m[i+1])
            break;
    if(i==n-1)
/***********FOUND***********/
        return f;
    return 4;
}
int main() {
    int  i,a[4][5]={{-2,0,3,5,7},{12,10,7,5,-1},{4,4,4,4,4},{4,0,-2,1,6}};
    for(i=0;i<4;i++)
    {
        switch(judge(a[i],5))
        {
            case 1:printf("a[%d] 相等\n",i);break;
            case 2:printf("a[%d] 递增\n",i);break;
            case 3:printf("a[%d] 递减\n",i);break;
            case 4:printf("a[%d] 无序\n",i);break;
        }
    }
    return 0;
}
