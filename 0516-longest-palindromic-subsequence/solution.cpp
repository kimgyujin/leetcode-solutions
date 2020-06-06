int dp[5001][5001];

class Solution {
public:
    int longestPalindromeSubseq(string s) {
    int n = s.length();
	memset(dp,0,sizeof(dp));
	
	int res = 1;
	for(int i=0;i<n;i++)
	{
		dp[i][i] = 1;
	}
	for(int i=0;i<n-1;i++)
	{
		if(s[i]==s[i+1])
		{
			dp[i][i+1] = 2;
			res = 2;
		}
	}
	for(int len=2;len<=n;len++)
	{
		for(int l=0;l<n;l++)
		{
			int r = l + len - 1;
			if(r >= n)
			{
				break;
			}
			if(s[l]==s[r])
			{
				dp[l][r] = max(dp[l][r],dp[l+1][r-1] + 2);
			}
			dp[l][r] = max(dp[l][r],max(dp[l+1][r],dp[l][r-1]));
			res = max(res,dp[l][r]);
		}
	}

	cout << res << '\n';
	return res;    
    }
};
