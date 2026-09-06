class Solution {
public:
    struct Compare {
        bool operator()(vector<int> a, vector<int> b) {
            int da_squared = a[0] * a[0] + a[1] * a[1];
            int db_squared = b[0] * b[0] + b[1] * b[1];
            return da_squared < db_squared;
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, Compare> pq; // largest has priority
        vector<vector<int>> output;
        Compare cmp;
        for (auto& point : points) {
            if (pq.size() < k) {
                pq.push(point);
                continue;
            }
            if (cmp(point, pq.top())) {
                pq.pop();
                pq.push(point);
            }
        }
        while (pq.size() != 0) {
            output.push_back(pq.top());
            pq.pop();
        }
        return output;
    }
};