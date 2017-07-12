#include <iostream>
using namespace std;


 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 


int main() {
    int* p = new int(1);
    delete p;
    *p = 2;
    cout << *p << endl;

return 0;

}