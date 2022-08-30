/*1、【程序功能】
查找并输出同时出现的两个一维数组中的整数，
每个一维数组中的元素均已按值升序排列，
并且每个数组中的元素没有相同的值。
函数int coincidence_count(int a[],int b[],int m,int n,int c[])
按上述要求在a指向的数组前m个元素和b指向的数组前n个元素中查找，
将找到的整数保存到c指向的数组中。
测试数据：
	a数组中的数据：1，2，4，8，10，12，13，14，16，18
	b数组中的数据：3，4，7，8， 9，10，12，13，16，19
	运行结果：
		No.		Array 1		Array 2
		0  			1			3
		1  			2			4
		2  			4			7
		3		  	8			8
		4			10			9
		5			12			10
		6			13			12
		7			14			13
		8			16			16
		9			18			19
There are 6 equal numbers:4  8  10  12  13  16
*/
#include <conio.h>
#include <stdio.h>
int coincidence_count(int a[],int b[],int m,int n,int c[])
{   int count,ia,ib;
    count=ia=ib=0;
    while(ia<m||ib<n)
        if(a[ia]<b[ib])
            ia++;
/***************FOUND******************/
        else  if(a[ia]>b[ib])
            ib++;
        else
/***************FOUND******************/
        {   c[count++]=a[ia];
            ia++;
            ib++;
        }
    return count-1;
}
main()
{   int a[]={1,2,4,8,10,12,13,14,16,18},b[]={3,4,7,8,9,10,12,13,16,19};
    int c[10],i,na,nb,n;
    na=sizeof(a)/sizeof(int);
    nb=sizeof(b)/sizeof(int);
    printf("\n  Coincidence Count of two Increasing Arrays\n");
    printf("\n No.  Array 1 Array 2");
    for(i=0;i<na;i++)
/***************FOUND******************/
        printf("\n%3d%10d%10d",i,a[i],b[i]);
    printf("\n There are %d equal numbers:",n=coincidence_count(a,b,na,nb,c));
    for(i=0;i<n;i++)
        printf("%5d",c[i]);
}
