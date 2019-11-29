
func twoSum(nums []int, target int) []int {
	var res []int
	var flag bool
	for i := 0; i < len(nums); i++ {
		for k := i + 1; k < len(nums); k++ {
			if nums[i] + nums[k] == target {
				res = append(res, i, k)
				flag = true
				break
			}
		}
		if flag {
			break
		}
	}
	return res
}
