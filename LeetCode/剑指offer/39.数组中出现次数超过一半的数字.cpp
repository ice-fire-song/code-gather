class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // 一、简单方便，就是耗内存
        // unordered_map<int, int> mp;
        // int half_len = nums.size() / 2;
        // for(int i = 0; i < nums.size(); i++) {
        //     mp[nums[i]]++;
        //     if(mp[nums[i]] > half_len) return nums[i];
        // }
        // return 0;
        // 二、结果的数字的数量必定大于其他数的数量，所以设置计数器（遇到相同的+1，不同的-1）
        int count = 1;
        int ret = nums[0];
        for(int i = 0; i < nums.size(); i++) {
            if(ret == nums[i]) {
                count++;
                continue;
            }else count--;
            if(count == 0) {
                ret = nums[i];
                count++;
            }
        
        }
        return ret;
  
    }
};