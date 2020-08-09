class Solution {
public:
    vector<int> printNumbers(int n) {
        int max_second = pow(10, n);
        vector<int> ret;
        for(int i = 1; i < max_second; i++) {
            ret.push_back(i);
        }
        return ret;
    }
};