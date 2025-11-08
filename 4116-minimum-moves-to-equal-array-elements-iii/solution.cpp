class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        int res = 0;
        for(auto x : nums)
            {
                res += (nums[0] - x);
            }
        return res;
    }
};
