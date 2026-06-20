class Solution {
private:
    void backtrack(int n, string curr, int numOpen, int numClosed, vector<string>& result) {
        //cout << n << " " << curr << " " << numOpen << " " << numClosed << " " << endl;
        if (numOpen > n || numClosed > n) {
            return;
        } else if (numOpen == numClosed && n == numOpen) {
            result.push_back(curr);
            return;
        } else if (numOpen == numClosed) {
            curr += "(";
            backtrack(n, curr, numOpen + 1, numClosed, result);
        } else if (numOpen > numClosed) {
            curr += "(";
            backtrack(n, curr, numOpen + 1, numClosed, result);
            curr.pop_back();
            curr += ")";
            backtrack(n, curr, numOpen, numClosed + 1, result);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string curr = "(";
        backtrack(n, curr, 1, 0, result);
        return result;
    }
};