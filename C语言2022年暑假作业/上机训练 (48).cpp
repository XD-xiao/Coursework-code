/*9������������
�������ܡ�
��֤��3-2008֮������������д���������������������֮��Ϊ2008��
�����Ҫ��
(1)��д����int fun( int n, int *a, int *b)���书������3~n֮��Ѱ��һ������,���ǵĺ͵���n�����ҵ������������ֱ𱣴浽a,bָ��ı����У���������1�����Ҳ�������������0��
(2)��дmain��������������n���ò������ݳ�ʼ��������fun�����ҳ�3~n֮���ֵΪn��һ�����������ҵ�����������������Ļ��
���������������н����
�������ݣ�n=2008
���н����a=5     b=2003    a+b=2008*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
int prime(int n)
{  
	int i;         
    if(n==1) return false;  
    for(i=2;i<=sqrt(n);i++)
		if(n%i==0)  return false;
	    return true;

}
int fun( int n, int a[])
{   
	int i,j;
	for( i=2 ; i<n/2 ; i++ )
	{
		if(prime(i)&&prime(j=n-i))
		{
			a[0]=i;
			a[1]=j;
			return 1;
		}
	}
	return 0;
}
main()
{   int p,x[2];
    printf("Input p="); scanf("%d",&p);
    if(fun(p,x)==1)
		   printf("n=%d\na=%-6db=%-6da+b=%-6d\n ",p,x[0],x[1],x[0]+x[1]);  	
else 
	       printf("Not be found!\n "); 
}
