/*----------------------------------------------------------------------
������Ĵ�
------------------------------------------------------------------------
��Ŀ����һ��8λ��������ʾ���ڣ�����ǰ4λ��ʾ�꣬�м�2λ��ʾ�£����2λ��ʾ�ա�
���磺20170901��ʾ2017��9��1��
      20200510��ʾ2020��5��10��
      ���������������֮��������� 
      �������н��Ϊ��
      20170901-20200510����983��

------------------------------------------------------------------------
ע�⣺�������л�ɾ�У�Ҳ���ø��ĳ���Ľṹ��
----------------------------------------------------------------------*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>

int valid_date(int date)
{
    int year,month,day;
    int mon[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    year=date/10000;
    month=date/100%100;
    day=date%100;
    if(month>12)
        return 2;
/***********FOUND***********/
    mon[1]+=(year%4==0&&year%100!=0||year%400==0);
/***********FOUND***********/
    return day>mon[month-1];
}

int main()
{
    int first=20170901,last=20200510,date;
    int year,month,day,val,days;
    for(days=0,date=first;date<=last; )
    {        
        year=date/10000;
        month=date/100%100;
        day=date%100;
        val=valid_date(date);
        if(val==0)
        {
            ++days;
            ++date;
        }
        else if(val==1)
            date=year*10000+(month+1)*100+1;
        else if(val==2)
/***********FOUND***********/
            date=(year+1)*10000+101;
    }
    printf("%u-%u����%d��\n",first,last,days);
    return 0;
}
