from collections import deque
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def rightSideView(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: List[int]
        """
        if not root:
            return []
        big_queue = deque()
        big_queue.append(deque([root]))
        output = []
        while big_queue:
            sub_queue = deque() # []
            while len(big_queue[0]) > 0:
                if big_queue[0][0].left: # 1's left is 2
                    sub_queue.append(big_queue[0][0].left) # [2]
                if big_queue[0][0].right: # 1's right is 3
                    sub_queue.append(big_queue[0][0].right) # [2,3]
                if len(big_queue[0]) == 1:
                    output.append(big_queue[0][0].val)
                    print(output)
                big_queue[0].popleft() # pop 1 away
            if len(sub_queue) > 0:
                big_queue.append(sub_queue)
            big_queue.popleft()
        return output
            
            