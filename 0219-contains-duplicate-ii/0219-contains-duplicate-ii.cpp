class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        int n = nums.size();

        for(int i=0;i<n;i++){
            int val = nums[i];
            if(freq.find(val) == freq.end()){
                freq[val] = i;
            }
            else{
                int index = freq[val];
                if(abs(index-i) <= k) return true;
                freq[val] = i;
            }
        }

        return false;
    }
};