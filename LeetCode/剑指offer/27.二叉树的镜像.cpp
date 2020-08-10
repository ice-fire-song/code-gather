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
    TreeNode* mirrorTree(TreeNode* root) {
        if(root == NULL) return root;
        TreeNode* ret = new TreeNode(root->val);
        image(root, ret);
        return ret;
    }
    void image(TreeNode* root, TreeNode* ret) {
        if(root == NULL) return ;
        if(root->left != NULL) {
            TreeNode* n1 = new TreeNode(root->left->val);
            ret->right = n1;
        }
        if(root->right != NULL) {
            TreeNode* n2 = new TreeNode(root->right->val);
            ret->left = n2;
        }
        
        image(root->left, ret->right);
        image(root->right, ret->left);
    }
};