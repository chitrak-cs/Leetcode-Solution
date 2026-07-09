class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int id = 1;
        vector<int>components(n);
        components[0] = id;

        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1] <= maxDiff){
                components[i] = id;
            }
            else{
                id++;
                components[i] = id;
            }
        }

        int q = queries.size();
        vector<bool>ans(q);
        for(int i=0;i<q;i++){
            int u = queries[i][0];
            int v = queries[i][1];

            if(components[u] == components[v]){
                ans[i] = true;
            }
            else ans[i] = false;
        }

        return ans;
    }
};