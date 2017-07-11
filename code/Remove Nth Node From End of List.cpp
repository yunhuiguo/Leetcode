#include <iostream>
using namespace std;


 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* pre = new ListNode(0);
        ListNode* cur = head;
        pre->next =  cur;

        if(cur->next != NULL) {
            int end = 2;
            ListNode* run = cur->next;

            if(run->next == NULL) {
                if(n == 2)
                    return head->next;
                else
                    head->next = NULL;
                    return head;
            } else {

                while(run->next != NULL) {
                    run = run->next;
                    end++;
                    while(end > n) {
                        pre = cur;
                        cur = cur->next;
                        end--;
                    }
                }

                    if(head == cur)
                        return head->next;
                    pre->next = cur->next;
                    cur->next = NULL;
                    return head;
            }


        } else {
            return NULL;
        }
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