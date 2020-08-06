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
    int maxD = -1; // 记得深度最大值
    int maxDepth(TreeNode* root) {
        DFS(root, 0);
        return maxD;
    }
    void DFS(TreeNode* root, int path) {
        if(root == NULL) { // 终止条件
            if(path > maxD) maxD = path;
            return;
        }
        DFS(root->left, path + 1);
        DFS(root->right, path + 1);
    }
};