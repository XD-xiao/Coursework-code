/*�������ܡ�
����������ȷ�����������1900-9999��Χ�ڣ����㲢�����������֮���������������磺2008-8-1��2009-8-1֮����������Ϊ365��
��ʾ���ܱ�4�������Ҳ��ܱ�100��������������꣬�ܱ�400���������Ҳ�����꣬�����������ƽ�ꡣ
�����Ҫ��
��1����д����int days()��������������int mon[2][13] ={{0,31,28,31,30,31,30, 31,31,30,31,30,31},{0,31,29,31,30,31,30, 31,31,30,31,30,31}};�ͷ���d1��d2֮��������
��2����дmain����������days�������1980-2-1��2009-8-1֮����������������������Ļ��
���������������н����
��ʾ��first date:����1980-2-1
��ʾ��second date:����2009-8-1
�����10774 days*/
#include<stdio.h> 
//ʱ�����㺯��
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
	printf("�����뿪ʼ����(yyyy/MM/dd)��");
	scanf("%d/%d/%d",&yearst,&monthst,&dayst);
	printf("�������������(yyyy/MM/dd)��");
	scanf("%d/%d/%d",&yearend,&monthend,&daystend);
	total = (yearend - yearst)*365;//�����������ݵ�������
	total -= days(yearst,monthst,dayst);//��ȥ��ʼ���ڵ�����
	total += days(yearend,monthend,daystend);//�����ѹ����ڵ�����
	 i = yearst;
	while(i != yearend)//�ж��Ƿ�����
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
	printf("%d��%d��%d����%d��%d��%d�������%d��\n",yearst,monthst,dayst,yearend,monthend,daystend,total);
	return 0;

}


