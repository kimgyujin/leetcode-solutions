class Solution {
public:
    int cnt[100001];
    bool partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(n%k!=0) return false;
        
        memset(cnt,0,sizeof(cnt));
        
        for(auto x : nums)
        {
            cnt[x] += 1;
        }

        for(int i=1;i<=100000;i++)
        {
            if(cnt[i] > 0) 
            {
                if(cnt[i] > n/k) return false;
            }
        }

        return true;
    }
};
