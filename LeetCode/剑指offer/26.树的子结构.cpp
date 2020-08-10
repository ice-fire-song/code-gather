/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(A == NULL || B == NULL) return false;
        // 遍历A树，拿A的每个节点node和B的根节点通过help(node,B)来进行前序遍历，判断从node出发，是否有和B一样结构的树
        return help(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
    
    bool help(TreeNode* A, TreeNode* B) {
        if (A == NULL || B == NULL) {
            return B == NULL ? true : false;
        }
        if(A->val != B->val) return false;
        return help(A->left, B->left) && help(A->right, B->right);

    }
};