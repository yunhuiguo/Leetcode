#include <iostream>
using namespace std;


struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        
    }
};


int main() {
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(2);
    a->next = b;
    Solution s;
    ListNode* head = s.removeNthFromEnd(a, 2);

    while(head != NULL) {
        cout << head->val;
        head =  head->next;
    }

    cout << endl;


    return 0;
}