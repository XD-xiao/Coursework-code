/*1、函数fun的功能是：输出M行M列整数方阵，
然后求两条对角线上各元素之和，返回此和数。
含有错误的程序如下：*/ 
#include <conio.h>
#include <stdio.h>
#define  M   5
/****************FOUND**************/
int  fun(int n,int xx[][M])
{ 
/****************FOUND**************/
int i,j,sum=xx[n/2][n/2];
  printf("\nThe %d x %d matrix:\n",M,M);
  for(i=0;i<M;i++)
  {  for(j=0;j<M;j++)
      printf("%d",xx[i][j]);
     printf("\n");
  }
  for(i=0;i<n;i++)
/****************FOUND**************/
	if(i!=n-i-1)	sum+=xx[i][i]+xx[i][n-i-1];
  return(sum);
}
main( )
{  int aa[M][M]={ {1,2,3,4,5},{4,3,2,1,0},
{6,7,8,9,0},{9,8,7,6,5},{3,4,5,6,7}};
   printf ("\nThe sum of all elements on 2 diagnals is %d.",fun(M,aa));
} 
