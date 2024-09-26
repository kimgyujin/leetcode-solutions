class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int n = prices.size();
        int Min = prices[0]; // 해당 변수는 첫번째 날부터 i-1번째 날까지의 가격의 최소값
        // 싸게 사서 비싸게 파는 것이 중요함.
        for(int i=1;i<n;i++)
        {
            res = max(res,prices[i] - Min); // 정답 갱신
            Min = min(Min,prices[i]); //최소값 갱신
        }
        return res;
    }
};
