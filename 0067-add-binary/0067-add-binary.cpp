class Solution {
public:
    string addBinary(string a, string b) {
        int n1 = a.size();
        int n2 = b.size();
        int i=n1-1;
        int j=n2-1;
        int carry = 0;
        string ans = "";
        while(i>=0 || j>=0 || carry){
            int sum = carry;
            if(i>=0){
                sum += a[i] - '0';
                i--;
            }

            if(j>=0){
                sum += b[j] - '0';
                j--;
            }

            char val = sum % 2 + '0';
            ans.push_back(val);
            carry = sum / 2;
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};