class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sz = nums.size();
        int current = 0;
        
        int best = nums[0];

        //choose between current element 
        //or the previous array(treat the whole prev as 1 unit) + current
        for(int i=0; i < sz ; i++){
            current = max(nums[i], current + nums[i]);
            best = max(best, current);  
        }
        return best;

    }
};
