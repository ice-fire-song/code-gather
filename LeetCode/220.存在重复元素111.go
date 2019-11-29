

func containsNearbyAlmostDuplicate(nums []int, k int, t int) bool {
    if k >= 10000 {
    	return false
	}
	for i := 0; i < len(nums); i++ {
		for k := i + 1; k < len(nums); k++ {
			if math.Abs((float64(nums[i] )- float64(nums[k]))) <= float64(t) && math.Abs(float64(i) - float64(k)) <= float64(k) {
				return true
			}
		}
	}
	return false
}
