class Solution {
public:
    string replaceSpace(string s) {
        string tmp = "%20";
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ' ') {
                s.erase(i, 1);    // 从i开始（包括i）删除1个长度
                s.insert(i, tmp); // 会在i-1, i之间插入
            }
        }
        return s;
    }
};