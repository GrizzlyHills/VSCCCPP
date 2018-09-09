#include <stdio.h>

typedef struct student  //名字为student的结构体类型
{
int id;         //声明学号为int型
char name[20];  //声明性别为字符数组
char sex;       //声明性别为字符型 
int age;        //声明年龄为整形
float score;    //声明成绩为实型
char addr[30];  //声明地址为字符数组
}Student;              //注意大括号后的";"

int main()
{
    Student s1,s2;                   //区别在于C中要用 typedef 创建结构体变量类型
    s1 = {1,{'一','\0'},'M',18,99.9,{'G'}};
    //cout << s1.id << endl << s1.name << endl << s1.sex << endl << s1.age << endl << s1.score << endl << s1.addr << endl;
    printf("hello world!\n");
    return 0;
}