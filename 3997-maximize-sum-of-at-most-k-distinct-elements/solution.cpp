class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        set <long long int,greater<long long int>> S;
        for(auto x : nums) S.insert(x);

        vector <int> res;
        for(auto x : S)
        {
            if(res.size() >= k) break;
            res.push_back(x);
        }

        return res;
    }
};
