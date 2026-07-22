class Solution {
public:
    int maxActiveSectionsAfterTrade(string str) {
        int one = 0;
        int n = str.size();
        for(int i=0;i<n;i++){
            if(str[i] == '1') one++;
        }

        string s = '1' + str + '1';
        n += 2;

        vector<char>charector;
        vector<int>length;
        int i =0;
        while(i<n){
            char ch = s[i];
            int j = i;
            while(j<n && s[j] == ch) j++;
            charector.push_back(ch);
            length.push_back(j-i);
            i=j;
        }

        int gain = 0;
        n = charector.size();
        for(i=1;i<n-1;i++){
            if(charector[i-1] == '0' && charector[i] == '1' && charector[i+1] == '0'){
                int val = length[i-1] + length[i+1];
                gain = max(val,gain);
            }
        }

        return one + gain;
    }
};