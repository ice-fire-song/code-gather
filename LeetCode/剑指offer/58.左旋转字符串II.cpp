class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string res;
        res = s.substr(n);
        res += s.substr(0, n);
        return res;
    }
};