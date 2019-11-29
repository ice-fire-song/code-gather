

func intersect(nums1 []int, nums2 []int) []int {
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
	var res []int
	for ; i < min; i++ {
		map1[nums1[i]]++
		map2[nums2[i]]++
	}
	if len1 >= len2 {
		for ; i < len1; i++ {
			map1[nums1[i]]++
		}
		for k,v := range map2 {
			if map1[k] > 0 {
				t := math.Min(float64(v),float64(map1[k]))
				for {
					if t <= 0 {
						break
					}
					res = append(res,k)
					t--
				}
			}

		}
		return res
	}else {
		for ; i < len2; i++ {
			map2[nums2[i]]++
		}
		for k,v := range map1 {
			if map2[k] > 0 {
				t := math.Min(float64(v),float64(map2[k]))
				for {
					if t <= 0 {
						break
					}
					res = append(res,k)
					t--
				}
			}
		}
		return res
	}
	return res
}
