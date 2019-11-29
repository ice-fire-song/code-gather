
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func insertionSortList(head *ListNode) *ListNode {
	var h *ListNode = new(ListNode)
	h.Next = head
	var pre *ListNode = h
	var cur *ListNode = head
	var lat *ListNode

	for cur != nil{
		lat = cur.Next // 记录下一个要插入排序的值
		if lat != nil && lat.Val < cur.Val {
			for pre.Next != nil && pre.Next.Val < lat.Val {
				pre = pre.Next
			}


			var tmp *ListNode = pre.Next
			pre.Next = lat
			cur.Next = lat.Next
			lat.Next = tmp
			pre = h
		} else {
			cur = lat
		}
	}

	return h.Next
}
