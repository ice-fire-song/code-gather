
// 左右标志并进法
// 比较左右标志高度，选择高度低的标志向中间移动。因为高度低的标志往中间移动，才可能有机会遇到高度较大的标志，从而使面积更大
func maxArea(height []int) int {
	var l, r = 0, len(height) - 1
	var area, max int
	for l != r {
		if height[l] > height[r] {
		    area = (r - l) * height[r]
		    r--
		}else {
			area = (r - l) * height[l]
			l++
		}
		if area > max {
			max = area
		}
	}
	return max
}
