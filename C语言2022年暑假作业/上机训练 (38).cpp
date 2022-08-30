/*7、亲密数和亲数
【程序功能】
    如果a的因子和等于b，b的因子和等于a，（因子或称真因子是指包括1但
	不包括本身的数），且a不等于b，则称a，b为亲密数对。
	要求编程求出四位数1000-3000的相应的亲密数对。
【编程要求】
    （1）编写函数int Relation(int a[][2], int m1, int m2)。
	函数返回四位数的亲密数的对数，亲密数对存放在二维数组a[][2]返回。
    （2） 编写main函数，定义整型数组int b[10][2]，整型量n1,n2；在
	键盘输入n1和n2后调用Relation函数求出1000-3000数之间的亲密数对b[][2]，
	并输出到屏幕。
【测试数据与运行结果】
输入数据：1000，3000
输出数据：(1184,1210)
          (2620,2924)*/
#include<stdio.h>
#include<math.h>
//运算量大，稍等后出结果 
int factorsum(int x)
{	
	int sum=0;
	for(int j=1;j<x;j++)
		if(x%j==0)
			sum+=j;
	return sum;
}
 int Relation(int a[][2], int m1, int m2)
{
	int count=0;
	for(int i=m1;i<=m2;i++)
		for(int j=m1;j<=m2;j++)
		{
			if(i!=j&&i==factorsum(j)&&j==factorsum(i))
				a[count][0]=i,a[count++][1]=j;
			
		}
	return count ;
}
main()
{
	int n1,n2;
	printf("Input n1~n2:");
	scanf("%d%d",&n1,&n2);
	int a[90][2];
	int len =Relation(a, n1, n2);
	for(int i=0;i<len;i++)
		printf("%3d,%3d\n",a[i][0],a[i][1]);
}

