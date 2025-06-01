class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        int n = nums.size();

        for(int i=1;i<(1<<n)-1;i++)
        {
            long long int A = 1;
            long long int B = 1;
            for(int j=0;j<n;j++)
            {
                if((i&(1<<j)))
                {
                    A*=nums[j];
                    if(A > target) A = target + 1;
                }
                else
                {
                    B*=nums[j];
                    if(B > target) B = target + 1;
                }
            }
            if(A==target && B==target) return true;
        }
        return false;
    }
};
