class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector <int> v1,v2;
        string token;
        {
            stringstream ss;
            ss << version1;
            while(getline(ss,token,'.'))
            {
                v1.push_back(stoi(token));
            }
        }
        {
            stringstream ss;
            ss << version2;
            while(getline(ss,token,'.'))
            {
                v2.push_back(stoi(token));
            }
        }        
        int n = max(v1.size(),v2.size());
        while(v1.size() < n) v1.push_back(0);
        while(v2.size() < n) v2.push_back(0);

        for(int i=0;i<n;i++)
        {
            if(v1[i] < v2[i]) return -1;
            else if(v1[i] > v2[i]) return 1;
        }
        return 0;
    }
};
