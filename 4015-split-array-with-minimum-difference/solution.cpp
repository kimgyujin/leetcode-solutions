class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        vector <bool> l(n+2,false);
        vector <bool> r(n+2,false);
        vector <long long int> psum(n+1,0);
        l[0] = true;
        l[1] = true;

        psum[0] = 0;
        for(int i=1;i<=n;i++)
        {
            psum[i] = psum[i-1] + nums[i-1];
        }
        for(int i=2;i<=n;i++)
        {
            if(nums[i-2] < nums[i-1])
            {
                l[i] = true;
            }
            if(l[i]==false) break;
        }

        r[n+1] = true;
        r[n] = true;
        for(int i=n-1;i>=1;i--)
        {
            if(nums[i-1] > nums[i])
            {
                r[i] = true;
            }
            if(r[i]==false) break;
        }

        long long int res = 1e18;
        for(int i=1;i<n;i++)
        {
            if(l[i] && r[i+1])
            {
                long long int A = psum[i];
                long long int B = psum[n] - A;
                res = min(abs(A-B),res);
            }
        }

        if(res>=1e18) res = -1;

        return res;
    }
};
