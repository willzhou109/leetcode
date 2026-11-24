class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        n = len(nums)
        missing = n * (n + 1) // 2
        for num in nums:
            missing -= num
        return missing # only the absent value remains