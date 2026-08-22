class Solution {
public:
    bool checkDivisibility(int n) {
        string str = to_string(n);
        int sum = 0;
        int prod = 1;
        for(auto s:str){
            int digit = s - '0';
            sum += digit;
            prod *= digit;
        }

        if(n % (sum+prod) == 0){
            return true;
        }
        return false;
    }
};