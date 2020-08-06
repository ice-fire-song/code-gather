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
    vector<int> reversePrint(ListNode* head) {
        // 思路：根据栈的先进后出特性，先顺序遍历链表，将元素入栈，之后再从栈中取出元素即可
        stack<int> s;
        vector<int> ret;
        while(head) {
            s.push(head->val);
            head = head->next;
        }
        while(!s.empty()) {
            int top = s.top();
            s.pop();
            ret.push_back(top);
        }
        return ret;
    }
};