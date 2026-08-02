class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        set<vector<int>> st;

        for(int i=0;i<n;i++){
            int l=0,r=n-1;
            while(l<r){
                if(l!=i && r!=i && (nums[i]+nums[l]+nums[r]==0)){
                    vector<int> v= {nums[i],nums[l],nums[r]};
                    sort(v.begin(),v.end());
                    st.insert(v);
                    l++;r--;
                }
                else if((nums[i]+nums[l]+nums[r] >0)){
                    r--;
                }
                else{
                    l++;
                }
            }
        }

        for(auto &x : st){
            ans.push_back(x);
        }

        return ans;
    }
};