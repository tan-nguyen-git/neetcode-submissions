class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<std::array<int, 26>, set<int>> frequencyMap;
        int count = 0;
        for(const auto& str: strs){
            std::array<int, 26> arr{}; //init all of them to 0
            for(const auto& ch: str){
                arr[ch-'a'] ++;
            }
            frequencyMap[arr].insert(count);
            count++;
        } 

        for(const auto& [k,v]: frequencyMap){
            vector<string> group;
            for(const auto& ele: v){
                group.push_back(strs.at(ele));
            }
            res.push_back(group);
        }
        return res;

    }
};
