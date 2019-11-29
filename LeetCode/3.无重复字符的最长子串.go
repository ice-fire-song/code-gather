

//1.暴力法
//func lengthOfLongestSubstring(s string) int {
//	var max, count int
//	for i := 0; i < len(s); i++ {
//		count = 0
//		tmp := make(map[uint8]int)
//		tmp[s[i]]++
//		count++
//		for k := i + 1; k < len(s); k++ {
//			if tmp[s[k]] > 0 {
//				break
//			}
//			tmp[s[k]]++
//			count++
//		}
//		if i != 0 && count > max {
//			max = count
//		}else if i == 0 {
//			max = count
//		}
//	}
//	return max
//}

//2.优化
func lengthOfLongestSubstring(s string) int {
	var i, flag, maxLen = 0, 0, 0
	var index int
	for i = 0; i < len(s); i++ {
		index = strings.Index(s[flag:i], string(s[i]))
		if index >= 0 {
			if (i - flag) > maxLen {
				maxLen = i - flag
			}
			flag = flag + index + 1
		}

	}
	if (i - flag) > maxLen {

		maxLen = i - flag
	}
    return maxLen
}