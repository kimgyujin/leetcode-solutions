class Solution {
public:
    int minTime(string s, vector<int>& order, int k) {
        set <long long int> S;
        int n = s.length();
        S.insert(-1);
        S.insert(n);
        long long int sum = 0;
        for(int i=0;i<order.size();i++)
        {
            auto it = S.lower_bound(order[i]);
            long long int R = *it;
            it--;
            long long int L = *it;
            R = (R - order[i]);
            L = (order[i] - L);
            sum += (L*R);
            if(sum >= k) return i;
            S.insert(order[i]);
        }
        return -1;
    }
};
