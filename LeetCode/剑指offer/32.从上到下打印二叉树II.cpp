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
        vector<vector<int>> ret;
        if(!root) return ret;  // 判断是否为空 []
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            vector<int> level;
            int size = q.size(); // 记录当前层元素的个数
            // 以下的操作：
            // 1、遍历队列，取出当前层的所有元素，压入level中
            // 2、每取出一个元素都将其“不为NULL”的子节点压入队列
            for(int i = 0; i < size; i++) { 
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ret.push_back(level);
        }
        return ret;
    }

};