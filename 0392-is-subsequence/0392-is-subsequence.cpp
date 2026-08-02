class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();

        int i=0,j=0;
        while(i<n2 && j<n1){
            if(t[i] == s[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }

        if(j>=n1) return true;
        return false;
    }
};