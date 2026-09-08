class Solution {
public:
    string minWindow(string s, string t) {
        int sz1 = s.size(), sz2 = t.size();
        if(sz1 < sz2) return "";
        std::string res ="";
        
        std::unordered_map<char, int> m1, m2;
        //m1 store the frequency and unique char inside m1
        for(auto c : t){
            m1[c]++;
        }
        int need = m1.size();
        int have = 0;
        int resSz = INT_MAX;        //start the window with size = sz1
        int l = 0 ;
        int startPos =0;
        for(int r = 0 ; r < sz1 ; r++){
            char c = s[r];
            m2[c]++;
            if(m1.contains(c) && m1[c] == m2[c]){
                have++;
            }
           
            
            while(have == need){
                int strSz = r - l +1;
                if( strSz < resSz ){
                    startPos = l;
                    resSz = strSz;
                }
                m2[s[l]]--;
                if(m1[s[l]] > m2[s[l]] ){
                    have--;
                }
                l++;
            }
        }
        //never been updated
        if(resSz == INT_MAX) return "";
        return s.substr(startPos, resSz);
    }
};
