#include <iostream>
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* n = new ListNode(0);
        ListNode* head = n;

        if(l1 == NULL)
            return l2;
        else if(l2 == NULL)
            return l1;
        else {
            while(l1 != NULL && l2 != NULL) {
                if(l1-> val <= l2-> val) {
                    n->next = l1;
                    n = n->next;
                    l1 = l1->next;
                } else {
                    n->next = l2;
                    n= n->next;
                    l2 = l2->next;
                } 
            }

            while(l1 != NULL) {
                n->next = l1;
                n = n->next;
                l1 = l1->next;
            }
            while(l2 != NULL) {
                n->next = l2;
                n = n->next;
                l2 = l2->next;
            }
        }

        return head->next;
    }
};

int main() {


}