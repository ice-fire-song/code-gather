class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // 和求最大的子序列和一样
        int max = -102;
        int sum = 0; 
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(sum > max) max = sum;
            if(sum < 0) sum = 0;
           
        }
        return max;
    }
};