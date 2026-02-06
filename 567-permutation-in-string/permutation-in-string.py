class Solution(object):
    def checkInclusion(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        if len(s1) > len(s2):
            return False
        s1_freqs = [0] * 26
        s2_window_freqs = [0] * 26
        for i in range(len(s1)):
            s1_freqs[ord(s1[i]) - ord('a')] += 1
        
        l = 0
        r = l + len(s1) - 1
        while r < len(s2):
            if l == 0:
                for i in range(l, r + 1):
                    s2_window_freqs[ord(s2[i]) - ord('a')] += 1
            if s2_window_freqs == s1_freqs:
                return True
            else: # shift window right
                s2_window_freqs[ord(s2[l]) - ord('a')] -= 1
                l += 1
                r += 1
                if r == len(s2):
                    return False
                s2_window_freqs[ord(s2[r]) - ord('a')] += 1
        return False


