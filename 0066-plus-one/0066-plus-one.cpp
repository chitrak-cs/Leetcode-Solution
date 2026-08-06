class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int index = n-1;
        int last = digits[n-1];
        last++;
        int carry = 0;
        carry += last/10;
        last = last % 10;
        index--;
        vector<int>ans;
        ans.push_back(last);
        while(index>=0){
            last = carry + digits[index];
            index--;
            carry = last/10;
            last = last % 10;
            ans.push_back(last);
        }
        if(carry) ans.push_back(carry);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};