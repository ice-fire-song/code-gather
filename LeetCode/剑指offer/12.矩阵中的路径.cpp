class Solution {
public:

    bool exist(vector<vector<char>>& board, string word) {
        for(int x = 0; x < board.size(); x++) {
            for(int y = 0; y < board[0].size(); y++) {
                if(DFS(board, word, x, y, 0)) return true;
            }
        }
        return false;
    }
    bool DFS(vector<vector<char>> &board, string word, int x, int y, int k) {
        // 终止条件
        if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != word[k]) return false;
        if(k == word.size() - 1) return true;
        // 递归
        char tmp = board[x][y];
        board[x][y] = '/'; // 保证“在当前路径”中不走回头路
        bool ret = DFS(board, word, x + 1, y, k + 1) || DFS(board, word, x , y + 1, k + 1) || DFS(board, word, x - 1, y, k + 1) || DFS(board, word, x , y - 1, k + 1);
        board[x][y] = tmp; // 回溯时，要还原board[x][y]，以便下一条路径查找
        return ret;
    }
};