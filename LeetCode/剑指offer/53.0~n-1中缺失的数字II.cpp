class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i = 0;
        for(i = 0; i < nums.size(); i++) {
            if(nums[i] != i) return nums[i] - 1;
        }
        return nums[i - 1] + 1;
    }
};