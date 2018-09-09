    //priority_queue用法示例
    #include <iostream>
    #include <queue>
    #include <functional>   // std::greater
    using namespace::std;

    int main()
    {
        priority_queue<double> priorities1;
        priorities1.push(3.2);
        priorities1.push(9.8);
        priorities1.push(5.6);
        while(!priorities1.empty()) {
            cout << priorities1.top() << " ";        //输出结果：9.8 5.6 3.2
            priorities1.pop();
        }
        cout << endl;
        priority_queue<double, vector<double>, greater<double> > priorities2;
        priorities2.push(3.2);
        priorities2.push(9.8);
        priorities2.push(5.6);
        while(!priorities2.empty()) {
            cout << priorities2.top() << " ";        //输出结果：3.2 5.6 9.8
            priorities2.pop();
        }

        system("pause");        
        return 0;
    }