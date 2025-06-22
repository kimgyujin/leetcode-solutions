class Solution {
public:
    double dp[1<<12][5];
    double minTime(int n, int k, int m, vector<int>& time, vector<double>& mul) {
        for(int i=0;i<(1<<n);i++)
        {
            for(int j=0;j<m;j++)
            {
                dp[i][j] = 1e18;
            }
        }

        dp[0][0] = 0;
        priority_queue <pair<double,pair<int,int>>,vector<pair<double,pair<int,int>>>,greater<pair<double,pair<int,int>>>> pque;
        pque.push(make_pair(dp[0][0],make_pair(0,0)));
        while(!pque.empty())
        {
            int i = pque.top().second.first;
            int j = pque.top().second.second;
            if(dp[i][j] < pque.top().first)
            {
                pque.pop();
                continue;
            }
            pque.pop();
            for(int a=1;a<(1<<n);a++)
            {
                int bcnt = __builtin_popcount(a);
                if(bcnt <= k)
                {
                    if((i&a)==0)
                    {
                        int T = 0;
                        for(int b=0;b<n;b++)
                        {
                            if((a&(1<<b)))
                            {
                                if(T < time[b]) T = time[b];
                            }
                        }
                        if((i|a)==(1<<n)-1)
                        {
                            double total = T*mul[j];
                            int state = total;
                            state+=j;
                            state%=m;
                            int ni = i|a;
                            int nj = state;
                            if(dp[ni][nj] > dp[i][j] + total)
                            {
                                dp[ni][nj] = dp[i][j] + total;
                                pque.push(make_pair(dp[ni][nj],make_pair(ni,nj)));
                            }
                        }
                        else
                        {
                            double total = T*mul[j];
                            int state = floor(total);
                            state%=m;
                            state+=j;
                            state%=m;
                            int ni = (i | a);
                            for(int b=0;b<n;b++)
                            {
                                if((ni&(1<<b)))
                                {
                                    double total2 = time[b]*mul[state];
                                    int state2 = floor(total2);
                                    state2%=m;
                                    state2 += state;
                                    state2%=m;
                                    int ni = (i|a) - (1<<b);
                                    int nj = state2;
                                    if(dp[ni][nj] > dp[i][j] + total + total2)
                                    {
                                        dp[ni][nj] = dp[i][j] + total + total2;
                                        pque.push(make_pair(dp[ni][nj],make_pair(ni,nj)));
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        double res = 1e18;
        for(int i=0;i<m;i++)
        {
            res = min(res,dp[(1<<n)-1][i]);
        }
        if(res >= 1e18) res = -1;
        return res;
    }
};
