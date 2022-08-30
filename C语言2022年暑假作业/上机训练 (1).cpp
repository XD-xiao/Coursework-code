/*3、编程题
编程要求：
（1）编写函数double getscore(double score[])，函数形参score指向的数组中存放N个裁判给一个参赛选手的打分。
	函数功能是依据score数组中的分数按上述方法计算一个参赛选手的最后得分，并作为函数返回值返回。
（2）编写函数。函数功能是声明数组score并用测试数据初始化，用score数组作为实参调用getscore函数计算数组score中参赛选手的最后得分，
	将score数组中数据及该选手的最后得分输出到屏幕。
测试数据与运行结果：
测试数据：
   9.47  9.56  9.96  10.00  9.75  9.78  9.95  9.86  9.82  9.18
输出：
   9.47  9.56  9.96  10.00  9.75  9.78  9.95  9.86  9.82  9.18
   last score=9.79*/
#include<stdio.h>
#include<math.h>
double getscore(double score[])
{
	double sum=0;
	for(int i=0 ; i<10 ;i++)
		sum+=score[i];
	return sum/10;
}
main()
{
	double score[10]={9.47, 9.56 ,9.96,10.00 ,9.75 ,9.78, 9.95, 9.86 ,9.82 ,9.18};
	printf("last score = %lf",getscore(score));	//不知道具体计算方法 
}
