class Solution:
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
        n = len(nums)
        psum = [0]*(n+1)
        for i in range(n):
            psum[i+1] = psum[i] + nums[i]
        memo = dict()
        res = -1e18
        for i in range(n):
            x = nums[i] - k
            y = nums[i] + k

            if x in memo.keys():
                res = max(res, psum[i+1] - memo[x])
            if y in memo.keys():
                res = max(res, psum[i+1] - memo[y])
            if not nums[i] in memo.keys():
                memo[nums[i]] = psum[i]
            else:
                memo[nums[i]] = min(memo[nums[i]],psum[i])
    
        if res == -1e18:
            res = 0
        return res
