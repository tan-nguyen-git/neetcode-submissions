class Solution {
public:
    //you have h hours to eat 
    //upper bound is the last element after sort
    //max rate is the element, ceil (x/k) to finish x pile
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int startRate = 1;
        int maxRate = -1;
        for(auto x: piles){
            if(x > maxRate) maxRate = x;
        }
        int res = 0;
        while(startRate <= maxRate){
            int hour =0;
            int mRate = startRate + (maxRate - startRate)/2;
            for(auto x: piles){
                hour += ceil((double)x/mRate);

            }
            if(hour <= h){
                maxRate = mRate -1;
                res = mRate;
            }
            else{
                startRate = mRate +1;
            }

        }
        
        return res;
        
    }
};
