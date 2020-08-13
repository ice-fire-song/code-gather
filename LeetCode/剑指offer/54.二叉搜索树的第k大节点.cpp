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
    // 中序遍历二叉搜索树
    int kthLargest(TreeNode* root, int k) {
        vector<int> inorder;
        inorderScan(root, inorder);
        return inorder[inorder.size() - k];
    }
    void inorderScan(TreeNode* root, vector<int> &inorder) {
        if(root == NULL) return;
        inorderScan(root->left, inorder);
        inorder.push_back(root->val);
        inorderScan(root->right, inorder);
    }
};