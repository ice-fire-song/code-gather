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
    ListNode* reverseList(ListNode* head) {
        /*
         思路：用三个指针pre, cur, next
         next: 用于带动pre、cur移动
         pre:  反转时的目的节点
         cur:  反转时的源节点
         如：1->2 (pre: 1, cur: 2)
        */
       

        if(head == NULL || head->next == NULL) return head;
        ListNode* pre = NULL;
        ListNode* cur = head;
        ListNode* next = head->next;
        while(cur) {
            cur->next = pre;
            pre = cur;
            cur = next;
            if(next != NULL) {
                next = next->next;
            }
        }
        return pre;
    }
};