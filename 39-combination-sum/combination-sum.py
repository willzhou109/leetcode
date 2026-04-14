class Solution(object):
    def backtrack(self, candidates, target, i, currCombination, currSum, combinations):
        
        if i == len(candidates):
            return
        if currSum == target:
            print(currCombination)
            combinations.append(list(currCombination))
            return
        elif currSum > target:
            return
        # otherwise:
        currCombination.append(candidates[i])
        currSum += candidates[i]
        self.backtrack(candidates, target, i, currCombination, currSum, combinations) # left side of decision tree
        currSum -= currCombination.pop()
        self.backtrack(candidates, target, i + 1, currCombination, currSum, combinations)

    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        currCombination = []
        combinations = []
        self.backtrack(candidates, target, 0, currCombination, 0, combinations)
        return combinations
