class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        if(n==1) res = 1;
        else res = 2;
        int cnt = 2;

        for(int i=2;i<n;i++)
        {
            if(nums[i-2] + nums[i-1] == nums[i])
            {
                cnt+=1;
                res = max(res,cnt);
            }
            else
            {
                cnt = 2;
            }
        }

        return res;
    }
};
