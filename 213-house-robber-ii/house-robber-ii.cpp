class Solution {
private:
    int robP1(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        vector<int> maxArr(n);
        maxArr[n - 1] = nums[n - 1];
        maxArr[n - 2] = nums[n - 2];
        maxArr[n - 3] = nums[n - 1] + nums[n - 3];
        for (int i = n - 4; i >= 0; --i) {
            maxArr[i] = max(maxArr[i + 2], maxArr[i + 3]) + nums[i];
        }
        
        return max(maxArr[0], maxArr[1]);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int lastHouse = nums[n - 1];
        nums.pop_back();
        int max1 = robP1(nums);
        nums.push_back(lastHouse);
        // replace first house with 0
        nums[0] = 0;
        int max2 = robP1(nums);
        return max(max1, max2);
    }
};