/*����:���ִ�������
    ����merge�Ĺ�����:�ϲ������ַ�������Ϊһ���¼��ϣ�ÿ���ַ������¼����н�����һ�Σ����������¼������ַ����ĸ�����
    ���������������н����
     ��������:
     s1����:{��while��,��for��,��switch��,��if��,��break��,��continue��}
     s2����:{��for��,��case��,��do��,��else��,��char��,��switch��}
     ���н��:*/
      //while  for  switch  if  break   continue  case  do  else  char
#include <stdio.h>
#include <string.h>
int merge(char s1[ ][10],char s2[ ][10],char s3[ ][10],int m,int n)
{
	int i,j,count=0;
	for(i=0;i<m;i++)
		strcpy(s3[count++],s1[i]);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			if(strcmp(s1[j],s2[i])==0)
				break;
		if(j>=m)
			strcpy(s3[count++],s2[i]);
	}
		
		
			
	return count;
}

main()
{
	int i,j;
	char s1[6][10]={"while","for","switch","if","break","continue"},
	s2[6][10]={"for","case","do","else","char","switch"},s3[20][10];
	j=merge(s1,s2,s3,6,6);
	for(i=0;i<j;i++)
	    printf("%s  ",s3[i]);
}
