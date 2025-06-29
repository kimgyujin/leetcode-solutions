class Solution {
public:
    vector<int> longestCommonPrefix(vector<string>& words) {
        int n = words.size();
        vector <int> arr;
        vector <int> res;
        multiset <int,greater<int>> S;
        for(int i=0;i<n-1;i++)
        {
            int cnt = 0;
            int N = words[i].length();
            int M = words[i+1].length();
            for(int j=0;j<min(N,M);j++)
            {
                if(words[i][j]!=words[i+1][j]) break;
                cnt+=1;
            }
            arr.push_back(cnt);
            S.insert(cnt);
        }
        arr.push_back(0);
        S.insert(0);

        for(int i=0;i<n;i++)
        {
            S.erase(S.find(arr[i]));
            if(i-1>=0) S.erase(S.find(arr[i-1]));
            if(i==0 || i==n-1)
            {
                res.push_back(*S.begin());
            }
            else
            {
                int cnt = 0;
                int N = words[i-1].length();
                int M = words[i+1].length();
                for(int j=0;j<min(N,M);j++)
                {
                    if(words[i-1][j]!=words[i+1][j]) break;
                    cnt+=1;
                }               
                N = *S.begin();
                N = max(N,cnt);
                res.push_back(N);
            }
            S.insert(arr[i]);
            if(i-1>=0) S.insert(arr[i-1]);            
        }
        return res;
    }
};
