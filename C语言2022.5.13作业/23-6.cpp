/*6.【程序功能】
数组部分元素逆置。
【编程要求】
（1）编写函数void  reverse( int a[], int n,int m )，
其功能是在a指向的有n个元素的数组中找到最后一个素数，
再将该素数之前的m个元素（不包括该素数本身）逆置。
若该素数之前的元素个数不足m时，则从第一个数组元素开始逆置。
（2）编写main函数，声明一维数组a并用测试数据初始化，
接收键盘输入的m值，用a数组和m变量作为实参调用reverse函数，
将变换后的a数组中的数据输出到屏幕。
【测试数据与运行结果】 
测试数据：
a数组初始数据：4  3  6  7  8  13  9  19  21  26   
运行结果：
当m=4时，a数组变为：4  3  6  9  13  8  7  19  21  26
当m=8时，a数组变为：9  13  8  7  6  3  4  19  21  26
*/
#include<stdio.h>
#include<math.h>
void  reverse( int a[], int n,int m )
{
	int i,j,i_p,temp[10];
	for( i=n-1 ; i>=0 ; i--)
	{
		for( j=2 ; j<=sqrt(a[i]) ; j++ )
			if(a[i]%j==0)
				break;
		if(j>sqrt(a[i]))
		{
			i_p=i;
			break;
		}
	}
	if(i_p-m<0)
		m=i_p;
	j=0;
	for( i=i_p-m ; i<i_p ; i++ )
		temp[j++]=a[i];
	
	for( i=i_p-m ; i<i_p ; i++ )
		a[i]=temp[--j];
}
main()
{
	int a[10]={4,3,6,7,8,13,9,19,21,26};
	int n=10,m,i;
	printf("Input m:");
	scanf("%d",&m);
	reverse(a,n,m);
	for(i=0;i<n;i++)
		printf("%5d",a[i]);
	printf("\n"); 
} 
