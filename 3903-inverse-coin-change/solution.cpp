class Solution {
public:
    long long int ways[101];
    vector<int> findCoins(vector<int>& numWays) {
        vector <int> res;
        int n = numWays.size();

        ways[0] = 1;
        for(int i=0;i<n;i++)
        {
            numWays[i] -= ways[i+1];
            if(numWays[i]==1)
            {
                int c = i+1;
                for(int j=0;j<=n;j++)
                {
                    if(j+c <= n) ways[j+c] += ways[j];        
                }
                res.push_back(c);
            }
        }

        for(int i=0;i<n;i++)
        {
            if(numWays[i] > 1 || numWays[i] < 0) return {};
        }
        return res;
    }
};
