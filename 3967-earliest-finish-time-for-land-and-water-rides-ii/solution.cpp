class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        vector <int> a,b;
        int n = landStartTime.size();
        int m = waterStartTime.size();

        for(int i=0;i<n;i++)
        {
            a.push_back(landStartTime[i] + landDuration[i]);
        }

        for(int i=0;i<m;i++)
        {
            b.push_back(waterStartTime[i] + waterDuration[i]);
        }     

        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        int res = 1e9;

        for(int i=0;i<n;i++)
        {
            int t = b[0];
            if(t < landStartTime[i]) t = landStartTime[i];
            t += landDuration[i];
            res = min(res,t);
        }

        for(int i=0;i<m;i++)
        {
            int t = a[0];
            if(t < waterStartTime[i]) t = waterStartTime[i];
            t += waterDuration[i];
            res = min(res,t);
        }        

        return res;
    }
};
