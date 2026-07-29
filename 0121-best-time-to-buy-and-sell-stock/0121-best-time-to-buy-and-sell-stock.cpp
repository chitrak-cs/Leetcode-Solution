class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int minprice = INT_MAX;
        int n = prices.size();

        for(int i=0;i<n;i++){
            if(prices[i] < minprice){
                minprice = prices[i];
            }
            else{
                int profit = prices[i] - minprice;
                maxprofit = max(maxprofit,profit);
            }
        }

        return maxprofit;
    }
};