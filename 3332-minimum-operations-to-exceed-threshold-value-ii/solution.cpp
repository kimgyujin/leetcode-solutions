class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue <long long int,vector<long long int>,greater<long long int>> pque;
        for(auto num : nums)
        {
            pque.push(num);
        }
        
        int res = 0;
        while(pque.top() < k)
        {
            long long int x = pque.top();
            pque.pop();
            long long int y = pque.top();
            pque.pop();
            res+=1;
            pque.push(x*2 + y);
        }
        return res;
    }
};
