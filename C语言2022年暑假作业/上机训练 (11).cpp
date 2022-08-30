/*2、编程题
    【程序功能】
    矩阵数据生成及排序。
    【编程要求】
     (1)编写函数void cresort(int a[][3],int n)。函数功能是：先根据a指向的二维数组中第1列(列下标为0)和第2列(列下标为1)的值按下表所列规则生成第3列各元素的值，再以行为单位重排a数组的各行，使得所有行按第3列元素值从小到大排列。
    第3列生成规则:
	若第1列和第2列都是素数，则第3列置4；
	若第1列和第2列都不是素数，则第3列置1；
	若第1列是素数，第2列不是素数，则第3列置3；
	若第1列不是素数，第2列都是素数，则第3列置2。
    (2)编写main函数。函数功能是声明5行3列二维数组a并用测试数据初始化,用数组a
作为实参调用cresort函数,将a数组中的数据输出到屏幕。
【测试数据与运行结果】
    测试数据:
    27  16     0
    11  12     0
    6    9     0
    7    13    0
    8    5     0
屏幕输出:
27    16    1
 6    9     1
 8    5     2
11    12    3
 7    13    4
*/
#include <stdio.h>
#include<math.h>

bool prime(int n)               /*本函数的功能是判定素数*/
{
	long j;
	for( j=2 ; j<=sqrt(n) ; j++ )
		if(n%j==0)
			return false;
	return true;
}
void cresort(int a[][3],int n)
{
	
	for(int i=0 ; i<n ; i++)
	{
		if(prime(a[i][0]))
			if(prime(a[i][1]))
				a[i][2]=4;
			else
				a[i][2]=3;
		else
			if(prime(a[i][1]))
				a[i][2]=2;
			else
				a[i][2]=1;
	}
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(a[i][2]>a[j][2])
				for(int k=0;k<3;k++)
				{
					int t=a[i][k];
					a[i][k]=a[j][k];
					a[j][k]=t;
				}
			
	
	
	
}
main()
{
	int a[5][3]={27,16,0,11,12,0,6,9,0,7,13,0,8,5,0};
	int i,j;
	cresort(a,5);
	for(i=0;i<5;i++)
	{
		for(j=0;j<3;j++)
			printf("%5d",a[i][j]);
		printf("\n");
	}
	
}


