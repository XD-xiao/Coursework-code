/*----------------------------------------------------------------------
��������ơ�
------------------------------------------------------------------------
��Ŀ����֪��str�Ǵ������λ16���������ַ��������ô��е�ʮ�������ִ���ȡ
      ����ת��Ϊʮ���������浽num�����С�����һ��������Ŀ��ֵobj���ҳ�
      num���������������ɸ�Ԫ��ֵ֮�͵���obj�������С�
      
���磺str[]="11a,41,1B,1a,5c,a7"
      ��ȡʮ����������ת�����numֵΪ�� num[]={282,65,27,26,92,167}
      ��������Ŀ��ֵobj=118, �� 
      num�д��±�1���±�3�ʹ��±�3���±�4������Ԫ��ֵ֮�͵���obj�� 

�������н���ǣ� 
      ��str[N]=11a,41 ,1B, 1a,5c,a7 ����ȡ����ֵ�У�282 65 27 26 92 167
      Ŀ��ֵΪ:118
      �ҵ����������������й���2�顣
      ��1����������������Ϊ��65 27 26
      ��2����������������Ϊ��26 92

1.��д����void change(char str[],int num[])����str������ʮ�����������ַ���
  ȡ����ת��Ϊʮ������������num�����С���ȡ����������ȡ������֮��׷����
  ֵ-1��ʾ������    
2.��д����int sum(int num[],int result[][2], int obj)����num���ҳ�����Ԫ��
  ֮�͵���Ŀ��ֵobj��ÿ�ֿ����ԣ�������ʼ�±����ֹ�±�ֱ𱣴���result��
  ��һ�к͵ڶ����У����������ܹ����Ŀ��ֵ���ܸ�����
---------------------------------------------------------
ע�⣺����Ķ�������main()�е��κ���䡣
-------------------------------------------------------*/
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define N 100

void change(char str[],int num[]) 
{
/**********Program**********/
	int number=0,count=0,bit;
	
	for(int i=0 ; str[i] ; i++)
	{
		if(str[i]==' ')
			i++;
		if(str[i]==0)
			break;
		if(isdigit(str[i]))
			bit=str[i]-'0';
		else if(isupper(str[i]))
			bit=str[i]-'A'+10;
		else if(islower(str[i]))
			bit=str[i]-'a'+10;
		else if(str[i]==',')
		{
			num[count++]=number;
			number=0;
			continue;
		}
		number=number*16+bit;
	}
	num[count++]=number;
	num[count]=-1;

/**********  End  **********/
}

int sum(int num[], int result[][2], int obj)
{
/**********Program**********/
	int count=0;
	for(int start=0 ; num[start+1]!=-1 ; start++)
	{
		int sum=0;
		for(int end=start ; num[end]!=-1 ; end++)
		{
			if(sum<obj)
				sum+=num[end];
			else if(sum>obj)
				break;
			else
			{
				result[count][0]=start;
				result[count++][1]=end-1;
				sum=0;
			}
		}
	}
	
	return count;
/**********  End  **********/
}

int main() 
{    
    char str[N]="11a,41 ,1B, 1a,5c,a7 ", obj = 118;
    int  num[N], result[N][2];    
    int i,j,val,s,re,n;
    FILE *fp;
    if((fp=fopen("DATA.dat","w"))==NULL)
    {
        printf("File open error\n");
        return 0;
    }    
    change(str,num);
    printf("��str[N]=%s����ȡ����ֵ�У�",str);     
    fprintf(fp,"��str[N]=%s����ȡ����ֵ�У�",str);     
    for(re=0; num[re]!=-1; re++)
    {
        printf("%d ",num[re]);
        fprintf(fp,"%d,",num[re]);
    }
    printf("\n");
    fprintf(fp,"\n");    
    printf("Ŀ��ֵΪ:%d\n",obj);   
    n = sum(num,result,obj);
    if (n<0)
    {
        printf("û���ҵ�����������������\n");        
        fprintf(fp, "û�ҵ�\n");        
    }
    else
    {
        printf("�ҵ����������������й���%d�顣\n",n);    
        for(i=0; i<n; i++)
        {
            printf("��%d����������������Ϊ��",i+1);
            for (s = result[i][0]; s<= result[i][1]; s++) 
            {
                printf("%d ",num[s]);                
                fprintf(fp,"%d; ",num[s]); 
            }
            printf("\n");           
        }
    } 
    fclose(fp);
    return 0;
}
