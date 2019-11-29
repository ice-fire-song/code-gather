
func multiply(num1 string, num2 string) string {
    s0 := "0"
    strings.Compare(num1, s0)
    if num1 == s0 || num2 == s0 {
        return s0
    }else {
        l := len(num1)
        r := len(num2)
        //用来存储两数相乘的结果，并且结果的长度不会大于两数长度之和
        num := make([]int, (l + r))
        //第一个数按位循环
        for i := 0; i < l; i++ {
            //得到最低位的数字
            n1 := int(num1[l-1-i] - '0')
            //保存进位
            tmp := 0
            //第二个数按位循环
            for j := 0; j < r; j++ {
                n2 := int(num2[r-1-j] - '0')
                //拿出此时的结果数组里存的数+现在计算的结果数+上一个进位数
                tmp = tmp + num[i+j] + n1 * n2
                //得到此时结果位的值
                num[i+j] = tmp % 10
                //此时的进位
                tmp /= 10
            }
            //第一轮结束后，如果有进位，将其放入到更高位
            num[i+r] = tmp
        }

        i := l + r - 1
        //由于所得的结果不知道是否刚好等于数组num的长度，因此，需要确定结果的长度
        for i > 0 && num[i] == 0 {
            i--
        }
        result := ""
        // 由于数组num 是从低位往高位存储的，所以需要倒转过来
        for i >= 0 {
            result += strconv.Itoa(num[i])
            i--
        }
       return result
    }
}