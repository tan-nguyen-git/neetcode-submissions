class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int  sz1 = s1.size(), sz2 = s2.size();
        if(sz1 > sz2) return false;
        int l =0, r = sz1 -1;
        //this map will store the frequency and the charactor
        std::unordered_map <char, int> m1,m2;
        for(auto c : s1){
            m1[c] ++;
        }

        for(int l = 0, r = sz1 -1; r < sz2 ; l++, r ++){
            
            if(l == 0){
                int count = 0;
                while(count <= r){
                    m2[s2[count]]++;
                    count++;
                }
                
            }
            else{
                
                m2[s2[l-1]] --;
                if(m2[s2[l-1] ]==0){
                    m2.erase(s2[l-1]);
                }
                m2[s2[r]]++;
            }
            if(m2 == m1) return true;
            
        }
        return false;
    }
};
