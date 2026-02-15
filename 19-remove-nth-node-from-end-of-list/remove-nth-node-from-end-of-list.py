# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: Optional[ListNode]
        :type n: int
        :rtype: Optional[ListNode]
        """
        p1 = head
        p2 = head
        prev = ListNode(-1) # the node behind p2
        # move p1 forward n times, so p2 will have a delay of n
        for i in range(0, n):
            p1 = p1.next
        # shift p1 and p2 and prev until p1 hits the end
        while p1:
            p1 = p1.next
            prev = p2
            p2 = p2.next
        
        prev.next = p2.next
        if prev.val == -1:
            head = prev.next
        return head
