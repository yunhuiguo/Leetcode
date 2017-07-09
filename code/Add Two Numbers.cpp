#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* run = head;
        int sum ;
        int carry = 0;

        while(l1 != NULL && l2 != NULL) {
            sum = (l1->val+l2->val+carry)%10;
            ListNode* tmp = new ListNode(sum);
            run->next = tmp;
            run = run->next;
            carry = (l1->val+l2->val+carry)/10;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1 != NULL) {
            ListNode* tmp = new ListNode((carry+l1->val)%10);
            carry = (l1->val+carry)/10;
            run->next = tmp;
            run = run->next;
            l1 = l1->next;
        }

         while(l2 != NULL) {
            ListNode* tmp = new ListNode((carry+l2->val)%10);
            carry = (l2->val+carry)/10;
            run->next = tmp;
            run = run->next;
            l2 = l2->next;
        }

        if(carry != 0) {
            ListNode* tmp = new ListNode(carry);
            run->next = tmp;
            run = run->next;
        }
        return head->next;
    }
};



int main() {
    Solution s;


}