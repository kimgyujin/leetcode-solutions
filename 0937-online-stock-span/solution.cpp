class StockSpanner {
public:
    vector <int> vec;
    StockSpanner() {
    }
    
    int next(int price) {
        int n = vec.size();
        int res = -1;
        for(int i=n-1;i>=0;i--)
        {
            if(price < vec[i])
            {
                res = n - i;
                break;
            }
        }
        if(res==-1) res = n+1;
        vec.push_back(price);
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
