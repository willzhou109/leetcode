class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() == 1 || s.size() == 0) {
            return true;
        }
        if (s[0] == s[s.size() - 1]) {
            return isPalindrome(s.substr(1, s.size() - 2));
        } else {
            return false;
        }
    }

    void backtrack(vector<string>& currPartition, string remaining, vector<vector<string>>& output) {
        if (remaining.size() == 0) {
            //cout << "adding to output" << endl;
            output.push_back(currPartition);
        }
        for (int i = 0; i < remaining.size(); ++i) {
            string test = remaining.substr(0, i + 1);
            std::cout << test << endl;
            if (isPalindrome(test)) {
                /*for (string x : currPartition) {
                    cout << x << ", ";
                }        
                cout << endl;*/

                currPartition.push_back(test);
                backtrack(currPartition, remaining.substr(i + 1), output);
                currPartition.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> output;
        vector<string> currPartition;
        backtrack(currPartition, s, output);
        return output;
    }
};