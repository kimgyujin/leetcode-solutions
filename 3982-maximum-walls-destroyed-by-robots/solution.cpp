class Solution {
public:
    int dp[100005][2];
    int L[100005];
    int R[100005];
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        vector <pair<int,int>> v;
        int n = robots.size();
        sort(walls.begin(),walls.end());
        for(int i=0;i<n;i++)
        {
            v.push_back(make_pair(robots[i],distance[i]));        
        }

        sort(v.begin(),v.end());

        for(int i=0;i<n;i++)
        {
            L[i] = v[i].second;
            R[i] = v[i].second;
            if(i!=0)
            {
                int d = v[i].first - v[i-1].first - 1;
                L[i] = min(L[i],d);
            }
            if(i!=n-1)
            {
                int d = v[i+1].first - v[i].first - 1;
                R[i] = min(R[i],d);
            }
        }

        for(int i=0;i<n;i++)
        {
            {
                int x = v[i].first - L[i];
                int y = v[i].first;
                int idxL = lower_bound(walls.begin(),walls.end(),x) - walls.begin();
                int idxR = upper_bound(walls.begin(),walls.end(),y) - walls.begin();
                dp[i+1][0] = max(dp[i+1][0],dp[i][0] + (idxR - idxL));
                if(i > 0)
                {
                    x = v[i-1].first + R[i-1] + 1;
                    x = max(x,v[i].first - L[i]);
                    y = v[i].first;
                    idxL = lower_bound(walls.begin(),walls.end(),x) - walls.begin();
                    idxR = upper_bound(walls.begin(),walls.end(),y) - walls.begin();    
                    int num = max(0,idxR - idxL);
                    dp[i+1][0] = max(dp[i+1][0],dp[i][1] + num);
                }
            }
            {
                int x = v[i].first;
                int y = v[i].first + R[i];
                int idxL = lower_bound(walls.begin(),walls.end(),x) - walls.begin();
                int idxR = upper_bound(walls.begin(),walls.end(),y) - walls.begin();
                dp[i+1][1] = max(dp[i+1][1],dp[i][0] + (idxR - idxL));  
                dp[i+1][1] = max(dp[i+1][1],dp[i][1] + (idxR - idxL));                                
            }
        }

        return max(dp[n][0],dp[n][1]);
    }
};
