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
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* slow = head;
        ListNode* fast = slow->next;
        ListNode* res = new ListNode(0);
        ListNode* run = res;

        while(fast != NULL) {
            while(fast != NULL && fast->val == slow->val)
                fast = fast->next;

            if(fast != NULL && fast == slow->next) {
                ListNode* tmp = new ListNode(slow->val);
                run->next = tmp;
                run = run->next;

                slow = fast;
                if(slow != NULL)
                    fast = slow->next;
            } else {
                slow = fast;
                if(slow != NULL)
                    fast = slow->next;
            }
        }

        if(slow != NULL && slow->next == NULL)  {
            ListNode* tmp = new ListNode(slow->val);
            run->next = tmp;
            run = run->next;
        }

        return res->next;
    }
};

int main() {
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(1);
    ListNode* c = new ListNode(1);
    a->next = b;
    b->next = c;

    Solution s;
    ListNode* res = s.deleteDuplicates(a);
    while(res != NULL) {
        cout << res->val;
        res = res->next;
    }
    cout << endl;


    return 0;
}