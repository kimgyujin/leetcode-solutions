from collections import defaultdict
class Solution:
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
        value2sum = defaultdict(lambda:1e15+1)
        c_sum = defaultdict(int)

        result = -1e14-1
        temp_sum = 0
        for idx, value in enumerate(nums):
            temp_sum += value
            value2sum[value] = min(value2sum[value], temp_sum)
            c_sum[idx] = temp_sum

            if value + k in value2sum.keys():
                result = max(result, c_sum[idx] - (value2sum[value+k]) + value + k)
            if value - k in value2sum.keys():
                result = max(result, c_sum[idx] - (value2sum[value-k]) + value - k)
        return 0 if result == -1e14-1 else result
