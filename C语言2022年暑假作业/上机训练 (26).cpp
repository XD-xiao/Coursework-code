/*4���Ĵ���
����Ŀ��N�������������ѷ���һά�����У�
���и��������к���fun�Ĺ����ǣ�
�����۰�����㷨��������m�������е�λ�á�
���ҵ����򷵻����±�ֵ����֮���򷵻أ�1��
��ʾ���۰���ҵĻ����㷨�ǣ�
ÿ�β���ǰ��ȷ�������д���ķ�Χ��low��high��
Ȼ���m���м�λ�ã�mid����Ԫ�ص�ֵ���бȽϣ�
���m��ֵ�����м�λ��Ԫ���е�ֵ��
����һ�εĲ��ҷ�Χ�����м�λ��֮���Ԫ���У�
��֮����һ�εĲ��ҷ�Χ�����м�λ��֮ǰ��Ԫ���С�
ֱ��low<high�����ҽ�����*/
#include <stdio.h>
#define  N  10
 /****************FOUND**************/
int fun (int a[ ], int m)   
{    int low=0, high=N-1, mid;
  /****************FOUND**************/     
while (low<=high)
{    mid=(low+high)/2;
         if(m<a[mid])
             high=mid-1;
         else if (m>a[mid])   
             low=mid+1;
 /****************FOUND**************/         
		else
			return (mid);
    }
    return (-1);
 }
main ()
{     int i, a[N]={-3,4,7,9,13,45,67,89,100,180}, k, m;
printf ("a�����е��������£�");
      for (i=0; i<N; i++)  printf ("%d", a[i]);
      printf("Enter m: ");  scanf("%d",&m);
      k=fun(a, m);
      if (k>=0) printf("m=%d,index=%d\n", m,k);
      else printf ("Not be found!\n");
}
