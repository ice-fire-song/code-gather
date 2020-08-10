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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return check(root->left, root->right);
    }
    // 先序遍历：
    // 左子树的左子节点和右子树的右子节点比较
    // 左子树的右子节点和右子树的左子节点比较
    bool check(TreeNode* left, TreeNode* right) {
        if(left == NULL && right == NULL) return true;
        if(left == NULL || right == NULL || left->val != right->val) return false;
        return check(left->left, right->right) && check(left->right, right->left);
    }
};