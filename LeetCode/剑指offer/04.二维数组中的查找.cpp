class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        // 每一行都进行二分查找
        if(matrix.size() == 0) return false;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0; i < n; i++) {
            int left = 0;
            int right = m - 1;
             while(left <= right) {
                 int mid = (left + right) / 2;
                 if(matrix[i][mid] == target) return true;
                 else if(matrix[i][mid] > target) right = mid - 1;
                 else left = mid + 1;
             }
        }
        return false;
    }
};