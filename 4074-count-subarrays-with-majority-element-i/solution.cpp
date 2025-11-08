class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
       int res = 0;
       int n = nums.size();
        for(int i=0;i<n;i++)
        {
            int cnt = 0;
            for(int j=i;j<n;j++)
            {
                if(nums[j]==target)
                {
                    cnt+=1;
                }
                int N = (j-i+1)/2 + 1;
                if(cnt >= N)
                {
                    res+=1;
                }
            }
        }
        return res;
    }
};
