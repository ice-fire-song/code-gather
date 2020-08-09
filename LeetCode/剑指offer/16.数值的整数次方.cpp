class Solution {
public:
    double myPow(double x, int n) {
        long long k = (long long) n; 
        double ret = 1;
        if(k < 0) {
            x = 1.0 / x;
            k *= -1; // 如果k是int，那么最后一个用例通过不了，会溢出
        }
        while(k) {
            if(k&1) ret *= x;
            x *= x;
            k >>= 1;
        }

        return ret;
    }
};