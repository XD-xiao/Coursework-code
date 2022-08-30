/*4、改错题
【题目】N个有序整数列已放在一维数组中，
下列给定程序中函数fun的功能是：
利用折半查找算法查找整数m在数组中的位置。
若找到，则返回其下标值，反之，则返回－1。
提示：折半查找的基本算法是：
每次查找前先确定数组中待查的范围，low和high，
然后把m与中间位置（mid）中元素的值进行比较，
如果m的值大于中间位置元素中的值，
则下一次的查找范围放在中间位置之后的元素中，
反之，下一次的查找范围落在中间位置之前的元素中。
直到low<high，查找结束。*/
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
printf ("a数组中的数据如下：");
      for (i=0; i<N; i++)  printf ("%d", a[i]);
      printf("Enter m: ");  scanf("%d",&m);
      k=fun(a, m);
      if (k>=0) printf("m=%d,index=%d\n", m,k);
      else printf ("Not be found!\n");
}
