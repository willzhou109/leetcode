class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int x : nums) {
            if (minHeap.size() < k) {
                minHeap.push(x);
            } else {
                if (x > minHeap.top()) {
                    minHeap.pop();
                    minHeap.push(x);
                }
            }
        }
        return minHeap.top();
    }
};