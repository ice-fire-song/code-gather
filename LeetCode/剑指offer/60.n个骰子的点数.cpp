class Solution {
public:
    vector<double> twoSum(int n) {
        vector<vector<int> >dp(n + 1, vector<int>(n*6 + 1, 0));
        vector<double> res;
        for(int i = 1; i <= n; i++) {
            for(int j = i; j <= i*6; j++) {
                if(i == 1) {
                    dp[i][j] = 1;
                    continue;
                }else {
                    for(int k = 1; k <= 6; k++) {
                        if(j - k >= i - 1) dp[i][j] += dp[i - 1][j - k];
                    }
                }
            }
        }
        for(int i = n; i <= n*6; i++) {
            res.push_back(dp[n][i] * pow(1.0/6, n));
        }
        return res;
    }
};