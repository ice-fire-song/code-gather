// package main
// import (
// 	"fmt"
// 	"math"
// 	"sort"
// )
// func main() {
// 	arr := []int{0,2,1,-3}
// 	fmt.Println(threeSumClosest(arr, 1))
// }

func threeSumClosest(nums []int, target int) int {

	sort.Ints(nums)
	sum := nums[0] + nums[1] + nums[2]
	var l, r int
	var tempSum int
	for i := 0; i < len(nums) - 2; i++ {
		l = i + 1
		r = len(nums) - 1
		for l < r {
			tempSum = nums[i] + nums[l] + nums[r]
			if math.Abs(float64(tempSum - target)) < math.Abs(float64(sum - target)) {
				sum = tempSum
			}
			if tempSum > target {
				r--
			}else if tempSum < target {
				l++
			}else {
				return target
			}
		}
	}
	return sum
}