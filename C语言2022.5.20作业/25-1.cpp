/*1���������ܡ�
���Ҳ����ͬʱ���ֵ�����һά�����е�������
ÿ��һά�����е�Ԫ�ؾ��Ѱ�ֵ�������У�
����ÿ�������е�Ԫ��û����ͬ��ֵ��
����int coincidence_count(int a[],int b[],int m,int n,int c[])
������Ҫ����aָ�������ǰm��Ԫ�غ�bָ�������ǰn��Ԫ���в��ң�
���ҵ����������浽cָ��������С�
�������ݣ�
	a�����е����ݣ�1��2��4��8��10��12��13��14��16��18
	b�����е����ݣ�3��4��7��8�� 9��10��12��13��16��19
	���н����
		No.		Array 1		Array 2
		0  			1			3
		1  			2			4
		2  			4			7
		3		  	8			8
		4			10			9
		5			12			10
		6			13			12
		7			14			13
		8			16			16
		9			18			19
There are 6 equal numbers:4  8  10  12  13  16
*/
#include <conio.h>
#include <stdio.h>
int coincidence_count(int a[],int b[],int m,int n,int c[])
{   int count,ia,ib;
    count=ia=ib=0;
    while(ia<m||ib<n)
        if(a[ia]<b[ib])
            ia++;
/***************FOUND******************/
        else  if(a[ia]>b[ib])
            ib++;
        else
/***************FOUND******************/
        {   c[count++]=a[ia];
            ia++;
            ib++;
        }
    return count-1;
}
main()
{   int a[]={1,2,4,8,10,12,13,14,16,18},b[]={3,4,7,8,9,10,12,13,16,19};
    int c[10],i,na,nb,n;
    na=sizeof(a)/sizeof(int);
    nb=sizeof(b)/sizeof(int);
    printf("\n  Coincidence Count of two Increasing Arrays\n");
    printf("\n No.  Array 1 Array 2");
    for(i=0;i<na;i++)
/***************FOUND******************/
        printf("\n%3d%10d%10d",i,a[i],b[i]);
    printf("\n There are %d equal numbers:",n=coincidence_count(a,b,na,nb,c));
    for(i=0;i<n;i++)
        printf("%5d",c[i]);
}
