class Solution {
public:
    bool checkDivisibility(int n) {
        long long int mul = 1;
        long long int sum = 0;
        long long int tmp = n;
        while(tmp > 0)
        {
            int x = (tmp%10);
            tmp/=10;
            sum+=x;
            mul*=x;
        }

        sum += mul;

        if(n%sum==0) return true;
        return false;
    }
};
