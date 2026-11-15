class Solution(object):
    hm = {}
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        if len(s) == 0:
            return 1
        if s[0] == '0':
            return 0
        if len(s) == 1:
            return 1
        # look at first two letters, are they <= 26?
        if (int(s[0] + s[1]) <= 26):
            leftChild = 0
            rightChild = 0
            if s[1:] in self.hm:
                leftChild = self.hm[s[1:]]
            else:
                leftChild = self.numDecodings(s[1:])
                self.hm[s[1:]] = leftChild
            if s[2:] in self.hm:
                rightChild = self.hm[s[2:]]
            else:
                rightChild = self.numDecodings(s[2:])
                self.hm[s[2:]] = rightChild
            return leftChild + rightChild

        else:
            return self.numDecodings(s[1:])
        