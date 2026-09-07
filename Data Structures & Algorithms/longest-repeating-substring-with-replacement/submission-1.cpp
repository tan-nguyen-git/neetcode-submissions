class Solution {
public:
    int characterReplacement(string s, int k) {
       
        int sz = s.size();
        int res = 0;
        int l =0;
        std::unordered_map <char, int> m;
        int maxFrequency =0;
        for(int r = 0 ; r <sz ; r++){
            char c = s[r];
            
            //update the frequency
            m[c] ++;
            maxFrequency = max(m[c] , maxFrequency);

            int toReplace = (r - l +1) - maxFrequency;
            while(toReplace >k){
                
               
                m[s[l]]--;
                l++;
                toReplace = (r - l +1) - maxFrequency;
            }
            res= max(res, (r-l+1));



        }
        return  res;
        
    }
};
