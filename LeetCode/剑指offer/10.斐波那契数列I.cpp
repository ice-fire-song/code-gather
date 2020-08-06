class Solution {
public:
    
    int fib(int n) {
        // 普通递归会超时
        // 动态规划
        int mod = 1000000007;
        int f0 = 0;
        int f1 = 1;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum = (f0 + f1) % mod;
            f0 = f1;
            f1 = sum;
        }
        return f0;
    }

};