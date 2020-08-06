class Solution {
public:
    int numWays(int n) {
        int f0 = 1;
        int f1 = 1;
        int sum = 0;
        for(int i = 1; i <= n; i++) {
            sum = (f0 + f1) % 1000000007;
            f0 = f1;
            f1 = sum;
        }
        return f0;
    }
};