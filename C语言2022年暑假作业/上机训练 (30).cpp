/*8、改错题
【题目】输入字符串s1和s2,函数find()判断s1中
是否包含字符串s2,若s1包含s2,则输出字符串s2在s1中的
开始位置，否则输出”No substring!”。
含有错误的源程序为：*/
#include<stdio.h>
#include<string.h>
/****************FOUND**************/ 
int find(char s1[],char s2[])
{   int i=0,j,k=0;
while(s1[i]){
/****************FOUND**************/
        j=0,k=i;			//没有改 
        while(s1[i]==s2[j]) {
			i++;
			j++;
		}
/****************FOUND**************/
        if(s2[j]==0) return(k);
		i++;
    }
    return(-1);
}

main()
{   int i;
    char s1[200],s2[100];
    gets(s1);gets(s2);
    i=find(s1,s2);
    if(i==-1)
        printf("s1=%s  s2=%s\n No substring!\n",s1,s2);
    else
        printf("s1=%s  s2=%s\n starting pos of substring is %d\n",s1,s2,i);
}
