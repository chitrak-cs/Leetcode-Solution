class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>prefix(n+1,0);
        for(int i=0;i<n;i++){
            if(nums[i] == target) nums[i] = 1;
            else nums[i] = -1;
        }

        for(int i=1;i<n+1;i++){
            prefix[i] = prefix[i-1] + nums[i-1];
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(prefix[j+1] - prefix[i] > 0) ans++;
            }
        }

        return ans;
    }
};