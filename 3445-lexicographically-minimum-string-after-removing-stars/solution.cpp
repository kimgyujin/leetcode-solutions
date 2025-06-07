class Solution {
public:
    string clearStars(string s) {
        priority_queue <pair<int,int>> pque;
        int n = s.length();
        set <int> S;
        string res = "";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!='*')
            {
                pque.push(make_pair(-(s[i]-'a'),i));
            }
            else
            {
                if(!pque.empty())
                {
                    S.insert(pque.top().second);
                    pque.pop();
                }
            }
        }
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!='*')
            {
                if(S.find(i)==S.end()) res += s[i];
            }
        }
        return res;
    }
};
