#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int my_atoi(const char* str)
{
	int num=0;	//保存转换后的数值
	int isNegative=0;	//记录是否有-号

	int n=0;
	const char *p=str;
	if(p==NULL)
	{
		printf("传入字符串为空\n");
		return -1;
	}
	
	while( *p++ != '\0' )
		n++;
	
	
	//重新指向字符串
	p=str;
	if( p[0] == '-' )
		isNegative=1;
	
	char temp='0';
	for(int i=0; i<n; i++)
	{
		char temp=*p++;
		if(temp > '9' || temp < '0')
			continue;
		if(num!=0 || temp!='0')
		{
			temp-=0x30;	//字符传为数值
			num+= temp*(pow(10,n-1-i));	//位数
		}
	}
	
	if(isNegative)
		return (0-num);
	else
		return num;
}

int my_itoa(int value, char* str,int radix)
{
	char buf[100]={0};
	char zm[17]="0123456789abcdef";
	
	char *p=str;
	if(p==NULL)
	{
		printf("传入字符串为空\n");
		return -1;
	}
	
	if(radix==2 || radix==8 || radix==10 || radix==16)
	{
		printf("---%d进制\n",radix);
	}
	else
	{
		printf("只支持2,8,10,16进制\n");
		return -1;
	}
		
	int num=value;
	//判断是否为负数
	int isNegative=0;
	if( num < 0 )
		isNegative=1;
	
	int i=0;
	while(num>0)
	{
		buf[i++]=zm[num%radix];
		num/=radix;
	}
	
	for(int j=i-1; j>=0; j--)
	{
		*p++=buf[j];
	}
	*p='\0';
	
	return 1;
}

int main(int argc,char *argv[])
{
	int ret=my_atoi("10010");
	printf("ret:%d\n",ret);
	
	int num=123666;
	char *p=malloc(100);
	my_itoa(num,p,16);
	printf("%s\n",p);
	p=NULL;
	free(p);
	
	
}




