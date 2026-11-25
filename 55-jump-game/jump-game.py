class Solution(object):
    def canJump(self, nums):
        farthest = 0 # every index from zero through farthest is reachable, any thing over farthest is unreachable
        last = len(nums) - 1

        for index, jump in enumerate(nums):
            if index > farthest:
                return False
            farthest = max(farthest, index + jump) # extends our reachable range
            if farthest >= last:
                return True
        