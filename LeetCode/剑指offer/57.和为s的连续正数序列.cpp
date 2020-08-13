class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        // 1,2,3,4,5...等差数列的[l, r]求和公式(l + r) * (r - l + 1) / 2
        vector<vector<int>> res;
        int l, r;
        for(l = 1, r = 2; l < r && r <= target / 2 + 1; ) {
            int sum = (l + r) * (r - l + 1) / 2;
            if(sum == target) {
                vector<int> tmp;
                for(int i = l; i <= r; i++)
                    tmp.push_back(i);
                res.push_back(tmp);
                l++;
            }else if(sum < target) r++;
            else l++;
        }
        return res;
    }
};