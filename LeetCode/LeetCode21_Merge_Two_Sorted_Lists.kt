/**
 * Example:
 * var li = ListNode(5)
 * var v = li.`val`
 * Definition for singly-linked list.
 * class ListNode(var `val`: Int) {
 *     var next: ListNode? = null
 * }
 */

// Approach: Find the smallest element of two list recursively
// Time complexity: O(N)
// Space complexity: O(N)
class Solution {
    fun mergeTwoLists(list1: ListNode?, list2: ListNode?): ListNode? = solve(list1, list2)
    
    tailrec fun solve(list1: ListNode?, list2: ListNode?): ListNode? =
        when {
            list1 == null && list2 == null -> null
            list1 == null -> list2
            list2 == null -> list1
            list1?.`val` > list2?.`val` -> ListNode(list2?.`val`).apply {
                next = solve(list1, list2?.next)
            }
            else -> ListNode(list1?.`val`).apply {
                next = solve(list1?.next, list2)
            }
        }
}

// Approach: Find the smallest element of two list and connect it iteratively
// Time complexity: O(N)
// Space complexity: O(1)
class Solution {
    fun mergeTwoLists(list1: ListNode?, list2: ListNode?): ListNode? {
        val head = ListNode(101)
        var cur = head
        var l1 = list1
        var l2 = list2
        
        while (l1 != null && l2 != null) {
            if (l1.`val` < l2.`val`) {
                cur.next = l1
                cur = cur.next
                l1 = l1.next
            } else {
                cur.next = l2
                cur = cur.next
                l2 = l2.next
            }
        }
        cur.next = if (l1 == null) l2 else l1
        
        return head.next 
    }
}