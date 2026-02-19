# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: Optional[ListNode]
        :type l2: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        c1 = l1
        c2 = l2
        output = ListNode(-1)
        ret = None
        carry = 0
        val = 0
        while c1 or c2:
            if c1 and c2:
                val = c1.val + c2.val + carry  
                c1 = c1.next
                c2 = c2.next
            elif c1:
                val = c1.val + carry
                c1 = c1.next
            else:
                val = c2.val + carry
                c2 = c2.next
           
            # calculate carry and val
            if val >= 10:
                    carry = 1
                    val = val - 10
            else:
                carry = 0


            new_node = ListNode(val)


            if output.val == -1: # if output is originally "empty"
                output = new_node
                ret = output
            else:
                output.next = new_node
                output = output.next
               
        if carry != 0:
            new_node = ListNode(carry)
            output.next = new_node
            output = output.next


        return ret