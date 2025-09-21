class Solution {
public:
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        map<vector<int>,int> visited;
        int n = nums1.size();
        queue <vector<int>> que;
        que.push(nums1);
        visited[nums1] = 0;
        while(!que.empty())
        {
            vector<int> now = que.front();
            que.pop();

            if(now == nums2) 
            {
                break;
            }

            for(int l=0;l<n;l++)
            {
                vector <int> sub;
                for(int r=l;r<n;r++)
                {
                    sub.push_back(now[r]);
                    vector <int> R;
                    for(int i=0;i<n;i++)
                    {
                        if(i < l || i > r) R.push_back(now[i]);
                    }
                    for(int i=0;i<=R.size();i++)
                    {
                        vector <int> next;
                        for(int j=0;j<i;j++) next.push_back(R[j]);
                        for(auto x : sub) next.push_back(x);
                        for(int j=i;j<R.size();j++) next.push_back(R[j]);
                        if(visited.find(next)==visited.end())
                        {
                            visited[next] = visited[now] + 1;
                            que.push(next);
                        }
                    }
                }
            }
        }

        return visited[nums2];
    }
};
