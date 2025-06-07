class Solution {
public:
    int arr[1000001];
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        memset(arr,-1,sizeof(arr));
        vector <int> vec;
        int n = x.size();
        for(int i=0;i<n;i++)
        {
            arr[x[i]] = max(arr[x[i]],y[i]);
        }
        for(int i=1;i<=1000000;i++)
        {
            if(arr[i]!=-1) vec.push_back(arr[i]);        
        }

        sort(vec.rbegin(),vec.rend());

        if(vec.size() >= 3)
        {
            return vec[0] + vec[1] + vec[2];
        }
        return -1;
    }
};
