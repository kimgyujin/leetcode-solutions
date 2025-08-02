class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int res = 1e9;
        int n = nums.size();

        for(int i=0;i<n;i++)
        {
            int cnt = i;
            int Min = nums[i];
            long long int Max = nums[i];
            Max*=k;
            int idx = upper_bound(nums.begin(),nums.end(),Max) - nums.begin();
            cnt += (n - idx);
            res = min(res,cnt);
        }
        return res;
    }
};
