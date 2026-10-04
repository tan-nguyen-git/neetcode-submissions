class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<std::array<int, 26>, vector<string>> frequencyMap;
        int count = 0;
        for(const auto& str: strs){
            std::array<int, 26> arr{}; //init all of them to 0
            for(const auto& ch: str){
                arr[ch-'a'] ++;
            }
            frequencyMap[arr].push_back(strs[count]);
            count++;
        } 
        vector<vector<string>> res;

        for(const auto& [k,v]: frequencyMap){
            vector<string> group;
            for(const auto& ele: v){
                group.push_back(ele);
            }
            res.push_back(group);
        }
        return res;

    }
};
