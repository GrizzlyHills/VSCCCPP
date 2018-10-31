

// 注意 const 的用法 ，不然报错



/*
    请实现一下函数
    函数原型：char *strstr(const char *s1, const char *s2)
    作用：判断字符串s2是否是s1的子串，如果是，则该函数返回s2在s1中首次出现的地址。否则，返回NULL。
*/
#include <stdio.h>
#include <string.h>

const char* mystrstr1(const char* dest, const char* src) {
	const char* tdest = dest;
	const char* tsrc = src;
	
	while (*tdest)
	{
		const char* flag = tdest;//设置标志位，方便回滚。
		while (*tdest == *tsrc && *tdest!='\0') {//开始进行比较，如果第一个字符相等，继续循环比较下一个字符。
			tdest++;
			tsrc++;
		}
		//上面循环完毕，有如下3种情况
		if (!*tsrc) {
			//tsrc已经到达\0位置，说明在dest中已经找到 子字符串，唯一找到字串的出口。
			return flag;//返回找到子串的起始位置。
		}
		if(!*tdest){
			//走到这里，tdest到达\0 而tsrc没有到达\0，没有找到
			return NULL;
		}
		//走到这里，没有匹配成功，继续从下一位开始匹配整个子串
		tdest++;
	}
	return NULL;
}

// 上面这函数好理解，但是用了2层循环，使用朴素的匹配模式算法只需要 1层循环。下面是改进后的方法。
/*
strstr 实现
第二种方法 朴素的模式匹配算法 ，只用一个外层循环
*/
const char* mystrstr2(const char* dest, const char* src) {
	const char* tdest = dest;
	const char* tsrc = src;
	int i = 0;//tdest 主串的元素下标位置，从下标0开始找，可以通过变量进行设置，从其他下标开始找！
	int j = 0;//tsrc 子串的元素下标位置
	while (i <= strlen(tdest) - 1 && j <= strlen(tsrc)-1)
	{
		if (tdest[i] == tsrc[j])//字符相等，则继续匹配下一个字符
		{
			i++;
			j++;
		}
		else//在匹配过程中发现有一个字符和子串中的不等，马上回退到 下一个要匹配的位置
		{
			i = i - j + 1;
			j = 0;
		}
	}
	//循环完了后j的值等于strlen(tsrc) 子串中的字符已经在主串中都连续匹配到了
	if (j == strlen(tsrc))
	{
		return tdest + i - strlen(tsrc);
	}
	return NULL;
}


int main()
{
    const char *s1 = "abcdef";
    const char *s2 = "cd";

    puts(mystrstr1(s1, s2));
    puts(mystrstr2(s1, s2));
    getchar();
    return 0;
}