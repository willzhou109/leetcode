class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int counts[26] = {0};
        priority_queue<int> max_heap;
        queue<pair<int,int>> queue;
        for (char& c : tasks) {
            counts[c - 'A']++;
        }
        for (int& value : counts) {
            if (value != 0) max_heap.push(value);
        }
        int time = 0;
        while (max_heap.size() != 0 || queue.size() != 0) {
            
            time++;
            if (max_heap.size() != 0) {
                int topFreq = max_heap.top();
                max_heap.pop();
                topFreq--;
                int nextTime = time + n;
                if (topFreq != 0) {
                    queue.push({topFreq, nextTime});
                }
            }

            if (queue.size() != 0 && queue.front().second == time) {
                max_heap.push(queue.front().first);
                queue.pop();
            }
        }
        return time;
    }
};