/*
**输入输出流到文件的重定向
*/

#include <iostream>
#include <fstream>
#include <cstring>
using namespace::std;

class CStudent {
    public:
        char szName[20];
        int nScore;
};

void WriteRead(CStudent &s)
{
    ofstream OutFile("students.dat",ios::out|ios::binary);              //若没有此文件会自动创建
    while(cin >> s.szName >> s.nScore) {
        if(stricmp(s.szName,"exit") == 0)           //名字为exit则结束
            break;
        OutFile.write((char*) &s,sizeof(s));
    }
    OutFile.close();
    ifstream inFile("students.dat",ios::in|ios::binary);
    if(!inFile) {
        cout << "error" << endl;
        return;
    }
    while(inFile.read((char*) &s,sizeof(s))) {
        int nReadedBytes = inFile.gcount();         //读了多少字节
        cout << s.szName << " " << s.nScore << endl;
    }
    inFile.close();
}
void Modification(CStudent &s)
{
    fstream ioFile("students.dat",ios::out|ios::in|ios::binary);            //再次创建会覆盖上次的文件
    if(!ioFile) {
        cout << "error" << endl;
        return;
    }
    ioFile.seekp(2 * sizeof(s),ios::beg);               //定位写指针到第三个记录
    ioFile.write("Mike",strlen("Mike") + 1);
    ioFile.seekg(0,ios::beg);                           //定位都指针到开头
    while(ioFile.read((char*) &s,sizeof(s))) {
        cout << s.szName << " " << s.nScore << endl;
    }
    ioFile.close();   
}
int main()
{
    CStudent s;
    int num;
    cout << "Operate File Write And Read, Input 1 " << endl << "Operate File Modification, Input 2 " << endl;
    while(cin >> num) {        
        switch(num) {
            case 1:
                WriteRead(s);
                cout << "Operate File Write And Read, Input 1 " << endl << "Operate File Modification, Input 2 " << endl;
                break;
            case 2:
                Modification(s);
                cout << "Operate File Write And Read, Input 1 " << endl << "Operate File Modification, Input 2 " << endl;
                break;
        }        
    }
    system("pause");
    return 0;
}