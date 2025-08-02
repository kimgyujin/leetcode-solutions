class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int res = 1e9;
        int n = landStartTime.size();
        int m = waterStartTime.size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                {
                    int t = 0;
                    if(t < landStartTime[i])
                    {
                        t = landStartTime[i];
                    }
                    t += landDuration[i];
                    if(t < waterStartTime[j])
                    {
                        t = waterStartTime[j];
                    }
                    t += waterDuration[j];
                    res = min(res,t);
                }
                {
                    int t = 0;
                    if(t < waterStartTime[j])
                    {
                        t = waterStartTime[j];
                    }
                    t += waterDuration[j];                    
                    if(t < landStartTime[i])
                    {
                        t = landStartTime[i];
                    }
                    t += landDuration[i];
                    res = min(res,t);
                }                
            }
        }
        return res;
    }
};
