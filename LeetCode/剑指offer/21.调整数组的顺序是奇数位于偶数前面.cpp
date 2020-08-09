class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        // 单指针法：用一个指针标准当前奇数部分的后一个元素的下标
        int odd = 0;
        int i = 0;
        int len = nums.size();
        while(i < len) {
            if(nums[i]&1) {
                swap(nums[i], nums[odd++]);
            }
            i++;
        }
        return nums;
    }
};