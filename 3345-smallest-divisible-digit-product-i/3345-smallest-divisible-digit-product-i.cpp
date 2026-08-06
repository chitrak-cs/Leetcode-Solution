class Solution {
private:
    int product(int n){
        int ans = 1;
        while(n>1){
            ans *= n%10;
            n = n/10;
        }
        return ans;
    }
public:
    int smallestNumber(int n, int t) {
        while(product(n)%t != 0){
            n++;
        }
        return n;
    }
};