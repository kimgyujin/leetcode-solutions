class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        vector <int> pmax(n,0);
        vector <int> pmin(n,0);       

        pmax[n-1] = nums[n-1];
        pmin[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            pmax[i] = max(pmax[i+1],nums[i]); 
            pmin[i] = min(pmin[i+1],nums[i]); 
        }

        long long int res = 0;
        for(int i=0;i<n-1;i++)
        {
            long long int X = max(abs(nums[i] - pmin[i+1]),abs(nums[i] - pmax[i+1]));
            res = max(res,X);
        }

        res*=k;

        return res;
    }
};
