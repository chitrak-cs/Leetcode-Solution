class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        int n = s.size();
        for(int i=0;i<n;i++){
            char ch = s[i];
            if(ch>='a' && ch<='z'){
                str += ch;
            }
            else if(ch>='A' && ch<='Z'){
                int diff = 'A' - 'a';
                str += ch-diff;
            }
            else if(ch>='0' && ch<='9'){
                str += ch;
            }
        }

        n = str.size();
        if(n==0 || n==1) return true;
        int i=0,j=n-1;
        while(i<=j){
            if(str[i] != str[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};