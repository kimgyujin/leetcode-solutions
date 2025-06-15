class Solution {
public:
    string generateTag(string caption) {
        stringstream ss;
        ss << caption;
        vector <string> word;
        string t;
        while(ss >> t) word.push_back(t);

        string res = "#";
        for(int i=0;i<word.size();i++)
        {
            for(int j=0;j<word[i].length();j++)
            {
                if(res.length() >= 100) break;
                if(j==0)
                {
                    if(i==0)
                    {
                        char ch = word[i][j];
                        if(ch>='A' && ch <='Z') ch = (char)(ch-'A'+'a');
                        res += ch;                        
                    }
                    else
                    {
                        char ch = word[i][j];
                        if(ch>='a' && ch <='z') ch = (char)(ch-'a'+'A');
                        res += ch;                        
                    }
                }
                else
                {
                    char ch = word[i][j];
                    if(ch>='A' && ch <='Z') ch = (char)(ch-'A'+'a');
                    res += ch;
                }
            }
            if(res.length() >= 100) break;
        }

        return res;
    }
};
