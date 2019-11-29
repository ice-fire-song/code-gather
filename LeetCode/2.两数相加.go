/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

 func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	var res, i, k *ListNode
	var tmp int
	node := new(ListNode)
	tmp = l1.Val + l2.Val
	if tmp >= 10 {
		node.Val = tmp - 10
		tmp = 1
	}else {
		node.Val = tmp
		tmp = 0
	}
	res = node
	var p = node
	k = l2.Next
	for i = l1.Next; i != nil; i = i.Next {
		    if k == nil {
		    	break
			}
			node := new(ListNode)
			tmp += i.Val + k.Val
			k = k.Next
			if tmp >= 10 {
				node.Val = tmp - 10
				tmp = 1
			}else {
				node.Val = tmp
				tmp = 0
			}
			p.Next = node
			p = p.Next

	}
	if i == nil {
		for ; k != nil; k = k.Next {
			node := new(ListNode)
			tmp += k.Val
			if tmp >= 10 {
				node.Val = tmp - 10
				tmp = 1
			}else {
				node.Val = tmp
				tmp = 0
			}
			p.Next = node
			p = p.Next
		}
	}else {
		for ; i != nil; i = i.Next {
			node := new(ListNode)
			tmp += i.Val
			if tmp >= 10 {
				node.Val = tmp - 10
				tmp = 1
			}else {
				node.Val = tmp
				tmp = 0
			}
			p.Next = node
			p = p.Next
		}
	}
	if tmp == 1 {
		node := new(ListNode)
		node.Val = 1
		p.Next = node
	}
	return res
}