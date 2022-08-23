class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [(10**9) for i in range (amount+1)]
        dp[0] = 0
        for i in range(len(coins)):
            for j in range(0,amount+1):
                if j + coins[i] > amount:
                    break
                if dp[j] >= 10**9:
                    continue
                dp[j + coins[i]] = min(dp[j + coins[i]],dp[j] + 1)
        if dp[amount] >= 10**9:
            return -1
        
        return dp[amount]


