class Solution(object):
    def dfs(self, coins, amount):
        if amount == 0:
            return 0
        else:
            minDepth = 100000
            for i in range(len(coins)):
                if coins[i] <= amount:
                    if amount - coins[i] in self.hm:
                        res = self.hm[amount - coins[i]]
                    else:
                        child = self.dfs(coins, amount - coins[i])
                        if child == -1:
                            res = -1
                        else:
                            res = child + 1
                        self.hm[amount - coins[i]] = res # store result into hashmap for future use
                    if res < minDepth and res != -1:
                        minDepth = res
            if minDepth == 100000:
                return -1
            else:
                return minDepth

    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        self.hm = {}
        return self.dfs(coins, amount)


