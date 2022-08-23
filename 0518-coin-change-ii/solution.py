class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        dp = [0 for i in range(amount+1)]
        dp[0] = 1
        n = len(coins)

        for i in range(n):
            for j in range(amount+1):
                if coins[i] + j > amount:
                    break
                if dp[j]==0:
                    continue
                dp[j + coins[i]] += dp[j]
        
        return dp[amount]
