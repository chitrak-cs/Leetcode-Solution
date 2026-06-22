class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        vector<long long>prefix(n);
        vector<long long>twice(n);
        sort(nums.begin(),nums.end());

        prefix[0] = nums[0];
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1] + nums[i];
        }

        for(int i=0;i<n;i++){
            twice[i] = 1LL * 2 * nums[i];
        }

        long long ans = -1;
        for(int i=n-1;i>=0;i--){
            if(prefix[i] > twice[i]){
                ans = prefix[i];
                break;
            }
        }

        return ans;
    }
};