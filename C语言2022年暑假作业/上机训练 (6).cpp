// 1、改错题
    /*【程序功能】
查找介于n1与n2(0<n1<n2<32768)之间所有满足下列条件的整数:
(1)该数的十进制表示中有且仅有两个相同的数字位;(2)该数是素数。
  【测试数据与运行结果】
    测试数据:n1=900
             n2=1200
    屏幕输出:
    911    919     929    977    991    997    1009    1013
    1019   1021    1031   1033   1051   1061   1091    1103
1109   1123    1129   1153   1163   1187   1193
*/

    #include<stdio.h>
    #include<math.h>
    int validate(int n)
    {  int i,j,k=0,num[5]={0},size=0;
       do
       {  num[size]=n%10;
          n=n/10;
          size++;
/***************FOUND****************/
 }while(n);
       for(i=0;i<size-1;i++)
for(j=i+1;j<size;j++)
           if(num[i]==num[j])
            k=k+1;
      /***************FOUND****************/
if(k==1)
        return 1;
      else
        return 0;
    } 
int prime(int n)
    {  int i;
       for(i=2;i<=(int)sqrt(n);i++)
         if(n%i==0)return 0;
      return 1;
    }
   main()
   {   int i,count=0,n1,n2;
      // scanf("%d%d",&n1,&n2);
      n1=900;       n2=1200;
       for(i=n1;i<=n2;i++)
 { /***************FOUND****************/
if(validate(i)&&prime(i))
           {   count++;
               printf("%d\t",i);
/***************FOUND****************/
               if((count+1)%8==0)printf("\n");
           }
       }
  }
