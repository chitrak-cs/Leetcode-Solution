class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        int n = nums.size();

        vector<long long>prefix(n);
        prefix[0] = nums[0];
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1] + nums[i];
        }

        int score = 0;
        for(int i=0;i<n;i++){
            if(prefix[i] > 0) score++;
        }

        return score;
    }
};