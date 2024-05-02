class Solution {
    vector <int> a,b;
    vector <int> pi;
    vector <int> res;

    void kmp()
    {
        int j = 0;
        for(int i=0; i<a.size(); i++)
        {
            while(j>0 && a[i] != b[j])
            {
                j = pi[j-1];
            }
            if(a[i] == b[j])
            {
                if(j==b.size() - 1)
                {
                    res.push_back(i - b.size() + 1);
                    j = pi[j];
                }
                else
                {
                    j++;
                }
            }
        }
    }

    void getpi()
    {
        pi.resize(b.size());
        int j = 0;
        for(int i=1; i<b.size(); i++)
        {
            while(j>0 && b[i] != b[j])
            {
                j = pi[j-1];
            }
            if(b[i]==b[j])
            {
                pi[i] = ++j;
            }
        }
    }
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        b = pattern;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] > nums[i-1]) a.push_back(1);
            else if(nums[i]==nums[i-1]) a.push_back(0);
            else a.push_back(-1);
        }
        getpi();
        kmp();
        return res.size();
    }
};
