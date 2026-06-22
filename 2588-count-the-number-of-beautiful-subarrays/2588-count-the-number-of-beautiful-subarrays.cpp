class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        unordered_map<long long,int> mp;

        long long xr = 0;
        long long ans = 0;

        mp[0] = 1;

        for(auto x : nums){
            xr ^= x;
            ans += mp[xr];
            mp[xr]++;
        }

        return ans;
    }
};