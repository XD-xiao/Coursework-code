/*【程序功能】
输入两个正确日期且年份在1900-9999范围内，计算并输出两个日期之间间隔的天数。例如：2008-8-1和2009-8-1之间间隔的天数为365。
提示：能被4整除并且不能被100整除的年份是闰年，能被400整除的年份也是闰年，其他年份则是平年。
【编程要求】
（1）编写函数int days()。函数定义数组int mon[2][13] ={{0,31,28,31,30,31,30, 31,31,30,31,30,31},{0,31,29,31,30,31,30, 31,31,30,31,30,31}};和返回d1与d2之间天数。
（2）编写main函数，调用days函数求出1980-2-1到2009-8-1之间的天数，并将此输出到屏幕。
【测试数据与运行结果】
显示：first date:输入1980-2-1
显示：second date:输入2009-8-1
输出：10774 days*/
#include<stdio.h> 
//时间差计算函数
days(int year,int month,int day){
	int sum = 0;
	int i;
	int months[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	for(i = 0; i < month; i++)
		sum += months[i];
	sum += day;
	if((year%4 == 0 && year%100 != 0 || year%400 == 0) && month >= 3)
		sum += 1;
	return sum;
}

int main(){
	int yearst,monthst,dayst;
	int yearend,monthend,daystend;
	int total=0;
	int i;
	printf("请输入开始日期(yyyy/MM/dd)：");
	scanf("%d/%d/%d",&yearst,&monthst,&dayst);
	printf("请输入结束日期(yyyy/MM/dd)：");
	scanf("%d/%d/%d",&yearend,&monthend,&daystend);
	total = (yearend - yearst)*365;//相差两日期年份的总天数
	total -= days(yearst,monthst,dayst);//减去开始日期的天数
	total += days(yearend,monthend,daystend);//加上已过日期的天数
	 i = yearst;
	while(i != yearend)//判断是否闰年
	{
		if(total>0){
		if(i%4 == 0 && i%100 != 0 || i%400 == 0)
			total+=1;
		    i++;
		}else{
			if(i%4 == 0 && i%100 != 0 || i%400 == 0)
		    i--;
		}
	}
	printf("%d年%d月%d日与%d年%d月%d日相差了%d天\n",yearst,monthst,dayst,yearend,monthend,daystend,total);
	return 0;

}


