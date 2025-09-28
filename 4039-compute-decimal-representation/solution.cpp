class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        long long int x = 1e9;
        vector <int> res;
        while(x > 0)
        {
            int a = n/x;
            n%=x;
            if(a > 0) res.push_back(x*a);
            x/=10;
        }

        return res;
    }
};
