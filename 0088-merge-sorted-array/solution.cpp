class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        priority_queue <int> pque;
        for(int i=0;i<m;i++) pque.push(-nums1[i]);
        for(int i=0;i<n;i++) pque.push(-nums2[i]);

        nums1.clear();

        while(!pque.empty())
        {
            nums1.push_back(-pque.top());
            pque.pop();
        }
    }
};
