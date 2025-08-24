class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int idx = nums[0];
        for(int i=1;i<n;i++)
        {
            if(idx < i) return false;
            idx = max(idx,i + nums[i]);
        }
        return true;
    }
};
