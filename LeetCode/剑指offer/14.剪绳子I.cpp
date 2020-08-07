class Solution {
public:
    int cuttingRope(int n) {
        // 引用题解大佬的推导结论：① 当所有绳段长度相等时，乘积最大。② 最优的绳段长度为 3 。
        if(n == 2) return 1;
        if(n == 3) return 2;
        int num_3 = n / 3;
        int remainder = n % 3;
        if(remainder == 0) return pow(3, num_3);
        if(remainder == 1) return pow(3, num_3 - 1) * 4;
        
        return pow(3, num_3) * 2;
    }
};