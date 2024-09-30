class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        vector <char> stk(n+1);
        int idx = -1;
        map <char,char> mn;
        for(auto ch : s)
        {
             if(ch=='(')
             {
                 idx+=1;
                 stk[idx] = ')';
             }
             else if(ch=='{')
             {
                 idx+=1;
                 stk[idx] = '}';
             }         
             else if(ch=='[')
             {
                 idx+=1;
                 stk[idx] = ']';
             }   
             else
             {
                 if(idx < 0) return false;
                 if(stk[idx]!=ch) return false;
                 idx--;
             }
        }
        
        if(idx >= 0) return false;
        return true;
    }
};
