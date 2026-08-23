class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int>indices;
        int n = boxes.size();

        for(int i=0;i<n;i++){
            if(boxes[i] == '1'){
                indices.push_back(i);
            }
        }

        vector<int>ans(n);
        for(int i=0;i<n;i++){
            int cnt = 0;
            for(auto index:indices){
                cnt += abs(i-index);
            }
            ans[i] = cnt;
        }

        return ans;
    }
};