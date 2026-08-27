class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(const string& str: strs){
            res+=str;
            res+='-';
        }
       
        cout<<res<<endl;
        return res;

    }

    vector<string> decode(string s) {
        vector<string> res;
        if(s.size()==0) return {};
        int i=0, spaceIndex=0;

        for(char ch:s){
            cout<<spaceIndex<<endl;
            if(ch =='-'){
                res.push_back(s.substr(i,spaceIndex-i));
                i=spaceIndex+1;
                
            }
            spaceIndex++;

        }
        return res;

    }
};
