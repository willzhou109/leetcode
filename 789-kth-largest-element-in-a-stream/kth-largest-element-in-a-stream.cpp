class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int k;
public:
    KthLargest(int k, vector<int>& nums) : k(k) {
        for (int n : nums) {
            min_heap.push(n);
        }
        while (min_heap.size() > k) {
            min_heap.pop();
        }
    }
    
    int add(int val) {
        if (min_heap.size() < k) {
            min_heap.push(val);
            return min_heap.top();
        }
        if (val <= min_heap.top()) {
            return min_heap.top();
        } else {
            min_heap.pop();
            min_heap.push(val);
            return min_heap.top();
        }
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */