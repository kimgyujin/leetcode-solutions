class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int res = 1e9;
        for(auto it : tasks)
        {
            res = min(res,it[0] + it[1]);
        }

        return res;
    }
};
