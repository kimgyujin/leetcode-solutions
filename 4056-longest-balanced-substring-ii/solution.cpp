class Solution {
public:
    int longestBalanced(string s) {
        vector <int> v(3,0);
        int n = s.length();
        int res = 1;

        int cnt = 1;
        for(int i=1;i<n;i++)
        {
            if(s[i-1]==s[i])
            {
                cnt+=1;
                res = max(res,cnt);
            }
            else
            {
                cnt = 1;
            }
        }
        res = max(res,cnt);
        
        for(char c='a';c<='c';c++)
        {
            map <int,int> memo;
            memo[0] = 0;
            int cnt = 0;
            for(int j=1;j<=n;j++)
            {
                if(s[j-1]==c)
                {
                    memo.clear();
                    cnt = 0;
                    memo[cnt] = j;
                }
                else
                {
                    if(c=='a')
                    {
                        if(s[j-1]=='b') cnt+=1;
                        else cnt-=1;
                    }
                    else
                    {
                        if(s[j-1]=='a') cnt+=1;
                        else cnt-=1;
                    }
                    if(memo.find(cnt)!=memo.end())
                    {
                        res = max(res,j - memo[cnt]);
                    }
                    else memo[cnt] = j;
                }
            }
        }

        int arr[3];
        memset(arr,0,sizeof(arr));
        map <pair<int,int>,int> memo2;
        memo2[make_pair(0,0)] = 0;
        for(int i=1;i<=n;i++)
        {
            if(s[i-1]=='a') arr[0]+=1;
            else if(s[i-1]=='b') arr[1]+=1;
            else arr[2]+=1;

            pair <int,int> tmp = make_pair(arr[0]-arr[1],arr[0]-arr[2]);
            if(memo2.find(tmp)!=memo2.end())
            {
                res = max(res,i - memo2[tmp]);
            }
            else
            {
                memo2[tmp] = i;
            }
        }
        return res;
    }
};
