class Solution {
public:
    int possibleStringCount(string word) {
        int res = 1;
        char ch = word[0];
        int cnt = 1;
        for(int i=1;i<word.length();i++)
        {
            if(ch==word[i]) cnt+=1;
            else
            {
                res += (cnt-1);
                ch = word[i];
                cnt = 1;
            }
        }
        res += (cnt-1);
        return res;
    }
};
