/*3、【程序功能】
找出满足下列条件的一个整数：
⑵ 该整数的十进制表示是一个三位数abc，且a＞b＞c＞0；
⑵  交换a、c位置后得到一个新的三位数，该数比原数小495；
⑶ 对abc作全排列得到的6个三位数之和为2886。
提示：从n个不同元素中任取m个元素（m＜n）按照一定的顺序排列起来，
被称为从n个不同元素中取出m个元素的一个排列。当m=n时的排列被称为全排列。
n个互不相同的元素可产生n!个全排列。
【编程要求】
（1）编写函数int sear(int x[])。函数功能：
找出满足上述条件的所有整数并依次保存到x指向的数组中，
函数返回满足条件的整数个数。
（2）编写main函数。函数功能：声明一个长度为10的一维数组，
用该数组作实参调用sear函数，将数组中的结果数据输出到屏幕。
【测试数据与运行结果】
屏幕输出：742
*/
#include<stdio.h>			//全排列 
int sum_all_permutations(int a,int b,int c)
{
	int nums[3],sum=0;
	nums[0]=a;
	nums[1]=b;
	nums[2]=c;
	int i,j,k;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			for(k=0;k<3;k++)
				if(i!=j&&j!=k&&i!=k)
					sum=sum+nums[i]*100+nums[j]*10+nums[k];
	return sum;
	
}
int sear(int x[])
{
	int i,a,b,c,new_i,count=0;
	for(i=100;i<=999;i++)
	{
		a=i/100;
		b=i/10%10;
		c=i%10;
		new_i=c*100+b*10+a;
		if(a>b&&b>c&&i-new_i==495&&sum_all_permutations(a,b,c)==2886)
			x[count++]=i;
	}
	return count;
}
main()
{
	int a[10];
	int len=sear(a);
	for(int i=0;i<len;i++)
		printf("%5d\n",a[i]);
}

