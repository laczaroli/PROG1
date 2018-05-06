#include <iostream>

using namespace std;

int main()
{
  int tmp = 0;
  int a = 3, b = 5;
  //VÁLTOZÓVAL
  cout << "A: " << a << " B: " << b << endl;
  tmp = a;
  a = b;
  b = tmp;
  cout << "A*: " << a << " B*: " << b << endl;
  // EXORRAL
  a = 3;
  b = 5;
  a = a ^ b;
  b = b ^ a;
  a = a ^ b;
  cout << "A**: " << a << " B**: " << b << endl;
  return 0;
}
