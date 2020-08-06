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
    /*
    参考题解：后续遍历 + 剪枝
    思路是对二叉树做后序遍历，从底至顶返回子树深度，若判定某子树不是平衡树则 “剪枝” ，直接向上返回。
    */
    bool isBalanced(TreeNode* root) {
        int ret = DFS(root);
        return ret != -1;
    }
    int DFS(TreeNode* root) {
        if(root == NULL) return 0;
        int left = DFS(root->left);
        if(left == -1) return -1;  // 剪枝，直接返回
        int right = DFS(root->right);
        if(right == -1) return -1; // 剪枝，直接返回
        return abs(left - right) >= 2?-1:max(left, right) + 1;
    }
};