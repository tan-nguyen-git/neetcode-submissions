class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        stack<pair<int,int>> s;
        int res = 0;
        vector<pair<int,int>> pS;
        for(int i = 0 ; i < n ; i++){
            pS.push_back({position[i],speed[i]});
        }

        sort(pS.begin(), pS.end(), [](pair<int, int> a, pair<int,int>b){
                                            return a.first > b.first;
        });

        for(auto p: pS){
            if(!s.empty()){
                double t = (double)(target - p.first)/ p.second;
                double time = (double)(target - s.top().first) / s.top().second;
                if(t <=  time) continue;
                else{
                    s.pop();
                }
            }
            res++;
            s.push({p.first, p.second});

        }

        return res;
        
    }
};