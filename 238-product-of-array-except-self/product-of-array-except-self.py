class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        array_left = [1] * len(nums) # array where at every index, the value is equal to the product of all values that are to the left of that index in nums
        array_right = [1] * len(nums) # array where at every index, the value is equal to the product of all values that are to the right of that index in nums
        product = [1] * len(nums)
        for i in range(len(nums)):
            if i > 0:
                array_left[i] = array_left[i-1] * nums[i-1]
            product[i] *= array_left[i]
        for i in range(len(nums) - 1, -1, -1):
            if i < len(nums) - 1:
                array_right[i] = array_right[i+1] * nums[i+1]
            product[i] *= array_right[i]    
        print(array_left)
        print(array_right)
        return product
