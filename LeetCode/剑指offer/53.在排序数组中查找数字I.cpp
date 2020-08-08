class Solution {
public:
    int search(vector<int>& nums, int target) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == target) sum++;
        }
        return sum;
    }
};