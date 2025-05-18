class Solution {
public:    
    int uf[100001];
    int find(int x)
    {
        if(uf[x] < 0) return x;
        return uf[x] = find(uf[x]);
    }

    void merge(int x,int y)
    {
        x = find(x);
        y = find(y);
        if(x==y) return;
        uf[x] += uf[y];
        uf[y] = x;
        return;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector <int> v = nums;
        sort(v.begin(),v.end(),[](int a,int b){
            int tmpa = a;
            int suma = 0;
            int tmpb = b;
            int sumb = 0;
            while(tmpa > 0)
            {
                suma += (tmpa%10);
                tmpa/=10;
            }
            while(tmpb > 0)
            {
                sumb += (tmpb%10);
                tmpb/=10;
            }

            if(suma==sumb)
            {
                return a < b;
            }
            return suma < sumb;            
        });
        map <int,int> mn;
        for(int i=0;i<n;i++)
        {
            mn[v[i]] = i;
        }
        
        for(int i=0;i<n;i++)
        {
            nums[i] = mn[nums[i]];
        }
        
        memset(uf,-1,sizeof(uf));
        for(int i=0;i<n;i++)
        {
            merge(i,nums[i]);
        }
        
        int res = 0;
        for(int i=0;i<n;i++)
        {
            if(uf[i] < 0)
            {
                res += (abs(uf[i]) - 1);
            }
        }
        
        return res;
    }
};
