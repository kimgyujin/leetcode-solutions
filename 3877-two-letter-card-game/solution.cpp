class Solution {
public:
    int score(vector<string>& cards, char x) {
        int cnt[2][10];
        int res = 0;
        int cnt2 = 0;
        
        memset(cnt,0,sizeof(cnt));

        for(auto c : cards)
        {
            if(c[0]==x && c[1]==x) cnt2+=1;
            else if(c[0]==x) cnt[0][c[1]-'a'] += 1;
            else if(c[1]==x) cnt[1][c[0]-'a'] += 1;
        }

        for(int c=0;c<=cnt2;c++)
        {
            int sum = 0;
            priority_queue <int> pque[2];
            if(c > 0) pque[0].push(c);
            if(cnt2-c > 0) pque[1].push(cnt2-c);
            for(int i=0;i<10;i++)
            {
                if(cnt[0][i] > 0) pque[0].push(cnt[0][i]);
                if(cnt[1][i] > 0) pque[1].push(cnt[1][i]);
                
            }

            while(pque[0].size() > 1)
            {
                auto p1 = pque[0].top();
                pque[0].pop();
                auto p2 = pque[0].top();
                pque[0].pop();

                int a = (p2 + 1)/2;
                p1 -= a;
                p2 -= a;
                sum += a;
                if(p1 > 0) pque[0].push(p1);
                if(p2 > 0) pque[0].push(p2);
            }

            while(pque[1].size() > 1)
            {
                auto p1 = pque[1].top();
                pque[1].pop();
                auto p2 = pque[1].top();
                pque[1].pop();

                int a = (p2 + 1)/2;
                p1 -= a;
                p2 -= a;
                sum += a;
                if(p1 > 0) pque[1].push(p1);
                if(p2 > 0) pque[1].push(p2);
            }            

            res = max(res,sum);
        }

        return res;
    }
};
