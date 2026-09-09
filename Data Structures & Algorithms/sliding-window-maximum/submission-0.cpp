class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int sz = nums.size();
        int currMax = -10001;
        std::priority_queue <std::pair<int,int>> pq;
        for(int l = 0, r = k -1; r < sz; l++,r++ ){
            
            if(l == 0){
                for(int i  = 0 ; i <= r ; i++){
                    pq.push({nums[i], i });
                }
                res.push_back(pq.top().first);
            }
            else{
               pq.push({nums[r], r });
               int maxIndex = pq.top().second;
               while(maxIndex < l  ){
                    pq.pop();
                    maxIndex = pq.top().second;
               }
               res.push_back(pq.top().first);
            }
        }
        return res;
        
    }
};
