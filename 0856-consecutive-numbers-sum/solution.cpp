class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int res = 0;
        for(long long int l=1; ;l++)
        {
            long long int A = l*(l-1);
            A/=2;
            A = n - A;
            if(A < 0) break;
            if(A%l==0)
            {
                if(A/l > 0) res+=1;
            }
        }
        return res;
    }
};
