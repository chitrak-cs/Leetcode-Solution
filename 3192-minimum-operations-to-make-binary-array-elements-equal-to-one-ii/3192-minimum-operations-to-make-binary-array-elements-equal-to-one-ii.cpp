class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int flip = 0;

        for(int i=0;i<n;i++){
            int cur = nums[i];

            if(flip%2 == 1){
                cur = 1 - cur;
            }

            if(cur == 0){
                ans ++;
                flip++;
            }
        }

        return ans;
    }
};