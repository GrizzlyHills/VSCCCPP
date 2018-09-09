/*
描述
约瑟夫问题：有N只猴子，按顺时针方向围成一圈选大王（编号从１到N），
从第P号开始报数，一直数到ｍ，数到ｍ的猴子退出圈外。
就这样，直到圈内只剩下一只猴子时，这个猴子就是猴王。

请写出一个程序，对于给定的N,P,M,计算并打印出依次出列的猴子的编号。

输入


输出


样例输入


样例输出

*/
#include<iostream>                     //这个解法确实有其独到之处
using namespace std;

struct Node{
    int num;
    Node *ahead;
    Node *next;
};
Node *Create(int N);
Node *Search(Node *head,int P);
Node *Release(Node *head,int M);
int main() {
    int N,P,M = 0;              //N起始节点，P开始节点
    cin >> N >> P >> M;         //每次释放第M个节点
    Node *head = Create(N);     //创建N个节点的环
    head = Search(head,P);      //找到第P个节点
    while(head->next != head){  //不断释放第M个元素，直到只剩一个元素
        head = Release(head,M); //释放第M个节点
    }
    cout << head->num;
    system("pause");
    return 0;
}

Node *Create(int N)             //不带空的头结点的双向循环链表
{
    Node *temp,*follow,*head = new Node;
    temp = head;
    follow = temp;
    temp->num = 1;              //头结点
    temp->next = new Node;
    temp->ahead = NULL;         //无所谓，先设为空好了
    temp = temp->next;   
    int i = 2;
    while(i < N){               //中间节点
        temp->num = i;
        temp->next = new Node;
        temp->ahead = follow;
        follow = temp;
        temp = temp->next;
        i++;
    }
    temp->num = N;              //尾节点
    temp->ahead = follow;   
    temp->next = head;
    head->ahead = temp;                     
    return head;
}

Node *Search(Node *head,int P)  //从Head开始寻找第P个节点
{
    while(head->num != P){
        head = head->next;
    }
    return head;
}

Node *Release(Node *head,int M) //释放Head开始的第M个节点
{
    int count = 1;
    Node *temp = head;
    while(count < M){           //寻找第M个节点
        temp = temp->next;
        count++;
    }          
    temp->ahead->next = temp->next;     //移除第M个节点
    temp->next->ahead = temp->ahead;    //移除第M个节点
    cout << temp->num << ",";
    head = temp->next;          //释放第M个节点所占内存空间
    delete temp;
    return head;  
}
//机器评判通过