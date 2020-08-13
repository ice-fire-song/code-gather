class Solution {
public:
    int translateNum(int num) {
        if(num <= 9) return 1;
        int two = num % 100;
        if(two >= 26 || two <= 9) return translateNum(num / 10);
        else return translateNum(num / 10) + translateNum(num / 100);
    }
};