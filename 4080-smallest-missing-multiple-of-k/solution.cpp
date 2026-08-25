class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set <int> S;
        for(auto it : nums) S.insert(it);
        int val = k;
        while(1)
        {
            if(S.find(val)==S.end()) break;
            val += k;
        }
        return val;
    }
};
