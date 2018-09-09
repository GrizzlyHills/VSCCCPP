#include <iostream>
#include <cstring>
using namespace::std;

struct student{
    int id_num;
    char name[10];
    student *next;
};

student *creat()
{
    student *head,*temp;
    int num,n = 0;
    char NAME[10];
    head = new student;
    temp = head;
    cin >> num >> NAME;
    while(num != -1){
        n++;
        temp->id_num = num;
        strcpy(temp->name,NAME);
        temp->next = new student;
        temp = temp->next;
        cin >> num >> NAME;
    }

    if(n == 0){
        head = NULL;
    }else{
        //delete temp;                             //该方法并不能删除掉该节点，怎么办？
        temp->id_num = num;
        strcpy(temp->name,NAME);
        temp->next = NULL;
    } 
    return head;
}

int main()
{
    student *stuLink = creat();
    student *temp = stuLink;
    while(temp){
        cout << temp->id_num << " " << temp->name << endl;
        temp = temp->next;
    }
    delete stuLink;
    system("pause");
    return 0;
}