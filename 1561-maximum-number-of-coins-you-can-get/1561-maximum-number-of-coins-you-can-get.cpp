class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        sort(piles.begin(),piles.end());
        reverse(piles.begin(),piles.end());

        int s = n/3;
        int ind = 1;
        int ans = 0;

        vector<int>nums;
        int size = 2*s;
        for(int i=0;i<size;i++){
            nums.push_back(piles[i]);
        }

        for(int i=0;i<s;i++){
            ans += nums[ind];
            ind += 2;
        }

        return ans;
    }
};