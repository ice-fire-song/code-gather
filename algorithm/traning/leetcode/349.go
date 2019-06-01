package main

import "fmt"

func intersection(nums1 []int, nums2 []int) []int {
	len1 := len(nums1)
	len2 := len(nums2)
	var i = 0
	var min int

	map1 := make(map[int]int)
	map2 := make(map[int]int)
	if len1 >= len2 {
		min = len2
	}else {
		min = len1
	}
	var res = make([]int,1,min)
	for ; i < min; i++ {
		map1[nums1[i]]++
		map2[nums2[i]]++
	}
	var t = 0
	if len1 >= len2 {
		for ; i < len1; i++ {
			map1[nums1[i]]++
		}
		for k,_ := range map2 {
			if map1[k] > 0 {
				fmt.Println(k,"  ",map1[k])
			res[t] = k
			t++
		}
		}
		return res
	}else {
		for ; i < len2; i++ {
			map2[nums2[i]]++
		}
		for k,_ := range map1 {
			if map2[k] > 0 {
				fmt.Println(k,"  ",map2[k])
			res[t] = k
			t++
		}
		}
		return res
	}
	return res
}
func main() {
	a := []int{1,2,2,1}
	b := []int{2,2}
	res := intersection(a,b)
	for i := 0; i < len(res); i++ {
		fmt.Print(" ",res[i])
	}
}
