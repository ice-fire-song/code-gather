
func sortColors(nums []int)  {
    var lp, curr, rp = 0, 0, len(nums) - 1
    var temp int
    for i := 0; i < len(nums); i++ {
        if nums[curr] == 0 {
            temp = nums[lp]
            nums[lp] = nums[curr]
            nums[curr] = temp
            lp++
            curr++
        }else if nums[curr] == 2 {
            temp = nums[rp]
            nums[rp] = nums[curr]
            nums[curr] = temp
            rp--
        }else {
                curr++
        }
    }
}