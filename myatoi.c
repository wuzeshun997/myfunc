#include <stdio.h>
#include <math.h>


int myatoi(const char* str)
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

int main(int argc,char *argv[])
{
	
	int ret=myatoi("10010");
	printf("ret:%d\n",ret);
}




