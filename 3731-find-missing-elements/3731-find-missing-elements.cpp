class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int start = nums[0];
        int end = nums[0];
        unordered_set<int>st;

        int n = nums.size();
        for(int i=0;i<n;i++){
            start = min(start,nums[i]);
            end = max(end,nums[i]);
            st.insert(nums[i]);
        }

        vector<int>ans;
        for(int i=start;i<=end;i++){
            if(st.find(i) == st.end()){
                ans.push_back(i);
            }
        }

        return ans;
    }
};