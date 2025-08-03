class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        vector <int> v;
        if(nums[1] > nums[0]) v.push_back(1);
        else if(nums[1] < nums[0]) v.push_back(-1);
        else return false;
        for(int i=2;i<n;i++)
        {
            if(nums[i]==nums[i-1]) return false;
            if(v.back()==1)
            {
                if(nums[i] < nums[i-1]) v.push_back(-1);
            }
            else
            {
                if(nums[i] > nums[i-1]) v.push_back(1);
            }
        }

        if(v.size()==3)
        {
            if(v[0]==1 && v[1]==-1 && v[2]==1) return true;
        }
        return false;
    }
};
