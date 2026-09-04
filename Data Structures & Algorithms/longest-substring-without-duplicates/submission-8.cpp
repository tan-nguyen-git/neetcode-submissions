class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //store charactor and its index
        std::unordered_map<char, int> m  ;
        int sz = s.size();
        int res =0;
        int currCount =0;
        int groupBegin = 0;

        for(int i =0; i< sz; i++){
            char c = s[i];
            if(m.contains(c)){

                groupBegin = max(groupBegin, m.at(c) + 1);
                m.at(c) = i;
                
                
            }
            else{
                m.insert({c,i});
            }
            currCount = i - groupBegin+1;
            res = max(currCount, res);
            
        }
       

        return res;
        
    }
};
