#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>

#define N 80

int GenStr(char s[],int a[]) 
{
/**********Program**********/
int i=0,j,p,k=0,t,b=0,max;
for(i=0;i<strlen(s)-1;i++)
{
	b=0;
	p=s[i]+s[i+1];
	t=p;
	int c[10];
	while(p)
	{
		c[b++]=p%10;
		p=p/10;
	}
	max=0;
	for(j=0;j<b;j++)
		if(c[j]>max)
			max=c[j];
	max++;
	p=0;
	j=1;
	while(t)
	{
		p=p+t%10*j;
		j=j*max;
		t=t/10;
	}
	a[k++]=p;
	
}
return k;
/**********  End  **********/
}

int Calculate(int a[], int n,int b[][2])
{
/**********Program**********/
int i,j,k=0,x,y,r,p;
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
		x=a[i];
		y=a[j];
		r=x%y;
		while(r)
		{
			x=y;
			y=r;
			r=x%y;
		}
		if(y==1)
		{
			b[k][0]=a[i];
			b[k++][1]=a[j];
			for(p=0;p<k;p++)
				if(b[k-1][1]==b[p][0])
					break;
			if(p<k)
				k--;
		}
	}
}
return k;
/**********  End  **********/
}

int main() 
{
    char s[]="c1F2k";
    int a[N]= {0},b[N][2]= {0};
    int num=0,i=0,n;

    FILE *fp;
    if((fp=fopen("DATA.dat","w"))==NULL) 
    {
        printf("File open error\n");
        exit(0);
    }
    num=GenStr(s,a);
    printf("The string s is: %s\n",s);
    fprintf(fp,"The string s is: %s\n",s);
    for(i=0; i<num; i++)
        printf("%d  ",a[i]);
    printf("\n");
    n= Calculate(a,num,b);
    for(i=0; i<n; i++) 
    {
        printf("%3d  %3d\n",b[i][0],b[i][1]);
        fprintf(fp,"%3d  %3d\n",b[i][0],b[i][1]);        
    }
}

