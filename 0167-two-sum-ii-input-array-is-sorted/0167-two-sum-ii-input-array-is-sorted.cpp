class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int>mpp;
        int n = numbers.size();
        for(int i=0;i<n;i++){
            int extra = target - numbers[i];
            if(mpp.find(extra) != mpp.end()){
                // number is found
                int index = mpp[extra];
                return {index+1,i+1};
            }
            else{
                mpp[numbers[i]] = i;
            }
        }

        return {-1,-1};
    }
};