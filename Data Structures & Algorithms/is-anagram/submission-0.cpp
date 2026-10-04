class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> m;
        for(const auto& ch : s){
            m[ch]++;
        }
        for(const auto&ch : t){
            if(m.contains(ch)){
                m[ch]--;
                if(m.at(ch) ==0) m.erase(ch);
            }
            else{
                return false;   
            }
            
        }

        return m.empty();

        
    }
};
