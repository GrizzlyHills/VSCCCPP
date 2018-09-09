#include <iostream>
#include <cstdlib>
using namespace::std;
double notation()
{
  char str[10];
  cin >> str;
  switch(str[0]){
    case '+':
      return notation() + notation();
      break;
    case '-':
      return notation() - notation();
      break;
    case '*':
      return notation() * notation();
      break;
    case '/':
      return notation() / notation();
      break;
    default:
      return atof(str);    
  }
}
int main()
{
    cout << notation();
    system("pause");
    return 0;
}