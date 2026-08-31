class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int sz = nums.size();
        // n+1 integers and range 1 to n inclusive
        // every value is valid index, repeted means
        // 2 or more value index point to one value => detecting cycle proplem
        // in this case there have to be a cycle and the ie the repeated number
        
        int slow = 0;
        int fast =0;
        int count = 0;
        while(true){
            slow = nums[slow];
            fast= nums[nums[fast]];

            if(slow == fast ){
                slow = 0;
                while(slow != fast){
                    slow = nums[slow];
                    fast= nums[fast];
                }
                return slow;
            }
        }
        return 0;
    }
};
