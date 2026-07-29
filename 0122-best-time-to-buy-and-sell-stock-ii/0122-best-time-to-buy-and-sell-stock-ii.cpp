class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mini = prices[0];
        int last = prices[0];

        int ans = 0;
        for(int i=1;i<n;i++){
            int num = prices[i];
                if(num >= last){
                    last = num;
                }
                else{
                    ans += last - mini;
                    mini = num;
                    last = num;
                }
        }
        ans += last - mini;
        return ans;
    }
};