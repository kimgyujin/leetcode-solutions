class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        long long int sum = 0;
        int res = 0;
        int cnt = 0;
        bool chk[201];
        memset(chk,false,sizeof(chk));
        for(auto x : nums)
        {
            sum += x;
            cnt+=1;
            if(x >= 0) chk[x] = true;
        }

        res = sum/cnt + 1;
        res = max(res, 1);

        if(res > 100)
        {
            return res;
        }
        
        while(res <= 200)
        {
            if(chk[res]==false) break;
            res+=1;
        }

        return res;
        
    }
};
