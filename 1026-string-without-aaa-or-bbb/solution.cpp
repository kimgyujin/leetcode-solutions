#pragma GCC optimize("O3")
#include <bits/stdc++.h>
 
using namespace std;

int dp[101][101][2][3];
pair<pair<int,int>,pair<int,int>> backtracking[101][101][2][3];


class Solution {
public:
    string strWithout3a3b(int A, int B) {
        // write your code in C++14 (g++ 6.2.0)

        memset(dp,-1,sizeof(dp));

        dp[1][0][0][1] = 1;
        dp[0][1][1][1] = 1;
        int n = A + B;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                int a = j;
                int b = i - j;
                if(a > A || b > B)
                {
                    continue;
                }
                for(int k=0;k<2;k++)
                {
                    for(int l=0;l<3;l++)
                    {
                        if(dp[a][b][k][l]==-1)
                        {
                            continue;
                        }
                        if(k==0)
                        {
                            if(l==2)
                            {
                                if(b+1<=B)
                                {
                                    if(dp[a][b+1][1][1] < dp[a][b][k][l] + 1)
                                    {
                                        dp[a][b+1][1][1] = dp[a][b][k][l] + 1;
                                        backtracking[a][b+1][1][1] = make_pair(make_pair(a,b),make_pair(k,l));
                                    }
                                }
                            }
                            else
                            {
                                if(b+1<=B)
                                {
                                    if(dp[a][b+1][1][1] < dp[a][b][k][l] + 1)
                                    {
                                        dp[a][b+1][1][1] = dp[a][b][k][l] + 1;
                                        backtracking[a][b+1][1][1] = make_pair(make_pair(a,b),make_pair(k,l));
                                    }
                                }
                                if(a+1<=A)
                                {
                                    if(dp[a+1][b][k][l+1] < dp[a][b][k][l] + 1)
                                    {
                                        dp[a+1][b][k][l+1] = dp[a][b][k][l] + 1;
                                        backtracking[a+1][b][k][l+1] = make_pair(make_pair(a,b),make_pair(k,l));
                                    }
                                }
                            }
                        }
                        else
                        {
                            if(l==2)
                            {
                                if(a+1<=A)
                                {
                                    if(dp[a+1][b][0][1] < dp[a][b][k][l] + 1)
                                    {
                                        dp[a+1][b][0][1] = dp[a][b][k][l] + 1;
                                        backtracking[a+1][b][0][1] = make_pair(make_pair(a,b),make_pair(k,l));
                                    }
                                }
                            }
                            else
                            {
                                if(a+1<=A)
                                {
                                    if(dp[a+1][b][0][1] < dp[a][b][k][l] + 1)
                                    {
                                        dp[a+1][b][0][1] = dp[a][b][k][l] + 1;
                                        backtracking[a+1][b][0][1] = make_pair(make_pair(a,b),make_pair(k,l));
                                    }
                                }
                                if(b+1<=B)
                                {
                                    if(dp[a][b+1][k][l+1] < dp[a][b][k][l] + 1)
                                    {
                                        dp[a][b+1][k][l+1] = dp[a][b][k][l] + 1;
                                        backtracking[a][b+1][k][l+1] = make_pair(make_pair(a,b),make_pair(k,l));
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        int res = 0;
        int a = A;
        int b = B;
        int x = 0;
        int y = 0;
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(res < dp[A][B][i][j])
                {
                    res = dp[A][B][i][j];
                    x = i;
                    y = j;
                }
            }
        }
        cout << res << '\n';
        stack <char> stk;
        while(1)
        {
            if(a==0 && b==0)
            {
                break;
            }
            int na = backtracking[a][b][x][y].first.first;
            int nb = backtracking[a][b][x][y].first.second;
            int nx = backtracking[a][b][x][y].second.first;
            int ny = backtracking[a][b][x][y].second.second;
            if(na!=a)
            {
                stk.push('a');
            }
            else if(nb!=b)
            {
                stk.push('b');
            }
            a = na;
            b = nb;
            x = nx;
            y = ny;
        }    

        string ans = "";
        while(!stk.empty())
        {
            ans += stk.top();
            stk.pop();
        }
        //cout << ans << '\n';
        return ans;        
    }
};
