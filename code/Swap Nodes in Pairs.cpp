#include <iostream>
using namespace std;


 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL)
            return head;

        ListNode* pre = new ListNode(0);
        ListNode* res = pre;
        pre->next = head;
        ListNode* slow = head;

        while(slow->next != NULL) {
            ListNode* fast = slow->next;
            slow->next = fast->next;
            pre->next = fast;
            fast->next = slow;
            if(slow->next != NULL) {
                pre = slow;
                slow = slow->next;
            }
        }

        return res->next;
    }
};

int main() {
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(3);
    a->next = b;
    b->next = c;
    Solution s;
    a = s.swapPairs(a);
    while(a != NULL) {
        cout << a->val;
        a = a->next;
    }
    cout << endl;

return 0;

}