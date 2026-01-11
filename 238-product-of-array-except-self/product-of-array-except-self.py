class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        array_left = [1] * len(nums) # array where at every index, the value is equal to the product of all values that are to the left of that index in nums
        array_right = [1] * len(nums) # array where at every index, the value is equal to the product of all values that are to the right of that index in nums
        for i in range(len(nums)):
            if i > 0:
                array_left[i] = array_left[i-1] * nums[i-1]
        for i in range(len(nums) - 1, -1, -1):
            if i < len(nums) - 1:
                array_right[i] = array_right[i+1] * nums[i+1]
        print(array_left)
        print(array_right)
        
        product = []
        for i in range(len(nums)):
            product.append(array_left[i] * array_right[i])
        return product
