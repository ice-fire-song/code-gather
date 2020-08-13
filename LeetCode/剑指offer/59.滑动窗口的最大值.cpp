class Solution {
public:
    int findMax(vector<int> &nums, int l, int r) {
        int MAX = nums[l];
        for(int i = l + 1; i <= r; i++) {
            MAX = max(MAX, nums[i]);
        }
        return MAX;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> res;
        if(nums.size() == 0) return res;
        int l = 0;
        int r = k - 1;
        int MAX = findMax(nums, l, r);
        res.push_back(MAX);
        while((++r) < nums.size()) {
            l++;
            if(nums[r] > MAX) {
                res.push_back(nums[r]);
                MAX = nums[r];
            }else res.push_back(findMax(nums, l, r));
        }
        return res;
    }
};