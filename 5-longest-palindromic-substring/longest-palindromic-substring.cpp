class Solution {
public:
    string longestPalindrome(string s) {
        int maxStart = 0;
        int maxLen = 1;
        for (int i = 0; i < s.length(); ++i) {
            int j = 1;
            // odd palidrome detection
            while (i - j >= 0 && i + j < s.length() && s[i - j] == s[i + j]) {
                if (2 * j + 1 > maxLen) {
                    maxLen = 2 * j + 1;
                    maxStart = i - j;
                }
                j += 1;
            }

            // even palindrome detection
            int k = 0;
            while (i - k >= 0 && i + 1 + k < s.length() && s[i - k] == s[i + 1 + k]) {
                if (2 * k + 2 > maxLen) {
                    maxLen = 2 * k + 2;
                    maxStart = i - k;
                }
                k += 1;
            }
        }
        return s.substr(maxStart, maxLen);
    }
};