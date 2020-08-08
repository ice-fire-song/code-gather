class Solution {
public:

    string minNumber(vector<int>& nums) {
        vector<string>str;
        for(int i = 0; i < nums.size(); i++) str.push_back(to_string(nums[i]));

        sort(str.begin(), str.end(), [](string& s1, string& s2){return s1 + s2 < s2 + s1;});
        string ret;
        for(int i = 0; i < str.size(); i++) ret += str[i];
        return ret;
    }
};