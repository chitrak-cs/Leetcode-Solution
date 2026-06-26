class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>prefix(n);
        for(int i=0;i<n;i++){
            if(nums[i] == target) nums[i] = 1;
            else nums[i] = -1;
        }

        prefix[0] = nums[0];
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1] + nums[i];
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int sum = 0;
                if(i>0){
                    sum = prefix[j] - prefix[i-1];
                }
                else sum = prefix[j];
                if(sum > 0) ans++;
            }
        }

        return ans;
    }
};