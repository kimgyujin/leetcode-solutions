#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<long long int, null_type, less_equal<long long int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset; 

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        ordered_multiset S;
        S.insert(0);
        long long int sum = 0;
        int res = 0;
        for(auto x : nums)
        {
            sum += x;
            long long int L = sum;
            L -= upper;
            long long int R = sum;
            R -= lower;
            R += 1;
            int l = S.order_of_key(L);
            int r = S.order_of_key(R);
           // cout << sum << ' ' << L << ' ' << R << ' ' << l << ' ' << r << '\n';
            if(r-l > 0) res += (r-l);
            S.insert(sum);
        }
        return res;
    }
};
