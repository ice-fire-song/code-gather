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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        /*
        思路：1、先遍历链表获得节点的总数量 len
        ·····2、再重新遍历到 第len - k个节点p后，把该节点p->next返回
        */
        int len = 0;
        ListNode* p = head;
        while(p) {
            p = p->next;
            len++;
        }
        p = head;
        int count = 1;
        while(p) {
            if(count == len - k) return p->next;
            p = p->next;
            count++;
        }
        return head;
    }
};