class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        cleaned = "".join(c.lower() for c in s if c.isalnum())
        print(cleaned)
        l = 0
        r = len(cleaned) - 1
        while l <= r:
            print(l)
            print(r)
            if cleaned[l] == cleaned[r]:
                l += 1
                r -= 1
            else:
                return False
        return True
