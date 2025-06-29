class Solution {
public:
    vector<string> partitionString(string s) {
        set <string> S;
        string a = "";
        vector <string> res;
        for(char ch : s)
        {
            a += ch;
            if(S.find(a)==S.end())
            {
                S.insert(a);
                res.push_back(a);
                a = "";
            }
        }
 
        return res;
    }
};
