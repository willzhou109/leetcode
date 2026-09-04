class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> max_pq;
        for (int n : stones) {
            max_pq.push(n);
        }
        while (max_pq.size() > 1) {
            int x = max_pq.top();
            max_pq.pop();
            int y = max_pq.top();
            max_pq.pop();
            if (x == y) {
                // push 0 which does nothing
                max_pq.push(0);
            } else {
                y = abs(y - x);
                max_pq.push(y);
            }
        }
        return max_pq.top();
    }
};