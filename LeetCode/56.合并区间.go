

func merge(intervals [][]int) [][]int {
	var length = len(intervals)
	if length == 1 {
		return intervals
	}else {
		sort.Slice(intervals,func(i int, j int) bool{
			return intervals[i][0] < intervals[j][0]
		})
		var res [][]int
		t := 0
		i := 0
		var k, flag int

		for ;i < len(intervals) - 1; {
			flag = intervals[i][1]
			k = i + 1
			for {
				if k >= length || flag < intervals[k][0] {
					break
				}else {
					if flag < intervals[k][1] {
						flag = intervals[k][1]
					}
					k++
				}

			}
			if k == i + 1 {
				temp := make([]int,2)
				res = append(res, temp)
				res[t][0] = intervals[i][0]
				res[t][1] = intervals[i][1]
				t++
				i = k
			}else {
				temp := make([]int,2)
				res = append(res, temp)
				res[t][0] = intervals[i][0]
				res[t][1] = flag
				t++
				i = k
			}
		}
		if k == length - 1 {
			temp := make([]int,2)
			res = append(res, temp)
			res[t][0] = intervals[k][0]
			res[t][1] = intervals[k][1]
		}
		return res
	}

}

