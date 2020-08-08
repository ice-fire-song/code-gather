class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        if(matrix.size() == 0) return ret;
        int u = 0; int d = matrix.size() - 1;    // 上限、下限
        int l = 0; int r = matrix[0].size() - 1; // 左限、右限

        while(true) {
            for(int i = l; i <= r; i++) ret.push_back(matrix[u][i]); // 从上左往上右
            if(++u > d) return ret; // 判断是否还能往下右
            for(int i = u; i <= d; i++) ret.push_back(matrix[i][r]); // 从上右往下右
            if(--r < l) return ret; // 判断是否还能往下左
            for(int i = r; i >= l; i--) ret.push_back(matrix[d][i]); // 从下右往下左
            if(--d < u) return ret; // 判断是否还能往上左
            for(int i = d; i >= u; i--) ret.push_back(matrix[i][l]); // 从下左往上左
            if(++l > r) return ret; // 判断是否还能往上右
        }
        return ret;
    }
};