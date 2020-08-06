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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 遍历完A链表的步数为 L1 + C, 遍历完B链表的步数为 L2 + C；（C为公共部分）
        // A遍历完后跳到headB继续走，B遍历完后跳到headA继续走，则A和B会在L1+L2+C中相聚
        ListNode* pa = headA;
        ListNode* pb = headB;
        while(pa != pb) {
            pa = pa == NULL?headB:pa->next;
            pb = pb == NULL?headA:pb->next;
        }
        return pa;
    }
};