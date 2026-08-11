class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        vector<int>abit(32);
        vector<int>bbit(32);
        vector<int>cbit(32);

        for(int i=0;i<32;i++){
            abit[i] = (a>>i) & 1;
            bbit[i] = (b>>i) & 1;
            cbit[i] = (c>>i) & 1;
        }

        for(int i=0;i<32;i++){
            if(cbit[i] == 0){
                ans += abit[i] + bbit[i];
            }
            else{
                if(abit[i] == 0 && bbit[i] == 0){
                    ans++;
                }
            }
        }

        return ans;
    }
};