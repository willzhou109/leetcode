class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        current_sum = nums[0]
        best_sum = nums[0]

        for i in range(1, len(nums)):
            num = nums[i]
            current_sum = max(current_sum + num, num) # maximum sum that ends at position i
            best_sum = max(best_sum, current_sum)

        return best_sum
            # [-2, -1, 3]