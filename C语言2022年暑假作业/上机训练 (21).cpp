/*1、完善程序
程序功能：某人有5张1块，3张2块和4张3块的游戏币，求解使用这些游戏币能组合出多少种不同面值的游戏活动。
运行结果：
24 kinds:
0,3,6,9,12,2,5,8,11,14,4,7,10,13,16,15,18,1,17,19,20,21,22,23,
	待完善的源程序*/
#include<stdio.h>
#include<conio.h>
int getZuhe(int a[])
{
int i,j,k,m,s,n=0;
for(i=0;i<6;i++)
for(j=0;j<6;j++)
    for(k=0;k<5;k++){
       s=  i+j*2+k* 3  ;
       for(m=0;m<n;m++)
          if(s==a[m])break;
      if( m>=n &&s<=23 )a[n++]=s;
    }
return n;
}
main()
{
int k,kind;
int a[120]={0};
kind=getZuhe(a);
printf("\n%d kinds:",kind);
for(k=0; k<kind    ;k++)
        printf("%4d,",a[k]);
}
