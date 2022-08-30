/*7、编程题
【题目】
(1)编写一个函数void fun (int array[ ], int n)，
将array数组中的前n个整数按从大到小的顺序排序。
(2)编写主函数main，从键盘上输入一个正整数，
求出该位是几位数，按从左到右的顺序显示各位数字，
用这些数字组成一个最小正整数（调用fun函数），
将以上三项结果输出到屏幕上。*/
#include<stdio.h>
#define N 63
fun(int array[],int n)
{
	for(int i=0 ; i<n-1 ; i++)
		for(int j=i+1 ; j<n ; j++)
			if(array[i]<array[j])
			{
				int temp=array[i];
				array[i]=array[j];
				array[j]=temp;
			}
}
main()
{
	int len=0,number,nums[N];
	printf("Input number:");
	scanf("%d",&number);
	while(number)
	{
		nums[len++]=number%10;
		number/=10;
	}
	printf("This is a %3d-digit figure\n",len);
	fun(nums,len);
	for(int i=0 ; i<len ; i++)
		printf("%d",nums[i]);
}
