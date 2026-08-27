class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int laE = nums[n-1];
        if(nums[0] < laE) return nums[0];

        int l =0, r= n -2;
        int res = laE;
        while(l <= r){
            int m = l + (r-l)/2;
            if(nums[m] > laE){
                l = m+1;
            }
            //equal never happen
            else{
                r = m -1;
                res=nums[m];
            }
        }
        cout<<res<<"-"<<laE<<endl;
        return min(res,laE);

        
    }
};
