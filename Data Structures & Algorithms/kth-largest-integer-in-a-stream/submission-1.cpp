class KthLargest {
public:
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_pq;
    int k ;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto& n : nums){
            
            min_pq.push(n);
            
            if(min_pq.size()>k){
                min_pq.pop();
            }
        }
    }
    
    int add(int val) {
        min_pq.push(val);

        if(min_pq.size()>k){
            min_pq.pop();
        }
        return min_pq.top();
        
    }
};
