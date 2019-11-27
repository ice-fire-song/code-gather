func removeDuplicates(nums []int) int {
    length := len(nums)
    i := 0
    for k := 1; k < length; k++ {
        if nums[i] != nums[k] {
             i++
            nums[i] = nums[k]
        }
    }
    return i + 1
}