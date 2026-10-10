class Solution {
public:
    void backTracking(vector<int>& nums,vector<vector<int>>& res, vector<int> currVec, int index){

        if(index == nums.size()) return;

        currVec.push_back(nums[index]);
        backTracking(nums, res, currVec, index+1);
        
        res.push_back(currVec);

        currVec.pop_back();
        backTracking(nums, res, currVec, index+1);




    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> v;
        backTracking(nums, res, v , 0 );
        res.push_back({});
        return res;


        
    }
};
