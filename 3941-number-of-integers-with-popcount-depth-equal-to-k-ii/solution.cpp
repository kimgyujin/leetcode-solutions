#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
class Solution {
public:
    ordered_set S[6];    
    int func(long long int x)
    {
        int d = 0;
        while(x > 1)
        {
            d+=1;
            long long int cnt = 0;
            long long int tmp = x;
            while(tmp > 0)
            {
                cnt += (tmp%2);
                tmp/=2;
            }
            x = cnt;
        }
        return d;
    }
    vector<int> popcountDepth(vector<long long>& nums, vector<vector<long long>>& queries) {
        vector <int> res;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            int d = func(nums[i]);
            if(d <= 5)
            {
                S[d].insert(i);
            }
        }

        int q = queries.size();
        for(int i=0;i<q;i++)
        {
            if(queries[i][0]==1)
            {
                int l = queries[i][1];
                int r = queries[i][2];
                int k = queries[i][3];
                int num = S[k].order_of_key(r+1) - S[k].order_of_key(l);
                res.push_back(num);
            }
            else
            {
                int idx = queries[i][1];
                long long int val = queries[i][2];
                long long int pval = nums[idx];
                int pd = func(pval);
                int d = func(val);
                if(pd <= 5) S[pd].erase(idx);
                nums[idx] = val;
                if(d <= 5) S[d].insert(idx);
            }
        }
        return res;
    }
};
