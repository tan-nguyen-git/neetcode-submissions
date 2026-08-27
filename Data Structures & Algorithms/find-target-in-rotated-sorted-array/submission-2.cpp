class Solution {
public:
    int binarySearch(vector<int>& vec, int l, int r, int target){
        while(l<=r){
            int m = l+(r-l)/2;
            if(vec[m] == target) return m;
            else if(vec[m] > target) r= m -1;
            else l =m+1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;

        // not rotated
        if (nums[0] <= nums[n-1]) return binarySearch(nums, 0, n-1, target);

        // find pivot (index of smallest element)
        int l = 0, r = n - 1;
        while (l < r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] > nums[r]) l = mid + 1;
        else r = mid; // keep mid
    }
        int pivot = l;

        // choose the sorted half
        if (target >= nums[pivot] && target <= nums[n-1])
            return binarySearch(nums, pivot, n-1, target);
        else
            return binarySearch(nums, 0, pivot-1, target);
    }

};