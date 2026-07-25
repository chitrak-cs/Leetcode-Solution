class Solution {
public:
    int maxProduct(int n) {
        string num = to_string(n);
        vector<int>freq(10);
        for(int i=0;i<num.size();i++){
            int digit = num[i]-'0';
            freq[digit]++;
        }

        int ans = 1;
        int cnt = 0;
        int i=9;
        while(i>=0 and cnt<2){
            if(freq[i] >= 2){
                if(cnt == 0){
                    ans = i*i;
                    return ans;
                }
                else ans *= i;
                cnt += 1;
            }
            else if(freq[i] == 1){
                ans *= i;
                cnt += 1;
            }
            i--;
        }

        return ans;
    }
};