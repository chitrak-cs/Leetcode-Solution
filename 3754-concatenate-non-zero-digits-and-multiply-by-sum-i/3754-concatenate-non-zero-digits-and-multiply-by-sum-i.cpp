class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n==0){
            return 0;
        }
        string temp = to_string(n);
        string ans = "";
        for(auto ch:temp){
            if(ch != '0'){
                ans += ch;
            }
        }

        n = stoi(ans);
        int digit = 0;
        for(auto ch:ans){
            int val = ch - '0';
            digit += val;
        }

        long long answer = 1LL * digit * n;
        return answer;
    }
};