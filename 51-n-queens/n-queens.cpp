class Solution {
public:
    void printBoard(vector<string>& curr) {
        for (string& s : curr) {
            cout << s << ", ";
        }
        cout << endl;
    }
    bool isPlaceable(vector<string>& curr, int r, int c) {
        // returns true if you can place a queen here such that no two queens can attack each other
        // row check
        for (int i = 0; i < c; ++i) {
            if (curr[r][i] == 'Q') {
                //cout << "row check failed" << endl;
                return false;
            }
        }
        // downward left diagonal check
        int r_idx = r;
        int c_idx = c;
        while (r_idx < curr.size() && c_idx >= 0) {
            if (curr[r_idx][c_idx] == 'Q') {
                //cout << "downward left failed" << endl;
                return false;
            }
            r_idx += 1;
            c_idx -= 1;
        }
        // upward left diagonal check
        r_idx = r;
        c_idx = c;
        while (r_idx >= 0 && c_idx >= 0) {
            if (curr[r_idx][c_idx] == 'Q') {
                //cout << "upward left failed" << endl;
                return false;
            }
            r_idx -= 1;
            c_idx -= 1;
        }

        return true;
    }

    void backtrack(vector<string>& curr, int c, int n, vector<vector<string>>& result) {
        //printBoard(curr);
        if (c == n) {
            result.push_back(curr);
            return;
        }

        for (int r = 0; r < n; ++r) {
            if (isPlaceable(curr, r, c)) {
                curr[r][c] = 'Q';
                backtrack(curr, c + 1, n, result);
                curr[r][c] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> curr;
        for (int i = 0; i < n; ++i) {
            string s = "";
            for (int j = 0; j < n; ++j) {
                s += '.';
            }
            curr.push_back(s);
        }
        printBoard(curr);
        vector<vector<string>> result;
        backtrack(curr, 0, n, result);
        return result;
    }
};