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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // 思路：BFS+反转
        vector<vector<int>> ret;
        if(!root) return ret; // 判断root是否为空
        queue<TreeNode*> q;
        q.push(root);
        int n = 1; // 记录当前处于第几层
        while(!q.empty()) {
            vector<int> level;
            int size = q.size();
            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front(); q.pop();
                level.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(n % 2 == 0) { // 第偶数层进行反转
                reverse(level);
            }
            ret.push_back(level);
            n++;
        }
        return ret;
    }
    void reverse(vector<int> &level) { // 反转函数
        int left = 0;
        int right = level.size() - 1;
        while(left < right) {
            int tmp = level[left];
            level[left++] = level[right];
            level[right--] = tmp;
        }
    }
};