
type alias []int
func (tp alias) Len() int {
	return len(tp)
}
func (tp alias) Less(i, j int) bool {
	return tp[i] < tp[j]
}
func (tp alias) Swap(i, j int) {
	temp := tp[i]
	tp[i] = tp[j]
	tp[j] = temp
}
func hIndex(citations []int) int {
	var temp = make(map[int]int)
	var flag int
	for i := 0; i < len(citations); i++ {
		if citations[i] == 0 {
			continue
		}else if citations[i] > len(citations) {
			flag = len(citations)
		}else if citations[i] > 0 {
			flag = citations[i] - 1
		}
		for k := 1; k <= flag; k++ {
			temp[k]++
		}
	}
	var res int
	for i := 1; i <= len(citations); i++ {
		if temp[i] >= i {
			res = i
		}
	}

	return res
}
