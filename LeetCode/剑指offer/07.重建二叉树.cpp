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
    vector<int> pre;
    map<int, int> mp;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        /*
        思路：从前序序列中找出根节点，从后续序列中分成左右子树。
        */
        pre = preorder;
        for(int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i; 
        }
        return build(0, 0, inorder.size() - 1);
    }
    TreeNode* build(int pre_root, int in_left, int in_right) {

        if(in_left > in_right) return NULL;
        TreeNode* root = new TreeNode(pre[pre_root]);
        int pre_root_i = mp[pre[pre_root]];
        root->left = build(pre_root + 1, in_left, pre_root_i - 1);
        root->right = build(pre_root + pre_root_i - in_left + 1, pre_root_i + 1, in_right);
        return root;
    }
};