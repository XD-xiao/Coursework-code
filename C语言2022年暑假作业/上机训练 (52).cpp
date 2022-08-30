/*题型2:整数拆分
     用一组整数验证命题，
	 任意一个百位数字与个位数字不同的三位正整数n1在
	 经过以下操作后一定会变换到1089:
	 将n1的百位数与个位数字交换得到n2，
	 求n1和n2差的绝对值得到n3，
	 
	 将n3的百位数字与个位数字交换得到n4；
	 求n3与n4的和得到n5，n5一定是1089,
	 若
	 n1、n3是一位数或两位数,则在高位补0使其成为三位数。
例如:n1:123,n2:321,n3:198(321,-123),n4:891,n5:1089(198+891)
   【编程要求】
（1）编写函数int fun(int a[ ],int b[ ], int n),其
功能是用n指向数组的前n个整数验证上述命题，将
所有符合命题的整数所在数组元素的下标
依次保存到b指向的数组中,函数返回b数组中数据的个数。      
（2）编写main函数，声明a数组并用测试数据初始化，
用a数组作为实参调用fun函数,将a数组中所有符合命题的整数输出到屏幕。
   【测试数据与运行结果】
    测试数据:123  765   1  45   121   1345  131  67  696  3589
    运行结果:123  765   1  45   67*/
#include <stdio.h>
#include<math.h>
#define N 100
long change(long num)
{
	long t=num%10*100;
	t=t+num/10%10*10;
	t=t+num/100;
	if(num/1000)
		t=t*1000+num/1000;
	return t;
}

long digital_arithmetic(long n1)
{
	long n2=change(n1);
	long n3=abs(n1-n2);
	while(n3<100)	
		n3=n3*10;
	long n4=change(n3);
	long n5=n3+n4;
	return n5;
	
}
int fun(int a[ ],int b[ ], int n)
{
	int count=0,i;
	for(i=0;i<n;i++)
	{
		if(a[i]%10!=a[i]/100&&digital_arithmetic(a[i])==1089)
			b[count++]=i;
	}
	return count;
}

main()
{
	int a[N]={123,765,1,45,121,1345,131,67,696,3589},b[N],n,i;
  	n=fun(a,b,10);
 	 for(i=0;i<n;i++)
  	    printf("%5d",a[b[i]]);
}
