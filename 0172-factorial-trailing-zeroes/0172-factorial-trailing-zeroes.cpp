class Solution {
    // number of zero depends on the number of factors of 5
    // formula: [n/5] + [n/25] + [n/125] ..
public:
    int trailingZeroes(int n) {
        int ans = 0;
        while(n>0){
            n = n/5;
            ans += n;
        }

        return ans;
    }
};