class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();

        int curmax = nums[0];
        int maxsum = curmax;

        int curmin = nums[0];
        int minsum = curmin;

        int total = nums[0];
        for(int i=1;i<n;i++){
            int x = nums[i];
            curmax = max(x,curmax+x);
            maxsum = max(curmax,maxsum);

            curmin = min(x,curmin+x);
            minsum = min(curmin,minsum);

            total += x;
        }

        int ans = max(maxsum,total-minsum);
        if(maxsum < 0){
            ans = maxsum;
        }

        return ans;
    }
};