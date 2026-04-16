class Solution {
private:
    void backtrack(vector<int>& nums, vector<int>& currPerm, vector<bool>& boolVec, vector<vector<int>>& result) {
        cout << "[";
        for (int x : currPerm) {
            cout << x;
            cout << ", ";
        }
        cout << "] ";
        cout << "[";
        for (bool x : boolVec) {
            cout << x;
            cout << ", ";
        }
        cout << "]" << endl;
        if (currPerm.size() == nums.size()) {
            
            result.push_back(currPerm);
            return;
        }
        for (int i = 0; i < boolVec.size(); ++i) {
            if (boolVec[i] == false) {
                currPerm.push_back(nums[i]);
                boolVec[i] = true;
                backtrack(nums, currPerm, boolVec, result);
                currPerm.pop_back();
                boolVec[i] = false;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> currPerm;
        vector<vector<int>> result;
        vector<bool> boolVec(nums.size(), false);
        backtrack(nums, currPerm, boolVec, result);
        return result;
    }
};