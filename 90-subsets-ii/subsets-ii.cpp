class Solution {
private:
    void backtrack(vector<int>& nums, vector<int>& curr, int i, vector<vector<int>>& result) {
        if (i >= nums.size()) {
            result.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        backtrack(nums, curr, i + 1, result);
        int initial = nums[i];
        while (i < nums.size() && nums[i] == initial) {
            i += 1;
        }
        curr.pop_back();
        backtrack(nums, curr, i, result);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        backtrack(nums, curr, 0, result);
        return result;
    }
};