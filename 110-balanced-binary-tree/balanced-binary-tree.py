# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isBalanced(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: bool
        """
        if root is None:
            return True
        stack = [root]
        mp = {None : 0} # node pointer vs height of that node
        while stack:
            node = stack[-1]
            if node.right and node.right not in mp:
                stack.append(node.right)
            elif node.left and node.left not in mp:
                stack.append(node.left)
            else:
                node = stack.pop()
                leftHeight = mp[node.left]
                rightHeight = mp[node.right]
                if abs(leftHeight - rightHeight) > 1:
                    return False
                mp[node] = 1 + max(leftHeight, rightHeight)
        return True