/*题型1:素数问题
    2009年三月考题:
    程序功能：找出7个默森尼数。法国数学家默森尼曾提出下列公式：Mp=2^p-1。当p是素数并且Mp也是素数时，称Mp为默森尼数，例如，p=5，Mp=2^5-1=31，5和31都是素数，因此31是默森尼数；而Mp=2^11-1=2047,11是素数,2047不是素数，因此2047不是默森尼数。
      [编程要求]
（1）编写函数void Mersenne(long a[ ],int m),其功能是求出前m个默森尼数并以此将它们保存到a指向的数组中。        
（2）编写main函数，调用Mersenne函数并保存前7个默森尼数，将运行结果输出到屏幕。
      【测试数据与运行结果】
      3   7   31  127  8191  131071  524287*/
#include <stdio.h>
#include<math.h>
#define N 7
int prime(long n)               /*本函数的功能是判定素数*/
{
	long j;
	for( j=2 ; j<=sqrt(n) ; j++ )
		if(n%j==0)
			return false;
	return true;
}
void Mersenne(long a[ ],int m)
{
	long num=2;
	int count=0;
	do
	{
		if(prime(num))
		{
			int Mer_num=pow(2,num)-1;
			if(prime(Mer_num))
				a[count++]=Mer_num;
		}
		num++;
	}while(count<N);
	
}

main()
{
	long a[7];
	int i;;
	Mersenne(a,N);
	for(i=0;i<N;i++)
		printf("%8ld",a[i]); 
}
