class Solution {
public:
    string processStr(string s) {
        string res;
        res = "";
        for(auto it : s)
        {
            if(it=='*')
            {
                if(res.length() > 0) res.pop_back();
            }
            else if(it=='#')
            {
                res += res;
            }
            else if(it=='%')
            {
                reverse(res.begin(),res.end());
            }
            else
            {
                res += it;
            }
        }
        return res;
    }
};
