class Solution {
private:
    int lower_bound(vector<int>& nums,int target){
        int n = nums.size();
        int low = 0;
        int high = n-1;

        while(low <= high){
            int mid = (high+low)/2;
            if(nums[mid] < target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return low;
    }

    int upper_bound(vector<int>& nums,int target){
        int n = nums.size();
        int low = 0;
        int high = n-1;

        while(low<=high){
            int mid = (high+low)/2;
            if(nums[mid] <= target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }

        return high;
    }


public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // starting position is the lower bound and ending position is the upper bound
        int l = lower_bound(nums,target);
        int r = upper_bound(nums,target);

        int n = nums.size();
        if(l == n || nums[l] != target){
            return {-1,-1};
        }

        return {l,r};
    }
};