class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        numSet = set()
        n = len(nums)
        for i in range(n):
            if nums[i] in numSet:
                return True
            numSet.add(nums[i])
        
        return False
        