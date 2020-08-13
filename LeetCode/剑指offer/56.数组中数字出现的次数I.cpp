class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        /*
        相同的值异或变为0，因此，异或每个元素，最终的结果sum就是那两个出现一次的数字a,b异或的结果。
        那如何才能拆开a,b呢？先sum &= (-sum)会获得最后一个1（即第n位的1），而1只能是1^0而来；所以a,b必定在第n位中一个为1，一个为0；再以这个值和每个元素进行“与”的操作，则可以分开第n位为1或0的两组了，每组再分别异或的操作就可以得到a,b
        */
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum ^= nums[i];
        }
        int a, b;
        sum = sum & (-sum); // 获取最后的一个1，只有1^0才能有1，则可将a,b拆开
        vector<int> res(2, 0);
        for(int num:nums) {
            if(num&sum) {
                res[0] ^= num;
            }else {
                res[1] ^= num;
            }
        }

        return res;
    }
};