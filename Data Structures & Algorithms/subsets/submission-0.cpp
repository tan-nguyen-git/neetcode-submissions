class Solution {
    //you will have a chance to include it
    //or to not include it
public:
    void backtrack(int i, vector<int>& nums,
               vector<int>& curr,
               vector<vector<int>>& res) {
    // base case
    // go to the last base-case then back-track 
    if(i== nums.size()){
        res.push_back(curr);
        return;
    }

    // choice 1: include nums[i]
    
    curr.push_back(nums[i]);
    backtrack(i+1, nums,curr, res);

    // undo choice
    curr.pop_back();
    // choice 2: exclude nums[i]
    backtrack(i+1, nums,curr, res);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(0,nums, curr, res);
        return res;
        
        
        
    }
};
