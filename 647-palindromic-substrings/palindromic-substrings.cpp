class Solution {
public:
    int countSubstrings(string s) {
        int maxStart = 0;
        int maxLen = 1;
        int count = 0;
        for (int i = 0; i < s.length(); ++i) {
            int j = 0;
            // odd palidrome detection
            while (i - j >= 0 && i + j < s.length() && s[i - j] == s[i + j]) {
                count += 1;
                j += 1;
            }

            // even palindrome detection
            int k = 0;
            while (i - k >= 0 && i + 1 + k < s.length() && s[i - k] == s[i + 1 + k]) {
                count += 1;
                k += 1;
            }
        }
        return count;
    }
};