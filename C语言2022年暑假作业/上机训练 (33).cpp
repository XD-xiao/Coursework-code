/*2、特殊数：495三位陷阱数
【程序功能】参考2009春C04编程题和网上资料编写
用一组整数验证命题：任意一个三位不完全相同的正整数在经过以下重排求差操作后一定会变换到495：求该三位数的排列最大数与最小数n1，n2，求其差的绝对值的最大数与最小数n3，n4。重复上述运算，最后得陷阱数495（因为954-459=495）。
例如123，其排列最大与最小值为321和123，相减，得198 。按上面做法再做一次，得到981-189=792，再做一次，得到972-279=693 ，之后得到963-369=594，之后得到954-459=495。以后反复都为495。
【编程要求】
（1）编写函数int fun(int a[], int b[], int n)。其功能是用a指向的数组的n个整数验证上述命题，将所有符合命题的数组元素下标保存到b指向的数组中，函数返回b数组中元素的个数。
（2）编写main函数，声明a数组并用测试的10个数据初始化，用a数组作为实参调用fun函数，将a数组所有符合上述命题的整数输出到屏幕。
【测试数据与运行结果】
测试数据：121,123,765,421,134,297,248,45,349,452
运行结果：123   765   421   134  297  248  349   452*/

#include<stdio.h>
Maximum_value(int &min,int &max,int num)
{
	int nums[63],n=0;
	while(num)
	{
		nums[n++]=num%10;
		num/=10;
	}
	for(int i=0 ; i<n-1 ; i++)
		for(int j=i+1 ; j<n ; j++)
			if(nums[i]>nums[j])
			{
				int t=nums[i];
				nums[i]=nums[j];
				nums[j]=t;
			}
	min=max=0;
	for(int i=n-1 ; i>=0 ; i--)
		max=max*10+nums[i];
	for(int i=0 ; i<n ; i++)
		min=min*10+nums[i];

}
int fun(int a[], int b[], int n)
{
	int min,max,count=0;
	for(int i=0 ; i<n ; i++)
	{
		Maximum_value(min,max,a[i]);
		while(max-min!=495&&min!=max)
			Maximum_value(min,max,max-min);
		
		if(min!=max)
			b[count++]=a[i];
	}
	return count ;
}
main()
{
	int a[10]={121,123,765,421,134,297,248,45,349,452};
	int b[10];
	int n=10;
	int len=fun(a,b,n);
	for(int i=0 ; i<len ; i++)
		printf("%5ld",b[i]);
	printf("\n");
}












