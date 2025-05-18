class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            int sum = 0;
            int tmp = nums[i];
            while(tmp > 0)
            {
                sum += (tmp%10);
                tmp/=10;
            }
            if(sum==i) return i;
        }
        return -1;
    }
};
