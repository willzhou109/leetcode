class Solution {
private:
    bool find(int i, int j, int wordIdx, string word, vector<vector<char>>& board) {
        //cout << "(" + to_string(i) + ", " +  to_string(j) + "), target letter: " + word[wordIdx] << endl;
        if (i >= board.size() || j >= board[0].size()) {
            return false;
        }
        if (board[i][j] == '#') {
            return false;
        }
        if (board[i][j] == word[wordIdx]) {
            // turn the current letter at the coord into a # to mark it as seen
            board[i][j] = '#';
            if (wordIdx == word.size() - 1) { // at the last letter
                return true;
            } else { // not at the last letter
                if (find(i - 1, j, wordIdx + 1, word, board)) {
                    return true;
                } else if (find(i + 1, j, wordIdx + 1, word, board)) {
                    return true;
                } else if (find(i, j - 1, wordIdx + 1, word, board)) {
                    return true;
                } else if (find(i, j + 1, wordIdx + 1, word, board)) {
                    return true;
                } else { // didn't find any possible paths
                    // restore the old letter 
                    board[i][j] = word[wordIdx];
                    return false;
                }
            }
        } else { // not the correct letter
            return false;
        }
     }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == word[0]) {
                    if (find(i, j, 0, word, board)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};