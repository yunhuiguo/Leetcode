#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL)
            return head;

        ListNode* slow = head;
        ListNode* fast = head;
        int diff = 0;
        int length = 1;

        while(diff < k) {
            fast = head;
            slow = head;
            diff = 0;
            if(length != 1)
                k = k % length;            
            while(fast->next != NULL) {
                fast = fast->next;
                diff++;
                length++;
                if(diff > k) {
                    slow = slow->next;
                    diff--;
                }
            }

    }

        if(k != 0) {
            ListNode* tmp = slow->next;
            slow->next = fast->next;
            fast->next = head;
            return tmp;
        } else
            return head;
    }
};


int main() {
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(3);
    ListNode* d = new ListNode(4);
    ListNode* e = new ListNode(5);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    Solution s;
    ListNode* res = s.rotateRight(a, 7);
    while(res != NULL) {
        cout << res->val;
        res = res->next;
    }
    cout << endl;


    return 0;
}