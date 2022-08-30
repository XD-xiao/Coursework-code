/*6.【程序功能】
将一维数组中的所有素数移到该数组的前端部分。
【编程要求】
（1）编写函数void  move( int b[], int n )，其功能是将b指向的有n个元素的
数组中的所有素数移动到该数组前端部分。
（2）编写main函数，声明数组a并用测试数据初始化，调用move函数对a数组做变换，
将变换后的a数组中数据输出到屏幕。
【测试数据与运行结果】 
测试数据：21  18   5   3  17  12   6  15   9  19
运行结果：5   3   17  19  21  18  12   6  15   9*/
#include<stdio.h>
#include<math.h> 
void  move( int b[], int n )
{
	int start=0,i,j,t;
	for( i=n-1 ; i>=start ; i-- )
	{
		for( j=2 ; j<=sqrt(b[i]) ;j++ )
			if(b[i]%j==0)
				break;
		if(j>sqrt(b[i]))
		{
			t=b[i];
			for( j=i ; j>0 ; j-- )
				b[j]=b[j-1];
			b[0]=t;
			start++;i++;
		}
	}
	
}
main()
{
	int i,a[10]={21,18,5,3,17,12,6,15,9,19},n=10;
	move(a,n);
	for( i=0 ; i<n ; i++ )
		printf("%5d",a[i]);
	printf("\n");
}
