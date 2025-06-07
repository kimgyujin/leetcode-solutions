class Solution {
public:
    long long int gcd(long long int a,long long int b)
    {
        if(b==0) return a;
        return gcd(b,a%b);
    }
    long long maxGCDScore(vector<int>& nums, int k) {
        int n = nums.size();
        long long int res = 0;

        for(int i=0;i<n;i++)
        {
            vector <int> arr(64,0);
            long long int g = 0;
            long long int len = 0;
            for(int j=i;j<n;j++)
            {
                g = gcd(nums[j],g);
                long long int val = nums[j];
                int cnt = 0;
                len += 1;
                while(val > 0)
                {
                    if(val%2!=0) break;
                    val/=2;
                    cnt+=1;
                }
                arr[cnt] += 1;
                val = g;
                cnt = 0;
                while(val > 0)
                {
                    if(val%2!=0) break;
                    val/=2;
                    cnt+=1;
                }      
                int count = 0;
                for(int a=0;a<=cnt;a++) count += arr[a];
                if(count <= k)
                {
                    res = max(res,len*2*g);
                }
                else
                {
                    res = max(res,len*g);
                }
            }
        }
        return res;
    }
};
