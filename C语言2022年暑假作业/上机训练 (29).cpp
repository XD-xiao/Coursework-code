/*7�������
����Ŀ��
(1)��дһ������void fun (int array[ ], int n)��
��array�����е�ǰn���������Ӵ�С��˳������
(2)��д������main���Ӽ���������һ����������
�����λ�Ǽ�λ�����������ҵ�˳����ʾ��λ���֣�
����Щ�������һ����С������������fun��������
�������������������Ļ�ϡ�*/
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
