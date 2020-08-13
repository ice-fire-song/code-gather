class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 双指针分别向左向右遍历
        // 这是个笨方法
        if(s == "") return 0;
        else if(s.size() == 1) return 1;
        int MAX = 1;
        for(int i = 1; i < s.size(); i++) {
            int l = i - 1;
            int r = i + 1;
            string ss;
            ss += s[i];
            while(l >= 0) {
                if(ss.find(s[l]) != string::npos) break;
                ss += s[l];
                l--;
            }
            while(r < s.size()) {
                if(ss.find(s[r]) != string::npos) break;
                ss += s[r];
                r++;
            }
            if(ss.size() > MAX) MAX = ss.size();
        }
        return MAX;
    }
};