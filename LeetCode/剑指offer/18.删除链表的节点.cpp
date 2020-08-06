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
    ListNode* deleteNode(ListNode* head, int val) {
        if(head == NULL) return head;
        if(head->val == val) return head->next;
        ListNode* head_tmp = head;
        while(head->next) {
            if(head->next->val == val) {
                ListNode* node = head->next;
                head->next = head->next->next;
                delete node;
                break;
            }
            head = head->next;
        }
        return head_tmp;
    }
};