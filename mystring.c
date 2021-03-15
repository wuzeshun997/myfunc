#include <stdio.h>

//功能：计算给定字符串的长度，不包括'\0'在内
int mystrlen(const char* str)
{
	if(str == NULL)
		return -1;
	
	int len=0;
	while( (*str++) != '\0' )
		len++;
	
	return len;
}


/**
*	功能:字符串复制函数,strcpy把含有'\0'结束符的字符串
*	复制到另一个地址空间，返回值的类型为char*
*/
char *mystrcpy(char* strDes,const char* strSrc)
{
	if( strDes==NULL || strSrc==NULL )
		return NULL;
	
	char *p=strDes;
	while( (*strDes++ = *strSrc++) != '\0' )
	
	return p;
}


/**
*	功能:strstr(str1,str2) 函数用于判断字符串str2是否是str1的子串。
*	如果是，则该函数返回str2在str1中首次出现的地址；否则，返回NULL。
*/
int mystrstr(char* string,char* substring)
{
	if( string==NULL || substring==NULL )
		return -1;
	
	int lenstr=mystrlen(string);
	int lensub=mystrlen(substring);
	
	if(lenstr<lensub)
		return -1;
	
	int i,j;
	for(i=0; i<lenstr-lensub; ++i)
	{
		for(j=0; j<lensub; ++j)
		{
			if(string[i+j] != substring[i])
			break;
		}
		if(j==lensub)
			return i;
	}
	
	return -1;
}


/**
*	功能:把src所指向的字符串（包括“\0”）复制到dest所指向的字符串后面
*	（删除*dest原来末尾的“\0”）。要保证*dest足够长，
*	以容纳被复制进来的*src。*src中原有的字符不变。返回指向dest的指针。
*/
char *mystrcat(char* strDes,const char* strSrc)
{
	if( strDes==NULL || strSrc==NULL )
		return NULL;
	
	char *p=strDes;
	
	while(*strDes != '\0');
		*strDes++;
	while(*strSrc != '\0')
		*strDes++=*strSrc++;
	
	*strDes='\0';
	return p;
}


/**
*	功能:对两个字符串进行比较,
*	若s1、s2字符串相等，则返回零；
*	若s1大于s2，则返回正数;
*	否则，则返回负数。
*/
int mystrcmp(const char* str1, const char* str2) 
{
	if( str1==NULL || str2==NULL )
		return -1;
	
	int ret = 0;
	
	//ret=0,相等,相等时要确定两个字符不为'\0';  ret!=0时,循环结束,判断ret值
	while( !(ret = *(unsigned char*)str1 - *(unsigned char*)str2) && *str1 ) 
	{
		str1++;
		str2++;
	}
 
	if(ret > 0)
		return 1;
 
	else if(ret < 0)
		return -1;
 
	return 0;
}


/**
*	功能:将str指向地址为起始地址的连续n个字节的数据复制到
*	以dest指向地址为起始地址的空间内,函数返回一个指向dest的指针.	
*/

void* mymemcpy(void *dest, const void *src, size_t n) {
	if(dest == NULL || src == NULL)
		return NULL;
 
	char* pdest = (char*)dest;
	char* psrc = (char*)src;
 
	while(n--)
		*pdest++ = *psrc++;
 
	return dest;
}


int main(int argc,const char* argv[])
{
	
} 