# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        fast = head
        slow = head
        while slow and fast:
            slow = slow.next
            if not slow:
                break
            fast = fast.next
            if not fast:
                break
            fast = fast.next
            if slow == fast:
                return True
        return False