class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        int n = arrivals.size();
        map <int,int> cnt;
        vector <bool> chk(n,false);
        int res = 0;
        for(int i=0;i<n;i++)
        {
            if(i-w >= 0)
            {
                if(chk[i-w]==false)
                {
                    cnt[arrivals[i-w]] -= 1;
                }
            }
            if(cnt[arrivals[i]]==m)
            {
                chk[i] = true;
                res+=1;
            }
            else
            {
                cnt[arrivals[i]]+=1;
            }
        }
        return res;
    }
};
