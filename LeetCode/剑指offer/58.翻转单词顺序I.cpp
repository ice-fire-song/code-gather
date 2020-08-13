class Solution {
public:
    string reverseWords(string s) {
        if(s.empty()) return "";
        vector<string> tmp;
        bool flag = false;
        string ss;
        for(int i = 0; i < s.size(); i++) {
            if(flag && s[i] == ' ') {
                tmp.push_back(ss);
                ss = "";
            }
            if(s[i] != ' ') {
                ss += s[i];
                flag = true;
            }else {
                flag = false;
            }
        }
        if(s[s.size() - 1] != ' ') tmp.push_back(ss);
        string res;
        for(int i = tmp.size() - 1; i >= 0; i--) {
            res += tmp[i] + " ";
        }
        if(res.empty()) return "";
        return res.erase(res.size() - 1, 1);
    }
};