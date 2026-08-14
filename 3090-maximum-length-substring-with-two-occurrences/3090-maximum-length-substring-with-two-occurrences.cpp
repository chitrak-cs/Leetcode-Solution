class Solution {
public:
    int maximumLengthSubstring(string s) {
       vector<int>letter(26,0);
       int n = s.size();

       int i=0,j=0;
       int maxlen = 1;
       while(j<n){
        letter[s[j]-'a']++;
        while(letter[s[j]- 'a'] > 2){
            letter[s[i]-'a']--;
            i++;
        }
        maxlen = max(maxlen,j-i+1);
        j++;
       }
       return maxlen; 
    }
};