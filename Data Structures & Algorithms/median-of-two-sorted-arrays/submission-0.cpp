class Solution {
public:
    //need to use binary search
    //find the one with the bigger size array
   
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()){
            swap(nums1, nums2); //just swap pointer O(1) 
        }
        int n = nums1.size();
        int m = nums2.size();

        int left = 0;
        int right = n;

        int half = (m + n +1)/2;

        while(left <= right){
            // Partition nums1
            int i = left + (right - left) / 2; // this is just (l + r)/2
            // Partition nums2
            int j = half - i;

            // Values immediately around the partitions
            int nums1Left  = (i == 0) ? INT_MIN : nums1[i - 1];
            int nums1Right = (i == n) ? INT_MAX : nums1[i];

            int nums2Left  = (j == 0) ? INT_MIN : nums2[j - 1];
            int nums2Right = (j == m) ? INT_MAX : nums2[j];

            // nums1 partition is too far left
            if (nums1Left > nums2Right) {
                right = i - 1;
            }

            // nums1 partition is too far right
            else if (nums2Left > nums1Right) {
                left = i + 1;
            }

            // Correct partition
            else {
                int leftMax = max(nums1Left, nums2Left);
                int rightMin = min(nums1Right, nums2Right);

                // Odd number of elements
                if ((n + m) % 2 == 1) {
                    return leftMax;
                }

                // Even number of elements
                return (leftMax + rightMin) / 2.0;
            }
        }

        return 0.0;
    }
    

    
};
