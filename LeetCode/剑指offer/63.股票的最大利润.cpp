class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int min_p = prices[0]; // 记录从第一天到第i天内最低的价格
        int max_p = 0;  // 记录最大的利润
        for(int i = 0; i < prices.size(); i++) {
            if(prices[i] < min_p) min_p = prices[i];
            if(prices[i] - min_p > max_p) max_p = prices[i] - min_p;
        }
        return max_p;
    }
};