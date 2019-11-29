
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
func maximumGap(nums []int) int {
	if len(nums) < 2 {
		return 0
	}
	sort.Sort(alias(nums))
	var max float64
	for i := 1; i < len(nums); i++ {
		max = math.Max(float64(nums[i] - nums[i - 1]), max)
	}
	return int(max)
}
