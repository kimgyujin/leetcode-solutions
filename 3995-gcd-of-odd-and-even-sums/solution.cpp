class Solution {
    long long int gcd(long long int a,long long int b)
    {
        if(b==0) return a;
        return gcd(b,a%b);
    }
public:
    int gcdOfOddEvenSums(int n) {
        long long int odd = 0;
        long long int even = 0;
        for(int i=1;i<=2*n;i++)
        {
            if(i%2==1) odd += i;
            else even += i;
        }

        long long int g = gcd(odd, even);
        return g;
    }
};
