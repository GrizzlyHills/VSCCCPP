/*
 * @Author: GrizzlyHills 
 * @Date: 2017-11-08 20:06:44 
 * @Last Modified by: GrizzlyHills
 * @Last Modified time: 2017-11-08 20:08:53
 */
#include <iostream>
using namespace::std;

class A
{
private:
	int n1;
	int n2;
	
public:
	// A():n2(0),n1(n2+2){}
	A():n1(n2+2),n2(0){}
	void Print(){
		cout << "n1: " << n1 << ", n2: " << n2 <<endl;  
	}
};

int main()
{

	A a;
	a.Print();

    system("pause");
	return 0;
}
