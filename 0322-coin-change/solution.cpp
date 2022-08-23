#include <bits/stdc++.h> 

using namespace std;

int dp[10001];

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
		fill(dp,dp+10001,1e9);
		dp[0] = 0;
		int n = coins.size();

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<=amount;j++)
			{
				if(j + coins[i] > amount) break;
				if(dp[j] >= 1e9) continue;
				dp[j + coins[i]] = min(dp[j + coins[i]],dp[j] + 1);
			}
		}

		if(dp[amount] >= 1e9) return -1;

		return dp[amount];
    }
};
