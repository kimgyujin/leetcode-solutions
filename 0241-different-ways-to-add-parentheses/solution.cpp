vector <int> calc(vector<int> l,vector<int> r,char op)
{
    vector <int> res;
    for(auto x : l)
    {
        for(auto y : r)
        {
            if(op=='+') res.push_back(x+y);
            else if(op=='-') res.push_back(x-y);
            else res.push_back(x*y);
        }
    }
    return res;
}

vector <int> dfs(string expression)
{
    bool chk = true;
    for(auto c : expression)
    {
        if(!('0'<=c && c<='9'))
        {
            chk = false;
            break;
        }
    }
    if(chk)
    {
        return {stoi(expression)};
    }

    vector <int> res;
    int n = expression.length();
    for(int i=0;i<n;i++)
    {
        if(expression[i]=='+' || expression[i]=='-' || expression[i]=='*')
        {
            vector <int> l = dfs(expression.substr(0,i));
            vector <int> r = dfs(expression.substr(i+1));
            vector <int> result = calc(l,r,expression[i]);
            for(auto it : result) res.push_back(it); 
        }
    }
    return res;
}
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        return dfs(expression);   
    }
};
