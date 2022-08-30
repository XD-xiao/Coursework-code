/*4、【编程要求】
（1）编写函数void squeeze(char s1[],char s2[],char s3[])，
其功能是：从s1指向的字符串中删去所有在s2指向的字符串中已出现的字符，
将从s1中删除的字符保存到s3指向的数组中。
（2）编写main函数。用给定的测试字符串s1和s2调用squeeze函数，
将处理后的s1字符串和s3字符串保存到结果文件myf2.out中。
	测试数据：s1:“abbcdefgghiijkl”,s2:“bdglkw”
	运行结果：s1: acefhiij, s3:bbdggkl
*/
#include<string.h>
#include<stdio.h>
#define M 63
void squeeze(char s1[],char s2[],char s3[])
{
	int i,j,k,n=0,m;
	m=strlen(s1);
	for(i=0;s2[i];i++)
		for(j=0;s1[j];j++)
			if(s1[j]==s2[i])
			{
				s3[n++]=s1[j];
				for(k=j;s1[k];k++)
					s1[k]=s1[k+1];
				j--;
			}
}

main()
{
	char s1[M]="abbcdefgghiijkl";
	char s2[M]="bdglkw";
	char s3[M];
	squeeze(s1,s2,s3);
	printf("s1:%s\n",s1);
	printf("s3:%s\n",s3);
	FILE *fp;
	fp=fopen("myf2.out","w");
	fprintf(fp,"%s\n",s1);
	fprintf(fp,"%s\n",s3);
	fclose(fp);
}


