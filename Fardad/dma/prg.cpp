#include <iostream>
using namespace std;
class Foo {
   int m_data;
public:
   Foo(int data) {
      m_data = data;
      display(clog) << " is created!" << endl;
   }
   operator int() {
      clog << "casting foo to " << m_data << endl;
      return m_data;
   }
   ostream& display(ostream& ostr = cout) {
      return ostr << m_data;
   }
   ~Foo() {
      clog << m_data << " is dying!" << endl;
   }
};
void dmaExample() {
   int* p = new int[3] {1, 2, 3};
   //   int* q = new int(3);
   int* q = new int{ 3 };
   int i;
   for(int i = 0; i < 3; i++) {
      cout << p[i] << " ";
   }
   cout << endl;
   cout << *q << endl;
   delete[] p;
   delete q;
}
int main() {
   Foo f(10);
   int num;
   f.display() << endl;
   f = 200;

   num = f;
   cout << num << " is the cast operator result!" << endl;
   cout << "End of code!" << endl;
   return 0;
}