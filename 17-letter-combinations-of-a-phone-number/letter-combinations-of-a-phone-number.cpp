class Solution {
public:
    std::map<int, string> mp = {
        {2, "abc"},
        {3, "def"},
        {4, "ghi"},
        {5, "jkl"},
        {6, "mno"},
        {7, "pqrs"},
        {8, "tuv"},
        {9, "wxyz"}
    };

    void printOutput(vector<string>& output) {
        for (string& s : output) {
            cout << s << ", ";
        }
        cout << endl;
    }
    void backtrack(vector<string>& output, string& remainingDigits) {
        if (remainingDigits.size() == 0) {
            return;
        }
        string currLetters = mp[remainingDigits[0] - '0'];
        vector<string> newOutput;
        if (output.size() == 0) {
            for (char y : currLetters) {
                string s = {y};
                newOutput.push_back(s);
                printOutput(output);
            }
        } else {
            
            for (string& x : output) {
                for (char y : currLetters) {
                    string s = "";
                    s += x;
                    string ys = {y};
                    s += ys;
                    newOutput.push_back(s);
                    printOutput(newOutput);
                }
            }
        }
        string newNextLetters = mp[remainingDigits[0] - '0'];
        string remaining = remainingDigits.substr(1);
        output = newOutput;
        backtrack(output, remaining);
    }
    vector<string> letterCombinations(string digits) {
        vector<string> output;
        backtrack(output, digits);
        return output;
    }
};