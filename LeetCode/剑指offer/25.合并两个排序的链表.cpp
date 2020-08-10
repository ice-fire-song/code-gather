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
        ListNode* head = new ListNode(0);
        ListNode* h_p = head;
        ListNode* l1_p = l1;
        ListNode* l2_p = l2;
        while(l1_p != NULL && l2_p != NULL) {
            while(l1_p != NULL && l2_p != NULL) {
                if(l1_p->val <= l2_p->val) {
                    ListNode* node = new ListNode(l1_p->val);
                    h_p->next = node;
                    h_p = h_p->next;
                    l1_p = l1_p->next;
                }else break;
            }
            while(l2_p != NULL && l1_p != NULL) {
                if(l2_p->val <= l1_p->val) {
                    ListNode* node = new ListNode(l2_p->val);
                    h_p->next = node;
                    h_p = h_p->next;
                    l2_p = l2_p->next;
                }else break;
            }
        }
        while(l1_p != NULL) {
            ListNode* node = new ListNode(l1_p->val);
            h_p->next = node;
            h_p = h_p->next;
            l1_p = l1_p->next;
        }
        while(l2_p != NULL) {
            ListNode* node = new ListNode(l2_p->val);
            h_p->next = node;
            h_p = h_p->next;
            l2_p = l2_p->next;
        }
        return head->next;
    }
};