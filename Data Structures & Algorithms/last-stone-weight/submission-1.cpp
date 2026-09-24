class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int sz = stones.size();

        if (sz == 1) return stones[0];
        if (sz == 2) return abs(stones[0] - stones[1]);

        priority_queue<int> pq;
        
        for (auto& s : stones) {
            pq.push(s);
        }

        while (pq.size() > 1) {
            int tp1 = pq.top();
            pq.pop();

            int tp2 = pq.top();
            pq.pop();

            int remain = abs(tp1 - tp2);

            if (remain > 0) {
                pq.push(remain);
            }
        }

        return pq.empty() ? 0 : pq.top();
    }
};