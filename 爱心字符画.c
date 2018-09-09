#include "stdio.h"
#define x '\3'
#define y ' '
int main(void){
    char a[][14]={{y,y,y,y,y,y,y,y,y,x,y,y,y,'\0'},{y,y,y,y,y,y,y,x,x,x,x,y,y,'\0'},
    {y,y,x,x,x,x,x,y,y,y,y,y,y,'\0'},{y,y,x,y,y,y,y,y,y,y,y,y,y,'\0'},
    {y,y,x,y,y,y,x,y,y,y,y,y,y,'\0'},{y,x,y,y,y,y,x,y,y,y,y,y,y,'\0'},
    {y,x,y,y,y,y,x,y,y,y,y,y,y,'\0'},{y,x,x,x,x,x,x,x,x,x,x,x,x,'\0'},
    {y,y,y,y,y,y,x,y,y,y,y,y,y,'\0'},{y,y,y,x,y,y,x,y,y,x,y,y,y,'\0'},
    {y,y,y,x,y,y,x,y,y,y,x,y,y,'\0'},{y,y,x,y,y,y,x,y,y,y,y,x,y,'\0'},
    {y,x,y,y,y,y,x,y,y,y,y,y,x,'\0'},{x,y,y,y,y,y,x,y,y,y,y,y,x,'\0'},
    {y,y,y,y,x,y,x,y,y,y,y,y,y,'\0'},{y,y,y,y,y,x,y,y,y,y,y,y,y,'\0'}
    },i;
    for(i=0;i<16;printf("%s\n",a[i++]));
    printf("\n");
    getchar();
    return 0;
}