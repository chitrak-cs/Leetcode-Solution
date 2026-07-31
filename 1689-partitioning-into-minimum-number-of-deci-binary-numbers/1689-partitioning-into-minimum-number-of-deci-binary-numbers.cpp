class Solution {
public:
    int minPartitions(string str) {
        int ans = 0;
        int n = str.size();
        for(int i=0;i<n;i++){
            int digit = str[i] - '0';
            ans = max(ans,digit);
        }
        return ans;
    }
};