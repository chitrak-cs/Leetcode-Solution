class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        int m = n/3;
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;


        int index = 0;
        while(m--){
            vector<int>temp(3);
            for(int i=0;i<3;i++){
                temp[i] = nums[index];
                index++;
            }
            if(temp[2] - temp[0] > k) return {};
            ans.push_back(temp);

        }

        return ans;
    }
};