class Solution {
public:
    // dfs+回溯+set去重
    set<string> st;
    vector<string> res;
    vector<string> permutation(string s) {
        if(s.empty()) return res;
        DFS(s, 0);
        return res;
    }
    void DFS(string s, int i) {
        // 终止条件
        if(i == s.size()) {
            if(st.count(s) == 0) {
                res.push_back(s);
                st.insert(s);
            }
            return;
        }
        for(int j = i; j < s.size(); j++) {
            swap(s[j], s[i]);
            DFS(s, i + 1);
            swap(s[j], s[i]);  // 回溯
        }
    }
};