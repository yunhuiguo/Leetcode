#include <iostream>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode* slow = head;
        ListNode* fast = slow->next;

        while(fast != NULL) {
            while(fast != NULL && fast->val == slow->val) {
                fast = fast->next;
            }

            slow->next = fast;
            slow = fast;
            if(slow != NULL)
                fast = slow->next;
            
        }

        return head;
    }
};


int main() {
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(1);
    ListNode* c = new ListNode(2);
    ListNode* d = new ListNode(3);
    ListNode* e = new ListNode(3);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    Solution s;
    ListNode* res = s.deleteDuplicates(a);
    while(res != NULL) {
        cout << res->val;
        res = res->next;
    }
    cout << endl;


    return 0;
}