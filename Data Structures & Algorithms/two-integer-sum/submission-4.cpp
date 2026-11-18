class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, std::set<int>> m;
        int count =0;
        for(int i =0; i < nums.size(); i ++){
            m[nums[i]].insert(i);
        }
        for(int i =0;  nums.size(); i ++ ){
            int need = target - nums[i];
            if(m.contains(need) ){
                //set have 2 element but because only 1 valid solution
                if(m.at(need).size() == 2){
                    return { *m.at(need).begin(),*(++m.at(need).begin())};
                }
                //set have 1 element
                else{
                    if(i !=*m.at(need).begin())
                        return {i, *m.at(need).begin()};
                }
            }
        }
        
        
    }
};
