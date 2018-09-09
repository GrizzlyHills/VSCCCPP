/*
 * @Author: GrizzlyHills 
 * @Date: 2018-04-16 01:37:54 
 * @Last Modified by:   GrizzlyHills 
 * @Last Modified time: 2018-04-16 01:37:54 
 */

#include<stdio.h>
#define MIN__MY(a,b) ((a)<=(b)?(a):(b))  
  
int main()  
{  
    int arry[5] = {10,20,30,40,50};  
    int *p = &arry[0];  
    printf("%d & %d : MIN = %d, *p = %d\n", arry[1], 10, MIN__MY(*p++, 10), *p);  // 20 & 10 : MIN = 20, *p = 10
	getchar();
    return 0;  
}  