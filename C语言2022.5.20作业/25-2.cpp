/*2、【编程要求】
（1）编写函数int findword(char s[],char t[],char ch[][20])。
函数功能：在由若干句子组成的字符串s中搜索包含字符串t的所有单词，
将这些单词存放在数组ch中，函数返回找到的单词格式。
称字符串s为“被搜索字符串”，字符串t为“搜索字符串”。
（2）编写main函数。函数功能：声明数组s和t，
用被搜索字符串和搜索字符串初始化这两个数组。
调用函数findword对给定的测试数据进行检索，
并将检索到的包含字符串t的所有单词及单词的个数。
【测试数据及运行结果】
	被搜索字符串：No living man all things can. Graspall,loseall.
	搜索字符串：all
	检索结果：all,Graspall,loseall. 3*/
#include<stdio.h>
#include<ctype.h>
#define N 40
#define M 20
int findword(char s[],char t[],char ch[][20])
{
	int i=0,str_j,t_j,sign,n=0;
	while(s[i])
		if(isalpha(s[i]))
		{
			sign=str_j=t_j=0;
			while(isalpha(s[i]))
			{
				ch[n][str_j]=s[i++];
				if(ch[n][str_j++]==t[t_j])
					t_j++;
				else
					t_j=0;
				if(t[t_j]==0)
					sign=1;
			}
			ch[n][str_j]=0;
			if(sign)
				n++;
		}
		else
			i++;
	return n;
}

main()
{
	int i=0,n=0;
	char str[N][M],s[N*M]="No living man all things can. Graspall,loseall.",t[M]="all";
	n=findword(s,t,str);
	for(i=0;i<n;i++)
		printf("%s,",str[i]);
	printf("\b.%2d",n);
}



