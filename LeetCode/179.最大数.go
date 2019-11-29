

func largestNumber(nums []int) string {
	sort.Slice(nums,func (i int, j int) bool {
		return fmt.Sprintf("%d",nums[i]) + fmt.Sprintf("%d",nums[j]) > fmt.Sprintf("%d",nums[j]) + fmt.Sprintf("%d",nums[i])
	})
	var res string
	if nums[0] == 0 {
		res += "0"
		return res
	}
	for i := 0; i < len(nums); i++ {
		res += fmt.Sprintf("%d",nums[i])
	}

	return res
}
