class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, unordered_set<int>> m;
        int sz = nums.size();

        for (int i = 0; i < sz; i++) {
            m[nums[i]].insert(i);
        }

        for (int i = 0; i < sz; i++) {
            int n = nums[i];
            int rem = target - n;

            if (m.contains(rem)) {

                // Same number, such as 3 + 3 = 6
                if (rem == n) {
                    if (m[rem].size() >= 2) {
                        for (int index : m[rem]) {
                            if (index != i) {
                                return {i, index};
                            }
                        }
                    }
                }

                // Different numbers
                else {
                    return {i, *m[rem].begin()};
                }
            }
        }

        return {};
    }
};