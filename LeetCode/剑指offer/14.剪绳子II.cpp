class Solution {
public:
    int cuttingRope(int n) {
        // 数学推导+快速幂
        if(n <= 3) return n - 1;
        int num_3 = n / 3;
        int rem = n % 3;
        if(rem == 0) return (int)(quick(3, num_3) % mod);
        if(rem == 1) return (int)(quick(3, num_3 - 1) * 4 % mod);
        return (int)(quick(3, num_3) * 2 % mod);
    }
    int mod = 1000000007;
    long long quick(long long b, int p) {
        long long sum = 1;
        while(p) {
            if(p&1) sum = (sum * b) % mod;
            b = (b * b) % mod;
            p >>= 1;
        }
        return sum;
    }
};