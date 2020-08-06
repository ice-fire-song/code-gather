/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        /*
        思路：unordered_map底层实现是一个哈希表
        第一次遍历链表：新建一个个节点（已经存好val），并且每个节点通过unordered_map结构和原链表的各个节点形成映射。
        第二次遍历链表：在第一次遍历中，新建的每个节点只是存好val并没有相互关联关系。所以第二次遍历的目的是形成关联关系。
        */
        unordered_map<Node*, Node*> mp;
        Node* p = head;
        // 第一遍历：新建与原链表一一对应的新节点
        while(p) {
            mp[p] = new Node(p->val);
            p = p->next;
        }
        // 第二次遍历：给新建的节点形成关联关系
        p = head;
        while(p != NULL) {
            if(p->next != NULL) {
                mp[p]->next = mp[p->next];
            }
            if(p->random != NULL) {
                mp[p]->random = mp[p->random];
            }
            p = p->next;
        }
        return mp[head];
    }
};