class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            int r = i + 2*k - 1;
            if(r >= n) break;
            vector <int> a,b;
            for(int j=i;j<i+k;j++)
            {
                a.push_back(nums[j]);
            }
            for(int j=i+k;j<i+2*k;j++)
            {
                b.push_back(nums[j]);
            }
            bool ok = true;
            for(int j=1;j<k;j++)
            {
                if(a[j-1] >= a[j] || b[j-1] >= b[j])
                {
                    ok = false;
                    break;
                }
            }
            if(ok) return true;
        }
        return false;
    }
};
