class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        int ret = 0;
        while(n) {
            ret++;
            n -= (n&(-n));  // 使用树状数组的lowbit()的思路，每次(n&(-n))得到的都是当前n高位1组成的数
        }
        return ret;
    }
};