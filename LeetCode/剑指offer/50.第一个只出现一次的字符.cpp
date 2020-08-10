class Solution {
public:
    char firstUniqChar(string s) {
        // map<char, int> mp;
        // for(int i = 0; i < s.size(); i++) 
        //     mp[s[i]]++;
        // for(int i = 0; i < s.size(); i++) {
        //     if(mp[s[i]] == 1) return s[i];
        // }
        // return ' ';
        int arr[26] = {0}; // 用数组会更快，而且只有26个字母
        for(int i = 0; i < s.size(); i++) {
            arr[s[i] - 'a']++;
        }
        for(int i = 0; i < s.size(); i++) {
            if(arr[s[i] - 'a'] == 1) return s[i];
        }
        return ' ';
    }
};