func threeSum(nums []int) [][]int {
	sort.Ints(nums)
	var res [][]int
	var length = len(nums)
    var i int
	var l, r, sum int
	var ind = 0
	for i = 0; i < length; i++ {

		if i == 0 || nums[i] > nums[i-1] {
			l = i + 1
			r = length - 1
			for {
				if l >= r {
					break
				}
				sum = nums[i] + nums[l] + nums[r]
				if sum == 0 {
					temp := make([]int, 3)
					res = append(res, temp)
					res[ind][0] = nums[i]
					res[ind][1] = nums[l]
					res[ind][2] = nums[r]
					ind++
					l++
					r--
					for {
						if l < r && nums[l] == nums[l-1] {
							l++
						}else {
							break
						}
					}
					for {
						if l < r && nums[r] == nums[r+1] {
							r--
						}else {
							break
						}
					}
				}else if sum > 0 {
					r--
				}else {
					l++
				}
			}
		}

	}

	return res
}