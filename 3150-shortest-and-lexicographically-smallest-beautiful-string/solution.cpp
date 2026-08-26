class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string res = "";
        int n = s.length();
        for(int i=0;i<n;i++)
        {
            int cnt = 0;
            string t = "";
            for(int j=i;j<n;j++)
            {
                t += s[j];
                if(s[j]=='1') cnt+=1;
                if(cnt==k)
                {
                    if(res=="")
                    {
                        res = t;
                    }
                    else
                    {
                        if(res.length() > t.length())
                        {
                            res = t;
                        }
                        else if(res.length() == t.length())
                        {
                            res = min(res,t);
                        }
                    }
                    break;
                }
            }
        }
        return res;
    }
};
