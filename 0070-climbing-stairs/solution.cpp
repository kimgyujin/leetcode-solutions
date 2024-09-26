class Solution {
public:
    int climbStairs(int n) {
		    // 각 층로부터 1층 또는 2층으로 나갈 수 있기 때문에 점화식을 다음과 같이 세울 수 있음.
		    // a_i = a_(i-1) + a_(i-2)
		    // 사실 피보나치 수열
		    vector <long long int> f(n+1);
        f[0] = 1;
        f[1] = 1;
        for(int i=2;i<=n;i++)
        {
            f[i] = f[i-1] + f[i-2];
        }
        return f[n];
    }
};
