class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int>letter(26,0);
        int n = s.size();
        for(int i=0;i<n;i++){
            letter[s[i]-'a']++;
        }

        string middle = "";
        for(int i=0;i<26;i++){
            if(letter[i]%2 == 1){
                middle = 'a' + i;
                letter[i]--;
            }
        }

        string left = "";
        for(int i=0;i<26;i++){
            int f = letter[i]/2;
            while(f--){
                left += 'a' + i;
            }
        }

        string right = left;
        reverse(right.begin(),right.end());

        string ans = left + middle + right;
        return ans;
    }
};