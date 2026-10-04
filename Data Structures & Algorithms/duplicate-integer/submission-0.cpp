class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> s;
        for(const auto& n : nums){
            if(s.contains(n)) return true;
            s.insert(n);
        }
        return false;

    }
};