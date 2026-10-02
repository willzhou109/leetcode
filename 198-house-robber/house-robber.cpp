class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        vector<int> maxArr(n);
        maxArr[n - 1] = nums[n - 1];
        maxArr[n - 2] = nums[n - 2];
        maxArr[n - 3] = nums[n - 1] + nums[n - 3];
        for (int i = n - 4; i >= 0; --i) {
            maxArr[i] = max(maxArr[i + 2], maxArr[i + 3]) + nums[i];
            /*for (int x : maxArr) {
                cout << x << " ";
            }
            cout << endl;*/
        }
        
        return max(maxArr[0], maxArr[1]);
    }
};