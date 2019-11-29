

// 分治法
// 分别以字符串的每个字符为轴，左右对称比较，得出以该轴为中心的回文子串。最后，取得长度最长的回文子串
// 注意：轴可能由相邻且相同的多个字符组成。比如："cbbd"中的"bb"
func GetPalindrome(s string, i int) string {
	var l, r = i - 1, i + 1
    for {
		if r < len(s) && s[r] == s[i] { //分治法中，考虑对称轴可能由相邻且相同的多个字符组成
			r++
		}else {
				break
		}
	}
	for l >= 0 && r < len(s) && s[l] == s[r] {
		l--
		r++
	}
	return s[l+1:r]
}
func longestPalindrome(s string) string {
	var length = 0
	var res, tmp string
	for i := 0; i < len(s); i++ {
		tmp = GetPalindrome(s, i)
        if len(tmp) > length {
        	length = len(tmp)
        	res = tmp
	    }
	}
	return res
}
