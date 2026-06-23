class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int m = strs.size();
        int n = strs[0].size();
        string ans = "";

        for(int i=0;i<n;i++){
            char ch = strs[0][i];
            for(int j=1;j<m;j++){
                string str = strs[j];
                if(str.size()<i || ch != str[i]) return ans;
            }
            ans += ch;
        }

        return ans;
    }
};