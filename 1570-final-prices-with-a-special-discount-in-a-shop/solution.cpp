class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector <int> res;
        int n = prices.size();
        for(int i=0;i<n;i++)
        {
            bool ok = false;
            for(int j=i+1;j<n;j++)
            {
                if(prices[j] <= prices[i])
                {
                    res.push_back(prices[i] - prices[j]);
                    ok = true;
                    break;
                }
            }
            if(!ok) res.push_back(prices[i]);
        }

        return res;
    }
};
