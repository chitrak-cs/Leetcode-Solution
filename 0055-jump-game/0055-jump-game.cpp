class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int end = 0;
        for(int i=0;i<n;i++){
            int step = nums[i];
            if(i>end) return false;
            end = max(end,i+step);
            if(end>=n) return true;
        }
        return true;
    }
};