class Solution {
private:
    void backtrack(vector<int>& sortedCandidates, int target, int i, vector<int>& currCombination, int currCombinationSum, vector<vector<int>>& combinations) {
        cout << "i = ";
        cout << i;
        cout << " [ ";
        for (int val : currCombination) {
            cout << val;
            cout << ", ";
        }
        cout << "]";
        cout << " currCombinationSum: ";
        cout << currCombinationSum << endl;
        if (currCombinationSum == target) {
            cout << "found" << endl;
            combinations.push_back(currCombination);
            return;
        } else if (i >= sortedCandidates.size() || currCombinationSum > target) {
            return;
        }
        currCombination.push_back(sortedCandidates[i]);
        currCombinationSum += sortedCandidates[i];
        backtrack(sortedCandidates, target, i + 1, currCombination, currCombinationSum, combinations);
        int initial = sortedCandidates[i];
        while (i < sortedCandidates.size() && sortedCandidates[i] == initial) {
            i += 1;
        }
        int popped = currCombination.back();
        currCombination.pop_back();
        currCombinationSum -= popped;
        backtrack(sortedCandidates, target, i, currCombination, currCombinationSum, combinations);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> currCombination;
        vector<vector<int>> combinations;
        backtrack(candidates, target, 0, currCombination, 0, combinations);
        return combinations;
    }
};